#include "TestApp.h"

#include <iostream>

void Test3(int x)
{
	std::cout << "Called with " << x << std::endl;
}

int main(void)
{
	/*TestApp app;
	app.Start();*/

	/*rfe::Event<, void>*/

	rfe::Event test;
	test.Subscribe([]() { std::cout << "Called" << std::endl; });

	rfe::Event<int> test2;
	test2.Subscribe(Test3);

	test2.Invoke(5);
	test.Invoke();

	return 0;
}