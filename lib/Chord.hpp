#pragma once
#include <set>
#include "PitchMap.hpp"

namespace instmt
{
	namespace chord
	{
		/**
		* 和音の構成音の種類
		*/
		enum ExtensionType
		{
			Third,		// 第三音
			Fifth,		// 第五音
			Seventh,	// 第七音
			Tension		// 装飾音
		};

		/**
		* コード装飾の基本クラス
		*/
		class ExtensionBase
		{
		protected:
			unsigned int step;	// 度数, 0 = 1度，1 = 短2度
			ExtensionType type;
			string extName;		// コード装飾の実名

		public:
			ExtensionBase(const unsigned int step, const ExtensionType type, const string& extName)
				: step(step), type(type), extName(extName) {}

			/**
			* 度数(step)からPitchに変換する
			* @return basePitchからstepだけ移動したPitch
			*/
			const Pitch& ToPitch(const PitchMap& map, const Pitch& base) const
			{
				return map.ChangePitch(base, step);
			}

			/**
			* コード装飾の文字
			* @return コード装飾の文字
			*/
			inline const string& ToString() const
			{
				return extName;
			}
		};

		/**
		* コードのベースになるクラス
		*/
		class Chord
		{
		protected:
			Pitch basePitch;		// ベースになるピッチ
			vector<Pitch> pitches;	// コードを構成するピッチ

		public:
			Chord(const PitchMap& map, const Pitch& pitch, const vector<ExtensionBase>& extentions = {})
			{
				Pitch::Substitute(basePitch, pitch);

				// 構成音を追加する
				for (auto itr = extentions.begin(); itr != extentions.end(); ++itr)
				{
					AddExtension(map, *itr);
				}
			}

			virtual ~Chord() {}

			/**
			* 構成音を追加する
			* @param map ピッチの表
			* @param ext 追加したいExtension
			* @return Pitchに変換されたext
			*/
			inline const Pitch& AddExtension(const PitchMap& map, const ExtensionBase& ext)
			{
				auto pitch = ext.ToPitch(map, basePitch);
				auto index = lower_bound(pitches.begin(), pitches.end(), pitch, [](const Pitch& lhs, const Pitch& rhs) -> bool { return lhs.pitchName < rhs.pitchName; });
				pitches.insert(index, pitch);
				return *index;
			}

			/**
			* pitchesから重複を除いた状態にする
			*/
			inline const void Normalize()
			{
				//set<Pitch> s(pitches.begin(), pitches.end());
				//pitches = vector<Pitch>(s.begin(), s.end());
			}
		};

		/**
		* major3rd
		*/
		class Major3rd : public ExtensionBase
		{
		public:
			Major3rd()
				: ExtensionBase(4, ExtensionType::Third, "") {}
		};

		/**
		* minor3rd
		*/
		class Minor3rd : public ExtensionBase
		{
		public:
			Minor3rd()
				: ExtensionBase(3, ExtensionType::Third, "m") {}
		};

		/**
		* 第3音が長2度
		*/
		class Sus2 : public ExtensionBase
		{
		public:
			Sus2()
				: ExtensionBase(2, ExtensionType::Third, "sus2") {}
		};

		/**
		* 第3音が完全4度
		*/
		class Sus4 : public ExtensionBase
		{
		public:
			Sus4()
				: ExtensionBase(5, ExtensionType::Third, "sus4") {}
		};

		/**
		* M7th
		*/
		class Major7th : public ExtensionBase
		{
		public:
			Major7th()
				: ExtensionBase(11, ExtensionType::Seventh, "M7") {}
		};

		/**
		* 7th
		*/
		class Minor7th : public ExtensionBase
		{
		public:
			Minor7th()
				: ExtensionBase(10, ExtensionType::Seventh, "7") {}
		};

		/**
		* 第7音が長6度
		*/
		class Add6th : public ExtensionBase
		{
		public:
			Add6th()
				: ExtensionBase(9, ExtensionType::Seventh, "6") {}
		};

		/**
		* 第5音が減5度
		*/
		class Flat5th : public ExtensionBase
		{
		public:
			Flat5th()
				: ExtensionBase(6, ExtensionType::Fifth, "(-5)") {}
		};

		/**
		* 第5音が完全5度
		*/
		class Perfect5th : public ExtensionBase
		{
		public:
			Perfect5th()
				: ExtensionBase(7, ExtensionType::Fifth, "") {}
		};

		/**
		* 第5音が増5度
		*/
		class Sharp5th : public ExtensionBase
		{
		public:
			Sharp5th()
				: ExtensionBase(8, ExtensionType::Fifth, "(+5)") {}
		};

		/**
		* 長2度を付加
		*/
		class Add2 : public ExtensionBase
		{
		public:
			Add2()
				: ExtensionBase(2, ExtensionType::Tension, "add2") {}
		};

		/**
		* 長4度を付加
		*/
		class Add4 : public ExtensionBase
		{
		public:
			Add4()
				: ExtensionBase(5, ExtensionType::Tension, "add4") {}
		};

		/**
		* 9度を付加
		*/
		class Add9th : public ExtensionBase
		{
		public:
			Add9th()
				: ExtensionBase(2 + 12, ExtensionType::Tension, "+9") {}
		};

		/**
		* b9度を付加
		*/
		class AddFlat9th : public ExtensionBase
		{
		public:
			AddFlat9th()
				: ExtensionBase(1 + 12, ExtensionType::Tension, "+b9") {}
		};

		/**
		* #9度を付加
		*/
		class AddSharp9th : public ExtensionBase
		{
		public:
			AddSharp9th()
				: ExtensionBase(3 + 12, ExtensionType::Tension, "+#9") {}
		};

		/**
		* 11度を付加
		*/
		class Add11th : public ExtensionBase
		{
		public:
			Add11th()
				: ExtensionBase(5 + 12, ExtensionType::Tension, "+11") {}
		};

		/**
		* #11度を付加
		*/
		class AddSharp11th : public ExtensionBase
		{
		public:
			AddSharp11th()
				: ExtensionBase(6 + 12, ExtensionType::Tension, "+#11") {}
		};

		/**
		* 13度を付加
		*/
		class Add13th : public ExtensionBase
		{
		public:
			Add13th()
				: ExtensionBase(9 + 12, ExtensionType::Tension, "+13") {}
		};

		/**
		* b13度を付加
		*/
		class AddFlat13th : public ExtensionBase
		{
		public:
			AddFlat13th()
				: ExtensionBase(8 + 12, ExtensionType::Tension, "+b13") {}
		};
	}
}