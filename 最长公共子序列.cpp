//最长公共子序列
#include<iostream>
#include<string>
using namespace std;

int cnt = 0;
void Sequence(int** b, int i, int j, string x, string y) {
	if (i == 0 || j == 0) {
		return;
	}
	if (b[i][j] == 0) {
		Sequence(b, i - 1, j - 1, x, y);
		//cout << x[i - 1];
		cnt++;
	}
	else if (b[i][j] == 1) {
		Sequence(b, i - 1, j, x, y);
	}
	else {
		Sequence(b, i, j - 1, x, y);
	}
}

int main() {
	string x, y;
	cin >> x >> y;
	int xlen = x.length();
	int ylen = y.length();

	int** c = new int* [xlen + 1];
	int** b = new int* [xlen + 1];
	for (int i = 0; i <= xlen; i++) {
		c[i] = new int[ylen + 1];
		b[i] = new int[ylen + 1];
	}
	for (int i = 0; i <= xlen; i++) {
		c[i][0] = 0;
		b[i][0] = 0;
	}
	for (int j = 0; j <= ylen; j++) {
		c[0][j] = 0;
		b[0][j] = 0;
	}
	// 0-> ↖  1->↑  2->←
	for (int i = 1; i <= xlen; i++) {
		for (int j = 1; j <= ylen; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 2;
			}
		}
	}
	Sequence(b, xlen, ylen, x, y);
	cout << cnt;
	for (int i = 0; i <= xlen; i++) {
		delete[] c[i];
		delete[] b[i];
	}
	delete[] c;
	delete[] b;

	return 0;
}
