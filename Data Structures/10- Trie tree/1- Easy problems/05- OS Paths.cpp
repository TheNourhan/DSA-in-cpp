#include<iostream>
#include<cstring>	// memset
#include<vector>

using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR];
	bool isLeaf { };

public:
	trie() {
		// set an array to 0s. Here pointers to null
		memset(child, 0, sizeof(child));
	}

	void insert(const vector<string> &path){
        for(int i=0;i<(int)path.size();++i){
            trie* cur = this;

            for(int idx=0;idx<(int)path[i].size();++idx){
                int ch = path[i][idx] - 'a';
                if (cur->child[ch] == 0){
                    cur->child[ch] = new trie();
                }
                cur = cur->child[ch];
            }
            cur->isLeaf = true;
        }
	}

	bool subpath_exist(const vector<string> &path){//MY SOLUTION

        trie* cur;
        for(int i=0;i<(int)path.size();++i){
            cur = this;

            for(int idx=0; idx<(int)path[i].size();++idx){
                int ch = path[i][idx] - 'a';
                if (!cur->child[ch])
                    return false;	// such path don't exist

                cur = cur->child[ch];
            }
        }
        return cur->isLeaf;
	}
};

void test(){
    trie tree;

	vector<string> path;

	path = {"home", "software", "eclipse"};
	tree.insert(path);

	path = {"home", "software", "eclipse", "bin"};
	tree.insert(path);

	path = {"home", "installed", "gnu"};
	tree.insert(path);

	path = {"user", "mostafa", "tmp"};
	tree.insert(path);

	path = {"user", "mostafa", "tmp"};
	cout << tree.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa"};
	cout << tree.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa", "private"};
	cout << tree.subpath_exist(path) << "\n"; // 0
}

int main() {
	test();

	return 0;
}
