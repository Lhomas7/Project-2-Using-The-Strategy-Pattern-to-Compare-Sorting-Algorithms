#ifndef MERGESORTSTRATEGY_H
#define MERGESORTSTRATEGY_H

#include <iostream>
#include <vector>
#include "sortStrategy.h"

template <typename T>
class MergeSortStrategy : public SortStrategy<T> {
	public:
		MergeSortStrategy() {}
		virtual void sort(std::vector<T>&) override;
};

#endif

#include "mergeSortStrategy.tpp"
