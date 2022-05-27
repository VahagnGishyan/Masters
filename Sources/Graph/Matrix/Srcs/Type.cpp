
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Type.hpp"

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			SType::SType(const EDirection dir, const EWeighing weigh) : m_dir(dir), m_weigh(weigh) {}
			SType::~SType() {}

			SType::EDirection SType::direction()                const noexcept { return (m_dir);   }
			SType::EWeighing  SType::weighing()                 const noexcept { return (m_weigh); }

			void              SType::direction(const EDirection dir)  noexcept { m_dir = dir;      }
			void              SType::weighing (const EWeighing weigh) noexcept { m_weigh = weigh;  }
		}
	}
}
