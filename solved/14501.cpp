#include<bits/stdc++.h>

using namespace std;

int day[16];
int money[16];
int dp[16];

int main() {
	// 오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
	// 각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> day[i + 1] >> money[i + 1];
	};

	// 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
	// n이 크지 않네? N일은 여러 일이 될 수 있음. 결국 N-M일의 최대값을 구하면 N일의 최대값도 구할 수 있음.
	// 최대한 많은 상담을 구해야 함.

	// i일에 시작해서 n일까지
	for (int i = 1;i <= n;i++) {

		// 1. i일 차 상담을 한다고 가정함. 
		// 2. day를 참조해서 현재 일자에 가져갈 수 없는 값이라면 포기함.
		// 3. 현재 일자의 작업을 판별함. 유효하다면 money를 더하고 종료.

		for (int j = 1;j < i;j++) {
			// 현재 일자 전에 할 수 있는 최대값을 구함.
			if (i >= day[j] + j) {
				dp[i] = max(dp[i], dp[j]);
			}
		}

		if (i + day[i] <= n + 1) {
			dp[i] += money[i];
		}
	}

	cout << *max_element(dp, dp + 16);


}