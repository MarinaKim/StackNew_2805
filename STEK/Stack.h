#pragma once
//top - самый верхзний элемент в стеке
//pop- удаление из стека
//push- добавлени в стек
//size- ф-ция кол-во элементов в стеке
//empty-функция bool пусто или нет
//LIFO- last in first out

//подход для реализации с помощью массивов или связанных списков

#include"Library.h"
template<typename type> class Stack {
private:
	type *els;
	size_t length;
	size_t buf_size;
public:
	//конструктор по умочанию
	Stack();
	//parameter constructor
	Stack(type* mass, int n);
	//copy constructor
	Stack(const Stack& obj);

	type& top();
	void push(type e);
	void pop();
	size_t size();
	bool empty();
	void join(Stack& obj);
	int count();

	bool check(char c);
	//destructor
	~Stack();

};