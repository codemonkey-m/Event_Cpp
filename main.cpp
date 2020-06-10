// Event.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "./Event/Event.h"
#include <tuple>
#include <Windows.h>
using namespace std;

int main()
{
	Event<string, tuple<string, int>> EventTest;
	EventTest.on("connect", [&](auto tp) {
		cout << get<0>(tp) << " : " << get<1>(tp) << endl;
	});
	EventTest.emit("connect", forward_as_tuple("clinet connect to server ... ", GetTickCount()));

	Event<int, int> EventTest1;
	EventTest1.on(1, [&](int n) {
		cout << "recv msg is : " <<  n << endl;
	});
	EventTest1.emit(1, GetTickCount());

	Event<string, pair<string, int>> EventTest2;
	EventTest2.on("data", [&] (auto _pair) {
		cout << _pair.first << ":" << _pair.second << endl;
	});
	EventTest2.emit("data", make_pair("current tick is", GetTickCount()));

	//std::cout << "Hello World!\n";
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
