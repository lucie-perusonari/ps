#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

/*
	*문제 번호 : 9465

	*문제명 : 스티커

	*문제 설명 :
		  상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

		  상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다. 즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.



		  모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다. 먼저, 그림 (b)와 같이 각 스티커에 점수를 매겼다. 상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오. 즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.

		  위의 그림의 경우에 점수가 50, 50, 100, 60인 스티커를 고르면, 점수는 260이 되고 이 것이 최대 점수이다. 가장 높은 점수를 가지는 두 스티커 (100과 70)은 변을 공유하기 때문에, 동시에 뗄 수 없다.

	*입력 :
		  첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다. 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다. 연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

	*출력 :
		  각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

*/

//* 동적계획법을 이런 방식으로도 사용할 수 있단 걸 알았음.
//* ㅅ

vector<vector<int>> sticker = { vector<int>(0), vector<int>(0) };
unordered_map<int, unordered_map<int, int>> cache;

int greedy(int row, int column) {
	if (cache.count(row) && cache[row].count(column)) {
		return cache[row][column];
	}

	int other_row = (row + 1) % 2;

	//* 인접한 값을 모두 검사함.
	//* 여기서 column + 1과 column + 2가 존재하는지 먼저 검사해야 함.

	if (column + 1 >= sticker[0].size()) {
		cache[row][column] = sticker[row][column];
		return cache[row][column];
	}

	//* 검사.
	if (column + 2 >= sticker[0].size()) {
		cache[row][column] = sticker[row][column] + sticker[other_row][column + 1];
		return cache[row][column];
	}

	//* 스코어가 좋은 쪽으로 감.
	cache[row][column] = sticker[row][column] + max(greedy(other_row, column + 1), greedy(other_row, column + 2));
	return cache[row][column];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;

	while (t--) {
		cin >> n;

		int score = 0;

		//* 스티커는 2n개 만큼 존재함. 길이가 n인 배열이 2개.
		for (int i = 0; i < n; i++) {
			cin >> score;
			sticker[0].push_back(score);
		}
		for (int i = 0; i < n; i++) {
			cin >> score;
			sticker[1].push_back(score);
		}

		cout << max(greedy(0, 0), greedy(1, 0)) << endl;

		sticker[0].clear();
		sticker[1].clear();
		cache.clear();
	}

}