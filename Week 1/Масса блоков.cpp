#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    uint64_t N, R;
    cin >> N >> R;

    uint64_t M = 0;
    for (int i = 0; i < N; ++i) {
        uint64_t a, b, c;
        cin >> a >> b >> c;
        M += a * b * c * R;
    }
    cout << M << endl;
    return 0;
}