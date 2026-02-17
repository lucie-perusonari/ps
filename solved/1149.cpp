#include <bits/stdc++.h>

using namespace std;

int dp[1001][3];
int rgb[1001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int i = 0;
	while (i < n) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
		i++;
	}

	dp[0][0] = rgb[0][0];
	dp[0][1] = rgb[0][1];
	dp[0][2] = rgb[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + rgb[i][j];
		}
	}

	cout << *min_element(dp[n - 1], dp[n - 1] + 3);

	return 0;
}