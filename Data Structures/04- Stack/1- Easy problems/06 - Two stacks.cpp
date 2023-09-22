#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int top_S1 { };
	int top_S2 { };
	int* array { };
public:
	Stack(int size) : size(size), top_S1(-1), top_S2(size) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(int id, int x) {
		assert(!isFull());
		if(id==1){              // stack 1
          array[++top_S1] = x;
		}else{                  // stack 2
            array[--top_S2] = x;
		}
	}

	int pop(int id) {
		assert(!isEmpty());
		if(id==1){
            return array[top_S1--];
		}else{
		    return array[top_S2++];
		}
	}

	int peek(int id) {
		assert(!isEmpty());
		if(id==1){
            return array[top_S1];
		}else{
            return array[top_S2];
		}
	}

	bool isFull(){
		return top_S1==size-1 || top_S2==0 || top_S2-top_S1==1;
	}

	int isEmpty() {
		return top_S1 == -1 && top_S2==size;
	}

	void display() {
	    // stack 1
		for (int i = top_S1; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
		// stack 2
		for (int i = top_S2; i < size; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
};

int main() {

    Stack stk(10);
	stk.push(2, 5);
	stk.push(2, 6);
	stk.pop(2);
	stk.push(2, 7);
	stk.push(2, 9);

	stk.push(1, 4);
	stk.push(1, 6);
	stk.push(1, 8);
	stk.display();

	return 0;
}
