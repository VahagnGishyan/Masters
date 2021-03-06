
// This is a personal academic project. Dear PVS-Studio, please check it.

//////////////////////////////////////////////////////////////////////////

#ifndef DEBUG_HPP
#define DEBUG_HPP

//////////////////////////////////////////////////////////////////////////

#include "..\Kernel\KernelDefs.hpp"
#include "..\Core.hpp"

//////////////////////////////////////////////////////////////////////////

#define DEBUG_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Debug
	{
		void DEBUG_EXPORT DLLWorkImp (const std::string dllname, std::ostream& file);
		void DEBUG_EXPORT testDLLWork(std::ostream& file = std::cout);
		void DEBUG_EXPORT logFile    (const std::string& err, std::ostream& file = std::cout);
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !DEBUG_HPP

//////////////////////////////////////////////////////////////////////////
