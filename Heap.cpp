#include<iostream>

using namespace std;

struct Heap {
	double* arr;
	int size = 1;
	bool isMin;

	double getMax() {
		return arr[1];
	}

	Heap(int n, bool answer) {
		arr = new double[n + 1];
		isMin = answer;
	}

	void insert(double data) {
		arr[size++] = data;
		heapify(size - 1);
	}

	void swap(int a, int b) {
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	void heapify(int el) {
		if (!isMin) {
			while (el > 1 && (arr[el / 2] < arr[el])) {
				swap(el / 2, el);
				el /= 2;
			}
		}
		else {
			while (el > 1 && (arr[el / 2] > arr[el])) {
				swap(el / 2, el);
				el /= 2;
			}
		}
	}

	void deleteRoot() {
		swap(1, size - 1);
		size--;
		sift(1);
	}

	void sift(int i) {
		if (!isMin) {
			int maxIdx = i;
			int leftIdx = i * 2;
			if (leftIdx<size && arr[leftIdx] > arr[maxIdx]) {
				maxIdx = leftIdx;
			}
			int rightIdx = i * 2 + 1;
			if (rightIdx<size && arr[rightIdx] > arr[maxIdx]) {
				maxIdx = rightIdx;
			}
			if (i != maxIdx) {
				swap(i, maxIdx);
				sift(maxIdx);
			}
		}
		else {
			int minIdx = i;
			int leftIdx = i * 2;
			if (leftIdx<size && arr[leftIdx] < arr[minIdx]) {
				minIdx = leftIdx;
			}
			int rightIdx = i * 2 + 1;
			if (rightIdx<size && arr[rightIdx] < arr[minIdx]) {
				minIdx = rightIdx;
			}
			if (i != minIdx) {
				cout << "swapping min and i" << arr[minIdx] << " ," << arr[i] << endl;
				swap(i, minIdx);
				sift(minIdx);
			}
		}
	}

	int getSize() {
		return size;
	}
};