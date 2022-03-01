#pragma once

#ifdef _DEBUG
#include <iostream>
#define RFE_LOG(msg) std::cout << "[LOG] " << msg << std::endl;
#else
#define RFE_LOG(msg)
#endif

