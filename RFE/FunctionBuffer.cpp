#include "pch.h"
#include "FunctionBuffer.hpp"

void rfe::FunctionBuffer::Push(std::function<void()>&& fn)
{
	functions.push(fn);
}

void rfe::FunctionBuffer::DumpInvoke()
{
	while (!functions.empty())
	{
		functions.front()();
		functions.pop();
	}
}
