#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 11053

	*문제명 : 가장 긴 증가하는 부분 수열

	*문제 설명 :
		  수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

		  예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

	*입력 :
		  첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

		  둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	*출력 :
		  첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

*/

vector<int> numbers;
unordered_map<int, int> cache;

//* i값에서 시작해서 순서를 밟아나감.
//* 이 문제는 두고두고 복습해야할 것 같음.
int increase(int n) {
	if (cache.count(n)) {
		return cache[n];
	}

	int max_length = 1;
	for (int i = n + 1; i < numbers.size(); i++) {
		if (numbers[n] >= numbers[i]) {
			continue;
		}

		max_length = max(max_length, 1 + increase(i));
	}

	cache[n] = max_length;

	return max_length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ai;
	cin >> n;

	while (n--) {
		cin >> ai;
		numbers.push_back(ai);
	}

	int max_length = 0;
	for (int i = 0; i < numbers.size(); i++) {
		max_length = max(max_length, increase(i));
	}

	cout << max_length;
}