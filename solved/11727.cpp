#include <bits/stdc++.h>

using namespace std;

long long dp[1001];

int main() {
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	// N은 -1 혹은 -2로 처리할 수 있다.
	// N-1은 길이 1짜리 블록을 선택한 경우
	// N-2는 길이 2짜리 블록을 선택한 경우다.
		// 그런데 N-2의 경우에는 경우의 수가 2개다.
		// 그렇다면 *2를 해줘야함. 

	for (int i = 3;i <= n;i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n];
}