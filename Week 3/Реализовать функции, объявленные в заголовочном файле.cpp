#include "sum_reverse_sort.h"
#include <vector>
#include <algorithm>
#include <iostream>

int Sum(int a, int b) {
	return a + b;
}

string Reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}