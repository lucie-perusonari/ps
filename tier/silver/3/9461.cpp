#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 9461

	*문제명 : 파도반 수열

	*문제 설명 :
		  오른쪽 그림과 같이 삼각형이 나선 모양으로 놓여져 있다. 첫 삼각형은 정삼각형으로 변의 길이는 1이다. 그 다음에는 다음과 같은 과정으로 정삼각형을 계속 추가한다. 나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가한다.

		  파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이이다. P(1)부터 P(10)까지 첫 10개 숫자는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9이다.

		  N이 주어졌을 때, P(N)을 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. (1 ≤ N ≤ 100)

	*출력 :
		  각 테스트 케이스마다 P(N)을 출력한다.

*/

unordered_map<int, long> cache = { {1, 1}, {2, 1}, {3, 1}, {4, 2}, {5, 2}, {6, 3}, {7, 4}, {8, 5}, {9, 7}, {10, 9} };

long dp(int n) {
	if (cache.count(n)) {
		return cache[n];
	}

	if (n <= 0) {
		return 0;
	}

	if (n <= 10) {
		return cache[n];
	}

	cache[n] = dp(n - 1) + dp(n - 5);
	return cache[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 어느 정도 이전 값들의 영향을 받아서 이후의 값이 결정되는 것 같다. 하지만 초반의 생성 원리를 모르겠음.

	// 삼각형을 붙인다는 뜻은 현재 도형에서 변을 하나 없얘고, 2개의 변을 추가한다는 뜻이다.
	// 그렇다면 남은 하나의 변은 어떻게 되는지 예측할 수 있는가?

	while (n--) {
		int a;
		cin >> a;
		cout << dp(a) << "\n";
	}
}