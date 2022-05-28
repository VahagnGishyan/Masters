
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Size.hpp"

namespace Masters
{
	namespace Matrix
	{
		CSize::CSize() : m_height(0), m_length(0) {}
		CSize::CSize(const CHeight& height, const CLength& length) /*except { std::string } */
			: m_height(height), m_length(length)
		{
			if ((height < 0) || (length < 0))
			{
				throw std::string("CSize(height, length), height && length must be >= 0");
			}
		}
		CSize::CSize(CHeight&& height, CLength&& length)             /*except { std::string } */
			: m_height(height), m_length(length)
		{
			if ((height < 0) || (length < 0))
			{
				throw std::string("CSize(height, length), height && length must be >= 0");
			}
		}
		CSize::~CSize() {}

		////////////////////////////////////////////////////////////////////////////////////////////////////

		void                 CSize::height(const CHeight& height) noexcept { m_height = height; }
		void                 CSize::height(CHeight& height)       noexcept { m_height = height; }

		void                 CSize::length(const CLength& length) noexcept { m_length = length; }
		void                 CSize::length(CLength&& length)      noexcept { m_length = length; }

		const Sizes::CHeight CSize::height() const                noexcept { return (m_height); }
		const Sizes::CLength CSize::length() const                noexcept { return (m_length); }

		////////////////////////////////////////////////////////////////////////////////////////////////////

		bool operator== (const CSize& left, const CSize& right) noexcept
		{
			return ((left.height() == right.height()) && (left.length() == right.length()));
		}
		bool operator!= (const CSize& left, const CSize& right) noexcept
		{
			return ((left.height() != right.height()) || (left.length() != right.length()));
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////

		namespace Sizes
		{
			MacroClassIntImp(CHeight);
			MacroClassIntImp(CLength);

			bool isValid(const CSize& loc) noexcept
			{
				return ((loc.height() >= Sizes::CHeight(0)) && (loc.length() >= Sizes::CLength(0)));
			}
		}
	}
}

