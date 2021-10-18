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

		int s_ptr; //текущий индекс значимого элемента в стеке
		int s_size; //максимальный размер стека
		char s_stack[SIZE][4]; // сам булеан стек, 3 - потому что максимальное кол-во элементов лв = 3
	public:
		Stack(); //Иницализация
		~Stack(); //Деструктор

		void Push(char* a); //Положить в стек
		char* Pop(); //Забрать из стека
		char* Top(); //Получить верхний элемент стека
		bool IsEmpty(); //Проверить, является ли стек пустым

	};
}
