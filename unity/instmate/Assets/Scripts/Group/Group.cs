using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 群の要素，群の元
/// </summary>
public struct Element
{
    private int number;
    private int ceil;

    private static int MusicalMod(int x)
    {
        int n = x >> 2;
        while ((n & 0xFC) > 0)
            n = (n >> 2) + (n & 3);
        x &= 3;
        if (n == 3 || n == 0) return x;
        return x + (n << 2);
    }

    public Element(int number, int ceil)
    {
        this.number = MusicalMod(number);
        this.ceil = ceil;
    }

    /// <summary>
    /// べき乗の数
    /// </summary>
    public int Number
    {
        get
        {
            return number;
        }
    }

    /// <summary>
    /// 位数
    /// </summary>
    public int Ceil
    {
        get
        {
            return ceil;
        }
    }

    /// <summary>
    /// 元となる
    /// </summary>
    /// <param name="l"></param>
    /// <param name="r"></param>
    /// <returns></returns>
    public static Element operator* (Element l, Element r)
    {
        if (l.Ceil != r.Ceil)
            throw new System.Exception("Not equal a ceil of an element");
        return new Element(l.Number + r.Number, l.Ceil);
    }
}

/// <summary>
/// 巡回群
/// </summary>
public class CyclicGroup
{
    public CyclicGroup(List<int> list, int ceil)
    {
        this.Ceil = ceil;
        this.List = new List<Element>(list.Count);
        for (int i = 0; i < list.Count; ++i)
        {
            this.List[i] = new Element(list[i], ceil);
        }
    }

    public CyclicGroup(List<Element> list, int ceil)
    {
        this.Ceil = ceil;
        this.List = new List<Element>(list);
    }

    private static CyclicGroup MultipleGroup(Element elem, CyclicGroup group)
    {
        List<Element> retval = new List<Element>(group.List.Count);
        for (int i = 0; i < group.List.Count; ++i)
        {
            retval[i] = elem * group.List[i];
        }
        return new CyclicGroup(retval, group.Ceil);
    }

    public static CyclicGroup operator *(Element elem, CyclicGroup group)
    {
        return MultipleGroup(elem, group);
    }

    public static CyclicGroup operator *(CyclicGroup group, Element elem)
    {
        return MultipleGroup(elem, group);
    }
    

    protected int Ceil
    {
        get
        {
            return Ceil;
        }

        private set
        {
            Ceil = value;
        }
    }

    protected List<Element> List
    {
        get
        {
            return List;
        }

        private set
        {
            List = value;
        }
    }
}
