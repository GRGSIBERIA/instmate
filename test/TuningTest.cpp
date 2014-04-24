#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace instmatetest
{
	TEST_CLASS(TuningTest)
	{
	private:
		void TestGetPitch(const instmt::PitchMap map, const unsigned int str, const unsigned int fret, const int target)
		{
			auto tune = instmt::GuitarRegularTuning(map);
			auto pitch = tune.GetPitch(str, fret);
			Assert::AreEqual((int)pitch.pitchName, target);
		}

	public:
		TEST_METHOD(TestGetPitch)
		{
			instmt::PitchMap map;
			TestGetPitch(map, 0, 0, instmt::E);
			TestGetPitch(map, 5, 0, instmt::E);
			TestGetPitch(map, 1, 0, instmt::A);
			TestGetPitch(map, 0, 24, instmt::E);
		}
	};
}