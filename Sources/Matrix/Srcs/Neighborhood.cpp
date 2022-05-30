
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Neighborhood.hpp"

namespace Masters
{
	namespace Matrix
	{
		CNeighborhood::CNeighborhood() : m_node(), m_weight() {}
		CNeighborhood::CNeighborhood(const CLocation& node, const CWeight& weight) : m_node(node), m_weight(weight) {}
		CNeighborhood::CNeighborhood(CLocation&& node, CWeight&& weight) : m_node(node), m_weight(weight) {}
		CNeighborhood::~CNeighborhood() {}

		////////////////////////////////////////////////////////////////////////////////////////////////////

		const CLocation             CNeighborhood::node()   const noexcept { return (m_node); }
		const Neighborhood::CWeight CNeighborhood::weight() const noexcept { return (m_weight); }

		void CNeighborhood::node(const CLocation& node) noexcept { m_node = node; }
		void CNeighborhood::node(CLocation&& node)      noexcept { m_node = node; }

		void CNeighborhood::weight(const Neighborhood::CWeight& edgeWeight) noexcept { m_weight = edgeWeight; }
		void CNeighborhood::weight(Neighborhood::CWeight&& edgeWeight) noexcept { m_weight = edgeWeight; }

		////////////////////////////////////////////////////////////////////////////////////////////////////

		namespace Neighborhood
		{
			MacroClassIntImp(CWeight);

			/*notest*/
			bool valid(const CNeighborhood& neighborhood) noexcept { return (Location::valid(neighborhood.node())); }
		}
	}
}
