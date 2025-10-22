#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

template <typename T>
class SortStrategy {
	public:
		SortStrategy()=default;
		virtual void sort(std::vector<T>&) = 0;
		virtual ~SortStrategy()=default;
};

#endif
