#include <iostream>
#include <vector>

#include "sortStrategyContext.h"
#include "mergeSortStrategy.h"
#include "heapSortStrategy.h"
#include "bubbleSortStrategy.h"
#include "pair.h"

const int MAX = 100;

template <typename T>
void printPair(const std::string& msg, const std::vector<T>& vec) {
  std::cout << msg << std::endl;
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << "(" << vec[i].first << ", " << vec[i].second << ")   ";
  }
  std::cout << std::endl;
}

Pair<char, int> getPair() {
  char ch = (90 - (rand() % 26));
  return Pair(ch, rand()%100);
}



int main() {

	std::vector<Pair<char, int> > data;
  	data.reserve(MAX);
  	for (size_t i = 0; i < 10; ++i) {
    	data.push_back(getPair());
  	}
  	std::vector<Pair<char, int>> datacopy = data;

	MergeSortStrategy<Pair<char, int>> merge;
	HeapSortStrategy<Pair<char, int>> heap;
	BubbleSortStrategy<Pair<char, int>> bubble;

	SortStrategyContext<Pair<char, int>> context(&bubble);
	std::string s1 = "Unsorted Data; First 10:";
	printPair(s1,data);
	s1 = "BubbleSort First 10: ";
	printPair(s1,datacopy);
	context.sort(datacopy);

	datacopy = data;
	context.setStrategy(&merge);
	s1 = "MergeSort First 10: ";
	printPair(s1,datacopy);
	context.sort(datacopy);

	datacopy = data;
	context.setStrategy(&heap);
	s1 = "HeapSort First 10: ";
	printPair(s1,datacopy);
	context.sort(datacopy);

	return 0;
}
