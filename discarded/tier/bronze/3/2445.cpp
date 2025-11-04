#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
		*문제 번호 : 2445

		*문제명 : 별 찍기 - 8

		*문제 설명 :
			예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

		*입력 :
			첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

		*출력 :
			첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

*/

string wrtie_star(int count) {
	string str;
	for (int i = 0; i < count; i++) {
		str.append("*");
	}
	return str;
}

string wrtie_blank(int count) {
	string str;
	for (int i = 0; i < count; i++) {
		str.append(" ");
	}
	return str;
}

//* 최대한 간단하게 구현한 버전.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str;
	int max = 2 * n - 1;

	//* x축으로도 y축으로도 대칭이다.

	//* max/2
	for (int i = 1; i < (max / 2) + 1; i++) {
		str.append(wrtie_star(i));
		str.append(wrtie_blank((n * 2) - i * 2));
		str.append(wrtie_star(i));
		str.append("\n");
	}

	//* n
	str.append(wrtie_star(n));
	str.append(wrtie_star(n));
	str.append("\n");

	// n + max/2
	for (int i = 1; i < (max / 2) + 1; i++) {
		int k = (max / 2) + 1 - i;

		str.append(wrtie_star(k));
		str.append(wrtie_blank((n * 2) - k * 2));
		str.append(wrtie_star(k));
		str.append("\n");
	}

	cout << str;
}