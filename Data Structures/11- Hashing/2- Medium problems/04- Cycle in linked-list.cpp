#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data {};
	Node* next {};
	Node(int data) : data(data) {}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
public:

	void print() {
		// DON'T change head itself.
		// 		You will lose it
		Node* temp_head = head;
		while(temp_head != nullptr) {
			cout<<temp_head->data<<" ";
			temp_head = temp_head->next;
		}
		cout<<"\n";
	}

	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}

	void create_cycle() {
		for (int i = 0; i < 4; ++i)
			insert_end(i);
		Node* now = tail;
		for (int i = 0; i < 3; ++i)
			insert_end(14 + i);
		tail->next = now;// cycle
	}

	void remove_cycle(){
        unordered_set<Node*>visited;

        for(Node *prev=nullptr,*cur=head;cur;prev=cur,cur=cur->next){
            if(visited.count(cur)){
                prev->next=nullptr;
                tail=prev;
                break;
            }
            visited.insert(cur);
        }
	}

	// This code has memory leak, as we did not free memory
};


int main(){
    LinkedList lst;
	lst.create_cycle();
	lst.remove_cycle();
	lst.print();
	// 0 1 2 3 14 15 16

    return 0;
}

