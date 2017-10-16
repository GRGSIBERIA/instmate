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
        /// 音階番号から構成音を取得する
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public static Tone GetTone(int id)
        {
            return tones[Element.MusicalMod(id)];
        }

        /// <summary>
        /// 構成音の配列
        /// </summary>
        private static readonly ReadOnlyCollection<Tone> tones = Array.AsReadOnly(new Tone[] {
            new Tone(ToneType.None, 0, ""),     // ルート音は構成音と言いにくい？
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
        

        /// <summary>
        /// 非公開コンストラクタ
        /// tonesの初期化のみに使用する
        /// </summary>
        /// <param name="type">構成音の種類</param>
        /// <param name="toneId">音階番号</param>
        /// <param name="name">表示名</param>
        private Tone(ToneType type = ToneType.None, int toneId = 0, string name = "")
        {
            this.Type = type;
            this.ToneID = toneId;
            this.Name = name;
        }
        
        /// <summary>
        /// コピーコンストラクタ
        /// </summary>
        /// <param name="t">コピー元</param>
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
            var t = GetTone(toneId);
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

        /// <summary>
        /// 音階番号から構成音を初期化する関数
        /// </summary>
        /// <param name="id">音階番号</param>
        private void InitializeTones(int id)
        {
            var t = Tone.GetTone(id);
            bool isTone = true;     // 構成音判定
            switch (t.Type)
            {
                case ToneType.Third:
                    this.Third = t;
                    break;
                case ToneType.Fifth:
                    this.Fifth = t;
                    break;
                case ToneType.Seventh:
                    this.Seventh = t;
                    break;
                case ToneType.OnChord:
                    this.OnChord = t;
                    break;
                default:
                    isTone = false;
                    break;
            }
            if (isTone)     // 構成音として正しい並びだけ認識する
                this.List.Add(new Element(id));
        }

        /// <summary>
        /// リストからコードを作成する
        /// </summary>
        /// <param name="list"></param>
        public Chord(List<int> list) : base()
        {
            foreach (var l in list)
                InitializeTones(l);
        }

        /// <summary>
        /// リストからコードを作成する
        /// </summary>
        /// <param name="list"></param>
        public Chord(List<Element> list) : base()
        {
            foreach (var l in list)
                InitializeTones(l.Number);
        }

        /// <summary>
        /// リストからコードを作成する
        /// </summary>
        /// <param name="list"></param>
        public Chord(Group g) : base()
        {
            foreach (var l in g.List)
                InitializeTones(l.Number);
        }

        /// <summary>
        /// コピーコンストラクタ
        /// </summary>
        /// <param name="chord"></param>
        public Chord(Chord chord) : base(chord)
        {
            this.Name = chord.Name;
            this.Third = chord.Third;
            this.Fifth = chord.Fifth;
            this.Seventh = chord.Seventh;
            this.OnChord = chord.OnChord;
        }

        public Chord(string name) : base()
        {

        }

        private string NamingThird()
        {
            string retval = "";
            switch (this.Third.ToneID)
            {
                case 3:
                    retval = "m";
                    break;
                case 4:
                    retval = "maj";
                    break;
                case 5:
                    retval = "sus4";
                    break;
                default:
                    break;
            }
            return retval;
        }

        private string NamingFifth()
        {
            string retval = "";
            switch (this.Third.ToneID)
            {
                case 6:
                    retval = "-5";
                    break;
                case 7:
                    break;
                case 8:
                    retval = "+5";
                    break;
                default:
                    break;
            }
            return retval;
        }

        private string NamingSeventh()
        {
            string retval = "";
            switch (this.Third.ToneID)
            {
                case 9:
                    retval = "6";
                    break;
                case 10:
                    retval = "7";
                    break;
                case 11:
                    retval = "M7";
                    break;
                default:
                    break;
            }
            return retval;
        }

        private string DetectChordName(List<int> list)
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
