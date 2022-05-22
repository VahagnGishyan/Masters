#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "../GTest.hpp"
#include "Masters/CSmart/FundamentalTypes/Int.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace Masters;
using namespace Masters::CSmart;
using namespace Masters::CSmart::FundamentalTypes;

///////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(CSmartCInt, ClassCInt)
{
	{ CInt obj; EXPECT_EQ(obj.value(), 0); }

	{ constexpr int  value =  0;  CInt obj(value); EXPECT_EQ(obj.value(), value); }
	{ constexpr int  value =  1;  CInt obj(value); EXPECT_EQ(obj.value(), value); }
	{ constexpr int  value =  2;  CInt obj(value); EXPECT_EQ(obj.value(), value); }
	{ constexpr int  value = -1;  CInt obj(value); EXPECT_EQ(obj.value(), value); }
	{ constexpr int  value = -2;  CInt obj(value); EXPECT_EQ(obj.value(), value); }

	
	{ const     CInt value =  0;  CInt obj(value); EXPECT_TRUE(obj.value() == value.value()); }
	{ const     CInt value =  1;  CInt obj(value); EXPECT_TRUE(obj.value() == value.value()); }
	{ const     CInt value =  2;  CInt obj(value); EXPECT_TRUE(obj.value() == value.value()); }
	{ const     CInt value = -1;  CInt obj(value); EXPECT_TRUE(obj.value() == value.value()); }
	{ const     CInt value = -2;  CInt obj(value); EXPECT_TRUE(obj.value() == value.value()); }

	{ constexpr int value  =  0;  CInt obj(std::move(CInt(value))); EXPECT_EQ(obj.value(), value); }
	{ constexpr int value  =  1;  CInt obj(std::move(CInt(value))); EXPECT_EQ(obj.value(), value); }
	{ constexpr int value  =  2;  CInt obj(std::move(CInt(value))); EXPECT_EQ(obj.value(), value); }
	{ constexpr int value  = -1;  CInt obj(std::move(CInt(value))); EXPECT_EQ(obj.value(), value); }
	{ constexpr int value  = -2;  CInt obj(std::move(CInt(value))); EXPECT_EQ(obj.value(), value); }
}

#define MACRO_CSMART_NOINIT_EQ(MacroType, MacroValue)     \
{                                                         \
	MacroType obj;                                        \
	obj = MacroType(MacroValue);                          \
	EXPECT_EQ(obj.value(), MacroValue);					  \
	EXPECT_TRUE(obj == MacroValue);					      \
}

#define MACRO_CSMART_OPER_COPY(MacroType, MacroValue)     \
{                                                         \
	{                                                     \
		MacroType obj;                                    \
		obj.operator=(MacroValue);                        \
		EXPECT_TRUE(obj == MacroValue);                   \
	}                                                     \
	{                                                     \
		MacroType obj;                                    \
		MacroType dup = MacroValue;                       \
		obj.operator=(dup);                               \
		EXPECT_TRUE(obj == MacroValue);					  \
	}                                                     \
	{                                                     \
		MacroType obj;                                    \
		obj.operator=(std::move(MacroType(MacroValue)));  \
		EXPECT_TRUE(obj == MacroValue);                   \
	}                                                     \
}

#define MACRO_CSMART_OPER_EQ(MacroType, MacroValue)       \
{                                                         \
	{                                                     \
		MacroType obj(MacroValue);                        \
		EXPECT_TRUE(obj == MacroValue);                   \
	}                                                     \
	{                                                     \
		MacroType obj(MacroValue);                        \
		MacroType dup(MacroValue);                        \
		EXPECT_TRUE(obj == dup);                          \
	}                                                     \
	{                                                     \
		MacroType obj(MacroValue);                        \
		EXPECT_FALSE(obj == MacroValue + 1);              \
	}                                                     \
	{                                                     \
		MacroType obj(MacroValue);                        \
		MacroType dup(MacroValue + 1);                    \
		EXPECT_FALSE(obj == dup);                         \
	}                                                     \
}

#define MACRO_CSMART_OPER_NOEQ(MacroType, MacroValue)     \
{                                                         \
	{                                                     \
		MacroType obj(MacroValue);                        \
		EXPECT_FALSE(obj != MacroValue);                  \
	}                                                     \
	{                                                     \
		MacroType obj(MacroValue);                        \
		MacroType dup(MacroValue);                        \
		EXPECT_FALSE(obj != dup);                         \
	}                                                     \
	{                                                     \
		MacroType obj(MacroValue);                        \
		EXPECT_TRUE(obj != MacroValue + 1);               \
	}                                                     \
	{                                                     \
		MacroType obj(MacroValue);                        \
		MacroType dup(MacroValue + 1);                    \
		EXPECT_TRUE(obj != dup);                          \
	}                                                     \
}

#define MACRO_CSMART_NOINIT_GT(MacroType, MacroL, MacroR) \
{                                                         \
	{                                                     \
		MacroType obj(MacroR);                            \
		EXPECT_FALSE(obj > MacroL);                       \
	}                                                     \
	{                                                     \
		MacroType obj(MacroR);                            \
		MacroType dup(MacroL);                            \
		EXPECT_FALSE(obj > dup);                          \
	}                                                     \
	{                                                     \
		MacroType obj(MacroL);                            \
		EXPECT_TRUE(obj > MacroR);                        \
	}                                                     \
	{                                                     \
		MacroType obj(MacroL);                            \
		MacroType dup(MacroR);                            \
		EXPECT_TRUE(obj > dup);                           \
	}                                                     \
}

#define MACRO_CSMART_NOINIT_LT(MacroType, MacroL, MacroR) \
{                                                         \
	{                                                     \
		MacroType obj(MacroR);                            \
		EXPECT_FALSE(obj < MacroL);                       \
	}                                                     \
	{                                                     \
		MacroType obj(MacroR);                            \
		MacroType dup(MacroL);                            \
		EXPECT_FALSE(obj < dup);                          \
	}                                                     \
	{                                                     \
		MacroType obj(MacroL);                            \
		EXPECT_TRUE(obj < MacroR);                        \
	}                                                     \
	{                                                     \
		MacroType obj(MacroL);                            \
		MacroType dup(MacroR);                            \
		EXPECT_TRUE(obj < dup);                           \
	}                                                     \
}

#define MACRO_CSMART_NOINIT_EQGT(MacroType, MacroL, MacroR) \
{                                                           \
	{                                                       \
		MacroType obj(MacroR);                              \
		EXPECT_FALSE(obj > MacroL);                         \
	}                                                       \
	{                                                       \
		MacroType obj(MacroR);                              \
		MacroType dup(MacroL);                              \
		EXPECT_FALSE(obj > dup);                            \
	}                                                       \
	{                                                       \
		MacroType obj(MacroL);                              \
		EXPECT_TRUE(obj >= MacroR);                         \
	}                                                       \
	{                                                       \
		MacroType obj(MacroL);                              \
		MacroType dup(MacroR);                              \
		EXPECT_TRUE(obj >= dup);                            \
	}                                                       \
}

#define MACRO_CSMART_NOINIT_EQLT(MacroType, MacroL, MacroR) \
{                                                           \
	{                                                       \
		MacroType obj(MacroR);                              \
		EXPECT_FALSE(obj < MacroL);                         \
	}                                                       \
	{                                                       \
		MacroType obj(MacroR);                              \
		MacroType dup(MacroL);                              \
		EXPECT_FALSE(obj < dup);                            \
	}                                                       \
	{                                                       \
		MacroType obj(MacroL);                              \
		EXPECT_TRUE(obj <= MacroR);                         \
	}                                                       \
	{                                                       \
		MacroType obj(MacroL);                              \
		MacroType dup(MacroR);                              \
		EXPECT_TRUE(obj <= dup);                            \
	}                                                       \
}


#define MACRO_GTEST_CLASS_INT(TestCaseName, TypeName)       \
TEST(TestCaseName, Test##TypeName)				     	    \
{															\
	MACRO_CSMART_NOINIT_EQ(TypeName, 0);					\
	MACRO_CSMART_NOINIT_EQ(TypeName, 1);					\
	MACRO_CSMART_NOINIT_EQ(TypeName, 2);					\
	MACRO_CSMART_NOINIT_EQ(TypeName, -1);					\
	MACRO_CSMART_NOINIT_EQ(TypeName, -2);					\
															\
	/* operator= */		         							\
															\
	MACRO_CSMART_OPER_COPY(TypeName, 0);					\
	MACRO_CSMART_OPER_COPY(TypeName, 1);					\
	MACRO_CSMART_OPER_COPY(TypeName, 2);					\
	MACRO_CSMART_OPER_COPY(TypeName, -1);					\
	MACRO_CSMART_OPER_COPY(TypeName, -2);					\
															\
	/* operator== */                                        \
															\
	MACRO_CSMART_OPER_EQ(TypeName,  0);						\
	MACRO_CSMART_OPER_EQ(TypeName,  1);						\
	MACRO_CSMART_OPER_EQ(TypeName,  2);						\
	MACRO_CSMART_OPER_EQ(TypeName, -1);						\
	MACRO_CSMART_OPER_EQ(TypeName, -2);						\
															\
	/* operator!= */                                        \
															\
	MACRO_CSMART_OPER_NOEQ(TypeName, 0);					\
	MACRO_CSMART_OPER_NOEQ(TypeName, 1);					\
	MACRO_CSMART_OPER_NOEQ(TypeName, 2);					\
	MACRO_CSMART_OPER_NOEQ(TypeName, -1);					\
	MACRO_CSMART_OPER_NOEQ(TypeName, -2);					\
															\
	/* operator> */                                         \
															\
	MACRO_CSMART_NOINIT_GT(TypeName, 0, -1);				\
	MACRO_CSMART_NOINIT_GT(TypeName, 1, 0);					\
	MACRO_CSMART_NOINIT_GT(TypeName, 2, 1);					\
	MACRO_CSMART_NOINIT_GT(TypeName, -1, -26);				\
	MACRO_CSMART_NOINIT_GT(TypeName, -2, -4495);			\
															\
	/* operator< */                                         \
															\
	MACRO_CSMART_NOINIT_LT(TypeName, -1, 0);    			\
	MACRO_CSMART_NOINIT_LT(TypeName, 0, 1);					\
	MACRO_CSMART_NOINIT_LT(TypeName, 1, 2);					\
	MACRO_CSMART_NOINIT_LT(TypeName, -26, -6);				\
	MACRO_CSMART_NOINIT_LT(TypeName, -2615, -45);			\
															\
	/* operator>= */                                        \
															\
	MACRO_CSMART_NOINIT_EQGT(TypeName, 0, -1);		    	\
	MACRO_CSMART_NOINIT_EQGT(TypeName, 1, 0);		    	\
	MACRO_CSMART_NOINIT_EQGT(TypeName, 2, 1);		    	\
	MACRO_CSMART_NOINIT_EQGT(TypeName, -1, -26);	    	\
	MACRO_CSMART_NOINIT_EQGT(TypeName, -2, -4495);	    	\
															\
	/* operator<= */                                        \
															\
	MACRO_CSMART_NOINIT_EQLT(TypeName, -1, 0);			    \
	MACRO_CSMART_NOINIT_EQLT(TypeName, 0, 1);			    \
	MACRO_CSMART_NOINIT_EQLT(TypeName, 1, 2);			    \
	MACRO_CSMART_NOINIT_EQLT(TypeName, -26, -6);		    \
	MACRO_CSMART_NOINIT_EQLT(TypeName, -2615, -45);			\
}                                   						\

MacroClassInt(MyInt);
MACRO_GTEST_CLASS_INT(CSmartMacroInt, MyInt)
