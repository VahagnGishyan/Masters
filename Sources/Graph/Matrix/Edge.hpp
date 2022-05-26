
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_CEDGE_HPP
#define MT_MATRIX_CEDGE_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"
#include "Masters/CSmart/FundamentalTypes/Int.hpp"
#include "Location.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_CEDGE_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Edge
			{
				//MT_MATRIX_CEDGE_EXPORT MacroClassInt(CVertexIndex);
				MT_MATRIX_CEDGE_EXPORT MacroClassInt(CWeight);
			}

			class CEdge
			{
			private: // typedefs
				using CWeight  = Edge::CWeight;

			public: // ctor/dector
				CEdge(const CLocation node, const CWeight weight);
				virtual ~CEdge();

			public: // get set
				const CLocation node() const noexcept;
				const CWeight   weight() const noexcept;

				void node  (const CLocation nodeIndex)  noexcept;
				void weight(const CWeight   edgeWeight) noexcept;

			private: // member vars
				//CLocation	m_root; // from
				CWeight   m_weight; // ????
				CLocation m_node;   // to
			};

			using CEdgeList = std::vector<CEdge>;

			namespace Edge
			{
				bool isValid(const CEdge& edge) noexcept;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_CEDGE_HPP

//////////////////////////////////////////////////////////////////////////
