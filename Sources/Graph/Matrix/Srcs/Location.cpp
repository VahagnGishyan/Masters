
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Location.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{

			CLocation::CLocation()                                                     noexcept :
				m_ordinate(), m_abscissa() {}

			CLocation::CLocation(const COrdinate& ordinate, const CAbscissa& abscissa) noexcept :
				m_ordinate(ordinate), m_abscissa(abscissa) {}

			CLocation::CLocation(COrdinate&& ordinate, CAbscissa&& abscissa)           noexcept :
				m_ordinate(ordinate), m_abscissa(abscissa) {}

			CLocation::~CLocation() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////

			void            CLocation::ordinate(const COrdinate& ordinate) noexcept { m_ordinate = ordinate; }
			void            CLocation::ordinate(COrdinate&& ordinate)      noexcept { m_ordinate = ordinate; }

			void            CLocation::abscissa(const CAbscissa& abscissa) noexcept { m_abscissa = abscissa; }
			void            CLocation::abscissa(CAbscissa&& abscissa)      noexcept { m_abscissa = abscissa; }

			const Location::COrdinate CLocation::ordinate() const          noexcept { return (m_ordinate); }
			const Location::CAbscissa CLocation::abscissa() const          noexcept { return (m_abscissa); }

			////////////////////////////////////////////////////////////////////////////////////////////////////

			//bool CLocation::operator== (const CLocation& obj)           const  noexcept 
			//{
			//	return ((this->ordinate() == obj.ordinate()) && (this->abscissa() == obj.abscissa()));
			//};
			//bool CLocation::operator!= (const CLocation& obj)           const  noexcept 
			//{
			//	return ((this->ordinate() != obj.ordinate()) || (this->abscissa() != obj.abscissa()));
			//};

			bool operator== (const CLocation& left, const CLocation& right) noexcept
			{
				return ((left.ordinate() == right.ordinate()) && (left.abscissa() == right.abscissa()));
			}
			bool operator!= (const CLocation& left, const CLocation& right) noexcept
			{
				return ((left.ordinate() != right.ordinate()) || (left.abscissa() != right.abscissa()));
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////

			//bool CLocation::operator>= (const CLocation& obj)           const  noexcept 
			//{
			//	return ((this->ordinate() >= obj.ordinate()) && (this->abscissa() >= obj.abscissa()));
			//};
			//bool CLocation::operator<= (const CLocation& obj)           const  noexcept 
			//{
			//	return ((this->ordinate() <= obj.ordinate()) && (this->abscissa() <= obj.abscissa()));
			//};
			//bool CLocation::operator> (const CLocation& obj)            const  noexcept
			//{
			//	return ((this->ordinate() > obj.ordinate()) && (this->abscissa() > obj.abscissa()));
			//};
			//bool CLocation::CLocation::operator< (const CLocation& obj) const  noexcept
			//{
			//	return ((this->ordinate() < obj.ordinate()) && (this->abscissa() < obj.abscissa()));
			//};

			////////////////////////////////////////////////////////////////////////////////////////////////////

			bool Location::isValid(const CLocation& loc) noexcept
			{
				return ((loc.ordinate() >= COrdinate(0)) && (loc.abscissa() >= CAbscissa(0)));
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
}
