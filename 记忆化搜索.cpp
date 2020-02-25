#include <bits/stdc++.h>

using namespace std;

long long int memo[100];

long long int fun(int n) {
	if (n == 0 || n == 1) {
		return 1;        //终止条件
	}
	if (memo[n] != -1) {   //若在递归时发现当前值已经计算过，则直接返回此值
		return memo[n];
	}
	memo[n] = fun(n - 1) + fun(n - 2);   //将计算结果存起来
	return memo[n];
}

int main() {
	int n;
	cin >> n;
	memset(memo, -1, sizeof(memo));    //初始记忆数组为-1
	memo[0] = 1;     //fib第1和第2项是1
	memo[1] = 1;
	long long int ans = fun(n);
	cout << ans;
	return 0;
}