#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }

    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    auto first_third = elements.begin() + range_length / 3;
    auto second_third = elements.begin() + 2 * range_length / 3;

    MergeSort(elements.begin(), first_third);
    MergeSort(first_third, second_third);
    MergeSort(second_third, elements.end());

    vector<typename RandomIt::value_type> interim_result;
    merge(elements.begin(), first_third, first_third, second_third, back_inserter(interim_result));

    merge(interim_result.begin(), interim_result.end(), second_third, elements.end(), range_begin);
}

int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
