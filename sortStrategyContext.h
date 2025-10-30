#ifndef SORT_STRATEGY_CONTEXT_H
#define SORT_STRATEGY_CONTEXT_H

#include <vector>
#include "sortStrategy.h"
#include <chrono>
#include <cmath>
#include "pair.h"

template <typename T>
class SortStrategyContext {
	public:
		SortStrategyContext(SortStrategy<T>* s) : sortStrategy(s) {}
		void setStrategy(SortStrategy<T>* s) {sortStrategy = s;}
		void sort(std::string& msg, std::vector<T>& data) {
			auto start_time = std::chrono::steady_clock::now();
			sortStrategy->sort(data);
			print(msg, data);
			auto end_time = std::chrono::steady_clock::now();
        		auto elapsed_duration = end_time - start_time;
			std::chrono::duration<double, std::milli> elapsed_ms = elapsed_duration;
			double rounded_time = std::round(elapsed_ms.count() * 1000.0) / 1000.0;
        		std::cout << "Elapsed time: " << rounded_time
                  		<< " milliseconds\n" << std::endl;
		}
		void print(std::string& msg, std::vector<T>& data) {
			sortStrategy->print(msg, data);
		}

	private:
		SortStrategy<T>* sortStrategy;
};

#endif

