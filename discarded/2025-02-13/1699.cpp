#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 1699

	*문제명 : 제곱수의 합

	*문제 설명 :
		  어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 예를 들어 11=3^2+1^2+1^2(3개 항)이다.
		  이런 표현방법은 여러 가지가 될 수 있는데, 11의 경우 11=2^2+2^2+1^2+1^2+1^2(5개 항)도 가능하다.
		  이 경우, 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다.
		  또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로, 11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.

		  주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

	*출력 :
		  주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.

*/

unordered_map<int, int> cache;
//n을 처음부터 sqrt_num이하의 모든 자연수에 대입해봐야 한다.
int compute(int n) {
	int sqrt_num = sqrt(n);

	if (n == 0) {
		return 0;
	}

	if (cache.count(n)) {
		return cache[n];
	}

	int min_length = 100001;

	// sqrt_num의 특성 때문에, mod가 음수가 될 수 없음.
	while (sqrt_num > 0) {
		int mod = n - pow(sqrt_num, 2);
		min_length = min(min_length, 1 + compute(mod));

		sqrt_num--;
	}

	cache[n] = min_length;
	return cache[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << compute(n);
}