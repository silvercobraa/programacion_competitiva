#include <iostream>
#include <vector>
#include <algorithm>

// LMAO
#define MINUS_INF -1
#define INF 99999999999999999L

long test(long i, long divisor, long p) {
	long dividend = 0;
	long pos = 0;
	// while (i != 0) {
	for (long j = 0; j < p; j++) {
		// std::cout << "iteracion " << j << std::endl;
		dividend *= 10;
		long digit = i & 1;
		if (digit == 0) {
			dividend += 2;
		}
		else {
			dividend += 1;
		}
		pos++;
		i /= 2;
	}
	// std::cout << "dividend: " << dividend << std::endl;
	if (dividend % divisor == 0) {
		return dividend;
	}
	else {
		return 0;
	}
}

void search(long max, long divisor, long p, long case_) {
	long largest = MINUS_INF;
	long smallest = INF;
	for (long i = 0; i < max; i++) {
		long ans = test(i, divisor, p);
		if (ans) {
			largest = std::max(largest, ans);
			smallest = std::min(smallest, ans);
		}
	}
	// std::cout << "smallest: " << smallest << std::endl;
	// std::cout << "largest: " << largest << std::endl;
	std::cout << "Case " << case_ << ": ";
	if (largest == MINUS_INF || smallest == INF) {
		std::cout << "impossible" << '\n';
	}
	else if (largest == smallest) {
		std::cout << largest << '\n';
	}
	else {
		std::cout << smallest << ' ' << largest << '\n';
	}
}

int main(int argc, char const *argv[]) {
	long t;
	std::cin >> t;
	for (long i = 0; i < t; i++) {
		long p, q;
		std::cin >> p >> q;
		// std::cout << ' ' << (1 << p) << ' ' << (1 << q) << std::endl;
		search(1 << p, 1 << q, p, i + 1);
	}
	return 0;
}
