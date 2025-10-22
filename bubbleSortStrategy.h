#ifndef BUBBLESORTSTRATEGY_H
#define BUBBLESORTSTRATEGY_H

#include <iostream>
#include <vector>
#include "sortStrategy.h"

template <typename T>
class BubbleSortStrategy : public SortStrategy<T> {
	public:
		BubbleSortStrategy();
		virtual void sort(std::vector<T>&) override;
};

#endif
