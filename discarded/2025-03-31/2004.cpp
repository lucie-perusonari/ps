#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 2004

	*문제명 : 조합 0의 개수

	*문제 설명 :
		  (nm)$n \choose m$의 끝자리 0$0$의 개수를 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 정수 n$n$, m$m$ (0≤m≤n≤2,000,000,000$0 \le m \le n \le 2,000,000,000$, n≠0$n \ne 0$)이 들어온다.

	*출력 :
		  첫째 줄에 (nm)$n \choose m$의 끝자리 0$0$의 개수를 출력한다.

*/

// 이 로직으로 팩토리얼의 0의 개수를 구할 수 있음.
int five_count(int a) {
	int zero = 0;

	while (a > 0) {
		zero += a / 5;
		a /= 5;
	}

	return zero;
}

int two_count(int a) {
	int zero = 0;

	while (a > 0) {
		zero += a / 2;
		a /= 2;
	}

	return zero;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	// 조합은 n개 중에서 m개를 뽑았을 때 나올 수 있는 경우의 수. => 순서는 고려하지 않음.
	// 근데 값이 터무니 없이 커짐. 이것도 단순 연산으로는 풀 수 없는 문제인듯.

	int count = 0;

	// 일단 결과 값은 반드시 자연수임.
	// 분모와 분자에서 2와 5의 수를 구함. 2와 5중에서 작은 쪽이 0의 갯수와 같음.

	// 분모는 분자보다 많은 2, 5를 가질 수 있는가?
	// 1. '2와 5의 지수의 갯수'가 팩토리얼에 얼마나 포함되어 있는지 세는 함수가 있다고 가정하자.
	// 2. 이 함수는 n!이 (n-m)!과 m!를 합한 것보다 반드시 크다. floor함수의 성질을 이용하면 증명할 수 있다.
	// 3. n!에서 5의 배수를 세는 것과 n-m!과 m에서 5의 배수를 센 것을 합했을 때, 언제나 n!이 크다.
	// 4. 이게 모든 구간에 대해서 성립한다. 그 말은 분모에서 2와 5의 개수가 모자라서 0이 없어질 일은 없다는 뜻이다.
	// 5. 마지막으로 언제나 조합은 자연수이므로 2와 5의 수를 세서 작은 쪽을 쓰면, 0의 자리가 몇 개인지 알 수 있다.




	int two_result = two_count(n) - (two_count(n - m) + two_count(m));
	int five_result = five_count(n) - (five_count(n - m) + five_count(m));

	int result = (two_result > five_result) ? five_result : two_result;
	cout << result;
}
