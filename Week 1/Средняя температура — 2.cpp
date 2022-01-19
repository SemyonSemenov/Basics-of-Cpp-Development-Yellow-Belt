#include <iostream>
#include <vector>

using namespace std;

int main()
{   
    int64_t N;
    cin >> N;
    int64_t avg = 0;

    vector<int64_t> nums;
    for (int64_t i = 0; i < N; ++i) {
        int64_t num;
        cin >> num;
        avg += num;

        nums.push_back(num);
    }
    avg /= N;

    int64_t days = 0;
    for (int64_t i = 0; i < nums.size(); ++i) {
        if (nums[i] > avg) {
            days += 1;
        }
    }
    cout << days << endl;

    if (days > 0) {
        
        for (int64_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > avg) {
                cout << i << " ";
            }
        }
    }
    return 0;
}