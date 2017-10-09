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

        public Scale ExcludeAvoid(Chord chord)
        {
            for (int i = 0; i < chord.Count; ++i)
            {
                var c = chord[i];

                for (int j = 0; j < this.Count; ++j)
                {
                    var s = this[i].Number;

                    
                }
            }
            return new Scale(this);
        }

        public Scale ExcludeTritone(Chord chord)
        {
            return new Scale(this);
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
