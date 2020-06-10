// Event.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
