// Event.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "./Event/Event.h"
#include <tuple>
using namespace std;

int main()
{
	Event<std::tuple<std::string, int>> EventTest;
	EventTest.on("connect", [&](auto tp) {
		cout << std::get<0>(tp) << " : " << std::get<1>(tp) << endl;
	});
	EventTest.emit("connect", std::tuple<std::string, int>("clinet connect to server ... ", 13131));


	Event<int> EventTest1;
	EventTest1.on("msg", [&](int n) {
		cout << "recv msg is : " <<  n << endl;
	});
	EventTest1.emit("msg", 41541541);


	//std::cout << "Hello World!\n";
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
