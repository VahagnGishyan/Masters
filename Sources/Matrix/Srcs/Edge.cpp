
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Edge.hpp"

namespace Masters
{
	namespace Matrix
	{
		CEdge::CEdge(const CLocation& root, const CLocation& node, const CWeight& weight)
			: CNeighborhood(node, weight), m_root(root) {}
		CEdge::CEdge(CLocation&& root, CLocation&& node, CWeight&& weight)
			: CNeighborhood(node, weight), m_root(root) {}
		CEdge::CEdge(const CLocation& root, const CEdge& edge)
			: CNeighborhood(edge), m_root(root) {}
		CEdge::CEdge(CLocation&& root, CEdge&& edge)
			: CNeighborhood(edge), m_root(root) {}

		CEdge::~CEdge() {}

		////////////////////////////////////////////////////////////////////////////////////////////////////

		const CLocation     CEdge::root()        const noexcept { return (m_root); }

		void CEdge::root(const CLocation& root) noexcept { m_root = root; }
		void CEdge::root(CLocation&& root)      noexcept { m_root = root; }

		////////////////////////////////////////////////////////////////////////////////////////////////////

		namespace Edge
		{
			/*notest*/
			bool valid(const CEdge& edge) noexcept { return (Location::valid(edge.node())); }
		}
	}
}