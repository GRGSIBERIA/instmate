#include <vector>
#include "PitchMap.hpp"
using namespace std;

namespace instmt
{
	/**
	* スケールを表すためのクラス
	* ギターのフレットと音名の対応も含む
	*/
	class Scale
	{
	protected:
		vector<Pitch> pitches;

		Scale(const unsigned int size)
			: pitches(size) {}
	};

	/**
	* 弦楽器のスケールを表すクラス
	*/
	class Strings : public Scale
	{
	protected:
		unsigned int numberOfStrings;
		unsigned int numberOfFrets;

	public:
		Strings(const PitchMap& pitchMap, const unsigned int numberOfStrings, const unsigned int numberOfFrets, const vector<Pitch>& firstPitches)
			: Scale(numberOfStrings * numberOfFrets), numberOfFrets(numberOfFrets), numberOfStrings(numberOfStrings)
		{
			auto itr = firstPitches.begin();
			for (int i = 0; itr != firstPitches.end(); ++itr, ++i)
			{
				auto midiNum = itr->midiNoteNumber;
				for (unsigned int j = 0; j < numberOfFrets; ++j)
				{
					auto rhs = pitchMap.GetPitch(midiNum + j);
					auto lhs = this->pitches[i * numberOfFrets + j];
					Pitch::Substitute(lhs, rhs);
				}
			}
		}

		/**
		* 弦とフレット数からピッチを取得する
		* @param strings 弦番号，低音弦ほど低い数値
		* @param fret フレット数
		* @note 6弦=添字[0]
		*/
		inline const Pitch& GetPitch(const unsigned int strings, const unsigned int fret) const
		{
			return pitches[strings * numberOfFrets + fret];
		}
	};
}