// Event.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "./Event/Event.h"
#include <tuple>
#include <Windows.h>
using namespace std;

int main()
{
	Event<string, tuple<string, ULONGLONG>> EventTest;
	EventTest.on("connect", [&](const auto& tp) {
		cout << get<0>(tp) << " : " << get<1>(tp) << endl;
	});
	EventTest.emit("connect", forward_as_tuple("clinet connect to server ... ", GetTickCount64()));

	Event<int, ULONGLONG> EventTest1;
	EventTest1.on(1, [&](const auto& n) {
		cout << "recv msg is : " <<  n << endl;
	});
	EventTest1.emit(1, GetTickCount64());

	Event<int, string> EventTest3;
	EventTest3.on(1, [&](const auto& s) {
		cout << "get string is : " << s << endl;
	});
	string s = "1111";
	EventTest3.emit(1, s);

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
