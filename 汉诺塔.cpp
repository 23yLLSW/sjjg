#include <stdio.h>

void hnt(int n, char A, char B, char C) 
{
	if (n == 1) {
		printf_s("%c >%c\n", A, C);
	}
	else {
		hnt(n - 1, A, C, B);
		printf_s("%c >%c\n", A, C);                     
		hnt(n - 1, B, A, C);
	}

}

int main() {
	int n;
	scanf_s("%d", &n);
	hnt(n, 'A', 'B', 'C');
	return 0;
}