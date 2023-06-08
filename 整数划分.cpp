#include<stdio.h>
int huafen(int n, int m) {
	if ((n == 1)|(m==1)) {
		return 1;
	}
	if (n == m) {
		return 1 + huafen(n, n - 1);
	}
	if (n < m) {
		return huafen(n, n);
	}
	if (n > m) {
		return huafen(n - m, m) + huafen(n, m - 1);
	}
}
int main() {
	int n, m;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	printf_s("%d", huafen(n, m));
}