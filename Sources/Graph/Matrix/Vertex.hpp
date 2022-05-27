
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_CVERTEX_HPP
#define MT_MATRIX_CVERTEX_HPP

//////////////////////////////////////////////////////////////////////////

#include "Vertex\Location.hpp"
#include "Vertex\Edge.hpp"
//#include "CNManager.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_CVERTEX_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Vertex
			{
				using Index    = int; /*notest*/
				using Distance = int; /*notest*/

				class MT_MATRIX_CVERTEX_EXPORT CProperty /*notest*/
				{

				public: // get, set
					const Distance distance()                  const noexcept { return (m_distance);   }
					void           distance(const Distance distance) noexcept { m_distance = distance; }

				private:
					Distance m_distance;
				};
			}

			class MT_MATRIX_CVERTEX_EXPORT CVertex /*notest*/
			{ 
			public: // typedefs
				using UUniqueID = Graph::Matrix::Vertex::Index;
				using CProperty = Graph::Matrix::Vertex::CProperty;
				using CEdge     = Graph::Matrix::Vertex::CEdge;
				using CEdgeList = Graph::Matrix::Vertex::CEdgeList;
				using CLocation = Graph::Matrix::Vertex::CLocation;

			public: // ctor/dector

				CVertex();
				CVertex(const CLocation&  loc, const CProperty&  prop, const CEdgeList&  edges);
				CVertex(      CLocation&& loc,       CProperty&& prop,       CEdgeList&& edges);

				virtual ~CVertex();

			public:  // get set

				// location
				const CLocation& location   ()                          const noexcept;
				void             location   (const CLocation& loc)            noexcept;

				// property
				const CProperty& property   ()                          const noexcept;
				void             property   (const CProperty& loc)            noexcept;

				// edge list
				const CEdgeList& edgeList   ()                          const noexcept;
				void             edgeList   (const CEdgeList& edgeList)       noexcept;
				void             addEdge    (const CEdge& edgeList)           noexcept;
				const CEdge&     getEdge    (const int index)           const noexcept;

			private: // member vars
				CLocation m_location;
				CProperty m_property;
				CEdgeList m_edgeList;
			};

			using CVertexList = std::vector<CVertex>;
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_CVERTEX_HPP

//////////////////////////////////////////////////////////////////////////
