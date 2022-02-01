#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

void PrintVector(const vector<int>& nums) {
    for (auto& num : nums) {
        cout << num << " ";
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums;
    for (int i = 0; i < N; ++i) {
        nums.push_back(N - i);
    }
    do {
        PrintVector(nums);
        cout << endl;
    } while (prev_permutation(nums.begin(), nums.end()));
}