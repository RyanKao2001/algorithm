/* �Ը������ַ���������Ҫ���������Գ��Ӵ��ĳ��ȡ�
���磬����Is PAT&TAP symmetric?����Գ��Ӵ�Ϊs PAT&TAP s��
������Ӧ�����11��
 
�����ʽ��

������һ���и������Ȳ�����1000�ķǿ��ַ�����
�����ʽ��
��һ���������Գ��Ӵ��ĳ��ȡ�

����������
Is PAT&TAP symmetric?

���������
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