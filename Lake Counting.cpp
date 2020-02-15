/*
Lake Counting (POJ No.2386)
��һ����СΪN*M��԰�ӣ���������ˮ������ͨ�Ļ�ˮ����Ϊ��������һ��ġ�
�����԰�����ܹ��ж���ˮ�ݣ�������ָͨ������ͼ�����W��*�Ĳ��֣�

***
*W*
***
����������N��M <= 100��

�������룺
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.��
���������
3
*/
#include <iostream>
#define MAXN 110

using namespace std;

int n;
int m;
int ans;
int vis[MAXN][MAXN] = { 0 };
char feild[MAXN][MAXN];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int x, int y);
bool check(int x, int y);

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> feild[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (feild[i][j] == 'W' && vis[i][j] != 1) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
}

void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx, ny)) {
			vis[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	if (feild[x][y] == '.') {
		return false;
	}
	if (vis[x][y] == 1) {
		return false;
	}
	return true;
}