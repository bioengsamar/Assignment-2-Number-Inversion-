#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int merge(int arr[], int left, int mid, int right)//mid = left + (right - left) / 2;
{
	int count = 0;
	int n1 = mid - left + 1;// First subarray is arr[l..m] >>left
	int n2 = right - mid;// Second subarray is arr[m+1..r] >> right
	int *L=new int[n1], *R=new int[n2]; //dynamic array for left and right

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])  //when left item is less than right item
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			count += (n1-i); //find how many convertion is performed


		}
		k++;

	}

	while (i < n1) //if first list has remaining item, add them in the list
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) //if second list has remaining item, add them in the list
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	return count;
}


int mergeSort(int arr[], int left, int right)
{
    int count = 0;
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		count += mergeSort(arr, left, mid); //merge sort left sub array
		count += mergeSort(arr, mid + 1, right); //merge sort right sub array
		count += merge(arr, left, mid, right);  //merge two sub arrays
	}

	return count;
}


int number_Inversion(int arr[], int n) {
   return mergeSort(arr, 0, n - 1);
}
int main()
{

		int arr[] = { 30,20,40,5,90,80, 10 };
		int n = sizeof(arr) / sizeof(arr[0]);

		cout << "Number of inversions = "<< number_Inversion(arr, n);
	return 0;

	}
