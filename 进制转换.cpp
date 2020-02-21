#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main() {
	int k = 0, n, m;
	cout << "十进制转：";
	cin >> n;
	cout << "十进制数：";
	cin >> m;
	int arr[10] = { 0 };
	while(m) {
		arr[k++] = m % n;
		m /= n;
	}
	for (int i = k - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	return 0;
}