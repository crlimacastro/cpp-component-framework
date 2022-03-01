// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

#include <memory>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iterator>
#include <algorithm>

#include <raylib.h>

#ifdef RFE_EXPORTS
#define RFE_API __declspec(dllexport)   
#else
#define RFE_API __declspec(dllimport)   
#endif

#endif //PCH_H