#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;



/*
	*문제 번호 : 10844

	*문제명 : 쉬운 계단 수

	*문제 설명 :
		  45656이란 수를 보자.

		  이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

		  N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

	*입력 :
		  첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

	*출력 :
		  첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

*/

unordered_map<int, unordered_map<int, long long>> cache;
const long long MOD = 1000000000;


long compute(int n, int k = 0) {
	if (k < 0 || k > 9) return 0;
	if (n == 1) return 1;
	if (cache.count(n) && cache[n].count(k)) {
		return cache[n][k];
	}

	n--;

	long long result = compute(n, k - 1) + compute(n, k + 1);
	result = result % MOD;

	cache[n + 1][k] = result;

	return result;
}

//* 처음 n을 설정하면 그 다음 값은 2개로 제한됨. 따라서 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long result = 0;

	for (int i = 1; i < 10; i++) {
		result += compute(n, i);
	}

	cout << result % MOD;

}