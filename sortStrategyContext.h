#ifndef SORT_STRATEGY_CONTEXT_H
#define SORT_STRATEGY_CONTEXT_H

#include <vector>
#include "sortStrategy.h"
#include <chrono>


template <typename T>
class SortStrategyContext {
	public:
		SortStrategyContext(SortStrategy<T>* s) : sortStrategy(s) {}
		void setStrategy(SortStrategy<T>* s) {sortStrategy = s;}
		void sort(std::vector<T>& data) {
			auto start_time = std::chrono::steady_clock::now();
			sortStrategy->sort(data);
			auto end_time = std::chrono::steady_clock::now();
        	auto elapsed_duration = end_time - start_time;
        	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_duration);
        	std::cout << "Elapsed time: " << elapsed_ms.count()
                  	<< " milliseconds\n" << std::endl;
		}
		void print(std::string& msg, std::vector<T>& data) {
			sortStrategy->print(msg, data);
		}

	private:
		SortStrategy<T>* sortStrategy;
};

#endif

