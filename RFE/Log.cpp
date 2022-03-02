#include "pch.h"
#include "Log.h"

#include <iostream>

void rfe::Log(std::string msg)
{
	std::cout << "[RFE_LOG] " << msg << std::endl;
}
