
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Creator.hpp"

namespace Masters
{
	namespace Matrix
	{
		CCreator::CCreator(const CSize size, const SType& type, const CVertexList& list) :
			m_size(size), m_type(type), m_vertices(list) {}
		CCreator::~CCreator() {}

		const CSize&        CCreator::size()                      const noexcept { return (m_size); }
		const SType&        CCreator::type()                      const noexcept { return (m_type); }
		const CVertexList&  CCreator::vertices()                  const noexcept { return (m_vertices); }

		void                CCreator::size(const CSize& size)           noexcept { m_size = m_size; }
		void                CCreator::type(const SType& type)           noexcept { m_type = m_type; }
		void                CCreator::vertices(const CVertexList& list) noexcept { m_vertices = m_vertices; }

		void                CCreator::size(CSize&& size)                noexcept { m_size = m_size; }
		void                CCreator::type(SType&& type)                noexcept { m_type = m_type; }
		void                CCreator::vertices(CVertexList&& list)      noexcept { m_vertices = m_vertices; }
	}
}