#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[50][50];
int memo[50][50];

int fun(int i, int j) {
	if (i == n) {
		return num[i][j];
	}
	if(memo[i][j] == -1)
		memo[i][j] = num[i][j] + max(fun(i + 1, j), fun(i + 1, j + 1));
	return memo[i][j];
}

int main() {
	cin >> n;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num[i][j];
		}
	}
	cout << fun(0, 0);
	return 0;
}