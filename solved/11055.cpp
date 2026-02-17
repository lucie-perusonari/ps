#include <bits/stdc++.h>

using namespace std;

int arr[1000];

int dp[1001];
int prv[1001];
int main() {
	int n;
	cin >> n;


	// dp는 i를 포함하는 최대 크기의 수열.
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < i;j++) {

			// 자신보다 작은 값으로 되는  전부 추가 함.

			if (arr[i] > arr[j]) dp[i] = max(dp[j] + arr[i], dp[i]);
		}
	}


	cout << *max_element(dp, dp + 1001);

}