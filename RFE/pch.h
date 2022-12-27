// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

// Memory Leak Detection
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

// STD Library
#include <string>
#include <memory>
#include <functional>

// STL Containers
#include <vector>
#include <unordered_set>
#include <queue>

// Raylib
#include <raylib.h>

// Aliases
namespace rfe
{
	// Reference alias for smart (shared) pointers
	template<typename T>
	using ref = std::shared_ptr<T>;
}

// DLL Import/Export Macro
#ifdef RFE_EXPORTS
#define RFE_API __declspec(dllexport)   
#else
#define RFE_API __declspec(dllimport)   
#endif

#endif //PCH_H