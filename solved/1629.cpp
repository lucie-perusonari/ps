#include <iostream>
#include <math.h>

using namespace std;


// 기본적으로 long long을 사용해야 함.
// 
int main() {
	long long a, b, c;

	cin >> a >> b >> c;

	long long result = 1;


	// 제곱하면서 나머지를 구한다는 발상 자체는 통하는 것 같음.
	// 코드로 정확하게 어떻게 구현해야할까?
	// 1. b가 짝수면 a를 제곱하고 b를 반으로 나눈다.
	// 2. b가 홀수면 결과값에 a를 곱하고, a를 제곱한뒤 b를 반으로 나눈다.
	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % c;
		}

		a = (a * a) % c;
		b /= 2;
	}

	cout << result;
}
