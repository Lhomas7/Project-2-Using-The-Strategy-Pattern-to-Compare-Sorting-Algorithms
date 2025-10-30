#include <iostream>
#include <vector>

#include "sortStrategyContext.h"
#include "mergeSortStrategy.h"
#include "heapSortStrategy.h"
#include "bubbleSortStrategy.h"
#include "pair.h"

const int MAX = 20;

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
  	for (size_t i = 0; i < MAX; ++i) {
    	data.push_back(getPair());
  	}
  	std::vector<Pair<char, int>> datacopy = data;

	MergeSortStrategy<Pair<char, int>> merge;
	HeapSortStrategy<Pair<char, int>> heap;
	BubbleSortStrategy<Pair<char, int>> bubble;

	SortStrategyContext<Pair<char, int>> context(&bubble);
	context.sort(datacopy);
	std::string s1 = "Unsorted Data: ";
	printPair(s1,data);
	s1 = "BubbleSort: ";
	printPair(s1,datacopy);

	datacopy = data;
	context.setStrategy(&heap);
	context.sort(datacopy);
	s1 = "HeapSort: ";
	printPair(s1,datacopy);

	datacopy = data;
	context.setStrategy(&merge);
	context.sort(datacopy);
	s1 = "MergeSort: ";
	printPair(s1,datacopy);

	return 0;
}
