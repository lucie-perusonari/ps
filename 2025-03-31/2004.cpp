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
int five_count(int a, int b = 0) {
	int zero = 0;

	while (a > 0) {
		zero += a / 5;
		a /= 5;
	}

	while (b > 0) {
		zero += b / 5;
		b /= 5;
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

int zero_count(int a) {
	int zero_count = min(five_count(a), two_count(a));

	return zero_count;
}

unordered_map<int, int> test_case = { {1000, 249}, {10000, 2499}, {100000, 24999}, {1000000, 249998}, {20000000, 4999999}, {30000000, 7499998} };

void test() {
	for (const auto& entity : test_case) {
		int oracle = five_count(entity.first);
		if (five_count(entity.first) == entity.second) {
			cout << entity.first << " : " << oracle << " : 성공!" << endl;
		} else {
			cout << entity.first << " : " << oracle << " : 실패!" << endl;
		};
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	// 조합은 n개 중에서 m개를 뽑았을 때 나올 수 있는 경우의 수. => 순서는 고려하지 않음.
	// 근데 값이 터무니 없이 커짐. 이것도 단순 연산으로는 풀 수 없는 문제인듯.

	int count = 0;


	// n!/((n-m)!*m!)
	// 팩토리얼의 0 구하는 로직을 찾았음. 이를 이용하면 해볼만할 것 같음.
	int result = zero_count(n) - (zero_count(n - m) + zero_count(m));

	cout << result;
}