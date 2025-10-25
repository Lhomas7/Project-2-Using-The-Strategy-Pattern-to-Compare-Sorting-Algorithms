#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

template <typename T>
class SortStrategy {
	public:
		SortStrategy()=default;
		virtual void sort(std::vector<T>&) = 0;
		virtual ~SortStrategy()=default;
		virtual void print(std::string& msg, std::vector<T>& v) {
			std::cout << msg;
			for (int i = 0; i < v.size(); ++i) {
				std::cout << v[i] << " ";
			}
			std::cout << std::endl;
		}
};

#endif
