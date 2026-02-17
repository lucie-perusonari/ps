#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int dp[100001]; // 인덱스 0부터 n까지의 합.
int main() {
	int n, m;
	cin >> n >> m;


	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		dp[i + 1] = dp[i] + arr[i];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;

		cout << dp[j] - dp[i - 1] << "\n";

	}
}