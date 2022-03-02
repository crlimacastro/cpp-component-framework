// For memory leak identification
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "TestApp.h"

// Wrapper to check for memory leaks from TestApp
void StartApp()
{
	TestApp app;
	app.Start();
}

int main(void)
{
	StartApp();

	_CrtDumpMemoryLeaks();

	return 0;
}