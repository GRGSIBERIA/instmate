using System.Collections;
using System.Collections.Generic;
using UnityEngine;


namespace musical
{
    public class Scale : Group
    {
        public Scale(Group g) : base(g)
        {
        }

        public Scale(List<int> list) : base(list)
        {
        }

        public Scale(List<Element> list) : base(list)
        {
        }
    }

    public class Chord : Group
    {
        public Chord(List<int> list) : base(list)
        {
        }

        public Chord(List<Element> list) : base(list)
        {
        }

        public Chord(Group g) : base(g)
        {
        }
    }

}
