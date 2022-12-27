#include "pch.h"
#include "URL.h"

void rfe::URL::Open(std::string url)
{
	OpenURL(url.c_str());
}
