#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "../../GTest.hpp"
#include "../../CSmart/Int.hpp"
#include "Masters/Graph/Matrix/Location.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace Masters;
using namespace Masters::Graph::Matrix;
using namespace Masters::Graph::Matrix::Location;

///////////////////////////////////////////////////////////////////////////////////////////////////////

MACRO_GTEST_CLASS_INT(GraphMatrix, COrdinate)
MACRO_GTEST_CLASS_INT(GraphMatrix, CAbscissa)

#define MACRO_GTEST_LOC_AUTO(MacroGTest) \
{										 \
	MacroGTest(   0,   0);				 \
	MacroGTest(   0,   1);				 \
	MacroGTest(   1,   0);				 \
	MacroGTest(   0,  -1);				 \
	MacroGTest(  -1,   0);				 \
	MacroGTest(  -1,  -1);				 \
	MacroGTest(  -1,   2);				 \
	MacroGTest(   2,  -1);				 \
	MacroGTest(-126, 644);     		     \
	MacroGTest(   2,   0);				 \
	MacroGTest(   0,  -1);				 \
	MacroGTest(  -1,  -1);				 \
	MacroGTest(  -1,   0);				 \
	MacroGTest(  -5,  -5);				 \
	MacroGTest(   5,   5);				 \
	MacroGTest(5655, 955);				 \
	MacroGTest(-655, -95);				 \
}

#define MACRO_GM_LOCATION_NOINIT_EQ(OrdValue, AbsValue) \
{														\
	{													\
		CLocation obj;									\
		obj.ordinate(OrdValue);							\
		obj.abscissa(AbsValue);							\
														\
		ASSERT_EQ(obj.ordinate(), OrdValue);			\
		ASSERT_EQ(obj.abscissa(), AbsValue);			\
														\
		ASSERT_TRUE(obj.ordinate() == OrdValue);		\
		ASSERT_TRUE(obj.abscissa() == AbsValue);		\
	}													\
	{												    \
		CLocation obj(Location::COrdinate(OrdValue),	\
					  Location::CAbscissa(AbsValue));	\
													    \
		ASSERT_EQ(obj.ordinate(), OrdValue);			\
		ASSERT_EQ(obj.abscissa(), AbsValue);			\
														\
		ASSERT_TRUE(obj.ordinate() == OrdValue);		\
		ASSERT_TRUE(obj.abscissa() == AbsValue);		\
	}													\
}

#define MACRO_GM_LOCATION_INIT_EQ(OrdValue, AbsValue)	\
{														\
	{													\
		Location::COrdinate ord(OrdValue);              \
		Location::CAbscissa abs(AbsValue);              \
		CLocation obj(ord, abs);                        \
														\
		ASSERT_EQ(obj.ordinate(), OrdValue);			\
		ASSERT_EQ(obj.abscissa(), AbsValue);			\
														\
		ASSERT_TRUE(obj.ordinate() == OrdValue);		\
		ASSERT_TRUE(obj.abscissa() == AbsValue);		\
	}													\
	{												    \
		CLocation obj(Location::COrdinate(OrdValue),	\
					  Location::CAbscissa(AbsValue));	\
													    \
		ASSERT_EQ(obj.ordinate(), OrdValue);			\
		ASSERT_EQ(obj.abscissa(), AbsValue);			\
														\
		ASSERT_TRUE(obj.ordinate() == OrdValue);		\
		ASSERT_TRUE(obj.abscissa() == AbsValue);		\
	}													\
}


#define MACRO_GM_LOCATION_GET_SET(OrdValue, AbsValue) \
{													  \
	{												  \
		CLocation obj;                      \
		obj.ordinate(OrdValue);						  \
		obj.abscissa(AbsValue);						  \
													  \
		ASSERT_EQ(obj.ordinate(), OrdValue);		  \
		ASSERT_EQ(obj.abscissa(), AbsValue);		  \
													  \
		ASSERT_TRUE(obj.ordinate() == OrdValue);	  \
		ASSERT_TRUE(obj.abscissa() == AbsValue);	  \
	}												  \
	{												  \
		CLocation obj;								  \
		obj.ordinate(std::move(COrdinate(OrdValue))); \
		obj.abscissa(std::move(CAbscissa(AbsValue))); \
													  \
		ASSERT_EQ(obj.ordinate(), OrdValue);		  \
		ASSERT_EQ(obj.abscissa(), AbsValue);		  \
													  \
		ASSERT_TRUE(obj.ordinate() == OrdValue);	  \
		ASSERT_TRUE(obj.abscissa() == AbsValue);	  \
	}												  \
}

#define MACRO_GM_LOCATION_OPERATORS(OrdValue, AbsValue)               \
{			                                                          \
	Location::COrdinate ord(OrdValue);                                \
	Location::CAbscissa abs(AbsValue);                                \
	CLocation obj(ord, abs);                                          \
	EXPECT_TRUE(obj == CLocation(ord, abs));        				  \
																	  \
	EXPECT_TRUE(obj != CLocation(OrdValue,        AbsValue +    1));  \
	EXPECT_TRUE(obj != CLocation(OrdValue,        AbsValue -    1));  \
	EXPECT_TRUE(obj != CLocation(OrdValue + 1,    AbsValue       ));  \
	EXPECT_TRUE(obj != CLocation(OrdValue + 1,    AbsValue -    1));  \
	EXPECT_TRUE(obj != CLocation(OrdValue + 1,    AbsValue +    1));  \
	EXPECT_TRUE(obj != CLocation(OrdValue - 1,    AbsValue -    1));  \
	EXPECT_TRUE(obj != CLocation(OrdValue - 949,  AbsValue +   565)); \
	EXPECT_TRUE(obj != CLocation(OrdValue + 65,   AbsValue - 65651)); \
	EXPECT_TRUE(obj != CLocation(OrdValue - 5656, AbsValue -  1565)); \
}

#define MACRO_GM_LOCATION_VALID(OrdValue, AbsValue) \
{													\
	Location::COrdinate ord(OrdValue);              \
	Location::CAbscissa abs(AbsValue);              \
	CLocation obj(ord, abs);                        \
		                                            \
	if (OrdValue < 0 || AbsValue < 0)				\
	{												\
		ASSERT_FALSE(Location::isValid(obj));		\
	}												\
	else											\
	{												\
		ASSERT_TRUE(Location::isValid(obj));		\
	}												\
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixLocation, CtorEmpty)
{
	constexpr int defValue = 0;

	// Empty
	CLocation obj;

	ASSERT_EQ(obj.ordinate(), defValue);
	ASSERT_EQ(obj.abscissa(), defValue);

	ASSERT_TRUE(obj.ordinate() == defValue);
	ASSERT_TRUE(obj.abscissa() == defValue);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixLocation, Ctor)
{
	MACRO_GTEST_LOC_AUTO(MACRO_GM_LOCATION_NOINIT_EQ);
	//MACRO_GTEST_LOC_AUTO(MACRO_GM_LOCATION_INIT_EQ);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixLocation, GeterSeter)
{
	 //MACRO_GTEST_LOC_AUTO(MACRO_GM_LOCATION_GET_SET);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixLocation, Operators)
{
	//MACRO_GTEST_LOC_AUTO(MACRO_GM_LOCATION_OPERATORS);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixLocation, Valid)
{
	//MACRO_GTEST_LOC_AUTO(MACRO_GM_LOCATION_VALID);
}
