﻿using System.Collections;
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

        private List<Element> ExcludeNote(Chord chord, int addNoteNum)
        {
            List<Element> retval = new List<Element>();
            foreach (var s in this.List)
            {
                bool skipflag = false;
                foreach (var c in chord.List)
                {
                    var news = s * addNoteNum;
                    if (news == c)
                    {
                        skipflag = true;
                        break;
                    }
                }
                if (!skipflag)
                    retval.Add(s);
            }
            return retval;
        }

        /// <summary>
        /// アボイドノートを除外したスケールを生成
        /// </summary>
        /// <param name="chord"></param>
        /// <returns></returns>
        public Scale ExcludeAvoid(Chord chord)
        {
            return new Scale(ExcludeNote(chord, 1));
        }

        public Scale ExcludeTritone(Chord chord)
        {
            return new Scale(ExcludeNote(chord, 6));
        }
    }

    public class Chord : Group
    {
        public string Name { get; private set; }

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
