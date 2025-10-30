#include <iostream>
#include <vector>

#include "sortStrategyContext.h"
#include "mergeSortStrategy.h"
#include "heapSortStrategy.h"
#include "bubbleSortStrategy.h"
#include "pair.h"

const int MAX = 100;

Pair<char, int> getPair() {
  char ch = (90 - (rand() % 26));
  return Pair(ch, rand()%100);
}

int main() {

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

	return 0;
}
