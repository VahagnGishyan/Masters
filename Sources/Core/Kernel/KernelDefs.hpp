
// This is a personal academic project. Dear PVS-Studio, please check it.

//////////////////////////////////////////////////////////////////////////

#ifndef KERNEL_DEFS_HPP
#define KERNEL_DEFS_HPP

//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <memory> // always use smart pointers

//////////////////////////////////////////////////////////////////////////

#define DEBUG_MODE
#define EV_NAME_DEBUG_LOG_SET	"DEBUG_LOG_SET"
#define EV_VALUE_DEBUG_LOG_ON	"ON"
#define EV_VALUE_DEBUG_LOG_OFF	"OFF"

//////////////////////////////////////////////////////////////////////////

#define MASTERS_LIB

#ifdef MASTERS_LIB
#define MASTERS_EXPORT __declspec(dllexport)
#else
#define MASTERS_EXPORT __declspec(dllimport)
#endif // MASTERS_LIB

//////////////////////////////////////////////////////////////////////////

#endif // !KERNEL_DEFS_HPP

//////////////////////////////////////////////////////////////////////////


