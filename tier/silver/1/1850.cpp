#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 1850

	*문제명 : 최대공약수

	*문제 설명 :
		  모든 자리가 1로만 이루어져있는 두 자연수 A와 B가 주어진다. 이때, A와 B의 최대 공약수를 구하는 프로그램을 작성하시오.

		  예를 들어, A가 111이고, B가 1111인 경우에 A와 B의 최대공약수는 1이고, A가 111이고, B가 111111인 경우에는 최대공약수가 111이다.

	*입력 :
		  첫째 줄에 두 자연수 A와 B를 이루는 1의 개수가 주어진다. 입력되는 수는 2^63보다 작은 자연수이다.

	*출력 :
		  첫째 줄에 A와 B의 최대공약수를 출력한다. 정답은 천만 자리를 넘지 않는다.

*/

long long euclid(long long a, long long b) {
	long long r = a % b;

	if (r == 0) {
		return b;
	}

	return euclid(b, r);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;

	cin >> a >> b;

	//* 최대 공약수는 두 수를 나눌 수 있는 가장 큰 수.
	long long min_length = min(a, b);
	long long max_length = max(a, b);

	string result = "";
	for (int i = 0;i < euclid(max_length, min_length);i++) {
		result += "1";
	}

	cout << result;

}