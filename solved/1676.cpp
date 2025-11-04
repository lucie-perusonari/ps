#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 1676

	*문제명 : 팩토리얼 0의 개수

	*문제 설명 :
		  N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

	*출력 :
		  첫째 줄에 구한 0의 개수를 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// N!은 너무 큰데? 연산을 하기 전에 추측할 수 있어야겠는데?

	int count = 0;

	// 팩토리얼은 인수분해한다고 생각해보자. 5로 나눠지면 그만큼 0을 붙일 수 있다.
	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp > 1) {
			if (temp % 5 == 0) {
				count++;
				temp /= 5;
			} else {
				break;
			}
		}
	}

	cout << count;

}