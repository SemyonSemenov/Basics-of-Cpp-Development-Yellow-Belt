#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <map>
using namespace std;

// Preliminary declaration of template functions
template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);
template <typename Type> vector<Type> operator * (const vector<Type>& v1, const vector<Type>& v2);
template <typename Key, typename Value> map<Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2);
template <typename T> T Sqr(T x);

// Declare template functions
template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p2.second * p2.second;
    return make_pair(f, s);
}

template <typename Type>
vector<Type> operator * (const vector<Type>& v1, const vector<Type>& v2) {
    vector<Type> res;
    for (int i = 0; i < v1.size(); ++i) {
        res.push_back(v1[i] * v2[i]);
    }
    return res;
}

template <typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2) {
    map<Key, Value> res;
    for (auto& el : m1)
    {
        res[el.first] = el.second * m2.at(el.first);
    }
    return res;
}

template <typename T>
T Sqr(T x) {
    return x * x;
}

int main()
{
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
