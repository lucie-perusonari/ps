#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 10820

	*문제명 : 문자열 분석

	*문제 설명 :
		  문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

		  각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

	*입력 :
		  첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

	*출력 :
		  첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	while (getline(cin, str)) {
		int lower = 0;
		int upper = 0;
		int number = 0;
		int blank = 0;

		for (const auto& c : str) {
			if (c >= 'a' && c <= 'z') {
				lower++;
			}
			if (c >= 'A' && c <= 'Z') {
				upper++;
			}
			if (c >= '0' && c <= '9') {
				number++;
			}
			if (c == ' ') {
				blank++;
			}
		}

		cout << lower << ' ' << upper << ' ' << number << ' ' << blank << "\n";
	}




}