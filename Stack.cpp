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
        std::cout << "Cоздан стек id: <" << id << "> \n";
    }

    Stack::~Stack() 
    {
        std::cout << "”ничтожен стек id: <" << id << "> \n";
    }

    void Stack::Push(char* a) // положить в стек
    {
        int i;
        if (s_ptr == s_size) // проверка на попытку занесени€ элемента в полный стек
        {
            std::cout << "ѕопытка занесени€ значени€ в полный стек";
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

    char* Stack::Pop() // забрать из стека
    {
        if (s_ptr == -1) // проверка на попытку забрать элемент из пустого стека
        {
            printf("ѕопытка чтени€ из пустого стека");
            exit(EXIT_FAILURE);
        }
        else return(s_stack[s_ptr--]);
    }

    char* Stack::Top()// получить значение верхнего элемента стека
    { 
        if (!IsEmpty()) 
            return(s_stack[s_ptr]); 
        else 
            exit(EXIT_FAILURE);
    }

    bool Stack::IsEmpty()// проверить, €вл€етс€ ли стек пустым
    { 
        return(s_ptr == -1); 
    }
}