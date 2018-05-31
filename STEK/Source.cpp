#include"Stack.h"
#include "Stack.cpp"
#include<stack>


int main() {
	int n;
	cout << "Enter the num of task: ";
	cin >> n;
	switch (n) {

	case 1: {
		Stack <int> s;
		s.push(3);
		s.push(5);

		cout << s.top() << endl;
		s.pop();
		cout << s.top() << endl;
		s.pop();
		cout << s.empty() << endl;
	}break;

	case 2: {
		Stack <int> s;
		s.push(3);
		s.push(5);
		while (!s.empty()) {
			cout << s.top() << endl;
			s.pop();
		}
	}break;

	case 3: {
		int a[5] = { 2,4,6,7,8 };
		Stack <int> s(a,3);
		s.push(3);
		s.push(5);
		while (!s.empty()) {
			cout << s.top() << endl;
			s.pop();
		}
	}break;
/*6. –азработать класс дл€ работы со стеком. 
Ёлемент стека Ц целое число. ¬вести две неубывающие
последовательности чисел в два стека. »спользовать 
третий стек дл€ сли€ни€ двух последовательностей в одну 
неубывающую последовательность. */
	case 4: {
		Stack <int> s,s1;
		s.push(1);
		s.push(3);
		s.push(5);
		/*while (!s.empty()) {
			cout << s.top() <<"\t";
			s.pop();
		}
		cout << endl;*/
		s1.push(2);
		s1.push(4);
		s1.push(6);
		/*while (!s1.empty()) {
			cout << s1.top() << "\t";
			s1.pop();
		}
		cout << endl;*/
		cout << "Join Stack:" << endl;
		s.join(s1);
		while (!s.empty()) {
			cout << s.top() << "\t";
			s.pop();
		}
		cout << endl;
	}break;
		/*7. –азработать класс дл€ работы со стеком.
		Ёлемент стека Ц символ. —формировать два стека,
		содержащие последовательности символов. ѕодсчитать
		общее число элементов в стеках. ѕредусмотреть 
		восстановление исходного расположени€ элементов в стеках. */
	case 5: {
		Stack <char> s, s1;
		s.push(';');
		s.push('.');
		s.push(',');
		s1.push('[');
		s1.push(']');
		s1.push(')');
		cout << "Count of s: " << s.count() << endl;
		cout << "Count of s1: " << s1.count() << endl;


	}break;
/*8. –азработать класс дл€ работы со стеком. 
Ёлемент стека Ц символ. »спользовать стек дл€ проверки 
правильности расстановки скобок трех типов (круглых, 
квадратных и фигурных) во введенном выражении.*/
	case 6: {
		Stack <char> s, s1;
		s.push('(');
		/*cout << s.top() << endl;*/
		s.push('{');
		/*cout << s.top() << endl;*/
		s.push('{');
		/*cout << s.top() << endl;*/
		s.push('[');
		/*cout << s.top() << endl;*/
		s.push(']');
		/*cout << s.top() << endl;*/
		s.push('(');
		/*cout << s.top() << endl;*/

		if (s.check('{') == true)
			cout << "Text true" << endl;
		else
		{
			cout << "False" <<endl;
		}
	}break;

	case 7: {
		/*stack<stack<int>> s;
		stack<int> in_s;*/
		Stack <Stack<int>>s;
		Stack<int> in_s;
		int a[9] = { 8,1,2,3,4,5,2,4,9 };
		s.push(in_s);
		s.top().push(a[0]);
		for (int i = 1;i < 9;i++) {
			if (s.top().top() < a[i])
				s.top().push(a[i]);
			else
			{
				/*stack<int> in_s;*/
				s.push(in_s);
				s.top().push(a[i]);
			}
		}
		while (!s.empty()) {
			while (!s.top().empty()) {
				cout << s.top().top() << "\t";
				s.top().pop();
			}
			cout << endl;
			s.pop();
		}
		
	}break;

		/*8. –азработать класс дл€ работы со стеком.
		Ёлемент стека Ц символ. »спользовать стек дл€ проверки
		правильности расстановки скобок трех типов (круглых,
		квадратных и фигурных) во введенном выражении.*/
		case 8:{
			char s[] = "{hdgf(ksf)kdjk[dkj()]}";
			Stack<char> s1;//for ()
			Stack<char> s2;//for []
			Stack<char> s3;//for {}
			for (int i = 0; i < strlen(s);i++) {
				if (s[i] == '(')
					s1.push('(');
				else if (s[i] == '[')
					s2.push('[');
				else if (s[i] == '{')
					s3.push('{');
				else if (s[i] == ')') {
					if (!s1.empty())
						s1.pop();
					else
					{
						break;
						cout << "Incorrect brackets" << endl;
					}
				}
				else if (s[i] == ']') {
					if (!s2.empty())
						s2.pop();
					else
					{
						break;
						cout << "Incorrect brackets" << endl;
					}
				}
				else if (s[i] == '}') {
					if (!s3.empty())
						s3.pop();
					else
					{
						break;
						cout << "Incorrect brackets" << endl;
					}
				}
			}
			if (s1.empty() && s2.empty() && s3.empty())
				cout << "correct" << endl;
			else 
				cout<< "incorrect" << endl;
		}break;
	}
	system("pause");
	return 0;
}