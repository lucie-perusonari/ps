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

// =메모1
// 우선 위와 아래를 인수분해된 형태로 생각해보자. => 
// 위와 아래를 인수분해해서 10만 추려낼 수 있을 것이다. 이게 기본적인 0의 갯수를 결정한다.
// 일단 5의 배수를 제외한 홀수는 반드시 포함된다.
// 그러나 10을 다 빼내더라도, 분수가 자연수가 아닐 가능성이 있다. 이 경우 0이 소수점만큼 사라진다.

// 근데 나올 지는 모르겠는데, 순환 소수면 0자리가 아예 없는 거잖아? => 이걸 알기 위해서는 역시 성질을 알아야 함.
// (n-m)!을 나누면 n은 n부터 n-m+1까지의 곱이 된다. 이를 m!으로 나누는 계산이다. (m<=n)
// m이 최대이더라도 결과 값은 반드시 1 이상이다.
// 그리고 논리적으로 분수 조합이란 존재하지 않으므로, 반드시 자연수가 최종 값이 될 것임.

// =메모2
// 이 문제는 조합의 뒷자리에 0이 얼마나 있는지를 구하라는 문제이다. 이걸 다른 동일한 문제로 바꿀 수 없을까?
	// 1. 계산 결과에서 10이 몇 번이나 곱해졌는지 구하라 => 이건 아님. 왜냐하면 분수가 존재할 수 있음.
	// 2. 그런데 분수가 존재한다고 해도 10이 있으면 다 해결이 되는가? 그렇지 않음. 최소 공배수를 알아야 함.
	// 3. 논리적으로 결과 값은 자연수가 되어야 함. 그렇다면 10의 곱을 완벽하게 구할 수 있을 거임.
	// 4. 근데 대체 어떤 이유로 반드시 자연수가 될 수 있는 거지?
		// 4.1. 분자와 분모의 곱의 개수는 반드시 동일 함. 각각 n 앞에서 m개를 곱한 것과, 뒤에서 m개를 곱한 것과 같음.

// =메모3
// 조합은 n개를 m개 넣은 다음. m!을 나누는 거임.
// n이 m번 뽑히는 모든 경우의 수에서 m!을 나눠주는 것. (순서를 신경쓰지 않음.)
// => 그리고 적어도 m!의 0의 개수는 구할 수 있음. 

// m만큼 n을 넣는다. 이건 m의 입장에서 봤을 때, 정렬된 순서로 n을 넣으라는 의미이기도 하다. => 뒤가 앞보다 계속 크거나, 계속 작거나.
// => 일단 이 접근법은 생각은 해두겠지만, 경우의 수를 상상하는 것만으로는 정답을 못 낼 것 같음.

// 10  9  8  7  6  5  4  3  2  1 => 9 8 7 6 4 3 1, 10 5 2
// 20 19 18 17 16 15 14 13 12 11 => 19 18 17 16 14 13 11, 20 15 12
