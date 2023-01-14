#include<bits/stdc++.h>
using namespace std;
void SWAP(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}
//1. Sap xep noi bot
void bubble_sort(int a[], int n){
	int count = 0;
	for (int i = 1; i < n; i++)				//ta chi can noi bot n - 1 lan
	{
		count = 0;
		for (int j = 0; j < n-i; j++)			//j < n - i
		{
			if (a[j] > a[j+1])
			{
				SWAP(a[j], a[j+1]);
				count++;
			}
		}
		if (count == 0)
			break;
	}
}

//2. Sap xep chon (selection)
void selection_sort(int a[], int n){
	int jmin = 0;
	for (int i = 1; i < n; i++)
	{
		jmin = i - 1;
		for (int j = i-1; j < n; j++)		//di tim chi so nho nhat jmin
		{
			if (a[j] < a[jmin])	//	sua lai, truoc day la if (a[j] <= a[jmin])
				jmin = j;
		}
		if (jmin != i - 1)					//neu jmin bien doi, trao doi 
			SWAP(a[i-1], a[jmin]);
	}
}

//3. Sap xep chen (insertion)
void insertion_sort(int a[], int n){
	int key, k;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		k = -1;
		for (int j = 0; j < i; j++)
		{
			if (key < a[j])
			{
				k = j;
				break;
			}
		}
		if (k != -1)
		{
			for (int j = i-1; j >= k; j--)
				a[j+1] = a[j];
			a[k] = key;
		}
	}
}

//4. Sap xep Shell (shell sort)
void shell_sort(int a[], int n)
{
    int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2)
	{
		for(i = interval; i < n; i++)
		{
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval)
			{
				a[j] = a[j - interval];	
			}
			a[j] = temp;
		}
    }
}

//5. Sap xep nhanh (Quick sort)
//su dung 2 ham: partition va sort
int partition(int a[], int left, int right){
	int pivot = a[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			SWAP(a[i], a[j]);
		}
	}
	SWAP(a[i+1], a[right]);
	printf("%d \n", i);
	return i;
}
//int partition(int a[], int left, int right){
//	int pivot = a[left];
//	int i = right + 1;
//	for (int j = right; j >= left + 1; j--)
//	{
//		if (a[j] > pivot)
//		{
//			i--;
//			SWAP(a[i], a[j]);
//		}
//	}
//	SWAP(a[i-1], a[left]);
//	return i;
//}
void quick_sort(int a[], int left, int right){
	if (left >= right) //co 1 phan tu
		return;
	else if (left + 1 == right)		// co 2 phan tu
	{
		if (a[left] > a[right])
			SWAP(a[left], a[right]);
	}
	else		//co 3 phan tu
	{
		int i = partition(a, left, right);
		quick_sort(a, left, i);
		quick_sort(a, i + 2, right);
	}
}

//6. Sap xep tron (merge sort)
void merge(int a[], int n, int p, int q, int r)
{
	int b[n];	//luu tam ket qua hop nhat
	int i, j, k;	// k: chi so mang hop nhat, i: chi so mang con trai, j: chi so mang con phai
	k = 0; i = p; j = q + 1;
	while (i <= q && j <= r)		//Khi i va j con song hanh cung nhau
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= q)		//neu i hon j 1 ky so
		b[k++] = a[i++];
	while (j <= r)		//neu j hon i mot ky so
		b[k++] = a[j++];
	for (int i = r; i >= p; i--)
		a[i] = b[--k];
}
void merge_sort(int a[], int n, int p, int r){
	int q;
	if (p < r)
	{
		q = (p+r) / 2;
		merge_sort(a, n, p, q);
		merge_sort(a, n, q+1, r);
		merge(a, n, p, q, r);
	}
}
int main(){
	int a[8] = {12,15,1,5,7,3,2,10};
	int n = sizeof(a)/sizeof(a[0]);
	//bubble_sort(a, n);
	//selection_sort(a, n);
	//insertion_sort(a, n);
	//shell_sort(a, n);
	quick_sort(a, 0, n-1);
	//merge_sort(a, n, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << a[i] <<" ";
}
