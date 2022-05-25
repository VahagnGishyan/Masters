
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
				using ValueType = int;

			public: // ctor/dector
				CInt(const ValueType value = 0)	noexcept;
				CInt(const CInt& obj)			noexcept;
				CInt(CInt&& obj)				noexcept;

				virtual ~CInt();

				//public: // pure virtual operators
				//	virtual CInt& operator=(const CInt& obj) noexcept = 0;
				//	virtual CInt& operator=(CInt&& obj)		 noexcept = 0;
				void operator=(const CInt&  obj) noexcept;
				void operator=(      CInt&& obj) noexcept;

				operator ValueType() const { return (value()); }

			protected: // get, set
				const ValueType value()              const { return (m_value); }
				void          value(const ValueType value) { m_value = value; }
			private: // mem vars
				ValueType m_value;
			};
		}
	}
}


#define  MacroClassInt(ClassName) /*MASTERS_EXPORT*/                                       \
MASTERS_EXPORT class ClassName : public Masters::CSmart::FundamentalTypes::CInt                       \
{                                                                                      \
public: /* ctor/dector*/                                                               \
	ClassName(const ValueType value = 0) noexcept : CInt(value) {}                       \
	ClassName(const ClassName& obj)    noexcept : CInt(obj)   {}                       \
	ClassName(ClassName&& obj)         noexcept : CInt(obj)   {}                       \
public: /* operators */                                                                \
ClassName& operator= (const ClassName& obj) noexcept         \
{                                                                       \
	if (this == &obj)                                                   \
		return *this;                                                   \
	value(obj.value());                                                 \
	return *this;                                                       \
}                                                                       \
ClassName& operator= (const ValueType value) noexcept          \
{                                                                       \
	this->value(value);                                                 \
	return *this;                                                       \
}                                                                       \
ClassName& operator= (ClassName&& obj) noexcept              \
{                                                                       \
	if (this == &obj)                                                   \
		return *this;                                                   \
	value(obj.value());                                                 \
	return *this;                                                       \
}                                                                       \
    operator ValueType() const { return (value()); }                      \
                                                                                       \
	/*MASTERS_EXPORT friend bool operator== (const ClassName &l, const ClassName &r);*/    \
    /*MASTERS_EXPORT friend bool operator!= (const ClassName &l, const ClassName &r);*/    \
    /*                                                                               */    \
    /*MASTERS_EXPORT friend bool operator> (const ClassName &l, const ClassName &r); */    \
    /*MASTERS_EXPORT friend bool operator< (const ClassName &l, const ClassName &r); */    \
    /*                                                                               */    \
    /*MASTERS_EXPORT friend bool operator>= (const ClassName &l, const ClassName &r);*/    \
    /*MASTERS_EXPORT friend bool operator<= (const ClassName &l, const ClassName &r);*/    \
};                                                                      

#define MacroClassIntImp(ClassName)                                     \
//                                                                        \
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
bool operator== (const ValueType value) const                         \
	{                                                                   \
		return (this->value() == value);                                \
	};                                                                  \
	bool operator!= (const ValueType value) const                         \
	{                                                                   \
		return (this->value() != value);                                \
	};                                                                  \
																		\
	bool operator>= (const ValueType value) const                         \
	{                                                                   \
		return (this->value() >= value);                                \
	};                                                                  \
	bool operator<= (const ValueType value) const                         \
	{                                                                   \
		return (this->value() <= value);                                \
	};                                                                  \
																		\
	bool operator> (const ValueType value) const                          \
	{                                                                   \
		return (this->value() >  value);                                \
	};                                                                  \
	bool operator< (const ValueType value) const                          \
	{                                                                   \
		return (this->value() <  value);                                \
	};                                                                  \
*/

//friend bool operator== (const ClassName& l, const ValueType& r);      \
//friend bool operator== (const ValueType& l, const ClassName& r);      \
//bool operator== (const ClassName& l, const ClassName& r)                \
//{                                                                       \
//    return (l.value() == r.value());                                    \
//}                                                                       \
//bool operator== (const ClassName& l, const ClassName::ValueType& r)       \
//{                                                                       \
//    return (l.value() == r);                                            \
//}                                                                       \
//bool operator== (const ClassName::ValueType& l, const ClassName& r)       \
//{                                                                       \
//	return (l == r.value());                                            \
//}                                         							    \
//friend bool operator!= (const ClassName &l, const ValueType &r);      \
//friend bool operator!= (const ValueType &l, const ClassName &r);      \
//bool operator!= (const ClassName& l, const ClassName::ValueType& r)       \
//{                                                                       \
//	return (l.value() != r);                                            \
//}                                                                       \
//bool operator!= (const ClassName::ValueType& l, const ClassName& r)       \
//{                                                                       \
//	return (l != r.value());                                            \
//}                                         							    \


//////////////////////////////////////////////////////////////////////////

#endif // !MT_CSUB_CINT_HPP

//////////////////////////////////////////////////////////////////////////
