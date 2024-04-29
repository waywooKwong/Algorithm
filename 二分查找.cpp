#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    vector<int> arr;
    int num;
    while (cin >> num)
    {
        arr.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }
    int target;
    cin >> target;
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = floor((l + r) / 2);
        if (arr[m] == target)
        {
            cout << m;
            return 0;
        }
        else if (arr[m] > target)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << -1;
    return 0;
}