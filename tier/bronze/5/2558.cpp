#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2558

	*문제명 : A+B - 2

	*문제 설명 :
		  두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 A, 둘째 줄에 B가 주어진다. (0 < A, B < 10)

	*출력 :
		  첫째 줄에 A+B를 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	cin >> a >> b;

	cout << a + b;

}