#include <vector>
#include "PitchMap.hpp"
using namespace std;

namespace instmt
{
	class Scale
	{
	protected:
		vector<Pitch> pitches;

		Scale(const unsigned int size)
			: pitches(size) {}
	};

	class Strings : public Scale
	{
	public:
		Strings(const PitchMap& pitchMap, const unsigned int numberOfStrings, const unsigned int numberOfFrets, const vector<Pitch>& firstPitches)
			: Scale(numberOfStrings * numberOfFrets)
		{
			auto itr = firstPitches.begin();
			for (int i = 0; itr != firstPitches.end(); ++itr, ++i)
			{
				auto midiNum = itr->midiNoteNumber;
				for (int j = 0; j < numberOfFrets; ++j)
				{
					this->pitches[i * numberOfFrets + j] = pitchMap.GetPitch(midiNum + j);
				}
			}
		}
	};
}