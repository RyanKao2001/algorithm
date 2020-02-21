#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
	int x;
	int y;
}_start, _end;     //_start为起点坐标，_end为终点坐标

int step;
char ans[1000] = { 0 };
const char dir[] = { 'D', 'L', 'R', 'U' };   //字典顺序
const int dx[] = { 1, 0, 0, -1 };    //方向向量
const int dy[] = { 0, -1, 1, 0 };
const int maxn = 100;
int maze[maxn][maxn];
int vis[maxn][maxn];
queue<node> que;       //node类型队列
int row, col;

bool check(int x, int y) {
	if (x<0 || x>row - 1 || y<0 || y>col - 1 || maze[x][y] == 1 || vis[x][y] != 0) {
		return false;        //if语句内：保证x，y处于迷宫内且不穿墙，未走过
	}
	return true;
}

void bfs() {
	que.push(_start);      //将起点坐标入队
	while (!que.empty()) {
		node far;      //定义父节点
		far = que.front();    //出队一个元素作为父节点
		que.pop();
		if (far.x == _end.x && far.y == _end.y) {
			break;     //到达终点退出循环
		}
		for (int i = 0; i < 4; i++) {
			node next;         //定义下一坐标node类型next
			next.x = far.x + dx[i];       //向四个方向试探
			next.y = far.y + dy[i];
			if (check(next.x, next.y)) {
				que.push(next);      //若检查通过则将此节点入队，再出队时就是作为父节点了
				vis[next.x][next.y] = vis[far.x][far.y] + 1;
			}        //vis数组除了标记已走过，也记录了步数	
		}
	}
}

//通过深搜将路径倒序表示出来，此题用了字母表示
void dfs(int x, int y, int step) {
	if (x == _start.x && y == _start.y) {   //到达了起点
		return;
	}
	for (int i = 0; i < 4; i++) {    //向四个方向试探
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (vis[nx][ny] == vis[x][y] - 1) {   //若下一个方向的vis数组数字比当前小1
			ans[step] = dir[3 - i];       //记录答案（因为是从终点返回，因此若要保证字典序最小，需要倒着表示）
			dfs(nx, ny, step + 1);
			break;   //找到了符合的方向就无需再寻找其他方向了，直接break
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
	vis[0][0] = 1;     //此处必须将起点设为1，否则check函数检查时发现vis[0][0]为0会向起点走
	bfs();
	output();
	dfs(_end.x, _end.y, 0);
	_strrev(ans);    //将答案数组逆序，逆序后即为起点到终点的路径
	cout << ans << endl;
	return 0;
}