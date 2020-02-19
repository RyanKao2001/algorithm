/* 对给定的字符串，本题要求你输出最长对称子串的长度。
例如，给定Is PAT&TAP symmetric?，最长对称子串为s PAT&TAP s，
于是你应该输出11。
 
输入格式：

输入在一行中给出长度不超过1000的非空字符串。
输出格式：
在一行中输出最长对称子串的长度。

输入样例：
Is PAT&TAP symmetric?

输出样例：
11
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2100;

char str1[maxn], str2[maxn];
int len1, len2, p[maxn], ans;

void init() {
	str2[0] = '$';
	str2[1] = '#';
	for (int i = 0; i < len1; i++) {
		str2[i * 2 + 2] = str1[i];
		str2[i * 2 + 3] = '#';
	}
	len2 = len1 * 2 + 2;
	str2[len2] = '@';
}

void manacher() {
	int id = 0, max = 0;
	for (int i = 0; i < len2; i++) {
		if (max > i) {
			p[i] = min(p[2 * id - i], max - i);
		}
		else {
			p[i] = 1;
		}
		for (; str2[i + p[i]] == str2[i - p[i]]; p[i]++);
		if (p[i] + i > max) {
			max = p[i] + i;
			id = i;
		}
	}
}

int main() {
	cin.getline(str1, maxn);
	len1 = strlen(str1);
	init();
	manacher();
	ans = 0;
	for (int i = 0; i < len2; i++) {
		ans = max(ans, p[i]);
	}
	cout << ans - 1 << endl;
	return 0;
}