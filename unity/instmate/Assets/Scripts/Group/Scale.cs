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

        /// <summary>
        /// アボイドノートを除外したスケールを生成
        /// </summary>
        /// <param name="chord"></param>
        /// <returns></returns>
        public Scale ExcludeAvoid(Chord chord)
        {
            List<Element> retval = new List<Element>();
            foreach(var s in this.List)
            {
                bool skipflag = false;
                foreach (var c in chord.List)
                {
                    var news = s * 1;
                    if (news == c)
                    {
                        skipflag = true;
                        break;
                    }
                }
                if (!skipflag)
                    retval.Add(s);
            }
            return new Scale(retval);
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
