#include <iostream>
#include <vector>

#include "sortStrategyContext.h"
#include "mergeSortStrategy.h"
#include "heapSortStrategy.h"
#include "bubbleSortStrategy.h"

const int MAX = 7;

int main() {
	std::vector<int> data;
	data.reserve(MAX);
	data = {15,8,5,20,18,10,17};
	std::vector<int> datacopy = data;

	MergeSortStrategy<int> merge;
	HeapSortStrategy<int> heap;
	BubbleSortStrategy<int> bubble;

	SortStrategyContext<int> context(&bubble);
	context.sort(datacopy);
	std::string s1 = "Unsorted Data: ";
	context.print(s1,data);
	s1 = "bubbleSort: ";
	context.print(s1,datacopy);

	datacopy = data;
	context.setStrategy(&heap);
	context.sort(datacopy);
	s1 = "heapSort: ";
	context.print(s1,datacopy);

	datacopy = data;
	context.setStrategy(&merge);
	context.sort(datacopy);
	s1 = "mergeSort: ";
	context.print(s1,datacopy);

	return 0;
}
