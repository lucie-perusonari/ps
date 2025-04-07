#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 10808

	*문제명 : 알파벳 개수

	*문제 설명 :
		  알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

	*출력 :
		  단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int size = (int)('z' - 'a');

	vector<int> count(size + 1, 0);

	for (const auto& s : str) {
		int index = s - 'a';
		count[index]++;
	}

	string result = "";

	for (const auto& n : count) {
		result.append(to_string(n));
		result.append(" ");
	}

	result.substr(0, result.size() - 2);

	cout << result;
}