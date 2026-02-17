#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	// n! / k! (n-k)!

	long long n_fact = 1;

	for (int i = 1;i <= n;i++) {
		n_fact *= i;
	}

	long long k_fact = 1;

	for (int i = 1;i <= k;i++) {
		k_fact *= i;
	}

	long long n_k_fact = 1;

	for (int i = 1;i <= n - k;i++) {
		n_k_fact *= i;
	}

	cout << n_fact / (k_fact * n_k_fact);
}