
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Vertex.hpp"

namespace Masters
{
	namespace Matrix
	{
		CVertex::CVertex() : m_location(), m_property(), m_edgeList() {}
		CVertex::CVertex(const CLocation& loc, const CProperty& prop, const CEdgeList& edges)
			: m_location(loc), m_property(prop), m_edgeList(edges) {}
		CVertex::CVertex(CLocation&& loc, CProperty&& prop, CEdgeList&& edges)
			: m_location(loc), m_property(prop), m_edgeList(edges) {}
		CVertex::~CVertex() {}

		// location
		const Vertex::CLocation& CVertex::location()                         const noexcept
		{
			return (m_location);
		}
		void             CVertex::location(const CLocation& loc)           noexcept
		{
			m_location = loc;
		}

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
		const Vertex::CEdgeList& CVertex::edgeList()                         const noexcept
		{
			return (m_edgeList);
		}
		void             CVertex::edgeList(const CEdgeList& edgeList)      noexcept
		{
			m_edgeList = edgeList;
		}
		void             CVertex::addEdge(const CEdge& edge)              noexcept
		{
			m_edgeList.push_back(edge);
		}
		const Vertex::CEdge& CVertex::getEdge(const int index)          const noexcept
		{
			return (m_edgeList[index]);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
	}
}