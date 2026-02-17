#include <bits/stdc++.h>

using namespace std;

long long dp[100];

int main() {
	// dp[i] = d[i-1] + dp[i-4]; ? 
	long long temp[] = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12 };

	for (int i = 0;i < 11;i++) {
		dp[i] = temp[i];
	}

	for (int i = 11;i < 100;i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;

		cout << dp[a - 1] << "\n";
	}
}