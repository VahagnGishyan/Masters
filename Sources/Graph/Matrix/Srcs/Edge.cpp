
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Edge.hpp"

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			CEdge:: CEdge(const CLocation node, const CWeight weight) : m_node(node), m_weight(weight) {}
			CEdge::~CEdge() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			
			const CLocation     CEdge::node  () const noexcept { return (m_node);   }
			const Edge::CWeight CEdge::weight() const noexcept { return (m_weight); }

			void CEdge::node  (const CLocation node)             noexcept { m_node = node; }
			void CEdge::weight(const CEdge::CWeight  edgeWeight) noexcept { m_weight = edgeWeight; }

			////////////////////////////////////////////////////////////////////////////////////////////////////

			namespace Edge
			{
				MacroClassIntImp(CWeight);

				bool isValid(const CEdge& edge) noexcept { return (Location::isValid(edge.node())); }
			}
			
			////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
}
