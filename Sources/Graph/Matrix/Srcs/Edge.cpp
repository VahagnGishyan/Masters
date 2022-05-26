
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Edge.hpp"

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			CEdge:: CEdge(const CLocation&  node, const CWeight&  weight) : m_node(node), m_weight(weight) {}
			CEdge:: CEdge(      CLocation&& node,       CWeight&& weight) : m_node(node), m_weight(weight) {}
			CEdge::~CEdge() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////

			CFullEdge::CFullEdge(const CLocation&  root, const CLocation&  node, const CWeight&  weight) 
				: m_root(root), m_edge(node, weight) {}
			CFullEdge::CFullEdge(      CLocation&& root,       CLocation&& node,       CWeight&& weight)
				: m_root(root), m_edge(node, weight) {}
			CFullEdge::CFullEdge(const CLocation&  root, const CEdge&  edge) 
				: m_root(root), m_edge(edge)         {}
			CFullEdge::CFullEdge(      CLocation&& root,       CEdge&& edge)
				: m_root(root), m_edge(edge) {}

			CFullEdge::~CFullEdge() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			
			const CLocation     CEdge::node  () const noexcept { return (m_node);   }
			const Edge::CWeight CEdge::weight() const noexcept { return (m_weight); }

			void CEdge::node  (const CLocation&       node)       noexcept { m_node = node; }
			void CEdge::node  (      CLocation&&      node)       noexcept { m_node = node; }
			void CEdge::weight(const CEdge::CWeight&  edgeWeight) noexcept { m_weight = edgeWeight; }
			void CEdge::weight(      CEdge::CWeight&& edgeWeight) noexcept { m_weight = edgeWeight; }

			////////////////////////////////////////////////////////////////////////////////////////////////////

			const CLocation     CFullEdge::root()                   const noexcept { return (m_root); }
			const CLocation     CFullEdge::node()                   const noexcept { return (m_edge.node()); }
			const Edge::CWeight CFullEdge::weight()                 const noexcept { return (m_edge.weight()); }

			void CFullEdge::root  (const CLocation&           root)       noexcept { m_root = root; }
			void CFullEdge::root  (      CLocation&&          root)       noexcept { m_root = root; }
			void CFullEdge::node  (const CLocation&           node)       noexcept { m_edge.node(node); }
			void CFullEdge::node  (      CLocation&&          node)       noexcept { m_edge.node(node); }
			void CFullEdge::weight(const CFullEdge::CWeight&  edgeWeight) noexcept { m_edge.weight(edgeWeight); }
			void CFullEdge::weight(      CFullEdge::CWeight&& edgeWeight) noexcept { m_edge.weight(edgeWeight); }

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
