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

	/*
		- x축으로도 y축으로도 대칭이다.
		- 그래서 나는 인덱스가 0일 때와 n-1일 때 동일한 값을 지니게 만드는 자연수를 찾고 싶다.

		|0 - x| = |n - 1 - x| 인 자연수 x는 뭔가?

		1. 절대값이므로 n - 1 = 2x 가 성립한다. (각각 음수와 양수이니 둘 다 더하면 0일 것.)
		2. (n - 1) / 2 가 그 값이다.
		3. 여기서 max를 대입하면... (2 * n - 2) / 2가 되어서 정수 값이 나온다. => (n - 1)
		4. 만일 (n - 1) / 2 가 분수인 경우에는 어떡하나?
			4. 1. 반복문은 수열이다. 수열은 자연수만을 인덱스로 가질 수 있다.
			4. 2. 이런데 분수 값이 나왔다는 뜻은, 수리적으로 해당 값이 존재하지 않는다는 뜻이다.
	*/


	// //* 대칭을 어떻게 깔끔하게 구현하지?
	// for (int i = 0;i < n;i++) {
	// 	int a = abs(i - n / 2); //* n/2를 i에 뺀 뒤, 절대값을 취하면 대칭이 됨. 0일 때 최소였으니, 최대가 됨.

	// 	//* 이후 a에 -를 취하면, 값이 반전되어서, 중앙일 때가 최대값이 됨.
	// 	//* 그런데 a값이 음수이므로, 0이 되게끔 값을 더해 줌. a는 -n/2이므로 n/2를 더해주는 것.
	// 	int b = n / 2 - a; //*0일 때 n/2가 나오므로 n/2가 최대값임. 
	// }

	for (int i = 0; i < 2 * n - 1; i++) {
		int current = (2 * n - 1) / 2 - abs(i - (2 * n - 1) / 2);
		int star = current + 1;
		int blank = (n * 2 - star * 2);

		str.append(wrtie_star(star));
		str.append(wrtie_blank(blank));
		str.append(wrtie_star(star));
		str.append("\n");
	}

	cout << str;
}