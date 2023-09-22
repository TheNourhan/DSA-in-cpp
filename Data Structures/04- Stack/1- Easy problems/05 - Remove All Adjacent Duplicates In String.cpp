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
string removeDuplicates(string s) {
        Stack stk;
        char c;

        for(int i=0;i<(int)s.size();i++){
            if(i>0 && !stk.isEmpty()){
                c=stk.peek();// befor top
            }
            stk.push(s[i]);
            if(stk.peek()==c && i>0){
                stk.pop();
                stk.pop();
                c=' ';
            }
        }
        string word="";
        while (!stk.isEmpty()){
            word += stk.pop();
        }
        reverse(word.begin(),word.end());

        return word;
}

int main() {

    cout<<removeDuplicates("abbaca")<<"\n";
    cout<<removeDuplicates("azxxzy")<<"\n";
    cout<<removeDuplicates("aaaaaa")<<"\n";


	return 0;
}
/*
    leetCode 1047:

    https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

