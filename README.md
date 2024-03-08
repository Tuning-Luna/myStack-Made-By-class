用C++里面的class设计了stack（栈）数据结构，分为用数组设计和用链表设计。

下面是设计思路，最后面的是源代码

**设计思路**

- 数组：`_top`既表示头元素，又能表示元素的数据，但没有元素在栈里时，`_top`为-1，无法通过下标的方式索引数据，而`_top+1`的值又可以表示元素
- 链表：创建Stack的**第一个节点创建在栈区**，表示**其的特殊性**，第一个节点的`_val`存放数据元素**的个数**，`_next`表示指向下一个数据。而之后的结点都用`new`开辟到堆区，存放`Stack`元素。

# 源码

## 用数组

`````c++
#include <iostream>
#include<cassert>
using namespace std;
const int MAX_SIZE = 100;
class Stack
{
	int _vals[MAX_SIZE];
	int _top;

public:
	Stack()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
			_vals[i] = 0;
		_top = -1;//空栈默认-1
	}

	~Stack() {}

	Stack(const Stack& s)
	{
		this->_top = s._top;

		for (int i = 0; i <= s._top; ++i)
			this->_vals[i] = s._vals[i];
	}

	void push(int elem)
	{
		if (this->_top == MAX_SIZE - 1)
		{
			cout << "栈满！" << endl;
			return;
		}
		else
		{
			++this->_top;
			this->_vals[this->_top] = elem;
		}
	}

	void pop()
	{
		if (this->empty())
		{
			cout << "空栈！" << endl;
			return;
		}
		else
		{
			--this->_top;
		}
	}

	int size()
	{
		return this->_top + 1;
	}

	int top()
	{
		if (this->empty())
		{
			cout << "空栈！" << endl;
			assert(0);
		}
		return this->_vals[this->_top];
	}

	bool empty()
	{
		return _top == -1;
	}

	void clear()
	{
		this->_top = -1;
	}
};
int main()
{
	Stack s;
	//**********test here**********
    
    
    //**********end**********
	return 0;
}
`````

## 用链表（栈链）

`````c++
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
`````

