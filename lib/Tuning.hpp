#include "Scale.hpp"

namespace instmt
{
	/**
	* ギターのレギュラーチューニング
	*/
	class GuitarRegularTuning : public Strings
	{
	public:
		GuitarRegularTuning(const PitchMap& map)
			: Strings(map, 6, 24, {
			map.GetPitch(PitchName::E, 2),
			map.GetPitch(PitchName::A, 2),
			map.GetPitch(PitchName::D, 3),
			map.GetPitch(PitchName::G, 3),
			map.GetPitch(PitchName::B, 3),
			map.GetPitch(PitchName::E, 4) })
		{

		}
	};

	/**
	* ギターのドロップDチューニング
	*/
	class GuitarDropDTuning : public Strings
	{
	public:
		GuitarDropDTuning(const PitchMap& map)
			: Strings(map, 6, 24, {
			map.GetPitch(PitchName::D, 2),
			map.GetPitch(PitchName::A, 2),
			map.GetPitch(PitchName::D, 3),
			map.GetPitch(PitchName::G, 3),
			map.GetPitch(PitchName::B, 3),
			map.GetPitch(PitchName::E, 4) })
		{

		}
	};
}