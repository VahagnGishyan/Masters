
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_CLOCATION_HPP
#define MT_MATRIX_CLOCATION_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"
#include "Masters/CSmart/FundamentalTypes/Int.hpp"
//#include "CSizes.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_CLOCATION_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Location
			{
				MT_MATRIX_CLOCATION_EXPORT MacroClassInt(COrdinate);
				MT_MATRIX_CLOCATION_EXPORT MacroClassInt(CAbscissa);
			}

			class MT_MATRIX_CLOCATION_EXPORT CLocation
			{
				using COrdinate = Matrix::Location::COrdinate;
				using CAbscissa = Matrix::Location::CAbscissa;

			public: // ctor/dector

				CLocation()                                                       noexcept;
				CLocation(const COrdinate&  ordinate, const CAbscissa&  abscissa) noexcept;
				CLocation(      COrdinate&& ordinate,       CAbscissa&& abscissa) noexcept;

				virtual ~CLocation()                                              noexcept;

			public: // public geter seter
				//MacroClassMember(COrdinate, ordinate);
				//MacroClassMember(CAbscissa, abscissa);

				void ordinate(const COrdinate& ordinate)       noexcept /*mut { mbr }*/;
				void ordinate(COrdinate&& ordinate)            noexcept /*mut { mbr }*/;

				void abscissa(const CAbscissa& abscissa)       noexcept /*mut { mbr }*/;
				void abscissa(CAbscissa&& abscissa)            noexcept /*mut { mbr }*/;

				const Location::COrdinate ordinate()     const noexcept /*mut { mbr }*/;
				const Location::CAbscissa abscissa()     const noexcept /*mut { mbr }*/;

			public: // operators

				friend bool MT_MATRIX_CLOCATION_EXPORT operator== (const CLocation& left, const CLocation& right) noexcept;
				friend bool MT_MATRIX_CLOCATION_EXPORT operator!= (const CLocation& left, const CLocation& right) noexcept;
				//bool operator>= (const CLocation& obj)   const noexcept;
				//bool operator<= (const CLocation& obj)   const noexcept;
				//bool operator>  (const CLocation& obj)   const noexcept;
				//bool operator<  (const CLocation& obj)   const noexcept;

			private: // mem vars
				COrdinate m_ordinate;
				CAbscissa m_abscissa;
			};

			namespace Location
			{
				bool MT_MATRIX_CLOCATION_EXPORT isValid(const CLocation& loc) noexcept;

				//bool isValidLoc(const CLocation& loc) noexcept 
				//{ 
				//	return ((loc.ordinate() >= COrdinate(0)) && (loc.abscissa() >= CAbscissa(0)));
				//}
				//bool isValidLoc(const CLocation& loc, const CSizes& sizes) noexcept 
				//{ 
				//	return (isValidLoc(loc)/*coordins > 0*/ &&
				//		(loc.abscissa() >= 0 && loc.ordinate() < sizes.Height().value()));  
				//}
				//bool isValidLoc(const CLocation& loc, const CSizes& sizes) noexcept
				//{
				//	return (isValidLoc(loc) && (loc.abscissa() >= 0 && loc.ordinate() < sizes.Height().value()));
				//}

				//void setNullLoc(CLocation& loc)       noexcept { loc.ordinate(-1); loc.abscissa(-1); }
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_CLOCATION_HPP

//////////////////////////////////////////////////////////////////////////
