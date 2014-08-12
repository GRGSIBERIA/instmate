#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace instmatetest
{		
	TEST_CLASS(PitchMapTest)
	{
	private:
		void CheckMidiNoteNumber(const instmt::PitchMap& map, const unsigned int num, const instmt::PitchName name)
		{
			auto test = map.GetPitch(num);
			Assert::AreEqual((unsigned int)test.pitchName, (unsigned int)name);
		}

		void CheckFrequency(const instmt::PitchMap& map, const float freq, const unsigned int noteNum)
		{
			auto test = map.GetPitch(freq);
			Assert::AreEqual(test.midiNoteNumber, noteNum);
		}

		void CheckPitchNumberOctave(const instmt::PitchMap& map, const unsigned int pitchNumber, const unsigned int octave, const unsigned int noteNum)
		{
			auto test = map.GetPitch(pitchNumber, octave);
			Assert::AreEqual(test.midiNoteNumber, noteNum);
		}

		void CheckChangePitch(const instmt::PitchMap& map, const unsigned int noteNum, const int changePitch, const unsigned int checkNoteNum)
		{
			auto test = map.GetPitch(noteNum);
			auto res = map.ChangePitch(test, changePitch);
			Assert::AreEqual(res.midiNoteNumber, checkNoteNum);
		}
	public:
		
		TEST_METHOD(TestGetInstance)
		{
			auto inst = instmt::PitchMapFactory::GetInstance();
			auto pitch = inst[0];
		}

		TEST_METHOD(TestMidiNoteNumber)
		{
			// TODO: テスト コードをここに挿入します
			instmt::PitchMap map;
			CheckMidiNoteNumber(map, 12, (instmt::PitchName)0);
			CheckMidiNoteNumber(map, 12, instmt::C);
			CheckMidiNoteNumber(map, 131, (instmt::PitchName)11);
			CheckMidiNoteNumber(map, 131, instmt::B);
		}

		TEST_METHOD(TestFrequency)
		{
			instmt::PitchMap map;
			CheckFrequency(map, 30, 23);
			CheckFrequency(map, 31, 24);
			CheckFrequency(map, 15000, 131);
			CheckFrequency(map, 14900, 130);
			CheckFrequency(map, 14, 12);
		}

		TEST_METHOD(TestPitchNumberOctave)
		{
			instmt::PitchMap map;
			CheckPitchNumberOctave(map, 0, 0, 12);
			CheckPitchNumberOctave(map, 11, 9, 131);
			CheckPitchNumberOctave(map, 9, 3, 57);
		}

		TEST_METHOD(TestChangePitch)
		{
			instmt::PitchMap map;
			CheckChangePitch(map, 12, 5, 17);
			CheckChangePitch(map, 12, -1, 12);	// 丸めテスト
			CheckChangePitch(map, 131, -6, 125);
			CheckChangePitch(map, 131, 5, 131);	// 丸めテスト
		}
	};
}