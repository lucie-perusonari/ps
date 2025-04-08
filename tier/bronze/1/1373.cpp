#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 1373

	*문제명 : 2진수 8진수

	*문제 설명 :
		  2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

	*출력 :
		  첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	cin >> a;

	//* 일단 노가다로 풀고 포맷팅으로 풀자.
	//* 2^1000000 -1까지 다뤄야 함. 터무니 없는 숫자인게 가장 큰 문제.
	//* 강제로 숫자가 아니라 그냥 문자열로 다루라는 소리임.

	reverse(a.begin(), a.end());

	long long decimal = 0;


	//* 2^0,1,2, 는 8진수의 첫 째자리.
	//* 2^3,4,5 => 2^3 *(2^0,1,2) 는 8진수의 둘 째자리.
	//* 문제는 인덱스를 넘어가면 어떻게 대처할지임.
	//* 숫자가 아예 0일 때에 어떻게 처리할지도 생각해야 함.

	int count = (a[0] == '1') ? 1 : 0;

	string octa = "";


	for (int i = 1; i < a.size();i++) {
		if (i % 3 == 0) {
			octa += to_string(count);
			count = 0;
		}

		if (a[i] == '1') {
			count += pow(2, i % 3);
		}
	}

	octa += to_string(count);

	reverse(octa.begin(), octa.end());

	cout << octa;
}