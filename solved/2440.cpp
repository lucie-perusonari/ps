#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2440

	*문제명 : 별 찍기 - 3

	*문제 설명 :
		  첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

	*입력 :
		  첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

	*출력 :
		  첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str;
	for (int k = 0;k < n; k++) {
		for (int i = 0;i < n - k;i++) {
			str.append("*");
		}
		str.append("\n");
	}

	str.pop_back();

	cout << str;

}