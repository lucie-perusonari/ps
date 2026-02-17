#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;

	cin >> n;
	int arr[305];
	int dp[305]; // i는 연속으로 밟은 계단의 수. j는 밟은 계단의 

	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	// i-3이므로 3까지는 구해줘야 함.
	for (int i = 4;i <= n;i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	cout << dp[n];

}