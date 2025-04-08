#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 2741

	*문제명 : N 찍기

	*문제 설명 :
		  자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.

	*출력 :
		  첫째 줄부터 N번째 줄 까지 차례대로 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str;

	for (int i = 0;i < n;i++) {
		str.append(to_string(i + 1) + "\n");
	}

	cout << str;

}