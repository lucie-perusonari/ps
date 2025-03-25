#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

/*
	*문제 번호 : 2089

	*문제명 : -2진수

	*문제 설명 :
		  -2진법은 부호 없는 2진수로 표현이 된다. 2진법에서는 20, 21, 22, 23이 표현 되지만 -2진법에서는 (-2)0 = 1, (-2)1 = -2, (-2)2 = 4, (-2)3 = -8을 표현한다. 10진수로 1부터 표현하자면 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001 등이다.

		  10진법의 수를 입력 받아서 -2진수를 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫 줄에 10진법으로 표현된 수 N이 주어진다.

	*출력 :
		  -2진법 수를 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	//* n이 양심적인 크기로 들어왔음.
	int n;
	cin >> n;

	string binary = "";


	//* 1. -2진법은 수열에 -2를 나누면 앞의 항이 무엇인지 알 수 있다. n은 규칙을 가진 수열이다. 
	//* 그렇다면 -2/를 나눈 후 나머지를 구한다. n의 각 항이 존재하는지 존재하지 않는 지 확인한다.
	//* 나머지가 0인 경우는 신경 쓸 필요없다. /-2를 곱해도 0이다.
	//* 하지만 나머지가 1인 경우 /-2를 하게 되면 그 값은 다음 연산 때 1/2 혹은 -1/2가 된다.
	while (abs(n) > 0) {
		int mod = n % -2;

		if (mod == 0) {
			n /= -2;
			binary += "0";
			continue;
		}

		if (n < 0) {
			n /= -2;
			n++;

			binary += "1";
			continue;
		} else {
			n /= -2;
			binary += "1";
			continue;
		}
	}

	reverse(binary.begin(), binary.end());

	if (binary.size() == 0) {
		binary = "0";
	}

	cout << binary;

}