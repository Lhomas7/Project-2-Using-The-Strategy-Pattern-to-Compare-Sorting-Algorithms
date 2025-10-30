#ifndef PAIR_H
#define PAIR_H

#include <iostream>

// A replacement for std::pair that compares only .first
// Used to illustrate stability of sorting algorithms.
template <typename A, typename B>
class Pair {
public:
    A first;
    B second;

    Pair() : first(), second() {}
    Pair(const A& a, const B& b) : first(a), second(b) {}

    bool operator<(const Pair<A,B>& rhs) const {
        return first < rhs.first;    // ignore second
    }

    bool operator>(const Pair<A,B>& rhs) const {
        return first > rhs.first;    // ignore second
    }

    bool operator==(const Pair<A,B>& rhs) const {
        return first == rhs.first && second == rhs.second;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pair<A,B>& p) {
        out << "(" << p.first << "," << p.second << ")";
        return out;
    }
};

#endif