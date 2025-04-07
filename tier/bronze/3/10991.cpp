#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 10991

	*문제명 : 별 찍기 - 16

	*문제 설명 :
		  예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

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

	//2n-1개에서

	string str;
	for (int i = 0;i < n;i++) {
		int blank = n - i - 1;

		int stars_count = ((i + 1) * 2) - 1;

		for (int k = 0;k < blank;k++) {
			str.append(" ");
		}

		for (int k = 0; k < stars_count; k++) {
			if (k % 2 == 0) {
				str.append("*");
			} else {
				str.append(" ");
			};
		}

		str.append("\n");
	}

	str.pop_back();

	cout << str;

}