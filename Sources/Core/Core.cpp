// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Core.hpp"

namespace Masters
{

	const std::string getenv(const std::string envName)
	{
		std::string value = "";
		if (!envName.empty())
		{
#ifdef _WIN32
			char* buf = nullptr;
			size_t sz = 0;

			if (_dupenv_s(&buf, &sz, envName.c_str()) == 0 && buf != nullptr)
			{
				value = std::move(std::string(buf));
				free(buf);
			}
#elif __linux__
			//const char const* env_value = std::getenv(env_name.c_str());
			//value = (env_value == nullptr ? std::string() : std::string(env_value));
#endif
		}
		return (value);
	}

	const bool isGUTestDetailsOn()
	{
		// if ENV_NM_GUTEST_SET == ENV_VL_GUTEST_SET_ON, result = on, else, result = false
		static bool result = (Masters::getenv(ENV_NM_GUTEST_DETAIL_SET) == std::string(ENV_VL_GUTEST_DETAIL_ON));
		return (result);
	}

}