#include<stdio.h>
void kp(int a[], int st, int en)
{
	int i = st;
	int j = en;
	int p = a[st];
	if (i >= j)
		return ;
	else
	{
		while (i != j)
		{
			while(a[i] <=p && i < j)
				i++;
			while (a[j] >p && i < j)
				j--;
			if (i < j)
			{
				int k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
		if (p > a[i])
		{
			a[st] = a[i];
			a[i] = p;
		}
		else
		{
			for (int k = st; k < i-1; k++)
			{
				a[k] = a[k + 1];
			}
			a[i-1] = p;
		}
	}

	kp(a, st, i - 1);
	kp(a, i + 1, en);
}
int main()
{
	int a[8] = { 5,3,4,6,4,2,7,9 };
	kp(a, 0, 7);
	int s;
	for (s = 0; s < 8; s++)
	{
		printf("%d\n", a[s]);
	}
	return 0;
}
