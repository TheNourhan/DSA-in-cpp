#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &nums) {
	for (int i=1;i<(int)nums.size();i++) {
        for(int j=i; j-1>=0 && nums[j]>nums[j-1];--j){
            swap(nums[j],nums[j-1]);
        }
	}
}

vector<int> read_vector() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	return v;
}

int main() {
	vector<int> v = read_vector();
	insertion_sort(v);

	for (int i = 0; i < (int) v.size(); ++i) {
		cout << v[i] << " ";
	}

	return 0;
}


