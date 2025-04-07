#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

/*
	*문제 번호 : 11652

	*문제명 : 카드

	*문제 설명 :
		  준규는 숫자 카드 N장을 가지고 있다. 숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -262보다 크거나 같고, 262보다 작거나 같다.

		  준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오. 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.

	*입력 :
		  첫째 줄에 준규가 가지고 있는 숫자 카드의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 숫자 카드에 적혀있는 정수가 주어진다.

	*출력 :
		  첫째 줄에 준규가 가장 많이 가지고 있는 정수를 출력한다.

*/

map<long long, int> counting_map;

// bool compare(pair<long long, int> a, pair<long long, int> b) {
// 	return a.second < b.second;
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long before_number;


	while (n--) {
		long long a;
		cin >> a;

		if (counting_map.count(a)) {
			counting_map[a]++;
		} else {
			counting_map[a] = 1;
		}
	}

	pair<long long, int> result = *counting_map.begin();

	for (const auto& entiry : counting_map) {
		if (entiry.second > result.second) {
			result = entiry;
		}
		if (entiry.second == result.second) {
			if (result.first > entiry.first) {
				result = entiry;
			}
		}
	}

	cout << result.first;


}