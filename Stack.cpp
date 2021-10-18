#include "Stack.h"
#include <iostream>
#include <fstream>

namespace vz_struct 
{
    int Stack::idCounter = 0;

    Stack::Stack()
    {
        id = ++idCounter;
        s_size = SIZE;
        s_ptr = -1;
        std::cout << "C����� ���� id: <" << id << "> \n";
    }

    Stack::~Stack() 
    {
        std::cout << "��������� ���� id: <" << id << "> \n";
    }

    void Stack::Push(char* a) // �������� � ����
    {
        int i;
        if (s_ptr == s_size) // �������� �� ������� ��������� �������� � ������ ����
        {
            std::cout << "������� ��������� �������� � ������ ����";
            exit(EXIT_FAILURE);
        }
        else {
            ++s_ptr;
            for (i = 0; a[i] != '\0'; i++)
            {
                s_stack[s_ptr][i] = a[i];
            }
            s_stack[s_ptr][i] = '\0';
        }
            
    }

    char* Stack::Pop() // ������� �� �����
    {
        if (s_ptr == -1) // �������� �� ������� ������� ������� �� ������� �����
        {
            printf("������� ������ �� ������� �����");
            exit(EXIT_FAILURE);
        }
        else return(s_stack[s_ptr--]);
    }

    char* Stack::Top()// �������� �������� �������� �������� �����
    { 
        if (!IsEmpty()) 
            return(s_stack[s_ptr]); 
        else 
            exit(EXIT_FAILURE);
    }

    bool Stack::IsEmpty()// ���������, �������� �� ���� ������
    { 
        return(s_ptr == -1); 
    }
}