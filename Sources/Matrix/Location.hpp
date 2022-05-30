//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_LOCATION_HPP
#define MT_MATRIX_LOCATION_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"
#include "Masters/CSmart/FundamentalTypes/Int.hpp"
#include "Masters/Matrix/Size.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_LOCATION_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Matrix
	{
		namespace Location
		{
			MacroClassInt(COrdinate);
			MacroClassInt(CAbscissa);
		}

		class MT_MATRIX_LOCATION_EXPORT CLocation
		{
			using COrdinate = Matrix::Location::COrdinate;
			using CAbscissa = Matrix::Location::CAbscissa;

		public: // ctor/dector

			CLocation()                                                       noexcept;
			CLocation(const COrdinate& ordinate, const CAbscissa& abscissa) noexcept;
			CLocation(COrdinate&& ordinate, CAbscissa&& abscissa) noexcept;
			CLocation(int, int) = delete;

			virtual ~CLocation()                                              noexcept;

		public: // public geter seter
			void ordinate(const COrdinate& ordinate)       noexcept /*mut { mbr }*/;
			void ordinate(COrdinate&& ordinate)            noexcept /*mut { mbr }*/;

			void abscissa(const CAbscissa& abscissa)       noexcept /*mut { mbr }*/;
			void abscissa(CAbscissa&& abscissa)            noexcept /*mut { mbr }*/;

			const Location::COrdinate ordinate()     const noexcept /*mut { mbr }*/;
			const Location::CAbscissa abscissa()     const noexcept /*mut { mbr }*/;

		public: // operators

			friend bool MT_MATRIX_LOCATION_EXPORT operator== (const CLocation& left, const CLocation& right) noexcept;
			friend bool MT_MATRIX_LOCATION_EXPORT operator!= (const CLocation& left, const CLocation& right) noexcept;

		private: // mem vars
			COrdinate m_ordinate;
			CAbscissa m_abscissa;
		};

		namespace Location
		{
			bool MT_MATRIX_LOCATION_EXPORT valid(const CLocation& loc) noexcept;
			bool MT_MATRIX_LOCATION_EXPORT valid(const CLocation& loc,
				const Size::CHeight& height, const Size::CLength& length) noexcept;
			bool MT_MATRIX_LOCATION_EXPORT valid(const CLocation& loc, const CSize& sizes) noexcept;
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_LOCATION_HPP

//////////////////////////////////////////////////////////////////////////
