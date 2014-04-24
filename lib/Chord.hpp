#pragma once
#include "PitchMap.hpp"

namespace instmt
{
	namespace ext
	{
		/**
		* 和音の構成音の種類
		*/
		enum ExtensionType
		{
			Third,
			Fifth,
			Seventh,
			Tension
		};

		/**
		* コード装飾の基本クラス
		*/
		class ExtensionBase
		{
		protected:
			unsigned int step;	// 度数, 0 = 1度，1 = 短2度
			ExtensionType type;

		public:
			ExtensionBase(const unsigned int step, ExtensionType type)
				: step(step), type(type) {}
		};

		/**
		* コードのベースになるクラス
		*/
		class Chord
		{
		protected:
			Pitch basePitch;
			vector<ExtensionBase> extentions;

		public:
			Chord(const Pitch& pitch, const vector<ExtensionBase>& extentions)
				: extentions(extentions) 
			{
				Pitch::Substitute(basePitch, pitch);
			}

			Chord& operator+(const ExtensionBase& add)
			{
				extentions.push_back(add);
				return (*this);
			}
		};

		/**
		* major3rd
		*/
		class Major3rd : public ExtensionBase
		{
		public:
			Major3rd()
				: ExtensionBase(4, ExtensionType::Third) {}
		};

		/**
		* minor3rd
		*/
		class Minor3rd : public ExtensionBase
		{
		public:
			Minor3rd()
				: ExtensionBase(3, ExtensionType::Third) {}
		};

		/**
		* 第3音が長2度
		*/
		class Sus2 : public ExtensionBase
		{
		public:
			Sus2()
				: ExtensionBase(2, ExtensionType::Third) {}
		};

		/**
		* 第3音が完全4度
		*/
		class Sus4 : public ExtensionBase
		{
		public:
			Sus4()
				: ExtensionBase(5, ExtensionType::Third) {}
		};

		/**
		* M7th
		*/
		class Major7th : public ExtensionBase
		{
		public:
			Major7th()
				: ExtensionBase(11, ExtensionType::Seventh) {}
		};

		/**
		* 7th
		*/
		class Minor7th : public ExtensionBase
		{
		public:
			Minor7th()
				: ExtensionBase(10, ExtensionType::Seventh) {}
		};

		/**
		* 第7音が長6度
		*/
		class Add6th : public ExtensionBase
		{
		public:
			Add6th()
				: ExtensionBase(9, ExtensionType::Seventh) {}
		};

		/**
		* 第5音が減5度
		*/
		class Flat5th : public ExtensionBase
		{
		public:
			Flat5th()
				: ExtensionBase(6, ExtensionType::Fifth) {}
		};

		/**
		* 第5音が完全5度
		*/
		class Perfect5th : public ExtensionBase
		{
		public:
			Perfect5th()
				: ExtensionBase(7, ExtensionType::Fifth) {}
		};

		/**
		* 第5音が増5度
		*/
		class Sharp5th : public ExtensionBase
		{
		public:
			Sharp5th()
				: ExtensionBase(8, ExtensionType::Fifth) {}
		};

		/**
		* 長2度を付加
		*/
		class Add2 : public ExtensionBase
		{
		public:
			Add2()
				: ExtensionBase(2, ExtensionType::Tension) {}
		};

		/**
		* 長4度を付加
		*/
		class Add4 : public ExtensionBase
		{
		public:
			Add4()
				: ExtensionBase(5, ExtensionType::Tension) {}
		};

		/**
		* 9度を付加
		*/
		class Add9th : public ExtensionBase
		{
		public:
			Add9th()
				: ExtensionBase(14, ExtensionType::Tension) {}
		};

		/**
		* #9度を付加
		*/
		class AddFlat9th : public ExtensionBase
		{
		public:
			AddFlat9th()
				: ExtensionBase(13, ExtensionType::Tension) {}
		};

		/**
		* b9度を付加
		*/
		class AddSharp9th : public ExtensionBase
		{
		public:
			AddSharp9th()
				: ExtensionBase(15, ExtensionType::Tension) {}
		};

		/**
		* 11度を付加
		*/
		class Add11th : public ExtensionBase
		{
		public:
			Add11th()
				: ExtensionBase(18, ExtensionType::Tension) {}
		};

		/**
		* #11度を付加
		*/
		class AddSharp11th : public ExtensionBase
		{
		public:
			AddSharp11th()
				: ExtensionBase(19, ExtensionType::Tension) {}
		};

		/**
		* 13度を付加
		*/
		class Add13th : public ExtensionBase
		{
		public:
			Add13th()
				: ExtensionBase(22, ExtensionType::Tension) {}
		};

		/**
		* b13度を付加
		*/
		class AddFlat13th : public ExtensionBase
		{
		public:
			AddFlat13th()
				: ExtensionBase(21, ExtensionType::Tension) {}
		};
	}
}