#include<iostream>
#include<cstring>	// memset
#include<vector>
#include<string>
#include <utility>
#include<sstream>
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

	void insert(string str, int idx = 0) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}

	string prefix_exist(string str, int idx = 0) {
	    trie* cur = this;
		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch]){
                break;
            }

            if(cur->child[ch]->isLeaf){
                return str.substr(0,idx+1);
            }
			cur = cur->child[ch];
		}
		return str;
	}
};

class Solution {
public:
    // Given a string, split to vector of strings
	vector<string> split(string str) {
		vector<string> ret;
		string word;
		istringstream iss(str);

		while (iss >> word)
			ret.push_back(word);
		return ret;
	}
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie root;
        for(int i=0;i<(int)dictionary.size();++i){
            root.insert(dictionary[i]);
        }
        vector<string>word = split(sentence);
        string res;
        for(int i=0;i<(int)word.size();++i){
            if(i){
                res += " ";
            }
            res += root.prefix_exist(word[i]);
        }
        return res;
    }
};

int main() {

    Solution test;
    vector<string>dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout<< test.replaceWords(dictionary, sentence);

	return 0;
}
/*
    leetCode 648:
    https://leetcode.com/problems/replace-words/
*/
