#ifndef BUBBLESORTSTRATEGY_TPP
#define BUBBLESORTSTRATEGY_TPP

#include <algorithm>
#include "bubbleSortStrategy.h"

template <typename T>
void BubbleSortStrategy<T>::sort(std::vector<T>& data) {
	unsigned nextToLast = data.size() - 2;
	if (nextToLast <= 0) return;
	bool done = false;
	while (!done) {
		done = true;
		for (unsigned i = 0; i <= nextToLast; ++i) {
			if (data[i] > data[i+1]) {
				std::swap(data[i], data[i+1]);
				done = false;
			}
		}
		--nextToLast;
	}
}

#endif
