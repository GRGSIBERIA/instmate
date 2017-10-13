using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;

namespace Musical
{
    /// <summary>
    /// 構成音の種類
    /// </summary>
    public enum ToneType
    {
        None,
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
        public ToneType Type { get; private set; }      // トーンの種類
        public int ToneID { get; private set; }         // 音階上のID
        public string Name { get; private set; }        // 構成音の名前

        /// <summary>
        /// 構成音の配列
        /// </summary>
        private static readonly ReadOnlyCollection<Tone> tones = Array.AsReadOnly(new Tone[] {
            new Tone(ToneType.Root, 0, ""),
            new Tone(ToneType.None, 1, ""),
            new Tone(ToneType.None, 2, ""),
            new Tone(ToneType.Third, 3, "m"),
            new Tone(ToneType.Third, 4, "maj"),
            new Tone(ToneType.Fifth, 5, "sus4"),
            new Tone(ToneType.Fifth, 6, "-5"),
            new Tone(ToneType.Fifth, 7, ""),
            new Tone(ToneType.Fifth, 8, "+5"),
            new Tone(ToneType.Seventh, 9, "6"),
            new Tone(ToneType.Seventh, 10, "7"),
            new Tone(ToneType.Seventh, 11, "M7"),
        });
        
        public Tone(ToneType type = ToneType.None, int toneId = 0, string name = "")
        {
            this.Type = type;
            this.ToneID = toneId;
            this.Name = name;
        }
        
        public Tone(Tone t)
        {
            this.Type = t.Type;
            this.ToneID = t.ToneID;
            this.Name = t.Name;
        }

        /// <summary>
        /// 音階番号から判断する
        /// </summary>
        /// <param name="toneId">音階番号，自動的に12未満にまとまる</param>
        public Tone(int toneId)
        {
            var t = tones[Element.MusicalMod(toneId)];
            this.Type = t.Type;
            this.ToneID = t.ToneID;
            this.Name = t.Name;
        }
    }

    /// <summary>
    /// 和音を表すクラス
    /// </summary>
    public class Chord : Group
    {
        public string Name { get; private set; }
        public Tone Third { get; private set; }
        public Tone Fifth { get; private set; }
        public Tone Seventh { get; private set; }
        public Tone OnChord { get; private set; }

        private void InitializeTones()
        {

        }

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
