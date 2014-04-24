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
			unsigned int step;	// 度数, 0 = 1度
			ExtensionType type;

		public:
			ExtensionBase(const unsigned int step, ExtensionType type)
				: step(step), type(type) {}
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
				: ExtensionBase(6, ExtensionType::Third) {}
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
				: ExtensionBase(7, ExtensionType::Fifth) {}
		};

		/**
		* 第5音が完全5度
		*/
		class Perfect5th : public ExtensionBase
		{
		public:
			Perfect5th()
				: ExtensionBase(8, ExtensionType::Fifth) {}
		};

		/**
		* 第5音が増5度
		*/
		class Sharp5th : public ExtensionBase
		{
		public:
			Sharp5th()
				: ExtensionBase(9, ExtensionType::Fifth) {}
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
	}
}