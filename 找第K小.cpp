#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int pos(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int devideSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = pos(arr, left, right);
        if (pivotIndex == k) {
            return arr[k];
        }
        else if (pivotIndex < k) {
            return devideSelect(arr, pivotIndex + 1, right, k);
        }
        else {
            return devideSelect(arr, left, pivotIndex - 1, k);
        }
    }
}

int main() {
    string line;
    getline(cin, line);
    vector<int> arr;
    istringstream iss(line);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }

    int k;
    cin >> k;

    int result = devideSelect(arr, 0, arr.size() - 1, k - 1);
    cout << result << endl;

    return 0;
}