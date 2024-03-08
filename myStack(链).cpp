#include <iostream>
#include<cassert>
using namespace std;
const int MAX_SIZE = 100;
class Stack
{
	int _val;
	Stack* _next;
	//第一个结点的数据存放元素个数，
	// this->_next指向栈顶(第一个元素)
public:
	Stack()
	{
		_val = 0;
		_next = nullptr;
	}

	~Stack()
	{

	}

	void push(int elem)
	{
		if (this->_val == MAX_SIZE)
		{
			cout << "满栈！" << endl;
			return;
		}
		else
		{
			Stack* p = new Stack;
			p->_val = elem;
			if (this->_val == 0)
			{
				this->_next = p;
				p->_next = nullptr;
				++this->_val;
				return;
			}
			Stack* temp = this->_next;
			this->_next = p;
			p->_next = temp;
			++this->_val;
			return;
		}
	}

	void pop()
	{
		if (this->_val == 0)
		{
			cout << "空栈！" << endl;
			return;
		}
		else
		{
			Stack* p = this->_next;
			this->_next = p->_next;
			delete p;
			--this->_val;
			return;

		}
	}

	int size()
	{
		return this->_val;
	}

	int top()
	{
		if (this->_val == 0)
		{
			cout << "空栈！" << endl;
			assert(0);
		}
		return this->_next->_val;
	}

	bool empty()
	{
		return (this->_val == 0);
	}

	void clear()
	{
		Stack* p = this->_next;
		while (p != nullptr)
		{
			Stack* temp = p;
			p = p->_next;
			delete temp;
			cout << "delete" << endl;
		}
		this->_val = 0;
		this->_next = nullptr;

	}
};
int main()
{
	//**********test**********
	Stack s;

	
	s.clear();
	//**********end**********
	return 0;
}