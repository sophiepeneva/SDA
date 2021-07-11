#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void insertionSort(int* arr, int n) {
	for (int i = 1;i < n;i++) {
		for (int j = i; j > 0 && arr[j] < arr[j - 1];j--) {
			swap(arr[j], arr[j - 1]);
		}
	}
}

void bubbleSort(int* arr, int n) {
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - i - 1;j++) {
			if (arr[j + 1] < arr[j]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectionSort(int* arr, int n) {
	for (int i = 0;i < n;i++) {
		int min = i;
		for (int j = i + 1;j < n;j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

void merge(int* arr, int left, int middle, int right) {
	int leftIndex = left;
	int rightIndex = middle + 1;
	int* temp = new int[right - left + 1];
	int index = 0;
	while (leftIndex <= middle && rightIndex <= right) {
		if (arr[leftIndex] < arr[rightIndex]) {
			temp[index++] = arr[leftIndex++];
		}
		else {
			temp[index++] = arr[rightIndex++];
		}
	}
	if (leftIndex > middle) {
		for (int i = index;i < right - left + 1;i++) {
			temp[i] = arr[rightIndex++];
		}
	}
	else {
		for (int i = index;i < right - left + 1;i++) {
			temp[i] = arr[leftIndex++];
		}
	}
	int counter = 0;
	for (int i = left;i <= right;i++) {
		arr[i] = temp[counter++];
	}
}

void mergeSort(int* arr, int left, int right) {
	if (left >= right)return;
	int middle = (left + right) / 2;
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	merge(arr, left, middle, right);

}

void quickSort(int* arr, int left, int right) {
	int i = left;
	int j = right;
	int pivot = arr[(i + j) / 2];
	while (i < j) {
		while (arr[i] < pivot)i++;
		while (arr[j] > pivot)j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j)quickSort(arr, left, j);
	if (i < right)quickSort(arr, i, right);
}

bool binarySearch(int* arr, int start, int end, int k) {
	if (start > end)return false;
	if (arr[(start + end) / 2] == k)return true;
	if (arr[(start + end) / 2] > k)return binarySearch(arr, start, (start + end) / 2 - 1, k);
	if (arr[(start + end) / 2] < k)return binarySearch(arr, (start + end) / 2 + 1, end, k);
}
