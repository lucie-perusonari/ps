#include <bits/stdc++.h>

using namespace std;

long long fibonacci[41];
long long zero[41];
long long one[41];

int main() {
	int t;
	cin >> t;

	fibonacci[0] = 1;
	fibonacci[1] = 1;

	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;

	for (int i = 2;i <= 40;i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << zero[n] << ' ' << one[n] << "\n";
	}


}