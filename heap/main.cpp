/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: program for hw5_1 to conduct heap operations.
 * Name: Justin Johnson
 * Date:12/6/2022
 */

#include <iostream>
#include <vector>
using namespace std;

// func declare
void display(vector<int> heap);
void displayMax(vector<int> heap);
bool isHeap(vector<int> heap);
void heapify(vector<int> &heap);
void insert(vector<int> &heap, int ele);
void deleteMax(vector<int> &heap);
void commands(vector<int> &heap);
void inp(vector<int> &heap);

int main() {
	bool hold;
	string s;
	int num, temp, comms, i = 0;
	// cin >> num;
	vector<int> heap;

	// heap.resize(num + 1);
	// for (int i = 1; i < num + 1; i++) {
	// 	cin >> temp;
	// 	heap[i] = (temp);
	// }
	inp(heap);

	// cout << " seg" << endl;
	hold = isHeap(heap);
	if (hold) {
		cout << "This is a heap." << endl;
	} else {
		cout << "This is NOT a heap." << endl;
		heapify(heap);
	}
	// cin >> comms;
	commands(heap);
	return 0;
}
void inp(vector<int> &heap) {
	int num, temp;
	cin >> num;
	heap.resize(num + 1);
	for (int i = 1; i < num + 1; i++) {
		cin >> temp;
		heap[i] = (temp);
	}
}
void display(vector<int> heap) {
	for (int i = 1; i < heap.size(); i++) {
		if (i < heap.size() - 1) {
			cout << heap[i] << " ";
		} else
			cout << heap[i];
	}
	cout << endl;
}
void insert(vector<int> &heap, int ele) {
	heap.push_back(ele);
	heapify(heap);
}
void deleteMax(vector<int> &heap) {
	heap[1] = heap.back();
	heap.pop_back();
	heapify(heap);
}
void displayMax(vector<int> heap) {
	cout << heap[1] << endl;
}
bool isHeap(vector<int> heap) {
	int parent;
	int lChild;
	int rChild;

	for (int j = heap.size() / 2; j > 0; j--) {
		parent = j;
		lChild = j * 2;		// left child
		rChild = j * 2 + 1; // right child
		if (lChild < heap.size()) {
			if (heap[lChild] > heap[parent]) {
				return false;
			}
		}
		if (rChild < heap.size()) {
			if (heap[rChild] > heap[parent]) {
				return false;
			}
		}
	}
	return true;
}
void heapify(vector<int> &heap) {
	int parent;
	int lChild, rChild; // childern
	bool flag;

	while (!isHeap(heap)) {
		for (int j = heap.size() / 2; j > 0; j--) {
			flag = false;
			parent = j;
			lChild = j * 2;
			rChild = j * 2 + 1;

			while (!flag && lChild < heap.size()) {
				if (lChild < heap.size()) {
					if (heap[lChild] < heap[rChild])
						lChild = rChild;
					if (heap[parent] >= heap[lChild])
						flag = true;
					else
						swap(heap[parent], heap[lChild]);
				}
			}
		}
	}
}
void commands(vector<int> &heap) {
	string s;
	int comms, num, ele;
	cin >> num;

	while (num--) {
		cin >> s;
		if (s == "display")
			display(heap);
		else if (s == "insert") {
			cin >> ele;
			insert(heap, ele);
		} else if (s == "deleteMax") {
			deleteMax(heap);
		} else if (s == "displayMax") {
			displayMax(heap);
		}
	}
}
