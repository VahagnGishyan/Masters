
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "../Int.hpp"

namespace Masters
{
	namespace CSmart
	{
		namespace FundamentalTypes
		{
			CInt::CInt(const ValueType value) noexcept : m_value(value)       {}
			CInt::CInt(const CInt& obj)		  noexcept : m_value(obj.m_value) {}
			CInt::CInt(CInt&& obj)            noexcept : m_value(obj.m_value) {}

			CInt::~CInt() {}
		
			void CInt::operator=(const CInt& obj) noexcept
			{
				this->m_value = obj.m_value;
			}
			void CInt::operator=(CInt&& obj)      noexcept
			{
				this->m_value = obj.m_value;
			}
		}
	}
}