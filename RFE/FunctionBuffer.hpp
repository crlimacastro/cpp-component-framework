#pragma once

namespace rfe
{
	// Object that queues up functions you can then and dispose of
	class RFE_API FunctionBuffer
	{
	public:
		// Pushes a function into the buffer
		void Push(std::function<void()>&& fn);
		// Cleans the buffer and calls all functions inside
		void DumpInvoke();
	private:
		std::queue<std::function<void()>> functions;
	};
}