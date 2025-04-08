#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 2011

	*문제명 : 암호코드

	*문제 설명 :
		  상근이와 선영이가 다른 사람들이 남매간의 대화를 듣는 것을 방지하기 위해서 대화를 서로 암호화 하기로 했다. 그래서 다음과 같은 대화를 했다.


			상근: 그냥 간단히 암호화 하자. A를 1이라고 하고, B는 2로, 그리고 Z는 26으로 하는거야.
			선영: 그럼 안돼. 만약, "BEAN"을 암호화하면 25114가 나오는데, 이걸 다시 글자로 바꾸는 방법은 여러 가지가 있어.
			상근: 그렇네. 25114를 다시 영어로 바꾸면, "BEAAD", "YAAD", "YAN", "YKD", "BEKD", "BEAN" 총 6가지가 나오는데, BEAN이 맞는 단어라는건 쉽게 알수 있잖아?
			선영: 예가 적절하지 않았네 ㅠㅠ 만약 내가 500자리 글자를 암호화 했다고 해봐. 그 때는 나올 수 있는 해석이 정말 많은데, 그걸 언제 다해봐?
			상근: 얼마나 많은데?
			선영: 구해보자!


		  어떤 암호가 주어졌을 때, 그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 5000자리 이하의 암호가 주어진다. 암호는 숫자로 이루어져 있다.

	*출력 :
		  나올 수 있는 해석의 가짓수를 구하시오. 정답이 매우 클 수 있으므로, 1000000으로 나눈 나머지를 출력한다.

		  암호가 잘못되어 암호를 해석할 수 없는 경우에는 0을 출력한다.

*/

unordered_map<string, unordered_map<int, long long>> cache;

// 길이가 너무 길어서 답이 없음. 하나하나씩 떼서 계산해야 함.
// size_t가 음수가 되면 어떻게 되는 거지? => 언더플로우가 나잖아?
long long dp(string str, int length = 0) {
	if (cache.count(str) && cache[str].count(length)) {
		long long result = cache[str][length];
		return result;
	}

	// 이 값이 0인 경우에는 딱코라는 뜻.
	if (str.length() < length || str[0] == '0') {
		return 0;
	}

	// 10, 20과 같은 애매한 길이의 숫자를 처리해주기 위해 사용.
	if (length == 1 && str.length() == 2 && str[1] == '0') {
		return 0;
	}

	// 길이가 0일 수도 있음.
	int number = stoi(str.substr(0, length));

	if (number > 26) {
		return 0;
	}

	// 원활한 캐싱을 위해 따로 선언함.
	string new_str = str.substr(length, str.length() - length);

	if (new_str.length() == 0) {
		return 1;
	}

	cache[str][length] = (dp(new_str, 1) + dp(new_str, 2)) % 1000000;
	return cache[str][length];
}


/*
	1. 과도하게 큰 숫자를 받지 못하는가?
	2. 0 처리에는 문제가 없는가? 0이 앞에 있는 경우, 0이 뒤에 있는 경우.
	3. 26 초과 처리에는 문제가 없는가?
	4. str 파싱에는 문제가 없는가?
	5.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	if (str[0] == '0') {
		cout << 0 << endl;
		return 0;
	}

	// 0이면 왼쪽 값을 검사. 3 이상이거나 0 같은 해석불가 케이스를 제거함.
	for (int i = 1;i < str.size();i++) {
		if (str[i] == '0') {
			int a = (int)(str[i - 1] - '0');
			if (a > 2 || a == 0) {
				cout << 0 << endl;
				return 0;
			}
		}
	}

	// 10 같은 경우에는 1이 나와야 함. 1010 같은 경우는 2가 나와야 함.
	// 0이 있는지 없는지 검사하는 것이 중요할 듯.
	cout << (dp(str, 1) + dp(str, 2)) % 1000000 << endl;
}