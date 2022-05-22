// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Debug.hpp"

void  Masters::Debug::DLLWorkImp(const std::string dllname, std::ostream& file)
{
	file << "DLL[" << dllname << "] is loaded" << std::endl;
}

void Masters::Debug::testDLLWork(std::ostream& file /*= std::cout*/)
{
	Masters::Debug::DLLWorkImp("MT::Core", file);
}

void Masters::Debug::logFile(const std::string& err, std::ostream& file /*= std::cout*/)
{
#ifdef DEBUG_MODE
	//if (std::string(Masters::getenv(EV_NAME_DEBUG_LOG_SET)) == 
		//std::string(Masters::getenv(EV_VALUE_DEBUG_LOG_ON)))
	{
		file << err << std::endl;
	}
#endif //!DEBUG_MODE
}
