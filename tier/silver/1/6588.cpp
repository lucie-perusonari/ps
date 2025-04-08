#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 6588

	*문제명 : 골드바흐의 추측

	*문제 설명 :
		  1742년, 독일의 아마추어 수학가 크리스티안 골드바흐는 레온하르트 오일러에게 다음과 같은 추측을 제안하는 편지를 보냈다.

		  4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.

		  예를 들어 8은 3 + 5로 나타낼 수 있고, 3과 5는 모두 홀수인 소수이다. 또, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 이다.

		  이 추측은 아직도 해결되지 않은 문제이다.

		  백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오.

	*입력 :
		  입력은 하나 또는 그 이상의 테스트 케이스로 이루어져 있다. 테스트 케이스의 개수는 100,000개를 넘지 않는다.

		  각 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다. (6 ≤ n ≤ 1000000)

		  입력의 마지막 줄에는 0이 하나 주어진다.

	*출력 :
		  각 테스트 케이스에 대해서, n = a + b 형태로 출력한다. 이때, a와 b는 홀수 소수이다. 숫자와 연산자는 공백 하나로 구분되어져 있다. 만약, n을 만들 수 있는 방법이 여러 가지라면, b-a가 가장 큰 것을 출력한다. 또, 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우에는 "Goldbach's conjecture is wrong."을 출력한다.

*/

// 출력 함수.
string result_str(int a, int b, int c) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 시간 제한이 0.5초임. 소수를 일일이 대입하면 확실하게 실패할 것임.
	// 테스트 케이스의 수가 최대 10만개임. 500번 안에 계산을 끝내야한다는 뜻임.

	int prime_count[1000001];

	// 초기화. 각 인덱스 번호가 해당 숫자를 대표함.
	for (int i = 0; i < 1000001; i++) {
		if (i % 2 == 0) {
			prime_count[i] = 0;
		} else {
			prime_count[i] = 1;
		}
	}

	//* 이 2개는 조건에 포함되지 않으므로 제외함.
	prime_count[0] = 0;
	prime_count[1] = 0;

	for (int i = 3; i < 500001; i += 2) {
		if (prime_count[i] == 0) {
			continue;
		}

		for (int k = i * 2; k < 1000001; k += i) {
			prime_count[k] = 0;
		}
	}

	vector<int> prime_list;
	for (int i = 3;i < 1000001;i += 2) {
		if (prime_count[i] == 1) {
			prime_list.push_back(i);
		}
	}

	string result = "";

	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		// 소수 2개를 구하는 로직.
		// 우선 소수로 뺀다. 그리고 나머지 수가 소수인지 확인한다.
		for (int i = 0; i < prime_list.size(); i++) {
			int a = prime_list[i];

			int b = n - a;

			if (prime_count[b] == 1) {
				result += to_string(n) + " = " + to_string(a) + " + " + to_string(b) + "\n";
				break;
			}
		}
	}

	cout << result;

}