#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(int a[], int n)
{
	int res = a[0];
	for (int i = 0; i < n; i++)
		res = max(res, a[i]);
	return res;
}

void countSort(int a[], const int n, int exp)
{
	vector<int> output(n); 
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		a[i] = output[i];
}
void radix_sort(int a[], int n)
{
	int m = getMax(a, n);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}

int main()
{
	int a[] = { 12, 21, 35, 3, 79, 105};
	int n = sizeof(a) / sizeof(a[0]);

	radix_sort(a, n);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}