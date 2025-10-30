#ifndef HEAPSORTSTRATEGY_H
#define HEAPSORTSTRATEGY_H

#include <iostream>
#include <vector>
#include "sortStrategy.h"

template <typename T>
class HeapSortStrategy : public SortStrategy<T> {
	public: 
		HeapSortStrategy() {}
		virtual void sort(std::vector<T>&) override;

	private:
		void makeHeap(std::vector<T>&);
		void bubbleDown(std::vector<T>&, unsigned noNodes, unsigned parent);
};

#endif

#include "heapSortStrategy.tpp"
