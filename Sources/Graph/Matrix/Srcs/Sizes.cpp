
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Sizes.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

//using namespace Masters::Graph::Matrix;
//using Masters::Graph::Matrix::CSizes;




////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			CSizes:: CSizes() : m_height(0),       m_length(0)       {}
			CSizes:: CSizes(const CHeight & height, const CLength & length) /*except { std::string } */ 
				: m_height(height), m_length(length) 
			{
				if ((height < 0) || (length < 0))
				{
					throw std::string("CSizes(height, length), height && length must be >= 0");
				}
			}
			CSizes:: CSizes(CHeight&& height, CLength&& length)             /*except { std::string } */ 
				: m_height(height), m_length(length) 
			{
				if ((height < 0) || (length < 0))
				{
					throw std::string("CSizes(height, length), height && length must be >= 0");
				}
			}
			CSizes::~CSizes() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////

			void                 CSizes::height(const CHeight& height) noexcept { m_height = height; }
			void                 CSizes::height(CHeight& height)       noexcept { m_height = height; }
				                 
			void                 CSizes::length(const CLength& length) noexcept { m_length = length; }
			void                 CSizes::length(CLength&& length)      noexcept { m_length = length; }

			const Sizes::CHeight CSizes::height() const                noexcept { return (m_height); }
			const Sizes::CLength CSizes::length() const                noexcept { return (m_length); }
			
			////////////////////////////////////////////////////////////////////////////////////////////////////

			bool operator== (const CSizes& left, const CSizes& right) noexcept
			{
				return ((left.height() == right.height()) && (left.length() == right.length()));  
			}
			bool operator!= (const CSizes& left, const CSizes& right) noexcept
			{
				return ((left.height() != right.height()) || (left.length() != right.length()));
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////

			bool Sizes::isValid(const CSizes& loc) noexcept
			{
				return ((loc.height() >= Sizes::CHeight(0)) && (loc.length() >= Sizes::CLength(0)));
			}
		}
	}
}

