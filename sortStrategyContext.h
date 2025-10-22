#ifndef SORT_STRATEGY_CONTEXT_H
#define SORT_STRATEGY_CONTEXT_H

#include <vector>
#include "sortStrategy.h"

template <typename T>
class SortStrategyContext {
	public:
		SortStrategyContext(SortStrategy<T>* s) : sortStrategy(s) {}
		void setStrategy(SortStrategy<T>* s) {sortStrategy = s;}

	private:
		SortStrategy<T>* sortStrategy;
};

#endif

