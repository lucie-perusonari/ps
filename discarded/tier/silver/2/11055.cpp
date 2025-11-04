#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 11055

	*문제명 : 가장 큰 증가하는 부분 수열

	*문제 설명 :
		  수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

		  예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가하는 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

	*입력 :
		  첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

		  둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	*출력 :
		  첫째 줄에 수열 A의 합이 가장 큰 증가하는 부분 수열의 합을 출력한다.

*/

unordered_map<int, int> cache;
vector<int> sequence;

//* 
int increase(int index) {
	if (cache.count(index)) {
		return cache[index];
	}

	//* 1. 배열을 뒤져서 자신보다 큰 값을 찾음.
	//* 2. 큰 값을 발견하면 현재 값과 그 값의 합을 더함. 그리고 (1.)로 돌아감.
	//* 3. 더 큰 값이 없다면, 현재 값을 return함.
	int current = sequence[index];
	int max_value = sequence[index];
	for (int i = index + 1; i < sequence.size(); i++) {
		if (sequence[i] > current) {
			max_value = max(max_value, current + increase(i));
		}
	}

	cache[index] = max_value;
	return cache[index];
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


	int max_value = 0;
	for (int i = 0; i < sequence.size(); i++) {
		max_value = max(max_value, increase(i));
	}

	cout << max_value;


}