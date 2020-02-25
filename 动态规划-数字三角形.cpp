/*
给定一个由 n行数字组成的数字三角形如下图所示。试设计一个算法，计算出从三角形
的顶至底的一条路径(每一步可沿左斜线向下或右斜线向下)，使该路径经过的数字总和最大。

输入格式:
输入有n+1行：
第 1 行是数字三角形的行数 n，1<=n<=100。
接下来 n行是数字三角形各行中的数字。所有数字在0..99 之间。
输出格式:
输出最大路径的值。
输入样例:
在这里给出一组输入。例如：
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出样例:
在这里给出相应的输出。例如：
30
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[50][50];   //记录状态的数组
int num[50][50];

void fun() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = num[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}             //状态转移方程
	}
	cout << dp[0][0];    //一直递推到顶端，dp[0][0]就是答案
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num[i][j];
		}
	}
	fun();
	return 0;
}