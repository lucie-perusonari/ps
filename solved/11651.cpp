#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 11651

	*문제명 : 좌표 정렬하기 2

	*문제 설명 :
		  2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

	*출력 :
		  첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

*/

struct dot {
	int x;
	int y;
};

bool compare(dot a, dot b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}

	return a.x < b.x;

	if (a.y < b.y) {
		return true;
	} else if (a.y == b.y) {
		if (a.x < b.x) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<dot> arr;

	while (n--) {
		int x, y;
		cin >> x >> y;

		arr.push_back(dot{ x,y });
	}

	sort(arr.begin(), arr.end(), compare);

	for (const auto& dot : arr) {
		cout << dot.x << " " << dot.y << "\n";
	}
}