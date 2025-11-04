#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 2156

	*문제명 : 포도주 시식

	*문제 설명 :
		  효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.


			포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
			연속으로 놓여 있는 3잔을 모두 마실 수는 없다.


		  효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 

		  예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

	*입력 :
		  첫째 줄에 포도주 잔의 개수 n이 주어진다. (1 ≤ n ≤ 10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.

	*출력 :
		  첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.

*/

//* n!을 구하는 것과 유사함.

vector<int> wines;
unordered_map<int, unordered_map<int, int>> cache;

//* 모든 경우의 수를 다 고려했는지 생각해봐야함.
//* 이번 문제 같은 경우에는, i+2를 해주지 않으면 1001같은 형태가 구조상 나올 수 없음.
int drink(int i, int count) {
	if (cache.count(i) && cache[i].count(count)) {
		return cache[i][count];
	}

	if (count == 2) {
		cache[i][count] = max(drink(i + 1, 0), drink(i + 2, 0));
		return cache[i][count];
	}

	if (i >= wines.size()) {
		return 0;
	}

	cache[i][count] = max(wines[i] + drink(i + 1, count + 1), wines[i] + drink(i + 2, 0));

	return cache[i][count];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int wine;
		cin >> wine;
		wines.push_back(wine);
	}

	int count = wines.size();

	int drink_max = 0;

	for (int i = 0; i < count; i++) {
		drink_max = max(drink_max, drink(i, 0));
	}

	cout << drink_max;

}