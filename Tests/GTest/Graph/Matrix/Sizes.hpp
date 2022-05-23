#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "../../GTest.hpp"
#include "../../CSmart/Int.hpp"
#include "Masters/Graph/Matrix/Sizes.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace Masters;
using namespace Masters::Graph::Matrix;
using namespace Masters::Graph::Matrix::Sizes;

///////////////////////////////////////////////////////////////////////////////////////////////////////

MACRO_GTEST_CLASS_INT(GraphMatrix, CHeight)
MACRO_GTEST_CLASS_INT(GraphMatrix, CLength)

///////////////////////////////////////////////////////////////////////////////////////////////////////

#define MACRO_GTEST_SIZE_AUTO(MacroGTest) \
{										 \
	MacroGTest(   0,   0);				 \
	MacroGTest(   0,   1);				 \
	MacroGTest(   1,   0);				 \
	MacroGTest( 126, 644);     		     \
	MacroGTest( 592,   0);				 \
	MacroGTest( 650,  51);				 \
	MacroGTest(  51, 550);				 \
	MacroGTest(   5,   5);				 \
	MacroGTest(5655, 955);				 \
}

#define MACRO_GM_SIZE_NOINIT_EQ(HtValue, LtValue)   \
{														\
	{													\
		CSizes obj;									    \
		obj.height(HtValue);							\
		obj.length(LtValue);							\
														\
		ASSERT_EQ(obj.height(), HtValue);			    \
		ASSERT_EQ(obj.length(), LtValue);			    \
														\
		ASSERT_TRUE(obj.height() == HtValue);		    \
		ASSERT_TRUE(obj.length() == LtValue);		    \
	}													\
	{												    \
		CSizes obj(Sizes::CHeight(HtValue),	            \
					  Sizes::CLength(LtValue));	        \
													    \
		ASSERT_EQ(obj.height(), HtValue);			    \
		ASSERT_EQ(obj.length(), LtValue);			    \
														\
		ASSERT_TRUE(obj.height() == HtValue);		    \
		ASSERT_TRUE(obj.length() == LtValue);		    \
	}													\
}

#define MACRO_GM_SIZE_INIT_EQ(HtValue, LtValue)	        \
{														\
	{													\
		CSizes obj(Sizes::CHeight(HtValue),				\
			Sizes::CLength(LtValue));				    \
														\
		ASSERT_EQ(obj.height(), HtValue);			    \
		ASSERT_EQ(obj.length(), LtValue);		    	\
														\
		ASSERT_TRUE(obj.height() == HtValue);	    	\
		ASSERT_TRUE(obj.length() == LtValue);	    	\
	}													\
	{												    \
		CSizes obj(Sizes::CHeight(HtValue),            	\
					  Sizes::CLength(LtValue));        	\
													    \
		ASSERT_EQ(obj.height(), HtValue);		    	\
		ASSERT_EQ(obj.length(), LtValue);		    	\
														\
		ASSERT_TRUE(obj.height() == HtValue);	    	\
		ASSERT_TRUE(obj.length() == LtValue);		    \
	}													\
}

#define MACRO_GM_SIZE_NEG_INIT_EQ(HtValue, LtValue)	    \
{														\
	{													\
		bool bExcept = false;						    \
		try												\
		{												\
			CSizes obj(Sizes::CHeight(HtValue),         \
				       Sizes::CLength(LtValue));	    \
		}												\
		catch(const std::string&)					    \
		{											    \
			bExcept = true;							    \
		}												\
		ASSERT_TRUE(bExcept);							\
	}													\
}

#define MACRO_GTEST_SIZE_NEG                    \
{                                               \
	MACRO_GM_SIZE_NEG_INIT_EQ(   0,   -1);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(  -1,    1);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(  -1,    0);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(-126,  644);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(-592,    0);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(-650,   51);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(  51, -550);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(   5,   -5);	    \
	MACRO_GM_SIZE_NEG_INIT_EQ(5655, -955);	    \
}

#define MACRO_GM_SIZE_GET_SET(HtValue, LtValue)         \
{													    \
	{												    \
		CSizes obj;								        \
		obj.height(HtValue);						    \
		obj.length(LtValue);						    \
													    \
		ASSERT_EQ(obj.height(), HtValue);		        \
		ASSERT_EQ(obj.length(), LtValue);		        \
													    \
		ASSERT_TRUE(obj.height() == HtValue);	        \
		ASSERT_TRUE(obj.length() == LtValue);	        \
	}												    \
	{												    \
		CSizes obj;								        \
		obj.height(std::move(CHeight(HtValue)));        \
		obj.length(std::move(CLength(LtValue)));        \
													    \
		ASSERT_EQ(obj.height(), HtValue);		        \
		ASSERT_EQ(obj.length(), LtValue);		        \
													    \
		ASSERT_TRUE(obj.height() == HtValue);	        \
		ASSERT_TRUE(obj.length() == LtValue);	        \
	}												    \
}

#define MACRO_GM_SIZE_OPERATORS(HtValue, LtValue)               \
{																\
	const CSizes obj         (Sizes::CHeight(HtValue),			\
							  Sizes::CLength(LtValue));			\
																\
	EXPECT_TRUE(obj == CSizes(Sizes::CHeight(HtValue),          \
							  Sizes::CLength(LtValue)));		\
																\
	EXPECT_TRUE(obj != CSizes(Sizes::CHeight(HtValue),			\
							  Sizes::CLength(LtValue + 1)));    \
	EXPECT_TRUE(obj != CSizes(Sizes::CHeight(HtValue),			\
							  Sizes::CLength(LtValue + 21)));   \
	EXPECT_TRUE(obj != CSizes(Sizes::CHeight(HtValue + 1),      \
							  Sizes::CLength(LtValue)));        \
	EXPECT_TRUE(obj != CSizes(Sizes::CHeight(HtValue + 1),      \
							  Sizes::CLength(LtValue + 1)));    \
	EXPECT_TRUE(obj != CSizes(Sizes::CHeight(HtValue + 656),    \
							  Sizes::CLength(LtValue + 4545))); \
	EXPECT_TRUE(obj != CSizes(Sizes::CHeight(HtValue + 1655),   \
							  Sizes::CLength(LtValue + 959)));  \
}

#define MACRO_GM_SIZE_VALID(HtValue, LtValue)   \
{                                               \
	CSizes obj(Sizes::CHeight(HtValue + 1655),  \
			   Sizes::CLength(LtValue + 959));  \
	if (HtValue < 0 || LtValue < 0)             \
	{                                           \
		ASSERT_FALSE(Sizes::isValid(obj));	    \
	}										    \
	else									    \
	{										    \
		ASSERT_TRUE(Sizes::isValid(obj));	    \
	}										    \
}

	//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixSizes, CtorEmpty)
{
	constexpr int defValue = 0;

	// Empty
	CSizes obj;

	ASSERT_EQ(obj.height(), defValue);
	ASSERT_EQ(obj.length(), defValue);

	ASSERT_TRUE(obj.height() == defValue);
	ASSERT_TRUE(obj.length() == defValue);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixSizes, Ctor)
{
	MACRO_GTEST_SIZE_AUTO(MACRO_GM_SIZE_NOINIT_EQ);
	MACRO_GTEST_SIZE_AUTO(MACRO_GM_SIZE_INIT_EQ);
	MACRO_GTEST_SIZE_NEG;
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixSizes, GeterSeter)
{
	MACRO_GTEST_SIZE_AUTO(MACRO_GM_SIZE_GET_SET);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixSizes, Operators)
{
	MACRO_GTEST_SIZE_AUTO(MACRO_GM_SIZE_OPERATORS);
}

//////////////////////////////////////////////////////////////////////////////////////////

TEST(GraphMatrixSizes, Valid)
{
	MACRO_GTEST_SIZE_AUTO(MACRO_GM_SIZE_VALID);
}

