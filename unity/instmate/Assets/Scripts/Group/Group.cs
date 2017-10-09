using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace musical
{

    /// <summary>
    /// 巡回群の元，位数12で固定
    /// </summary>
    public struct Element
    {
        private int number;

        private static int MusicalMod(int x)
        {
            int n = x >> 2;
            while ((n & 0xFC) > 0)
                n = (n >> 2) + (n & 3);
            x &= 3;
            if (n == 3 || n == 0) return x;
            return x + (n << 2);
        }

        public Element(int number)
        {
            this.number = MusicalMod(number);
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
        /// 巡回群の元となる要素同士の積
        /// </summary>
        /// <param name="l"></param>
        /// <param name="r"></param>
        /// <returns>a^n * a^m = a^(n+m)</returns>
        public static Element operator *(Element l, Element r)
        {
            return new Element(l.Number + r.Number);
        }

        /// <summary>
        /// 巡回群の元となる要素同士の積
        /// </summary>
        /// <param name="l"></param>
        /// <param name="r"></param>
        /// <returns>a^n * a^m = a^(n+m)</returns>
        public static Element operator *(Element l, int r)
        {
            return new Element(l.Number + r);
        }

        /// <summary>
        /// 巡回群の元となる要素同士の積
        /// </summary>
        /// <param name="l"></param>
        /// <param name="r"></param>
        /// <returns>a^n * a^m = a^(n+m)</returns>
        public static Element operator *(int l, Element r)
        {
            return new Element(l + r.Number);
        }

        public static bool operator ==(Element l, Element r)
        {
            return l.number == r.number;
        }

        public static bool operator !=(Element l, Element r)
        {
            return l.number != r.number;
        }
    }

    /// <summary>
    /// 巡回群の元を取る集合
    /// </summary>
    public class Group 
    {
        /// <summary>
        /// 巡回群の元を取る集合
        /// </summary>
        /// <param name="list">初期化リスト</param>
        public Group(List<int> list)
        {
            this.List = new List<Element>(list.Count);
            for (int i = 0; i < list.Count; ++i)
            {
                this.List[i] = new Element(list[i]);
            }
        }

        /// <summary>
        /// 巡回群の元を取る集合
        /// </summary>
        /// <param name="list">初期化リスト</param>
        public Group(List<Element> list)
        {
            this.List = new List<Element>(list);
        }

        /// <summary>
        /// 巡回群の元を取る集合
        /// </summary>
        /// <param name="g">コピー元の巡回群</param>
        public Group(Group g)
        {
            this.List = new List<Element>(g.List);
        }

        private static Group MultipleGroup(Element elem, Group group)
        {
            List<Element> retval = new List<Element>(group.List.Count);
            for (int i = 0; i < group.List.Count; ++i)
            {
                retval[i] = elem * group.List[i];
            }
            return new Group(retval);
        }

        /// <summary>
        /// 巡回群の元となる要素と集合の積
        /// </summary>
        /// <param name="elem"></param>
        /// <param name="group"></param>
        /// <returns>元となる要素と群の積の結果</returns>
        public static Group operator *(Element elem, Group group)
        {
            return MultipleGroup(elem, group);
        }

        /// <summary>
        /// 巡回群の元となる要素と集合の積
        /// </summary>
        /// <param name="elem"></param>
        /// <param name="group"></param>
        /// <returns>元となる要素と群の積の結果</returns>
        public static Group operator *(Group group, Element elem)
        {
            return MultipleGroup(elem, group);
        }

        /// <summary>
        /// インデクサ
        /// </summary>
        /// <param name="index"></param>
        /// <returns>Listの要素を返す</returns>
        public Element this[int index]
        {
            get
            {
                if (index >= List.Count)
                    index %= List.Count;
                return List[index];
            }
        }

        public int Count
        {
            get { return List.Count; }
        }

        /// <summary>
        /// 集合のリスト
        /// </summary>
        public List<Element> List
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
}