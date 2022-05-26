
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
				CEdge(const CLocation& node,  const CWeight&  weight);
				CEdge(      CLocation&& node,       CWeight&& weight);
				virtual ~CEdge();

			public: // get set
				const CLocation node() const noexcept;
				const CWeight   weight() const noexcept;

				void node  (const CLocation&  nodeIndex)  noexcept;
				void node  (      CLocation&& nodeIndex)  noexcept;
				void weight(const CWeight&    edgeWeight) noexcept;
				void weight(      CWeight&&   edgeWeight) noexcept;

			private: // member vars
				//CLocation	m_root; // from
				CWeight   m_weight; // ????
				CLocation m_node;   // to
			};

			class CFullEdgeRef
			{

			};

			class CFullEdge 
			{
			private: // typedefs
				using CWeight = Edge::CWeight;

			public: // ctor/dector
				CFullEdge(const CLocation&  m_root, const CLocation&  node, const CWeight&  weight);
				CFullEdge(      CLocation&& m_root,       CLocation&& node,       CWeight&& weight);
				
				CFullEdge(const CLocation&  m_root, const CEdge&  edge);
				CFullEdge(      CLocation&& m_root,       CEdge&& edge);
				
				virtual ~CFullEdge();

			public: // get set
				const CLocation root() const noexcept;
				const CLocation node() const noexcept;
				const CWeight   weight() const noexcept;

				void root  (const CLocation&  nodeIndex)  noexcept;
				void root  (      CLocation&& nodeIndex)  noexcept;
				void node  (const CLocation&  nodeIndex)  noexcept;
				void node  (      CLocation&& nodeIndex)  noexcept;
				void weight(const CWeight&    edgeWeight) noexcept;
				void weight(      CWeight&&   edgeWeight) noexcept;

			private: // member vars
				CLocation m_root;   // from
				CEdge     m_edge;
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
