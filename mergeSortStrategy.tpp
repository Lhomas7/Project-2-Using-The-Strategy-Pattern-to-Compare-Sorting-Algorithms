#ifndef MERGESORTSTRATEGY_TPP
#define MERGESORTSTRATEGY_TPP

#include <algorithm>
#include "mergeSortStrategy.h"

template <typename T>
void MergeSortStrategy<T>::sort(std::vector<T>& data) {
	int n = data.size();
	if (n <= 1) { 
		return data;
	}
	
	int mid = n / 2;
	std::vector<T> left(data.begin(), data.begin() + mid);
	std::vector<T> right(data.begin() + mid, data.end());
	
	left = sort(left);
	right = sort(right);
	
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < left.size() && j < right.size()) {

		if (!(right[j] < left[i])) {
			data[k++] = left[i++];
		}
		else {
			data[k++] = right[j++];
		}
	}
	while (i < left.size()) {
		data[k++] = left[i++];
	}
	while (j < right.size()) {
		data[k++] = right[j++];
	}
	
	return data;
} 

#endif
