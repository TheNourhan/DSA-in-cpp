#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidity(int a, int b, int c){
        if (a + b <= c || a + c <= b || b + c <= a)
            return false;
        else
            return true;
    }
    int largestPerimeter(vector<int>& nums){
            sort(nums.begin(), nums.end());
            int res[(int)nums.size()];
            int mx=0;
            for(int i=0;i<(int)nums.size()-2;++i){
                if(checkValidity(nums[i],nums[i+1],nums[i+2])){
                    res[i]= nums[i]+nums[i+1]+nums[i+2];
                    mx = max(res[i],mx);
                }
            }
            return mx;
    }
};

int main()
{

    vector<int>arr = {3,2,3,4};
    cout<<largestPerimeter(arr)<<"\n";

	return 0;
}



