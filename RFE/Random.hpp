#pragma once

namespace rfe::Random
{
	// Get a random value between min and max (both included)
	RFE_API int GetValue(int min, int max);
	// Set the seed for the random number generator
	RFE_API void SetSeed(unsigned int seed);
};