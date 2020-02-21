#include <iostream>
#include <cstdio>

using namespace std;

int row, col;
const int maxn = 110;
int chess[maxn][maxn];
int total;
bool is_put = false;
int last_case[maxn][maxn];
const int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int k;

void output() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j == 0) printf("%d", chess[i][j]);
			else printf(" %d", chess[i][j]);
		}
		cout << endl;
	}
}

bool check(int x, int y) {
	if (x < 0 || x >row-1 || y < 0 || y>col-1 || chess[x][y] != 0) {
		return false;
	}
	return true;
}

void dfs(int x, int y, int step) {
	if (is_put) return;
	if (step == row * col + 1) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				last_case[i][j] = chess[i][j];
			}
		}
		total++;
		if (total == k) {
			output();
			is_put = true;
		}
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx, ny)) {
			chess[nx][ny] = step;
			dfs(nx, ny, step + 1);
			chess[nx][ny] = 0;
		}
	}
}

int main() {
	while (scanf_s("%d %d %d", &row, &col, &k) != EOF) {
		chess[0][1] = 1;
		dfs(0, 1, 2);
		if (!is_put && total != 0) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (j == 0) printf("%d", last_case[i][j]);
					else printf(" %d", last_case[i][j]);
				}
				cout << endl;
			}
		}
		if (total == 0) {
			cout << "impossible" << endl;
		}
	}
	return 0;
}