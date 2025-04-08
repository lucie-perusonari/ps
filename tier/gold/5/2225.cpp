#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 2225

	*문제명 : 합분해

	*문제 설명 :
		  0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

		  덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

	*입력 :
		  첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

	*출력 :
		  첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

*/
int n, k;

unordered_map<int, unordered_map<int, int>> cache;

long dp(int n, int k) {
	if (cache.count(n) && cache[n].count(k)) {
		return cache[n][k];
	}

	if (n == 0 && k == 0) {
		return 1;
	}

	if (k < 0) {
		cache[n][k] = 0;
		return cache[n][k];
	}

	// n 이상의 값을 뺄 수 없으므로 반드시 n에는 양수가 전달됨.
	long result = 0;
	for (int i = 0; i <= n; i++) {
		result += dp(n - i, k - 1);
	}

	cache[n][k] = result % 1000000000;
	return cache[n][k];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cout << dp(n, k);

}