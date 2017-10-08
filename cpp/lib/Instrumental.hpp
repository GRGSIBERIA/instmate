#include <vector>
#include "ScaleMap.hpp"
using namespace std;

namespace instmt
{
	class Instrument
	{
	protected:
		vector<Pitch> pitches;

		Instrument(const unsigned int size)
			: pitches(size) {}
	};

	class Strings : public Instrument
	{
	public:
		Strings(const ScaleMap& scaleMap, const unsigned int numberOfStrings, const unsigned int numberOfFrets, const unsigned int pitchHeightOfNextString, const vector<Pitch>& firstPitches)
			: Instrument(numberOfStrings * numberOfFrets)
		{
			auto itr = firstPitches.begin();
			for (int i = 0; itr != firstPitches.end(); ++itr, ++i)
			{
				auto midiNum = itr->midiNoteNumber;
				for (int j = 0; j < numberOfFrets; ++j)
				{
					this->pitches[i * numberOfFrets + j] = scaleMap.GetPitch(midiNum + j);
				}
			}
		}
	};

}