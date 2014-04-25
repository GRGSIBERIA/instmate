#pragma once

#include <vector>
#include <algorithm>
using namespace std;

namespace instmt
{
	/**
	* ピッチ名
	*/
	enum PitchName
	{
		C = 0,
		CSharp = 1,
		D = 2,
		DSharp = 3,
		E = 4,
		F = 5,
		FSharp = 6,
		G = 7,
		GSharp = 8,
		A = 9,
		ASharp = 10,
		B = 11
	};

	/**
	* PitchとPitchの上昇と下降の距離を表すクラス
	*/
	class RelativeDistance
	{
	public:
		int upper;	// 上昇の距離
		int lower;	// 下降の距離

		RelativeDistance(int upper, int lower)
			: upper(upper), lower(lower) {}
	};

	/**
	* 音名とオクターブのペアで管理するクラス
	*/
	class Pitch
	{
	public:
		unsigned int midiNoteNumber;	// MIDIノートナンバー
		PitchName pitchName;			// ピッチ名
		unsigned int octave;			// オクターブ
		float frequency;				// 周波数

	public:
		Pitch(const unsigned int midiNoteNumber, const PitchName pitchName, const unsigned int octave, const float frequency)
			: midiNoteNumber(midiNoteNumber), pitchName(pitchName), octave(octave), frequency(frequency) {}

		Pitch(const unsigned int midiNoteNumber, const unsigned int pitchName, const unsigned int octave, const float frequency)
			: midiNoteNumber(midiNoteNumber), pitchName((PitchName)pitchName), octave(octave), frequency(frequency) {}

		Pitch() {}

		/**
		* コピーなしの代入
		* @param lhs 代入先のインスタンス
		* @param rhs 代入したいインスタンス
		*/
		inline static void Substitute(Pitch& lhs, const Pitch& rhs) 
		{
			lhs.frequency = rhs.frequency;
			lhs.midiNoteNumber = rhs.midiNoteNumber;
			lhs.octave = rhs.octave;
			lhs.pitchName = rhs.pitchName;
		}

		/**
		* 二つのPitchを比較する
		* @param lhs 左辺
		* @param rhs 右辺
		* @return lhs < rhs = 1; lhs > rhs = -1; lhs == rhs = 0;
		*/
		inline static const int Compare(const Pitch& lhs, const Pitch& rhs)
		{
			if (lhs.midiNoteNumber < rhs.midiNoteNumber)
				return 1;
			else if (lhs.midiNoteNumber > rhs.midiNoteNumber)
				return -1;
			return 0;
		}

		inline static const RelativeDistance GetRelativeDistance(const Pitch& lhs, const Pitch& rhs)
		{
			int up = 0;
			int low = 0;
			int comp = Compare(lhs, rhs);

			if (comp == 1)
			{
				up = rhs.pitchName - lhs.pitchName;
				low = lhs.pitchName + 12 - rhs.pitchName;
			}
			else if (comp == -1)
			{
				up = lhs.pitchName - rhs.pitchName;
				low = rhs.pitchName + 12 - lhs.pitchName;
			}

			return RelativeDistance(up, low);
		}

		/**
		* 二つのピッチの絶対的な距離を返す
		* @param lhs 左辺
		* @param rhs 右辺
		* @return プラスの場合，lhsの方が高音
		*/
		inline static const int GetAbsoluteDistance(const Pitch& lhs, const Pitch& rhs)
		{
			return (int)lhs.midiNoteNumber - (int)rhs.midiNoteNumber;
		}
	};


	/**
	* スケール表記の地図クラス
	*/
	class PitchMap
	{
	private:
		vector<Pitch> scale;				// スケール
		unsigned int maxScientificPitch;	// 国際的ピッチ表記の最大値
		unsigned int minMidiNoteNumber;

	public:
		/**
		* スケール表記の地図クラス
		*/
		PitchMap()
			: maxScientificPitch(9), minMidiNoteNumber(12)	// 0～8までのピッチ
		{
			scale = {
				Pitch(12, 0, 0, 16.35159783f  ),
				Pitch(13, 1, 0, 17.32391444f  ),
				Pitch(14, 2, 0, 18.35404799f  ),
				Pitch(15, 3, 0, 19.44543648f  ),
				Pitch(16, 4, 0, 20.60172231f  ),
				Pitch(17, 5, 0, 21.82676446f  ),
				Pitch(18, 6, 0, 23.12465142f  ),
				Pitch(19, 7, 0, 24.49971475f  ),
				Pitch(20, 8, 0, 25.9565436f	  ),
				Pitch(21, 9, 0, 27.5f		  ),
				Pitch(22, 10, 0, 29.13523509f ),
				Pitch(23, 11, 0, 30.86770633f ),
				Pitch(24, 0, 1, 32.70319566f  ),
				Pitch(25, 1, 1, 34.64782887f  ),
				Pitch(26, 2, 1, 36.70809599f  ),
				Pitch(27, 3, 1, 38.89087297f  ),
				Pitch(28, 4, 1, 41.20344461f  ),
				Pitch(29, 5, 1, 43.65352893f  ),
				Pitch(30, 6, 1, 46.24930284f  ),
				Pitch(31, 7, 1, 48.9994295f	  ),
				Pitch(32, 8, 1, 51.9130872f	  ),
				Pitch(33, 9, 1, 55.0f		  ),
				Pitch(34, 10, 1, 58.27047019f ),
				Pitch(35, 11, 1, 61.73541266f ),
				Pitch(36, 0, 2, 65.40639133f  ),
				Pitch(37, 1, 2, 69.29565774f  ),
				Pitch(38, 2, 2, 73.41619198f  ),
				Pitch(39, 3, 2, 77.78174593f  ),
				Pitch(40, 4, 2, 82.40688923f  ),
				Pitch(41, 5, 2, 87.30705786f  ),
				Pitch(42, 6, 2, 92.49860568f  ),
				Pitch(43, 7, 2, 97.998859f	  ),
				Pitch(44, 8, 2, 103.8261744f  ),
				Pitch(45, 9, 2, 110.0f		  ),
				Pitch(46, 10, 2, 116.5409404f ),
				Pitch(47, 11, 2, 123.4708253f ),
				Pitch(48, 0, 3, 130.8127827f  ),
				Pitch(49, 1, 3, 138.5913155f  ),
				Pitch(50, 2, 3, 146.832384f	  ),
				Pitch(51, 3, 3, 155.5634919f  ),
				Pitch(52, 4, 3, 164.8137785f  ),
				Pitch(53, 5, 3, 174.6141157f  ),
				Pitch(54, 6, 3, 184.9972114f  ),
				Pitch(55, 7, 3, 195.997718f	  ),
				Pitch(56, 8, 3, 207.6523488f  ),
				Pitch(57, 9, 3, 220.0f		  ),
				Pitch(58, 10, 3, 233.0818808f ),
				Pitch(59, 11, 3, 246.9416506f ),
				Pitch(60, 0, 4, 261.6255653f  ),
				Pitch(61, 1, 4, 277.182631f	  ),
				Pitch(62, 2, 4, 293.6647679f  ),
				Pitch(63, 3, 4, 311.1269837f  ),
				Pitch(64, 4, 4, 329.6275569f  ),
				Pitch(65, 5, 4, 349.2282314f  ),
				Pitch(66, 6, 4, 369.9944227f  ),
				Pitch(67, 7, 4, 391.995436f	  ),
				Pitch(68, 8, 4, 415.3046976f  ),
				Pitch(69, 9, 4, 440.0f		  ),
				Pitch(70, 10, 4, 466.1637615f ),
				Pitch(71, 11, 4, 493.8833013f ),
				Pitch(72, 0, 5, 523.2511306f  ),
				Pitch(73, 1, 5, 554.365262f	  ),
				Pitch(74, 2, 5, 587.3295358f  ),
				Pitch(75, 3, 5, 622.2539674f  ),
				Pitch(76, 4, 5, 659.2551138f  ),
				Pitch(77, 5, 5, 698.4564629f  ),
				Pitch(78, 6, 5, 739.9888454f  ),
				Pitch(79, 7, 5, 783.990872f	  ),
				Pitch(80, 8, 5, 830.6093952f  ),
				Pitch(81, 9, 5, 880.0f		  ),
				Pitch(82, 10, 5, 932.327523f  ),
				Pitch(83, 11, 5, 987.7666025f ),
				Pitch(84, 0, 6, 1046.502261f  ),
				Pitch(85, 1, 6, 1108.730524f  ),
				Pitch(86, 2, 6, 1174.659072f  ),
				Pitch(87, 3, 6, 1244.507935f  ),
				Pitch(88, 4, 6, 1318.510228f  ),
				Pitch(89, 5, 6, 1396.912926f  ),
				Pitch(90, 6, 6, 1479.977691f  ),
				Pitch(91, 7, 6, 1567.981744f  ),
				Pitch(92, 8, 6, 1661.21879f	  ),
				Pitch(93, 9, 6, 1760.0f		  ),
				Pitch(94, 10, 6, 1864.655046f ),
				Pitch(95, 11, 6, 1975.533205f ),
				Pitch(96, 0, 7, 2093.004522f  ),
				Pitch(97, 1, 7, 2217.461048f  ),
				Pitch(98, 2, 7, 2349.318143f  ),
				Pitch(99, 3, 7, 2489.01587f	  ),
				Pitch(100, 4, 7, 2637.020455f ),
				Pitch(101, 5, 7, 2793.825851f ),
				Pitch(102, 6, 7, 2959.955382f ),
				Pitch(103, 7, 7, 3135.963488f ),
				Pitch(104, 8, 7, 3322.437581f ),
				Pitch(105, 9, 7, 3520.0f	  ),
				Pitch(106, 10, 7, 3729.310092f),
				Pitch(107, 11, 7, 3951.06641f ),
				Pitch(108, 0, 8, 4186.009045f ),
				Pitch(109, 1, 8, 4434.922096f ),
				Pitch(110, 2, 8, 4698.636287f ),
				Pitch(111, 3, 8, 4978.03174f  ),
				Pitch(112, 4, 8, 5274.040911f ),
				Pitch(113, 5, 8, 5587.651703f ),
				Pitch(114, 6, 8, 5919.910763f ),
				Pitch(115, 7, 8, 6271.926976f ),
				Pitch(116, 8, 8, 6644.875161f ),
				Pitch(117, 9, 8, 7040.0f	  ),
				Pitch(118, 10, 8, 7458.620184f),
				Pitch(119, 11, 8, 7902.13282f ),
				Pitch(120, 0, 9, 8372.01809f  ),
				Pitch(121, 1, 9, 8869.844191f ),
				Pitch(122, 2, 9, 9397.272573f ),
				Pitch(123, 3, 9, 9956.063479f ),
				Pitch(124, 4, 9, 10548.08182f ),
				Pitch(125, 5, 9, 11175.30341f ),
				Pitch(126, 6, 9, 11839.82153f ),
				Pitch(127, 7, 9, 12543.85395f ),
				Pitch(128, 8, 9, 13289.75032f ),
				Pitch(129, 9, 9, 14080.0f	  ),
				Pitch(130, 10, 9, 14917.24037f),
				Pitch(131, 11, 9, 15804.26564f),
			};
		}

		/**
		* 周波数からピッチを割り出す
		* @param frequency 周波数
		* @return ピッチ
		*/
		const Pitch& GetPitch(const float frequency) const
		{
			Pitch freq_buf(0, 0, 0, frequency);
			auto first = std::lower_bound(scale.begin(), scale.end(), freq_buf, [](const Pitch& lhs, const Pitch& rhs) -> bool { return lhs.frequency < rhs.frequency; });
			auto index = first - scale.begin();		// 1番近い値を取り出す
			
			if (index + 1 == scale.size())
				return scale[index];

			// frequencyとの距離を調べて近い方を返す
			auto a = abs(scale[index].frequency - frequency);
			auto b = abs(scale[index + 1].frequency - frequency);

			if (a < b)
				return scale[index];
			return scale[index + 1];
		}

		/**
		* scaleに対する直接アクセス
		* @param 添字
		* @return ピッチ
		*/
		const Pitch& operator[] (const unsigned int num) const
		{
			return scale[num];
		}

		/**
		* MIDIノートナンバーからピッチを取得する
		* @param midiNoteNumber MIDIノートナンバー, 12～131
		* @return ピッチ
		*/
		inline const Pitch& GetPitch(const unsigned int midiNoteNumber) const
		{
			return scale[midiNoteNumber - minMidiNoteNumber];
		}

		/**
		* 指定したピッチ名（CからBまでの番号）とオクターブからピッチを取得する
		* @param pitchNameNumber ピッチ番号
		* @param octave オクターブ（0～9まで）
		* @return ピッチ
		*/
		inline const Pitch& GetPitch(const unsigned int pitchNameNumber, const unsigned int octave) const
		{
			auto index = octave * 12 + pitchNameNumber;
			return scale[index];
		}

		/**
		* 指定したピッチ名とオクターブからピッチを取得する
		* @param pitchName ピッチ名
		* @param octave オクターブ
		* @return ピッチ
		*/
		inline const Pitch& GetPitch(const PitchName pitchName, const unsigned int octave) const
		{
			auto index = octave * 12 + pitchName;
			return scale[index];
		}

		/**
		* ベースになるピッチから上昇/下降を行う
		* @param basePitch 元になるピッチ
		* @param difference 上昇/下降させたい値
		* @param roundable out of rangeになりそうな場合，自動的に数値を丸めるか
		*/
		inline const Pitch& ChangePitch(const Pitch& basePitch, const int difference, const bool roundable=true) const
		{
			int index = basePitch.midiNoteNumber - minMidiNoteNumber + difference;
			if (!roundable)
			{
				if (index >= (int)scale.size() || index < 0)
					throw std::out_of_range("PitchMap::UpPitch() : index out of range.");
			}
			else
			{
				if (index >= (int)scale.size())
					index = scale.size() - 1;
				else if (index < 0)
					index = 0;
			}
			return scale[index];
		}
	};
}