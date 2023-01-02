#include<stdio.h>
void sort(int a[], int l, int r)
{
	if (l == r)
		return;
	int i = l - 1; int j = r + 1;
	int x = (a[l] + a[r]) / 2;
	while (i < j)
	{
		do
		{
			i++;
		} while (a[i] < x);
		do
		{
			j--;
		} while (a[j] > x);
		int t = 0;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = b;
		}
	}
	sort(a, l, j);
	sort(a, j + 1, r);
}

int main()
{
	int n;
	int i;
	int a[1000000];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	sort(a, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}