#ifndef SORT_STRATEGY_CONTEXT_H
#define SORT_STRATEGY_CONTEXT_H

#include <vector>
#include "sortStrategy.h"

template <typename T>
class SortStrategyContext {
	public:
		SortStrategyContext(SortStrategy<T>* s) : sortStrategy(s) {}
		void setStrategy(SortStrategy<T>* s) {sortStrategy = s;}
		void sort(std::vector<T>& data) {
			sortStrategy->sort(data);
		}
		void makeHeap(std::vector<T>& data) {
			sortStrategy->makeHeap(data);
		}
		void print(std::string& msg, std::vector<T>& data) {
			sortStrategy->print(msg, data);
		}

	private:
		SortStrategy<T>* sortStrategy;
};

#endif

