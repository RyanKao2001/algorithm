#include <bits/stdc++.h>

using namespace std;

long long int memo[100];

long long int fun(int n) {
	if (n == 0 || n == 1) {
		return 1;        //��ֹ����
	}
	if (memo[n] != -1) {   //���ڵݹ�ʱ���ֵ�ǰֵ�Ѿ����������ֱ�ӷ��ش�ֵ
		return memo[n];
	}
	memo[n] = fun(n - 1) + fun(n - 2);   //��������������
	return memo[n];
}

int main() {
	int n;
	cin >> n;
	memset(memo, -1, sizeof(memo));    //��ʼ��������Ϊ-1
	memo[0] = 1;     //fib��1�͵�2����1
	memo[1] = 1;
	long long int ans = fun(n);
	cout << ans;
	return 0;
}