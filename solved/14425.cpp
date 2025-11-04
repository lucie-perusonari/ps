#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 14425

	*문제명 : 문자열 집합

	*문제 설명 :
		  총 N개의 문자열로 이루어진 집합 S가 주어진다.

		  입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다.

		  다음 N개의 줄에는 집합 S에 포함되어 있는 문자열들이 주어진다.

		  다음 M개의 줄에는 검사해야 하는 문자열들이 주어진다.

		  입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러 번 주어지는 경우는 없다.

	*출력 :
		  첫째 줄에 M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는지 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	unordered_map<string, bool> check_map;

	while (n--) {
		string str;
		cin >> str;

		check_map[str] = true;
	}

	int result = 0;

	while (m--) {
		string str;
		cin >> str;

		if (check_map.count(str)) {
			result++;
		};
	}

	cout << result;

}