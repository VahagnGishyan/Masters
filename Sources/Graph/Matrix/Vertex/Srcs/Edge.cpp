
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Vertex/Edge.hpp"

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Vertex
			{
				CEdge::CEdge() : m_node(), m_weight() {}
				CEdge::CEdge(const CLocation& node, const CWeight& weight) : m_node(node), m_weight(weight) {}
				CEdge::CEdge(CLocation&& node, CWeight&& weight) : m_node(node), m_weight(weight) {}
				CEdge::~CEdge() {}

				////////////////////////////////////////////////////////////////////////////////////////////////////

				CFullEdge::CFullEdge(const CLocation& root, const CLocation& node, const CWeight& weight)
					: CEdge(node, weight), m_root(root) {}
				CFullEdge::CFullEdge(CLocation&& root, CLocation&& node, CWeight&& weight)
					: CEdge(node, weight), m_root(root) {}
				CFullEdge::CFullEdge(const CLocation& root, const CEdge& edge)
					: CEdge(edge), m_root(root) {}
				CFullEdge::CFullEdge(CLocation&& root, CEdge&& edge)
					: CEdge(edge), m_root(root) {}

				CFullEdge::~CFullEdge() {}

				////////////////////////////////////////////////////////////////////////////////////////////////////

				const CLocation     CEdge::node() const noexcept { return (m_node); }
				const Edge::CWeight CEdge::weight() const noexcept { return (m_weight); }

				void CEdge::node(const CLocation& node)       noexcept { m_node = node; }
				void CEdge::node(CLocation&& node)       noexcept { m_node = node; }
				void CEdge::weight(const CEdge::CWeight& edgeWeight) noexcept { m_weight = edgeWeight; }
				void CEdge::weight(CEdge::CWeight&& edgeWeight) noexcept { m_weight = edgeWeight; }

				////////////////////////////////////////////////////////////////////////////////////////////////////

				const CLocation     CFullEdge::root()                   const noexcept { return (m_root); }

				void CFullEdge::root(const CLocation& root)       noexcept { m_root = root; }
				void CFullEdge::root(CLocation&& root)       noexcept { m_root = root; }

				////////////////////////////////////////////////////////////////////////////////////////////////////

				namespace Edge
				{
					MacroClassIntImp(CWeight);

					/*notest*/
					bool isValid(const CEdge& edge) noexcept { return (Location::isValid(edge.node())); }
				}
			}
		}
	}
}
