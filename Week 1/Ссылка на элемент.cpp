#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <map>
using namespace std;
template <typename Key, typename Value> Value& GetRefStrict(const map<Key, Value>& m, Key key);

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key key) {
    if (m.find(key) == m.end()) {
        throw runtime_error("");
    }
    Value& link = m[key];
    return link;
}

int main()
{
    map<int, string> m = { {0, "value"} };
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // output newvalue
    return 0;
}
