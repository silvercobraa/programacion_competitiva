#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

std::vector<int> customers;
std::map<std::set<int>,int> common_customers;
std::vector<int> ans;
int max_customers;

int common2(std::set<int> towers, std::set<int> s) {
	std::set<int> ss;
	set_intersection(towers.begin(),towers.end(),s.begin(),s.end(),
                  std::inserter(ss,ss.begin()));
	if (ss.size() > 1) {
		// si el area es comun  n torres, tengo que restarla n - 1 veces para considerearla 1 sola vez
		return (ss.size() - 1)*common_customers[s];
	}
	else {
		return 0;
	}
}

int common(std::set<int> towers, std::set<int> s) {
	std::cout << "towers:";
	for (auto tt: towers) {
		std::cout << ' ' << tt;
	}
	std::cout << std::endl;
	std::cout << "s:";
	for (auto ss: s) {
		std::cout << ' ' << ss;
	}
	std::cout << std::endl;
	for (auto ss: s) {
		if (towers.find(ss) == towers.end()) {
			return 0;
		}
	}
	std::cout << common_customers[s] << std::endl;
	return common_customers[s];
}

void comb(std::vector<int>& towers, int l, int r, int m) {
	// std::cout << "-> " << l << ' ' << r << ' ' << m << '\n';
	if (m == 0) {
		int total_customers = 0;
		for (int tower: towers) {
			// std::cout << tower << ' ';
			total_customers += customers[tower];
		}
		for (auto p: common_customers) {
			int ret = common2(std::set<int>(towers.begin(), towers.end()), p.first);
			// std::cout << ret << std::endl;
			total_customers -= ret;
		}
		// std::cout << std::endl;
		// std::cout << "total customers: " << total_customers << std::endl;
		if (total_customers > max_customers) {
			max_customers = total_customers;
			ans = towers;
		}
		return;
	}
	for (int i = l; i < r; i++) {
		towers.push_back(i + 1);
		comb(towers, i + 1, r + 1, m - 1);
		towers.pop_back();
	}
}

void comb(int n, int k) {
	std::vector<int> s;
	comb(s, 0, n - k + 1, k);
}



int main(int argc, char const *argv[]) {
	// n: torres totales
	// nn: torres a construir
	//m: cantidad de arean comunes
	// t: cantidad de torres en un area comun
	int n, nn;
	int dev_null;
	int case_number = 1;
	for (std::cin >> n >> nn; n != 0 || nn != 0; std::cin >> n >> nn) {
		customers = std::vector<int>(n + 1);
		max_customers = -1;
		for (size_t i = 0; i < n; i++) {
			std::cin >> customers[i + 1];
		}
		int m;
		std::cin >> m;
		for (size_t i = 0; i < m; i++) {
			int t;
			std::cin >> t;
			std::set<int> s;
			for (size_t j = 0; j < t; j++) {
				std::cin >> dev_null;
				s.insert(dev_null);
			}
			std::cin >> dev_null;
			if (s.size() > 1) {
				common_customers[s] += dev_null;
			}
		}

		comb(n, nn);

		std::cout << "Case Number  " << case_number << std::endl;
		std::cout << "Number of Customers: " << max_customers << std::endl;
		std::cout << "Locations recommended:";
		for (int a: ans) {
			std::cout << ' ' << a;
		}
		std::cout << std::endl << std::endl;
		customers.clear();
		common_customers.clear();
		case_number++;
	}
	return 0;
}
