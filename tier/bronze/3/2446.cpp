#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2446

	*문제명 : 별 찍기 - 9

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int max = 2 * n - 1;

	string str;
	for (int i = 0; i < max; i++) {
		int blank = n - 1 - abs(i - (n - 1));
		int star = max - blank * 2;

		str.append(wrtie_blank(blank) + wrtie_star(star) + "\n");
	}

	str.pop_back();
	cout << str;
}