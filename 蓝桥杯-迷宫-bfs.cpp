#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
	int x;
	int y;
}_start, _end;     //_startΪ������꣬_endΪ�յ�����

int step;
char ans[1000] = { 0 };
const char dir[] = { 'D', 'L', 'R', 'U' };   //�ֵ�˳��
const int dx[] = { 1, 0, 0, -1 };    //��������
const int dy[] = { 0, -1, 1, 0 };
const int maxn = 100;
int maze[maxn][maxn];
int vis[maxn][maxn];
queue<node> que;       //node���Ͷ���
int row, col;

bool check(int x, int y) {
	if (x<0 || x>row - 1 || y<0 || y>col - 1 || maze[x][y] == 1 || vis[x][y] != 0) {
		return false;        //if����ڣ���֤x��y�����Թ����Ҳ���ǽ��δ�߹�
	}
	return true;
}

void bfs() {
	que.push(_start);      //������������
	while (!que.empty()) {
		node far;      //���常�ڵ�
		far = que.front();    //����һ��Ԫ����Ϊ���ڵ�
		que.pop();
		if (far.x == _end.x && far.y == _end.y) {
			break;     //�����յ��˳�ѭ��
		}
		for (int i = 0; i < 4; i++) {
			node next;         //������һ����node����next
			next.x = far.x + dx[i];       //���ĸ�������̽
			next.y = far.y + dy[i];
			if (check(next.x, next.y)) {
				que.push(next);      //�����ͨ���򽫴˽ڵ���ӣ��ٳ���ʱ������Ϊ���ڵ���
				vis[next.x][next.y] = vis[far.x][far.y] + 1;
			}        //vis������˱�����߹���Ҳ��¼�˲���	
		}
	}
}

//ͨ�����ѽ�·�������ʾ����������������ĸ��ʾ
void dfs(int x, int y, int step) {
	if (x == _start.x && y == _start.y) {   //���������
		return;
	}
	for (int i = 0; i < 4; i++) {    //���ĸ�������̽
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (vis[nx][ny] == vis[x][y] - 1) {   //����һ�������vis�������ֱȵ�ǰС1
			ans[step] = dir[3 - i];       //��¼�𰸣���Ϊ�Ǵ��յ㷵�أ������Ҫ��֤�ֵ�����С����Ҫ���ű�ʾ��
			dfs(nx, ny, step + 1);
			break;   //�ҵ��˷��ϵķ����������Ѱ�����������ˣ�ֱ��break
		}
	}
}

void output() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%-3d", vis[i][j]);
		}
		cout << endl;
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> maze[i][j];
		}
	}
	_start.x = _start.y = 0;
	_end.x = row - 1;
	_end.y = col - 1;
	vis[0][0] = 1;     //�˴����뽫�����Ϊ1������check�������ʱ����vis[0][0]Ϊ0���������
	bfs();
	output();
	dfs(_end.x, _end.y, 0);
	_strrev(ans);    //�����������������Ϊ��㵽�յ��·��
	cout << ans << endl;
	return 0;
}