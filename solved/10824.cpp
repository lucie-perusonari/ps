#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 10824

	*문제명 : 네 수

	*문제 설명 :
		  네 자연수 A, B, C, D가 주어진다. 이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오.

		  두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다. 즉, 20과 30을 붙이면 2030이 된다.

	*입력 :
		  첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)

	*출력 :
		  A와 B를 붙인 수와 C와 D를 붙인 수의 합을 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string arr[4];

	for (int i = 0;i < 4;i++) {
		string str;
		cin >> str;
		arr[i] = str;
	}

	cout << stoll(arr[0] + arr[1]) + stoll(arr[2] + arr[3]);

}