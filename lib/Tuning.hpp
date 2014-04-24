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
			: Strings(map, 6, 25, {
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
	* ギターの半音下げチューニング
	*/
	class GuitarHalfStepDownTuning : public Strings
	{
	public:
		GuitarHalfStepDownTuning(const PitchMap& map)
			: Strings(map, 6, 25, {
			map.GetPitch(PitchName::DSharp, 2),
			map.GetPitch(PitchName::GSharp, 2),
			map.GetPitch(PitchName::CSharp, 3),
			map.GetPitch(PitchName::FSharp, 3),
			map.GetPitch(PitchName::C, 3),
			map.GetPitch(PitchName::DSharp, 4) })
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
			: Strings(map, 6, 25, {
			map.GetPitch(PitchName::D, 2),
			map.GetPitch(PitchName::A, 2),
			map.GetPitch(PitchName::D, 3),
			map.GetPitch(PitchName::G, 3),
			map.GetPitch(PitchName::B, 3),
			map.GetPitch(PitchName::E, 4) })
		{

		}
	};

	/**
	* ベースのレギュラーチューニング
	*/
	class BaseRegularTuning : public Strings
	{
	public:
		BaseRegularTuning(const PitchMap& map)
			: Strings(map, 4, 25, {
			map.GetPitch(PitchName::E, 2),
			map.GetPitch(PitchName::A, 2),
			map.GetPitch(PitchName::D, 3),
			map.GetPitch(PitchName::G, 3)})
			{

		}
	};

	/**
	* ベースの半音下げチューニング
	*/
	class BaseHalfStepDownTuning : public Strings
	{
	public:
		BaseHalfStepDownTuning(const PitchMap& map)
			: Strings(map, 4, 25, {
			map.GetPitch(PitchName::DSharp, 2),
			map.GetPitch(PitchName::GSharp, 2),
			map.GetPitch(PitchName::CSharp, 3),
			map.GetPitch(PitchName::FSharp, 3)})
			{

		}
	};
}