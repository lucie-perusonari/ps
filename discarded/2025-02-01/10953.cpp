#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 10953

	*문제명 : A+B - 6

	*문제 설명 :
		  두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 테스트 케이스의 개수 T가 주어진다.

		  각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. A와 B는 콤마(,)로 구분되어 있다. (0 < A, B < 10)

	*출력 :
		  각 테스트 케이스마다 A+B를 출력한다.

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	string ab;

	cin >> t;

	for (int i = 0;i < t;i++) {
		cin >> ab;

		string a = ab.substr(0, ab.find(",")); //* 길이이므로 인덱스보다 1이 크다.
		string b = ab.substr(ab.find(",") + 1);

		cout << stoi(a) + stoi(b) << endl; // *endl이 문제? 그럴 리가
	}
}