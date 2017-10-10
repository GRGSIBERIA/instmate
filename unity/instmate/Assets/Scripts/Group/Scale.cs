using System.Collections;
using System.Collections.Generic;
using UnityEngine;


namespace musical
{
    public class Scale : Group
    {
        /// <summary>
        /// スケールが影響を受けているコード
        /// </summary>
        public Chord Chord { get; protected set; }

        public Scale(Group g, Chord chord) : base(g)
        {
            this.Chord = chord;
        }

        public Scale(List<int> list, Chord chord) : base(list)
        {
            this.Chord = chord;
        }

        public Scale(List<Element> list, Chord chord) : base(list)
        {
            this.Chord = chord;
        }

        private enum DisableType
        {
            Chord,
            Avoid,
            Tritone
        }

        private List<Element> ExcludeNote(Chord chord, int addNoteNum, DisableType type)
        {
            List<Element> retval = new List<Element>();
            foreach (var s in this.List)
            {
                var elem = new Element(s);

                foreach (var c in chord.List)
                {
                    var news = s * addNoteNum;
                    if (news == c)
                    {
                        switch (type)
                        {
                            case DisableType.Chord:
                                elem.IsChordTone = true;
                                break;
                            case DisableType.Avoid:
                                elem.IsAvoid = true;
                                break;
                            case DisableType.Tritone:
                                elem.IsTritone = true;
                                break;
                        }
                        break;
                    }
                }
                retval.Add(elem);
            }
            return retval;
        }

        private void InitializeScale(Chord chord)
        {
            this.List = ExcludeNote(chord, 1, DisableType.Avoid);
            this.List = ExcludeNote(chord, 6, DisableType.Tritone);
            this.List = ExcludeNote(chord, 0, DisableType.Chord);
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
