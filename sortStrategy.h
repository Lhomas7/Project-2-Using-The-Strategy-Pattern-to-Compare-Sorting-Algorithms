#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

template <typename T>
class SortStrategy {
	public:
		SortStrategy()=default;
		virtual void sort(std::vector<T>&) = 0;
		virtual ~SortStrategy()=default;
		virtual void print(const std::string& msg, std::vector<T>& v) {
			std::cout << msg << std::endl;
			for (unsigned i = 0; i < 10; ++i) {
				std::cout << v[i] << " ";
			}
			std::cout << std::endl;
		}
};

#endif
