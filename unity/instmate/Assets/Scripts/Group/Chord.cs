using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Musical
{
    /// <summary>
    /// 構成音の種類
    /// </summary>
    public enum ToneType
    {
        Root,
        Third,
        Fifth,
        Seventh,
        OnChord
    }

    /// <summary>
    /// 構成音
    /// </summary>
    public struct Tone
    {
        public ToneType Type { get; private set; }      /// トーンの種類
        public int ToneID { get; private set; }         /// 音階上のID
        public string Name { get; private set; }        /// 構成音の名前
    }

    /// <summary>
    /// 和音を表すクラス
    /// </summary>
    public class Chord : Group
    {
        public string Name { get; private set; }
        public List<Tone> Tones { get; private set; }

        public Chord(List<int> list, string name) : base(list)
        {
            this.Name = name;
        }

        public Chord(List<Element> list, string name) : base(list)
        {
            this.Name = name;
        }

        public Chord(Group g, string name) : base(g)
        {
            this.Name = name;
        }

        public Chord(Chord chord) : base(chord)
        {
            this.Name = chord.Name;
        }

        private static string DetectChordName(List<int> list)
        {
            string name = "";



            return name;
        }

        private static List<int> DetectChordList(string name)
        {
            List<int> retval = new List<int>();

            return retval;
        }
    }
}
