#include"Stack.h"
template <typename type>
Stack<type>::Stack() {
	buf_size = 0;
	length = 0;
	els = nullptr;
}
template <typename type>
Stack<type>::Stack(type* mass, int n) {
	this->length = n;
	els = new type[this->length];
	this->buf_size = this->length;
	for (int i = 0;i < length;i++)
		this->els[i] = mass[i];
}

template<typename type>
Stack<type>::Stack(const Stack& obj) {
	this->length = obj.length;
	this->buf_size = obj.buf_size;
	this->els = new type[length];
	for (int i = 0;i < length;i++)
		els[i] = obj.els[i];
}

template<typename type>
type& Stack<type>::top() {
	return els[length - 1];
}

template<typename type>
size_t Stack<type>::size() {
	return length;
}

template<typename type>
bool Stack<type>::empty() {
	return (size() == 0);
}
template<typename type>
void Stack<type>::join(Stack & obj)
{
	int mas[6];
	
		while (!this->empty()) {
			for (int i = 0;i < 3;i++) {
			mas[i] = this->top();
			this->pop();
		}
	}
	
		while (!obj.empty()) {
			for (int i = 3;i < 6;i++) {
			mas[i] = obj.top();
			obj.pop();
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j > i; j--)
		{
			if (mas[j - 1] > mas[j])
			{
				int l = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = l;
			}
		}
	}
	cout << "Sort mass:" << endl;
	for (int i = 0;i < 6;i++)
		cout << mas[i] <<endl;
	for (int i = 0;i < 6;i++)
		this->push(mas[i]);

}
template<typename type>
int Stack<type>::count()
{
	int count = 0;
	while (!this->empty()) {		
		this->pop();
		count++;
	}
	return count;
}
template<typename type>
bool Stack<type>::check(char c)
{
	int count = 0, count1=0;
	char m[6];
	while (!this->empty()) {
		for (int i = 0;i < 6;i++) {
			m[i] = this->top();
			this->pop();
		}
	}
	if (c == '(')
	{
		for (int i = 0;i < 6;i++)
		{
			if (m[i] == c)
				count++;
			else if (m[i] == ')')
				count1++;
		}
	}
	if (c == '[')
	{
		for (int i = 0;i < 6;i++)
		{
			if (m[i] == c)
				count++;
			else if (m[i] == ']')
				count1++;
		}
	}
	if (c == '{')
	{
		for (int i = 0;i < 6;i++)
		{
			if (m[i] == c)
				count++;
			else if (m[i] == '}')
				count1++;
		}
	}

	if (count == count1)
		return true;
	else
	return false;
}

template <typename type>
void Stack<type>::pop() {
	length--;
}

template <typename type>
Stack<type>::~Stack() {
	delete[] els;
	els = nullptr; // надо забыть адрес, удалить
}

template <typename type>
void Stack<type>::push(type e) {
	if (buf_size == 0) {
		buf_size = 2;
		els = new type[buf_size];
	}
	else if (buf_size <= length) {
		buf_size *= 2;
		type *tmp = new type[buf_size];
		for (int i = 0;i < length;i++)
			tmp[i] = els[i];
		delete[] els;
		els = tmp;
	}
	els[length++] = e;
}