#include<iostream>
using namespace std;

int knapback(int n, int v, int* val, int* vol) {
    int** a = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        a[i] = new int[v + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else if (vol[i - 1] > j)
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(a[i - 1][j], a[i - 1][j - vol[i - 1]] + val[i - 1]);
        }
    }

    int result = a[n][v];
    for (int i = 0; i < n + 1; i++) {
        delete[] a[i];
    }
    delete[] a;

    return result;
}

int main()
{
    int n, v;
    cin >> n >> v;

    int* vol = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++)
    {
        int volume, value;
        cin >> volume >> value;
        vol[i] = volume;
        val[i] = value;
    }

    cout << knapback(n, v, val, vol) ;

    delete[] vol;
    delete[] val;
    return 0;
}