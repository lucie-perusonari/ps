#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 1912

	*문제명 : 연속합

	*문제 설명 :
		  n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

		  예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

	*입력 :
		  첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

	*출력 :
		  첫째 줄에 답을 출력한다.

*/

unordered_map<int, int> cache;
vector<int> sequence;



int compute(int i) {
	if (cache.count(i)) {
		return cache[i];
	}

	int current = sequence[i];

	// early return;
	if (sequence.size() - 1 == i) {
		cache[i] = current;
		return cache[i];
	}

	//* 뒷 부분의 부분합에서 손해가 난다면 멈춤.
	if (compute(i + 1) <= 0) {
		cache[i] = current;
	} else {
		cache[i] = current + compute(i + 1);
	}

	return cache[i];
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

	/**
	 * 부분합을 구할 수 있다. 그리고 부분합을 평가할 수 있음.
	 */

	int max_value = -1001;

	//* 마이너스인 케이스도 처리해야 함.
	for (int i = 0; i < sequence.size(); i++) {
		max_value = max(max_value, compute(i));
	}

	cout << max_value;

}