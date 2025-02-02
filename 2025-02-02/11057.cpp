#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 11057

	*문제명 : 오르막 수

	*문제 설명 :
		  오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

		  예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

		  수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

	*입력 :
		  첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

	*출력 :
		  첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

*/

unordered_map<int, unordered_map<int, long long>> cache;
const long long MOD = 10007;


long compute(int n, int k = 0) {
	if (k < 0 || k > 9) return 0;
	if (n == 1) return 1;
	if (cache.count(n) && cache[n].count(k)) {
		return cache[n][k];
	}

	n--;

	long long result = 0;

	for (int i = k; i <= 9; i++) {
		result += compute(n, i);
	}
	result = result % MOD;

	cache[n + 1][k] = result;

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long result = 0;

	for (int i = 0; i <= 9; i++) {
		result += compute(n, i);
	}

	cout << result % MOD;
}