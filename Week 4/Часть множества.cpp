#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result(0);
    auto iter = find_if(elements.begin(), elements.end(), [border](const T& el) {return el > border; });
    for (auto it = iter; it != end(elements); ++it) {
        result.push_back(*it);
    }
    return result;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}