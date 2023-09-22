#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int top { };
	int* array { };
public:
	Stack(int size) : size(size), top(-1) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(int x) {
		assert(!isFull());
		array[++top] = x;
	}

	int pop() {
		assert(!isEmpty());
		return array[top--];
	}

	int peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};

bool left_or_right(char c){
    if(c=='(' || c=='[' || c=='{'){
        return 0;
    }
    return 1; // Right
}
int is_true(char c){
    if(c=='(' || c==')'){
        return 0;
    }else if(c=='[' || c==']'){
        return 1;
    }else{
        return 2;
    }
}
bool isValid(string s) {
    Stack stk((int)s.size());

    for(int i=0;i<(int)s.size();i++){
        if(stk.isEmpty() && left_or_right(s[i])){ // Right and empty stack
            return false;
        }
        if(left_or_right(s[i]) && is_true(s[i])==is_true(stk.peek())){ // Right and True
            if(stk.isEmpty()){
                return false;
            }
            stk.pop();
        }else if(left_or_right(s[i]) && is_true(s[i])!=is_true(stk.peek())){ // Right and False
            return false;
        }else{
            stk.push(s[i]);
        }
    }
    if(stk.isEmpty()){
        return true;
    }
    return false;
}

int main(){

    cout << isValid("(())") << "\n";		// 1
	cout << isValid("(()[()])") << "\n";	// 1
	cout << isValid("(][)") << "\n";		// 0
	cout << isValid("(()") << "\n";		    // 0

	return 0;
}
/*
    leetCode 20:

    https://leetcode.com/problems/valid-parentheses/
*/
