
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_VERTEX_HPP
#define MT_MATRIX_VERTEX_HPP

//////////////////////////////////////////////////////////////////////////

#include "Location.hpp"
#include "Neighborhood.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_VERTEX_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Matrix
	{
		namespace Vertex
		{
			using Index    = int; /*notest*/
			using Distance = int; /*notest*/

			class MT_MATRIX_VERTEX_EXPORT CProperty /*notest*/
			{

			public: // get, set
				const Distance distance()                  const noexcept { return (m_distance); }
				void           distance(const Distance distance) noexcept { m_distance = distance; }

			private:
				Distance m_distance;
			};
		}

		class MT_MATRIX_VERTEX_EXPORT CVertex /*notest*/
		{
		public: // typedefs
			using UUniqueID      = Matrix::Vertex::Index;
			using CProperty      = Matrix::Vertex::CProperty;
			using CNeighborhood  = Matrix::CNeighborhood;
			using CNeighborhoods = Matrix::CNeighborhoods;
			using CLocation      = Matrix::CLocation;

		public: // ctor/dector

			CVertex();
			CVertex(/*const CLocation& loc, */const CProperty& prop, const CNeighborhoods& neighborhoods);
			CVertex(/*CLocation&& loc,*/ CProperty&& prop, CNeighborhoods&& neighborhoods);

			virtual ~CVertex();

		public:  // get set

			// location
			//const CLocation& location()                          const noexcept;
			//void             location(const CLocation& loc)            noexcept;

			// property
			const CProperty& property()                          const noexcept;
			void             property(const CProperty& loc)            noexcept;

			// edge list
			const CNeighborhoods&    edgeList()                         const noexcept;
			const CNeighborhood&     getEdge(const int index)           const noexcept;
			
			void neighborhoods(const CNeighborhoods& edgeList)  noexcept;
			void addNeighborhood(const CNeighborhood& edgeList) noexcept;

		private: // member vars
			//CLocation m_location;
			CProperty      m_property;
			CNeighborhoods m_neighborhoods;
		};

		using CVertexList      = std::vector<CVertex>;

	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_VERTEX_HPP

//////////////////////////////////////////////////////////////////////////
