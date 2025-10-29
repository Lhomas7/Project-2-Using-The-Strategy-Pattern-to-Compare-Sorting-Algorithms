#ifndef HEAPSORTSTRATEGY_TPP
#define HEAPSORTSTRATEGY_TPP

#include <algorithm>
#include "heapSortStrategy.h"

template <typename T>
void HeapSortStrategy<T>::makeHeap(std::vector<T>& data) {
	int startNode = data.size()/2 - 1;
	for (int i = startNode; i >= 0; --i) {
		bubbleDown(data, data.size(), i);
	}
} 

template <typename T>
void HeapSortStrategy<T>::bubbleDown(std::vector<T>& data, unsigned noNodes, unsigned parent) {
	bool done = false;
	while (!done) {
		unsigned leftChild = 2*parent+1;
		unsigned rightChild = 2*parent+2;
		unsigned largest = parent;
		if (leftChild < noNodes && data[leftChild] > data[largest]) {
			largest = leftChild;
		}
		if (rightChild < noNodes && data[rightChild] > data[largest]) {
			largest = rightChild;
		}
		if (largest != parent) {
			std::swap(data[largest], data[parent]);
		}
		else {
			done = true;
		}
	}
}

template <typename T>
void HeapSortStrategy<T>::sort(std::vector<T>& data) {
	makeHeap(data);
	for (unsigned int i = data.size()-1; i > 0; --i) {
		std::swap(data[0], data[i]);
		bubbleDown(data, i, 0);
	}
}

#endif
