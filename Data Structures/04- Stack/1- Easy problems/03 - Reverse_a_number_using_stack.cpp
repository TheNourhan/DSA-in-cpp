#include <iostream>
#include <cassert>
#include <climits>
#include<algorithm>
#include<string>
#include <sstream>
using namespace std;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		int data { };
		Node* next { };
		Node(int data) :
				data(data) {
		}
	};

	Node *head { };		// Points to Top

public:
	~Stack() {
		while (!isEmpty())
			pop();
	}
	void display() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void push(int value) {
		// By design: always new node = head
		// Great match with stack!
		Node* item = new Node(value);
		item->next = head;
		head = item;

		// Tip: This code works as long as machine has more RAM
		// In industry: You may check if return is null (can't create) or not.
	}

	int pop() {
		assert(!isEmpty());
		int element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	int peek() {
		assert(!isEmpty());
		int element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}



};

int reverse_num(int num){
	    string n = to_string(num);
	    reverse(n.begin(),n.end());
	    int num_int;
	    stringstream s;
	    s<<n;
	    s>>num_int;

	    Stack stk;

        while(num_int){
            stk.push(num_int%10);
            num_int/=10;
        }
        string number="";
        while (!stk.isEmpty()){
            string rev = to_string(stk.pop());
            number+=rev;
        }
        int res;
        stringstream ss;
	    ss<<number;
	    ss>>res;
	    return res;
}

int main() {

    cout<<reverse_num(1234)<<"\n";
    cout<<reverse_num(123456)<<"\n";


	return 0;
}

