#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 10951

	*문제명 : A+B - 4

	*문제 설명 :
		  두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

	*입력 :
		  입력은 여러 개의 테스트 케이스로 이루어져 있다.

		  각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)

	*출력 :
		  각 테스트 케이스마다 A+B를 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	//* 문제 사이트에서 알아서 EOF를 반환해줘야 함.
	while (cin >> a >> b) {
		cout << a + b << endl;
	}

}