
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_EDGE_HPP
#define MT_MATRIX_EDGE_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"
#include "Masters/CSmart/FundamentalTypes/Int.hpp"
#include "Location.hpp"
#include "Neighborhood.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_EDGE_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Matrix
	{
		/*temp, notest*/
		/*temp, check is root neighborhood node*/
		class /*MT_MATRIX_EDGE_EXPORT*/ CEdge : public CNeighborhood
		{
		public: // ctor/dector
			CEdge(const CLocation& m_root, const CLocation& node, const CWeight& weight);
			CEdge(CLocation&& m_root, CLocation&& node, CWeight&& weight);

			CEdge(const CLocation& m_root, const CEdge& edge);
			CEdge(CLocation&& m_root, CEdge&& edge);

			virtual ~CEdge();

		public: // get set
			const CLocation root() const noexcept;

			void root(const CLocation& nodeIndex)  noexcept;
			void root(CLocation&& nodeIndex)  noexcept;

		private: // member vars
			CLocation m_root;   // from
		};

		using CNeighborhoods = std::vector<CNeighborhood>;
		using CEdgeList      = std::vector<CEdge>;

		namespace Edge
		{
			bool MT_MATRIX_EDGE_EXPORT valid(const CEdge& edge) noexcept;
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_EDGE_HPP

//////////////////////////////////////////////////////////////////////////
