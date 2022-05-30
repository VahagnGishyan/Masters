
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_NEIGHBORHOOD_HPP
#define MT_MATRIX_NEIGHBORHOOD_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"
#include "Location.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_NEIGHBORHOOD_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Matrix
	{
		namespace Neighborhood
		{
			//MT_MATRIX_EDGE_EXPORT MacroClassInt(CVertexIndex);
			MT_MATRIX_NEIGHBORHOOD_EXPORT MacroClassInt(CWeight);

			class MT_MATRIX_NEIGHBORHOOD_EXPORT CCreator
			{

			};

			class MT_MATRIX_NEIGHBORHOOD_EXPORT CAutoCreator : public CCreator
			{

			};

			class MT_MATRIX_NEIGHBORHOOD_EXPORT CManualCreator : public CCreator
			{

			};
		}

		class MT_MATRIX_NEIGHBORHOOD_EXPORT CNeighborhood
		{
		protected: // typedefs
			using CWeight = Neighborhood::CWeight;

		public: // ctor/dector
			CNeighborhood();
			CNeighborhood(const CLocation& node, const CWeight& weight);
			CNeighborhood(CLocation&& node, CWeight&& weight);
			virtual ~CNeighborhood();

		public: // get set
			const CLocation node() const noexcept;
			const CWeight   weight() const noexcept;

			void node(const CLocation& nodeIndex)  noexcept;
			void node(CLocation&& nodeIndex)  noexcept;
			void weight(const CWeight& edgeWeight) noexcept;
			void weight(CWeight&& edgeWeight) noexcept;

		private: // member vars
			//CLocation	m_root; // from
			CWeight   m_weight; // ????
			CLocation m_node;   // to
		};

		/*temp*/
		using CNeighborhoods = std::vector<CNeighborhood>;

		namespace Neighborhood
		{
			enum class EStep
			{
				Right,
				Left,
				Up,
				Down,
				RightUp,
				RightDown,
				LeftUp,
				LeftDown,
			};
		}
	}
}
//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_NEIGHBORHOODS_HPP

//////////////////////////////////////////////////////////////////////////
