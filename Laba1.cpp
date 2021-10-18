#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Stack.h"
using namespace vz_struct;

/*
3. Используя стек, решить следующую задачу. 
В текстовом файле LOG записано без ошибок логическое выражение (ЛВ) в следующей форме: 
<ЛВ> ::= True | False | (!<ЛВ> ) | (<ЛВ >^ <ЛВ>) | (< ЛВ >v< ЛВ >)
Например: (! (T v F) ^ (F v T)). 
Вычислить (как boolean) значение этого выражения.
Знаки !, ^, v означают соответственно отрицание, конъюнкцию и дизъюнкцию. 
Для реализации АТД Стек использовать массив.
*/
char handling(char stack_element[3])
{
    if (stack_element[1] == '\0')
        return stack_element[0];
    if (stack_element[1] == 'v')
    {
        if ((stack_element[0] == 'T') || (stack_element[2] == 'T'))
            return 'T';
        else
            return 'F';
    }
    else 
    {
        if ((stack_element[0] == 'T') && (stack_element[2] == 'T'))
            return 'T';
        else
            return 'F';
    }
}

bool Boolean_expression_solution(Stack& stack)
{
    char safe_of_element[4]; //массив, для хранения лв
    char stack_element[4]; // массив, при считывании
    int num_of_elements = 0; //кол-во элементов в логическом выражении
    while (!stack.IsEmpty())
    {
        strcpy_s(stack_element, stack.Pop());
        for (int i = 0; stack_element[i] != '\0'; i++)
        {
            ++num_of_elements;
        }

        if (num_of_elements == 3)
        {
            stack_element[0] = handling(stack_element);
            stack_element[1] = '\0';
            safe_of_element[0] = stack_element[0];
            safe_of_element[1] = '\0';
        }
        else
        {
            if (stack_element[0] == '!')
            {
                if (safe_of_element[0] == 'T')
                    safe_of_element[0] = 'F';
                else
                    safe_of_element[0] = 'T';

            }
            else
            {
                if (stack_element[1] == '\0')
                    safe_of_element[0] = stack_element[0];
                // ниже для многочисленных ( возможно нужен if)
                else
                {
                    safe_of_element[1] = stack_element[0];
                    safe_of_element[2] = '\0';
                }
            }
             
        }
        if (!stack.IsEmpty())
        {
            strcpy_s(stack_element, stack.Pop());
            if (stack_element[0] == '!')
            {
                if (safe_of_element[0] == 'T')
                    safe_of_element[0] = 'F';
                else
                    safe_of_element[0] = 'T';
                safe_of_element[1] = '\0';
            }
            else
            {
                safe_of_element[1] = stack_element[0];
                safe_of_element[2] = '\0';
            }
            num_of_elements = 0;

        }
        
        if (!stack.IsEmpty()) //проверка на кол-во элементов, для выполнения цикла
        {
            strcpy_s(stack_element, stack.Pop());
            for (int i = 0; stack_element[i] != '\0'; i++)
            {
                ++num_of_elements;
            }

            if (num_of_elements == 3)
            {
                stack_element[0] = handling(stack_element);
                stack_element[1] = '\0';
                safe_of_element[2] = stack_element[0];
                safe_of_element[3] = '\0';
            }
            else
            {
                safe_of_element[2] = stack_element[0];
                safe_of_element[3] = '\0';
            }
            safe_of_element[0] = handling(safe_of_element);
            safe_of_element[1] = '\0';
        }
        stack_element[0] = handling(safe_of_element);
        stack_element[1] = '\0';
    }

    if (stack_element[0] == 'T') return true;
    else return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Открываем файл!";
    std::ifstream FileIn("LOG.txt"); //открыли файл для чтения.

    if (FileIn.is_open())
        std::cout << "\nФайл успешно открыт!\n";
    else {
        std::cout << "\nФайл не был открыт!\n";
        return 1;
    }

    Stack stack;
    char k;
    char element_of_boolean_expression[4];
    int i = 0;
    while (!FileIn.eof())
    {
        FileIn >> k;
        switch (k)
        {
        case 'T': 
            element_of_boolean_expression[i] = 'T';
            i++;
            break;
        case 'F':
            element_of_boolean_expression[i] = 'F';
            i++;
            break;
        case '!':
            element_of_boolean_expression[i] = '!';
            i++;
            break;
        case '^':
            element_of_boolean_expression[i] = '^';
            i++;
            break;
        case 'v':
            element_of_boolean_expression[i] = 'v';
            i++;
            break;
        case '(':
        case ')':
            if (i != 0) {
                element_of_boolean_expression[i] = '\0';
                i = 0;
                stack.Push(element_of_boolean_expression);
            }
            
        }
    }
    std::ofstream FileOut("OUT.txt"); //открыли файл для записи
    if (!FileOut.is_open()) // если выходной файл не открыт
    std::cout << "Выходной файл не может быть открыт!\n"; // сообщить об этом
    else 
    {
        FileIn.close(); // закрываем входной файл
        
        if (Boolean_expression_solution(stack))
            FileOut << "True";
        else
            FileOut << "False";
        FileOut.close(); // записываем результат и закрываем выходной файл
    }
    return 0;
}