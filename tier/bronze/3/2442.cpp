#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2442

	*문제명 : 별 찍기 - 5

	*문제 설명 :
		  첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2×N-1개를 찍는 문제

		  별은 가운데를 기준으로 대칭이어야 한다.

	*입력 :
		  첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

	*출력 :
		  첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

*/

string write_star(int count) {
	string str;
	for (int i = 0;i < count;i++) {
		str.append("*");
	}

	return str;
}

string write_blank(int count) {
	string str;
	for (int i = 0;i < count;i++) {
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

	int padding;

	string str;
	for (int i = 0; i < n; i++) {
		int current = (2 * (i + 1)) - 1;

		padding = (max / 2) - (current / 2);

		str.append(write_blank(padding));
		str.append(write_star(current));
		str.append("\n");
	}

	str.pop_back();

	cout << str;


}