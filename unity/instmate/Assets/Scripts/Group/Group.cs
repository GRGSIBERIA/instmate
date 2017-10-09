using System.Collections;
using System.Collections.Generic;
using UnityEngine;


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

    public int Number
    {
        get
        {
            return number;
        }
    }

    public int Ceil
    {
        get
        {
            return ceil;
        }
    }

    public static Element operator* (Element l, Element r)
    {
        if (l.Ceil != r.Ceil)
            throw new System.Exception("Not equal a ceil of an element");
        return new Element(l.Number + r.Number, l.Ceil);
    }
}

public class Group 
{
    private List<Element> list;
    private int ceil;

    public Group(List<int> list, int ceil)
    {
        this.ceil = ceil;
        this.List = new List<Element>(list.Count);
        for (int i = 0; i < list.Count; ++i)
        {
            this.List[i] = new Element(list[i], ceil);
        }
    }

    public Group(List<Element> list, int ceil)
    {
        this.ceil = ceil;
        this.list = new List<Element>(list);
    }

    private static Group MultipleGroup(Element elem, Group group)
    {
        List<Element> retval = new List<Element>(group.list.Count);
        for (int i = 0; i < group.list.Count; ++i)
        {
            retval[i] = elem * group.list[i];
        }
        return new Group(retval, group.ceil);
    }

    public static Group operator* (Element elem, Group group)
    {
        return MultipleGroup(elem, group);
    }

    public static Group operator* (Group group, Element elem)
    {
        return MultipleGroup(elem, group);
    }

    protected int Ceil
    {
        get
        {
            return ceil;
        }

        set
        {
            ceil = value;
        }
    }

    protected List<Element> List
    {
        get
        {
            return list;
        }

        set
        {
            list = value;
        }
    }
}
