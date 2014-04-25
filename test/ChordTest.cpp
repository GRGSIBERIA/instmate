#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace instmt::chord;

namespace instmatetest
{
	TEST_CLASS(ExtensionTest)
	{
	private:
		void CheckExtension(const instmt::PitchMap& map, const instmt::chord::ExtensionBase& ext, const instmt::PitchName name)
		{
			auto pitch = map.GetPitch(0u, 4u);
			auto result = ext.ToPitch(map, pitch);
			Assert::AreEqual((unsigned)result.pitchName, (unsigned)name);
		}

		void CheckToPitchForOctave(const instmt::PitchMap& map, const instmt::chord::ExtensionBase& ext, const unsigned int octave)
		{
			auto pitch = map.GetPitch(0u, 4u);
			auto result = ext.ToPitch(map, pitch);
			Assert::AreEqual(result.octave, octave);
		}
		
	public:
		TEST_METHOD(CheckExtension)
		{
			instmt::PitchMap map;
			CheckExtension(map, Major3rd(), instmt::E);
			CheckExtension(map, Minor3rd(), instmt::DSharp);
			CheckExtension(map, Sus2(), instmt::D);
			CheckExtension(map, Sus4(), instmt::F);
			CheckExtension(map, Add9th(), instmt::D);
			CheckExtension(map, Add11th(), instmt::F);
			CheckExtension(map, Add13th(), instmt::A);
			CheckExtension(map, Perfect5th(), instmt::G);
			CheckExtension(map, Major7th(), instmt::B);
		}

		TEST_METHOD(TestToPitch)
		{
			instmt::PitchMap map;
			CheckToPitchForOctave(map, Major3rd(), 4);
			CheckToPitchForOctave(map, Add9th(), 5);
		}
	};
}