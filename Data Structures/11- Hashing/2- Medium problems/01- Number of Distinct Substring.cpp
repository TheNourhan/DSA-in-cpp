#include<bits/stdc++.h>
using namespace std;
// O(L^3)
int count_unique_substrings(const string &str){
    unordered_set<string>num_unique_substring;
    for(int i=0;i<(int)str.size();++i){
        for(int j=i;j<(int)str.size();++j){
            num_unique_substring.insert(str.substr(i,j-i+1));
        }
    }
    return num_unique_substring.size();
}
int main(){
    cout<<count_unique_substrings("aaaaa")<<"\n";//5
    cout<<count_unique_substrings("aaaba")<<"\n";//11
    cout<<count_unique_substrings("abcdef")<<"\n";//21


    return 0;
}

