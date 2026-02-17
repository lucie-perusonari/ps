#include <bits/stdc++.h>

using namespace std;

int dp[15];
int main() {
	int t;
	cin >> t;

    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=4;i<=15;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
	while (t--) {
		int n;
		cin >> n;

		cout << dp[n] << endl;
	}
} 