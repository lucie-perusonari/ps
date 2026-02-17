#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	for (int i = 0;i < 8;i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}

	bool asc = true;
	bool desc = true;

	for (int i = 0;i < 7;i++) {
		if (arr[i] < arr[i + 1]) {
			desc = false;
		} else {
			asc = false;
		}
	}

	if (asc == false && desc == false) {
		cout << "mixed";
	} else if (asc == true) {
		cout << "ascending";
	} else {
		cout << "descending";
	}
}