#include <bits/stdc++.h>

using namespace std;

int dp[10000001];
int prv[10000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// 초기값 설정
	dp[1] = 0;
	if (n >= 2) { dp[2] = 1; prv[2] = 1; }
	if (n >= 3) { dp[3] = 1; prv[3] = 1; }

	for (int i = 4; i <= n; i++) {
		// 1을 빼는 경우를 기본값으로 설정
		dp[i] = dp[i - 1] + 1;
		prv[i] = i - 1;

		// 2로 나누어 떨어지는 경우
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			prv[i] = i / 2;
		}
		// 3로 나누어 떨어지는 경우
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			prv[i] = i / 3;
		}
	}

	cout << dp[n] << "\n";


	cout << n << ' ';
	while (n != 1) {
		cout << prv[n] << ' ';
		n = prv[n];
	}

	return 0;
}