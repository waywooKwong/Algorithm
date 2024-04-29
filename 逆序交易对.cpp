#include <iostream>
#include <vector>
using namespace std;

// 归并排序的合并操作，并计算逆序交易对数量
int merge(vector<int>& prices, int left, int mid, int right) {
    int count = 0;

    vector<int> temp(right - left + 1); // 临时数组存放排序后的结果
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (prices[i] > prices[j]) {
            // 若 prices[i] 大于 prices[j]，则构成逆序交易对，计算数量
            count += mid - i + 1;
            temp[k++] = prices[j++];
        }
        else {
            temp[k++] = prices[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = prices[i++];
    }

    while (j <= right) {
        temp[k++] = prices[j++];
    }

    // 将临时数组中的结果复制回原数组
    for (int p = 0; p < k; p++) {
        prices[left + p] = temp[p];
    }

    return count;
}

// 归并排序并计算逆序交易对数量
int mergeSort(vector<int>& prices, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    // 分别对左右两部分进行归并排序，并累加逆序交易对数量
    int count = mergeSort(prices, left, mid) + mergeSort(prices, mid + 1, right);

    // 合并左右两部分，并计算逆序交易对数量
    count += merge(prices, left, mid, right);

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int count = mergeSort(prices, 0, n - 1);
    cout << count << endl;

    return 0;
}
