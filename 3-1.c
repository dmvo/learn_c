#include <stdio.h>

int binsearch(int x, int v[], int n); /* from the book */
int binsearch1(int x, int v[], int n);

int main()
{
	int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("position of 1: %i\n", binsearch(1,v,10));
	printf("position of 1: %i\n", binsearch1(1,v,10));
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch1(int  x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;

	while (low < high) {
		mid = (low+high) / 2;
		if (x <= v[mid])
			high = mid;
		else
      			low = mid + 1;
	}
	return (x == v[low])? low : -1;
}
