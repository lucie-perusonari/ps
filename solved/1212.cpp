#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 1212

	*문제명 : 8진수 2진수

	*문제 설명 :
		  8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.

	*출력 :
		  첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	cin >> a;

	reverse(a.begin(), a.end());


	string binary = "";

	//* 8진수를 어떻게 2진수 3코드로 바꾸지?
	//* 그보다 역순으로 구하니 너무 혼란스러움.
	for (int i = 0;i < a.size() - 1;i++) {
		int octa = a[i] - '0';
		switch (octa)
		{
			case 0:
				binary += "000";
				break;
			case 1:
				binary += "100";
				break;
			case 2:
				binary += "010";
				break;
			case 3:
				binary += "110";
				break;
			case 4:
				binary += "001";
				break;
			case 5:
				binary += "101";
				break;
			case 6:
				binary += "011";
				break;
			case 7:
				binary += "111";
				break;
		}
	}

	switch (a.back() - '0')
	{
		case 0:
			if (binary.size() == 0) {
				binary = "0";
			}
			break;
		case 1:
			binary += "1";
			break;
		case 2:
			binary += "01";
			break;
		case 3:
			binary += "11";
			break;
		case 4:
			binary += "001";
			break;
		case 5:
			binary += "101";
			break;
		case 6:
			binary += "011";
			break;
		case 7:
			binary += "111";
			break;
	}

	reverse(binary.begin(), binary.end());

	cout << binary;

}