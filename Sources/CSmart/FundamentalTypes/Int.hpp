
//////////////////////////////////////////////////////////////////////////

#ifndef MT_CSUB_CINT_HPP
#define MT_CSUB_CINT_HPP

//////////////////////////////////////////////////////////////////////////

#include "Masters/Core.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_CSUB_CINT_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters	
{
	namespace CSmart
	{
		namespace FundamentalTypes
		{
			class MT_CSUB_CINT_EXPORT CInt
			{
			public: // typedefs
				using value_t = int;

			public: // ctor/dector
				CInt(const value_t value = 0)	noexcept;
				CInt(const CInt& obj)			noexcept;
				CInt(CInt&& obj)				noexcept;

				virtual ~CInt();

				//public: // pure virtual operators
				//	virtual CInt& operator=(const CInt& obj) noexcept = 0;
				//	virtual CInt& operator=(CInt&& obj)		 noexcept = 0;
				void operator=(const CInt&  obj) noexcept;
				void operator=(      CInt&& obj) noexcept;

			public: // get 
				const value_t value()              const { return (m_value); }
			protected: // set
				void          value(const value_t value) { m_value = value; }
			private: // mem vars
				value_t m_value;
			};
		}
	}
}


#define MacroClassInt(ClassName)                                        \
class ClassName : public Masters::CSmart::FundamentalTypes::CInt        \
{                                                                       \
public: /* ctor/dector*/                                                \
	ClassName(const value_t value = 0)     noexcept : CInt(value)    {} \
	ClassName(const ClassName& obj)		   noexcept : CInt(obj)      {} \
	ClassName(ClassName&& obj)             noexcept : CInt(obj)      {} \
public: /* operators */                                                 \
	ClassName& operator= (const ClassName& obj) noexcept                \
	{                                                                   \
		if (this == &obj)                                               \
			return *this;                                               \
		value(obj.value());                                             \
		return *this;                                                   \
	}                                                                   \
	ClassName& operator= (const value_t value) noexcept                 \
	{                                                                   \
		this->value(value);                                             \
		return *this;                                                   \
	}                                                                   \
	ClassName& operator= (ClassName&& obj) noexcept                     \
	{                                                                   \
		if (this == &obj)                                               \
			return *this;                                               \
		value(obj.value());                                             \
		return *this;                                                   \
	}                                                                   \
                                                                        \
	friend bool operator== (const ClassName &l, const ClassName &r);    \
    friend bool operator!= (const ClassName &l, const ClassName &r);    \
                                                                        \
    friend bool operator> (const ClassName &l, const ClassName &r);     \
    friend bool operator< (const ClassName &l, const ClassName &r);     \
                                                                        \
    friend bool operator>= (const ClassName &l, const ClassName &r);    \
    friend bool operator<= (const ClassName &l, const ClassName &r);    \
};                                                                      \
																		\
bool operator== (const ClassName& l, const ClassName& r)                \
{                                                                       \
	return (l.value() == r.value());                                    \
}                                                                       \
bool operator!= (const ClassName& l, const ClassName& r)                \
{                                                                       \
	return (l.value() != r.value());                                    \
}                                                                       \
                                                                        \
bool operator> (const ClassName& l, const ClassName& r)                 \
{                                                                       \
	return (l.value() > r.value());                                     \
}                                                                       \
bool operator< (const ClassName& l, const ClassName& r)                 \
{                                                                       \
	return (l.value() < r.value());                                     \
}                                                                       \
                                                                        \
bool operator>= (const ClassName& l, const ClassName& r)                \
{                                                                       \
	return (l.value() >= r.value());                                    \
}                                                                       \
bool operator<= (const ClassName& l, const ClassName& r)                \
{                                                                       \
	return (l.value() <= r.value());                                    \
}                                                                       \

/*
bool operator== (const value_t value) const                         \
	{                                                                   \
		return (this->value() == value);                                \
	};                                                                  \
	bool operator!= (const value_t value) const                         \
	{                                                                   \
		return (this->value() != value);                                \
	};                                                                  \
																		\
	bool operator>= (const value_t value) const                         \
	{                                                                   \
		return (this->value() >= value);                                \
	};                                                                  \
	bool operator<= (const value_t value) const                         \
	{                                                                   \
		return (this->value() <= value);                                \
	};                                                                  \
																		\
	bool operator> (const value_t value) const                          \
	{                                                                   \
		return (this->value() >  value);                                \
	};                                                                  \
	bool operator< (const value_t value) const                          \
	{                                                                   \
		return (this->value() <  value);                                \
	};                                                                  \
*/

//friend bool operator== (const ClassName& l, const value_t& r);      \
//friend bool operator== (const value_t& l, const ClassName& r);      \
//bool operator== (const ClassName& l, const ClassName& r)                \
//{                                                                       \
//    return (l.value() == r.value());                                    \
//}                                                                       \
//bool operator== (const ClassName& l, const ClassName::value_t& r)       \
//{                                                                       \
//    return (l.value() == r);                                            \
//}                                                                       \
//bool operator== (const ClassName::value_t& l, const ClassName& r)       \
//{                                                                       \
//	return (l == r.value());                                            \
//}                                         							    \
//friend bool operator!= (const ClassName &l, const value_t &r);      \
//friend bool operator!= (const value_t &l, const ClassName &r);      \
//bool operator!= (const ClassName& l, const ClassName::value_t& r)       \
//{                                                                       \
//	return (l.value() != r);                                            \
//}                                                                       \
//bool operator!= (const ClassName::value_t& l, const ClassName& r)       \
//{                                                                       \
//	return (l != r.value());                                            \
//}                                         							    \


//////////////////////////////////////////////////////////////////////////

#endif // !MT_CSUB_CINT_HPP

//////////////////////////////////////////////////////////////////////////
