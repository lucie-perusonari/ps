#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int dp[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	// dp를 인덱스 n까지의 연속합의 최대로 정의.
	// 연속해야하므로 n을 반드시 더한다고 전제함.

	dp[0] = arr[0];

	for (int i = 1;i < n;i++) {
		dp[i] = max(arr[i] + dp[i - 1], arr[i]);
	}

	cout << *max_element(dp, dp + n);

}