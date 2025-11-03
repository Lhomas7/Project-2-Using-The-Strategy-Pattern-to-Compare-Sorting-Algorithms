#include <iostream>
#include <vector>

#include "sortStrategyContext.h"
#include "mergeSortStrategy.h"
#include "heapSortStrategy.h"
#include "bubbleSortStrategy.h"
#include "pair.h"

const int MAX = 100000;

Pair<char, int> getPair() {
  char ch = (90 - (rand() % 26));
  return Pair<char, int>(ch, rand()%100);
}

int main() {

	//Pair testing
	std::vector<Pair<char, int> > data;
  	data.reserve(MAX);
  	for (size_t i = 0; i < MAX; ++i) {
    	data.push_back(getPair());
  	}
  	std::vector<Pair<char, int>> datacopy = data;
	std::cout << "Size of data being sorted: " << MAX << "\n" << std::endl;

	MergeSortStrategy<Pair<char, int>> merge;
	HeapSortStrategy<Pair<char, int>> heap;
	BubbleSortStrategy<Pair<char, int>> bubble;

	SortStrategyContext<Pair<char, int>> context(&bubble);
	std::string s1 = "Unsorted Data; First 10:";
	context.print(s1, data);
	s1 = "\nBubbleSort First 10: ";
	context.sort(s1,datacopy);

	datacopy = data;
	context.setStrategy(&merge);
	s1 = "MergeSort First 10: ";
	context.sort(s1,datacopy);

	datacopy = data;
	context.setStrategy(&heap);
	s1 = "HeapSort First 10: ";
	context.sort(s1,datacopy);

	//Integer testing
	// std::vector<int> newData;
	// newData.reserve(MAX);
	// for (unsigned i = 0; i < MAX; ++i) {
	// 	newData.push_back(rand()%100);
	// }

	// std::vector<int> newDataCopy = newData;
	// std::cout << "Size of data being sorted: " << MAX << "\n" << std::endl;

	// MergeSortStrategy<int> newMerge;
	// HeapSortStrategy<int> newHeap;
	// BubbleSortStrategy<int> newBubble;

	// SortStrategyContext<int> newContext(&newBubble);
	// s1 = "Unsorted Data; First 10:";
	// newContext.print(s1, newData);
	// s1 = "\nBubbleSort First 10: ";
	// newContext.sort(s1,newDataCopy);

	// newDataCopy = newData;
	// newContext.setStrategy(&newMerge);
	// s1 = "MergeSort First 10: ";
	// newContext.sort(s1,newDataCopy);

	// newDataCopy = newData;
	// newContext.setStrategy(&newHeap);
	// s1 = "HeapSort First 10: ";
	// newContext.sort(s1,newDataCopy);
	
	// return 0;
}
