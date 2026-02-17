#include <bits/stdc++.h>

using namespace std;

int arr[501][501];
int dp[501][501];

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	// 높이 i-1의 인덱스는 i-1 이다.
	// 자기 인덱스는 오른쪽, 자기 인덱스 -1은 왼쪽
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];

		}
	}

	cout << *max_element(dp[n], dp[n] + n + 1);


}