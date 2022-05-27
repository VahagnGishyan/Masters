
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_CSIZES_HPP
#define MT_MATRIX_CSIZES_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"
#include "Masters/CSmart/FundamentalTypes/Int.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_CSIZES_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Sizes
			{
				MacroClassInt(CHeight);
				MacroClassInt(CLength);
			}

			class MT_MATRIX_CSIZES_EXPORT CSize
			{
				using CHeight = Sizes::CHeight;
				using CLength = Sizes::CLength;

			public: // ctor/dector
				CSize();
				CSize(const CHeight& height, const CLength& length) /*except { std::string } */;
				CSize(CHeight&& height, CLength&& length)           /*except { std::string } */;
				CSize(int, int) = delete;
				virtual ~CSize();

			public: // public geter seter
				void height(const CHeight& height) noexcept;
				void height(CHeight& height)       noexcept;

				void length(const CLength& length) noexcept;
				void length(CLength&& length)      noexcept;

				const CHeight height() const       noexcept;
				const CLength length() const       noexcept;

			public: // operators
				friend bool MT_MATRIX_CSIZES_EXPORT operator== (const CSize& left, const CSize& right) noexcept;
				friend bool MT_MATRIX_CSIZES_EXPORT operator!= (const CSize& left, const CSize& right) noexcept;

			private: // member vars
				CHeight m_height;
				CLength m_length;
			};

			namespace Sizes
			{
				bool MT_MATRIX_CSIZES_EXPORT isValid(const CSize& loc) noexcept;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_CSIZES_HPP

//////////////////////////////////////////////////////////////////////////
