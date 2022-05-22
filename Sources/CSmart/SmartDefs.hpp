
//////////////////////////////////////////////////////////////////////////

#ifndef CSMART_DEFS_HPP
#define CSMART_DEFS_HPP

//////////////////////////////////////////////////////////////////////////

#include "CInt.hpp"

//////////////////////////////////////////////////////////////////////////

#define MacroClassMember(type, name)                              \
private:                                                          \
	type m_##name;                                                \
public:                                                           \
	type name()                  { return m_##name;  }            \
	void name(const type& value) { m_##name = value; }            \
	void name(type&& value)      { m_##name = value; }            \

namespace Masters
{
	namespace CSmart
	{

	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !CSMART_DEFS_HPP

//////////////////////////////////////////////////////////////////////////
