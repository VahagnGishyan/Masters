
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_CREATOR_HPP
#define MT_MATRIX_CREATOR_HPP

//////////////////////////////////////////////////////////////////////////

#include "Sizes.hpp"
#include "Vertex.hpp"
#include "Type.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_CREATOR_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Creator
			{
				
			}

			class MT_MATRIX_CREATOR_EXPORT CCreator
			{
				CCreator(const CSize size, const SType& type, const CVertexList& list);
				virtual ~CCreator();

			public: // get set
				const CSize&       size()     const noexcept;
				const SType&       type()     const noexcept;
				const CVertexList& vertices() const noexcept;

				void               size    (const CSize&        size) noexcept;
				void               type    (const SType&        type) noexcept;
				void               vertices(const CVertexList&  list) noexcept;
													   
				void               size    (      CSize&&       size) noexcept;
				void               type    (      SType&&       type) noexcept;
				void               vertices(      CVertexList&& list) noexcept;

			private:
				CSize       m_size;
				SType       m_type;
				CVertexList m_vertices;
			};
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_CREATOR_HPP

//////////////////////////////////////////////////////////////////////////
