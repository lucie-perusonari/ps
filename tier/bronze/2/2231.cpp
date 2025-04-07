#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2231

	*문제명 : 분해합

	*문제 설명 :
		  어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

		  자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

	*출력 :
		  첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.

*/

int main() {
	int n;

	cin >> n;

	int min = n;

	for (int i = 1;i <= n;i++) {
		int num1, num2, num3, num4, num5, num6, num7;

		num1 = i % 10;           // 1의 자리
		num2 = i % 100 / 10;     // 10의 자리
		num3 = i % 1000 / 100;   // 100의 자리
		num4 = i % 10000 / 1000; // 1000의 자리
		num5 = i % 100000 / 10000; // 10000의 자리
		num6 = i % 1000000 / 100000; // 100000의 자리
		num7 = i % 10000000 / 1000000; // 1000000의 자리

		if (i + (num1 + num2 + num3 + num4 + num5 + num6 + num7) == n) {
			min = i;
			break;
		};
	}

	if (min == n) min = 0;

	cout << min;


}