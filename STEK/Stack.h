#pragma once
//top - ����� �������� ������� � �����
//pop- �������� �� �����
//push- ��������� � ����
//size- �-��� ���-�� ��������� � �����
//empty-������� bool ����� ��� ���
//LIFO- last in first out

//������ ��� ���������� � ������� �������� ��� ��������� �������

#include"Library.h"
template<typename type> class Stack {
private:
	type *els;
	size_t length;
	size_t buf_size;
public:
	//����������� �� ��������
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