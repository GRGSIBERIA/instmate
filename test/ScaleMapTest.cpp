#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace instmatetest
{		
	TEST_CLASS(ScaleMapTest)
	{
	private:
		void CheckMidiNoteNumber(const instmt::ScaleMap& map, const unsigned int num, const instmt::PitchName name)
		{
			auto test = map.GetPitch(num);
			Assert::AreEqual((unsigned int)test.pitchName, (unsigned int)name);
		}

		void CheckFrequency(const instmt::ScaleMap& map, const float freq, const unsigned int noteNum)
		{
			auto test = map.GetPitch(freq);
			Assert::AreEqual(test.midiNoteNumber, noteNum);
		}

		void CheckPitchNumberOctave(const instmt::ScaleMap& map, const unsigned int pitchNumber, const unsigned int octave, const unsigned int noteNum)
		{
			auto test = map.GetPitch(pitchNumber, octave);
			Assert::AreEqual(test.midiNoteNumber, noteNum);
		}
	public:
		
		TEST_METHOD(TestMidiNoteNumber)
		{
			// TODO: �e�X�g �R�[�h�������ɑ}�����܂�
			instmt::ScaleMap map;
			CheckMidiNoteNumber(map, 12, (instmt::PitchName)0);
			CheckMidiNoteNumber(map, 12, instmt::C);
			CheckMidiNoteNumber(map, 131, (instmt::PitchName)11);
			CheckMidiNoteNumber(map, 131, instmt::B);
		}

		TEST_METHOD(TestFrequency)
		{
			instmt::ScaleMap map;
			CheckFrequency(map, 30, 23);
			CheckFrequency(map, 31, 24);
			CheckFrequency(map, 15000, 131);
			CheckFrequency(map, 14900, 130);
			CheckFrequency(map, 14, 12);
		}

		TEST_METHOD(TestPitchNumberOctave)
		{
			instmt::ScaleMap map;
			CheckPitchNumberOctave(map, 0, 0, 12);
			CheckPitchNumberOctave(map, 11, 9, 131);
			CheckPitchNumberOctave(map, 9, 3, 57);
		}

	};
}