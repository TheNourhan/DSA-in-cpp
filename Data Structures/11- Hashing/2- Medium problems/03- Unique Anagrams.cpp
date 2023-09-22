#include<bits/stdc++.h>
using namespace std;

int count_anagram_substrings(const string &str){

	unordered_set<string> s;
	for (int start = 0; start < (int) str.size(); ++start) {
		for (int end = start; end < (int) str.size(); ++end) {
            string word = str.substr(start, end - start + 1);
            sort(word.begin(),word.end());
			s.insert(word);
		}
	}
	return s.size();
}

int main(){
    cout << count_anagram_substrings("abba") << "\n";		// 6
	cout << count_anagram_substrings("aaaaa") << "\n";		// 5
	cout << count_anagram_substrings("abcba") << "\n";		// 9
	cout << count_anagram_substrings("aabade") << "\n";		// 17

    return 0;
}

