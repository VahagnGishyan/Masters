
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Vertex.hpp"

namespace Masters
{
	namespace Matrix
	{
		CVertex::CVertex() : /*m_location(),*/ m_property(), m_neighborhoods() {}
		CVertex::CVertex(/*const CLocation& loc, */ const CProperty & prop, const CNeighborhoods& neighborhoods)
			: /*m_location(loc),*/ m_property(prop), m_neighborhoods(neighborhoods) {}
		CVertex::CVertex(/*CLocation&& loc, */CProperty&& prop, CNeighborhoods&& neighborhoods)
			: /*m_location(loc),*/ m_property(prop), m_neighborhoods(neighborhoods) {}
		CVertex::~CVertex() {}

		// location
		//const Vertex::CLocation& CVertex::location()                         const noexcept
		//{
		//	return (m_location);
		//}
		//void             CVertex::location(const CLocation& loc)           noexcept
		//{
		//	m_location = loc;
		//}

		// property
		const CVertex::CProperty& CVertex::property()                         const noexcept
		{
			return (m_property);
		}
		void                      CVertex::property(const CProperty& prop)          noexcept
		{
			m_property = prop;
		}

		// edge list
		const CNeighborhoods& CVertex::edgeList()                         const noexcept
		{
			return (m_neighborhoods);
		}
		void             CVertex::neighborhoods(const CNeighborhoods& edgeList)      noexcept
		{
			m_neighborhoods = edgeList;
		}
		void             CVertex::addNeighborhood(const CNeighborhood& edge)              noexcept
		{
			m_neighborhoods.push_back(edge);
		}
		const CNeighborhood& CVertex::getEdge(const int index)          const noexcept
		{
			return (m_neighborhoods[index]);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
	}
}