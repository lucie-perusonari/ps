#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2609

	*문제명 : 최대공약수와 최소공배수

	*문제 설명 :
		  두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

	*출력 :
		  첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

*/

//* 확실하지 않음.
int euclid(int a, int b) {
	int n = a % b;

	if (n == 0) {
		return b;
	}

	return euclid(b, n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	cin >> a >> b;

	bool counting[10001];

	vector<int> prime;

	//* 체.
	for (int i = 0;i < 10000;i++) {
		counting[i + 1] = false;
	}

	for (int i = 2;i <= 10000;i++) {
		//* 거르지 않은 값이라면 체 거르기 실행.
		if (counting[i] == true) {
			continue;
		}

		//* 체 거르기.
		prime.push_back(i);
		for (int k = i;k <= 10000; k += i) {
			counting[k] == true;
		}
	}

	int min = euclid(a, b);
	int max = 1;

	//* 최소 공배수는 가장 조금 곱해서 두 수가 같아지게 만드는 것. => 비교해서 서로 모자란 부분을 채워주면 됨.
	// for (int i = 0;i < prime.size();i++) {
	// 	if (a % prime[i] == 0 || b % prime[i] == 0) {
	// 		if (a % prime[i] == 0) {
	// 			a /= prime[i];
	// 		}
	// 		if (b % prime[i] == 0) {
	// 			b /= prime[i];
	// 		}
	// 		max *= prime[i];
	// 		i--;
	// 	}
	// }

	//* 하지만 위는 좋은 방법이 아님. 
	// 최대 공약수로 수를 나누면, 두 수에 겹치는 숫자들이 제거 됨. => 그러면
	max = a * b / min;



	cout << min << "\n" << max;

}