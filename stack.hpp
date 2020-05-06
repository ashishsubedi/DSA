#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
	int top ;
	vector<T> stack;
	

  public:
	Stack(){
		top = -1;
	}
	Stack(vector<T> datas){
		top = datas.size()-1;
		stack = datas;
	}
	
	void push(T data){
		stack.push_back(data);
		top++;
	}
	T pop(){
		top--;
		return stack.pop_back();
	}
	T peek(){
		return stack[top];
	}
	int size(){
		return stack.size();
	}

};