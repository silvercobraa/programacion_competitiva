#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	string s, t;
	while (cin >> s >> t) {
		int j = 0;
		int matches = 0;
		for (size_t i = 0; i < s.size(); i++) {
			for ( ; j < t.size(); j++) {
				if (s[i] == t[j]) {
					matches++;
					j++;
					break;
				}
			}
		}
		if (matches == s.size()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
