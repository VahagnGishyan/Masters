#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "../../GTest.hpp"
#include "../../CSmart/Int.hpp"
#include "Masters/Graph/Matrix/Vertex/Edge.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace Masters;
using namespace Masters::Graph::Matrix;
using namespace Masters::Graph::Matrix::Vertex;
using namespace Masters::Graph::Matrix::Vertex::Edge;

///////////////////////////////////////////////////////////////////////////////////////////////////////

// temp,
// TODO :: test CVertexIndex, CEdgeWeight ...

MACRO_GTEST_CLASS_INT(GraphMatrix, CWeight)

#define MACRO_GM_FULLEDGE_NOINIT(Root, Weight, Node)    \
{														\
	{													\
		CFullEdge obj;									\
		obj.root(Root);								    \
		obj.weight(Weight);								\
		obj.node(Node);									\
														\
		ASSERT_EQ(obj.root(), Root);				    \
		ASSERT_EQ(obj.weight(), Weight);				\
		ASSERT_EQ(obj.node(), Node);					\
														\
		ASSERT_TRUE(obj.root() == Root);			    \
		ASSERT_TRUE(obj.weight() == Weight);			\
		ASSERT_TRUE(obj.node() == Node);                \
	}													\
}

//{												    \
//CEdge obj(Edge::CVertexIndex(RootID), \
//	Edge::CEdgeWeight(Weight), \
//	Edge::CVertexIndex(NoodID));			\
//	\
//	ASSERT_EQ(obj.rootID(), RootID);			    \
//	ASSERT_EQ(obj.weight(), Weight);			    \
//	ASSERT_EQ(obj.nodeID(), NoodID);			    \
//	\
//	ASSERT_TRUE(obj.rootID() == RootID);		    \
//	ASSERT_TRUE(obj.weight() == Weight);		    \
//	ASSERT_TRUE(obj.nodeID() == NoodID);		    \
//}													\

#define MACRO_GTEST_MAKE_LOC(Ord, abs) CLocation(Location::COrdinate((Ord)), Location::CAbscissa((abs)))

namespace Masters
{
	namespace GTest
	{
		namespace Graph
		{
			namespace Matrix
			{
				namespace Edge
				{
					struct CArgument final
					{
					public: 
						CArgument() {}
						CArgument(const CLocation node, const CWeight weight)
							: m_node(node), m_weight(weight) {}
					public:
						void          weight(const CWeight& weight) { m_weight = weight; }
						const CWeight weight() { return (m_weight); }

						void            node(const CLocation& node) { m_node = node; }
						const CLocation node() { return (m_node); }

					private:
						CWeight   m_weight;
						CLocation m_node;
					};

					using CArgumentList = std::vector<CArgument>;

					CArgumentList create()
					{
						return (GTest::Graph::Matrix::Edge::CArgumentList(
						{ 
						{ MACRO_GTEST_MAKE_LOC(  2,  1),    0 }, 
						{ MACRO_GTEST_MAKE_LOC( -1,  4),    0 }, 
						{ MACRO_GTEST_MAKE_LOC(644,  4),    1 }, 
						{ MACRO_GTEST_MAKE_LOC(  0,  4),    0 }, 
						{ MACRO_GTEST_MAKE_LOC( -1, -1),  145 }, 
						{ MACRO_GTEST_MAKE_LOC(  0, -5), -145 }, 
						{ MACRO_GTEST_MAKE_LOC( -5, -5),   15 }, 
						{ MACRO_GTEST_MAKE_LOC(  5, -5),  -95 }, 
						{ MACRO_GTEST_MAKE_LOC(  0,  0),    0 },
						{ MACRO_GTEST_MAKE_LOC(  1,  0),    0 },
						{ MACRO_GTEST_MAKE_LOC( -1,  1),    0 },
						{ MACRO_GTEST_MAKE_LOC(  0,  4),   -1 },
						{ MACRO_GTEST_MAKE_LOC( -1, -1),   -1 },
						{ MACRO_GTEST_MAKE_LOC(  2,  1),   -1 },
						{ MACRO_GTEST_MAKE_LOC( -1,  4),    2 },
						{ MACRO_GTEST_MAKE_LOC(644,  4), -126 },
						{ MACRO_GTEST_MAKE_LOC(  0,  4),    2 },
						{ MACRO_GTEST_MAKE_LOC( -1, -1),    0 },
						{ MACRO_GTEST_MAKE_LOC(  0, -5),   -1 },
						{ MACRO_GTEST_MAKE_LOC( -5, -5),   -5 },
						{ MACRO_GTEST_MAKE_LOC(  5, -5),    5 },
						{ MACRO_GTEST_MAKE_LOC(955, 47), 5655 },
						{ MACRO_GTEST_MAKE_LOC(-95, -8), -655 }
						}));
					}
				}
			}
		}
	}
}

TEST(GraphMatrixEdge, Ctor)
{
	using namespace GTest;
	using namespace GTest::Graph;
	using namespace GTest::Graph::Matrix;
	using namespace GTest::Graph::Matrix::Edge;

	CArgumentList list = GTest::Graph::Matrix::Edge::create();
	const int size = list.size();
	ASSERT_TRUE(size != 0);
	
	for (int index = 0; index < size; ++index)
	{
		{
			// no init
			CEdge obj;
			obj.weight(list[index].weight());
			obj.node(list[index].node());

			EXPECT_EQ(obj.weight(), list[index].weight());
			EXPECT_EQ(obj.node(), list[index].node());

			EXPECT_TRUE(obj.weight() == list[index].weight());
			EXPECT_TRUE(obj.node() == list[index].node());
		}

		{
			// init
			CEdge obj(list[index].node(), list[index].weight());;

			EXPECT_EQ(obj.weight(), list[index].weight());
			EXPECT_EQ(obj.node(),   list[index].node());

			EXPECT_TRUE(obj.weight() == list[index].weight());
			EXPECT_TRUE(obj.node()   == list[index].node());
		}

		{
			// init move
			CEdge obj(CLocation(list[index].node()), CWeight(list[index].weight()));;

			EXPECT_EQ(obj.weight(), list[index].weight());
			EXPECT_EQ(obj.node(),   list[index].node());

			EXPECT_TRUE(obj.weight() == list[index].weight());
			EXPECT_TRUE(obj.node()   == list[index].node());
		}
	}
}

TEST(GraphMatrixEdge, GetSet)
{
	using namespace GTest;
	using namespace GTest::Graph;
	using namespace GTest::Graph::Matrix;
	using namespace GTest::Graph::Matrix::Edge;

	CArgumentList list = GTest::Graph::Matrix::Edge::create();
	const int size = list.size();
	ASSERT_TRUE(size != 0);

	for (int index = 0; index < size; ++index)
	{
		{
			// no init
			CEdge obj;
			obj.weight(list[index].weight()); // set
			obj.node(list[index].node());     // set

			CWeight   weight(list[index].weight());
			CLocation node(list[index].node());

			EXPECT_EQ(obj.weight(), weight);
			EXPECT_EQ(obj.node(),   node);

			EXPECT_TRUE(obj.weight() == weight);
			EXPECT_TRUE(obj.node()   == node);
		}

		{
			// init
			CEdge obj(list[index].node(), list[index].weight());;

			CWeight   weight(list[index].weight());
			CLocation node(list[index].node());

			EXPECT_EQ(obj.weight(), weight);
			EXPECT_EQ(obj.node(), node);

			EXPECT_TRUE(obj.weight() == weight);
			EXPECT_TRUE(obj.node() == node);
		}

		{
			// init move
			CEdge obj(CLocation(list[index].node()), CWeight(list[index].weight()));;

			CWeight   weight(list[index].weight());
			CLocation node(list[index].node());

			EXPECT_EQ(obj.weight(), weight);
			EXPECT_EQ(obj.node(), node);

			EXPECT_TRUE(obj.weight() == weight);
			EXPECT_TRUE(obj.node() == node);
		}
	}
}