#include <iostream>
#include <cassert>
#include <climits>
#include <algorithm>
using namespace std;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		string data { };
		Node* next { };
		Node(string data) :
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

	void push(string value) {
		// By design: always new node = head
		// Great match with stack!
		Node* item = new Node(value);
		item->next = head;
		head = item;

		// Tip: This code works as long as machine has more RAM
		// In industry: You may check if return is null (can't create) or not.
	}

	string pop() {
		assert(!isEmpty());
		string element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	string peek() {
		assert(!isEmpty());
		string element = head->data;
		return element;
	}

	bool isEmpty() {
		return !head;
	}


};

string reverse_subwords(string line){
        reverse(line.begin(),line.end());
        int first=0;
        Stack stk;
        for(int i=0;i<line.size();i++){
            if(i==line.size()-1){
                stk.push(line.substr(first)+' ');
                break;
            }
            if(line[i]==' '){
                stk.push(line.substr(first,(i-first)+1));
                first = i+1;
            }
        }
        string word;
        while (!stk.isEmpty()){
            word += stk.peek() ;
            stk.pop();
        }
        return word;
}

int main() {s
	string line;
	getline(cin, line);

	cout<<reverse_subwords(line)<<"\n";

	return 0;
}

