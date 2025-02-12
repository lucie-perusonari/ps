#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 2579

	*문제명 : 계단 오르기

	*문제 설명 :
		  계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. <그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다.



		  <그림 1>

		  예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째 계단을 밟아 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다.



		  <그림 2>

		  계단 오르는 데는 다음과 같은 규칙이 있다.


			계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
			연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
			마지막 도착 계단은 반드시 밟아야 한다.


		  따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.

		  각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

	*입력 :
		  입력의 첫째 줄에 계단의 개수가 주어진다.

		  둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다. 계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.

	*출력 :
		  첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.

*/


vector<int> sequence;
unordered_map<int, int> cache;

//* 메모이제이션을 어케하지?
int compute(int i = 0, bool is_stepped = false) {
	if (i >= sequence.size()) {
		return 0;
	}

	int current = sequence[i];

	// 2칸 뛰기.
	if (is_stepped) {
		// cache[i] = current + compute(i + 2);
		return current + compute(i + 2);
	}

	//* 만일 3번째인 경우 이 캐시 값은 사용할 수 없음.
	if (cache.count(i)) {
		return cache[i];
	}

	cache[i] = max(current + compute(i + 1, true), current + compute(i + 2));
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

	//* 마지막 계단 밟기 설정하기 귀찮으니 뒤집음.
	reverse(sequence.begin(), sequence.end());

	/*
		1. 특정 인덱스에서 계단을 밟는 경우의 수는 2개.
		2. 연속으로 3개는 못 밟음.
		3. 마지막 계단은 무조건 밟아야 함.
	*/

	cout << compute();
}