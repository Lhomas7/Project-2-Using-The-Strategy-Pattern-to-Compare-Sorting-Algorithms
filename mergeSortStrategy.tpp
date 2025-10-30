#ifndef MERGESORTSTRATEGY_TPP
#define MERGESORTSTRATEGY_TPP

#include <algorithm>
#include "mergeSortStrategy.h"

template <typename T>
void MergeSortStrategy<T>::sort(std::vector<T>& data) {
    int n = data.size();
    if (n <= 1) return;

    std::vector<T> temp(n);

    // Each iteration merges subarrays of size 'curr_size'
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        // Pick starting point of subarrays to merge
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = std::min(left_start + curr_size - 1, n - 1);
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);

            // Merge two subarrays data[left_start..mid] & data[mid+1..right_end]
            int i = left_start;
            int j = mid + 1;
            int k = left_start;

            while (i <= mid && j <= right_end) {
                if (!(data[j] < data[i])) {
                    temp[k++] = data[i++];
                } else {
                    temp[k++] = data[j++];
                }
            }

            while (i <= mid)
                temp[k++] = data[i++];

            while (j <= right_end)
                temp[k++] = data[j++];

            // Copy merged subarray back into data
            for (int idx = left_start; idx <= right_end; ++idx)
                data[idx] = temp[idx];
        }
    }
}
#endif
