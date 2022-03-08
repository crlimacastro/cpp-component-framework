#include "pch.h"
#include "Random.hpp"

int rfe::Random::GetValue(int min, int max)
{
	return GetRandomValue(min, max);
}

void rfe::Random::SetSeed(unsigned int seed)
{
	SetRandomSeed(seed);
}
