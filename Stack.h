#pragma once
#include <fstream>
#define SIZE 100

namespace vz_struct
{
	class Stack
	{
	private:
		int id;
		static int idCounter;

		int s_ptr; //������� ������ ��������� �������� � �����
		int s_size; //������������ ������ �����
		char s_stack[SIZE][4]; // ��� ������ ����, 3 - ������ ��� ������������ ���-�� ��������� �� = 3
	public:
		Stack(); //������������
		~Stack(); //����������

		void Push(char* a); //�������� � ����
		char* Pop(); //������� �� �����
		char* Top(); //�������� ������� ������� �����
		bool IsEmpty(); //���������, �������� �� ���� ������

	};
}
