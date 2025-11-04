#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 11054

	*문제명 : 가장 긴 바이토닉 부분 수열

	*문제 설명 :
		  수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

		  예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

		  수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

	*출력 :
		  첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

*/

//* 특정 구간의 값을 담음.
//* 해당 인덱스에서 지닐 수 있는 최대 값들을 담음.
unordered_map<int, int> increase_cache;
unordered_map<int, int> decrease_cache;

vector<int> sequence;

int decrease(int index) {
	if (decrease_cache.count(index)) {
		return decrease_cache[index];
	}

	int current = sequence[index];

	int max_length = 1;
	for (int i = index + 1; i < sequence.size(); i++) {
		if (sequence[i] < current) {
			max_length = max(max_length, 1 + decrease(i));
		}
	}

	decrease_cache[index] = max_length;

	return decrease_cache[index];
}

int increase(int index) {
	if (increase_cache.count(index)) {
		return increase_cache[index];
	}

	int current = sequence[index];

	int max_length = 1;
	for (int i = index + 1; i < sequence.size(); i++) {
		if (sequence[i] > current) {
			max_length = max(max_length, 1 + increase(i));
		}

		if (sequence[i] < current) {
			max_length = max(max_length, 1 + decrease(i));
		}
	}

	increase_cache[index] = max_length;

	return increase_cache[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;
		sequence.push_back(a);
	}

	/*
		먼저 증가하는 수열을 구하고, 감소하는 수열을 구한다.
	*/

	int max_value = 0;

	for (int i = 0; i < sequence.size();i++) {
		max_value = max(max_value, increase(i));
	}

	cout << max_value;
}