#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<algorithm>

using namespace std;

// https://www.acmicpc.net/problem/7568
// 집단 내에서의 등수를 구하는 문제.
// "등수 = 키와 무게가 둘 다 큰 사람 + 1"으로 결정된다.

int main() {
	int n;
	cin >> n;

	vector<tuple<int, int>> arr;
	while (n--) {
		int w, h;
		cin >> w >> h;

		tuple<int, int> p = { w,h };
		arr.push_back(p);
	}

	vector<int> result;
	// 어차피 시간 제한도 안 걸리는데 그냥 노가다로 풀자.
	for (int i = 0;i < arr.size();i++) {
		int c = 1;

		auto [w1, h1] = arr[i];

		for (int j = 0;j < arr.size();j++) {
			auto [w2, h2] = arr[j];

			if (w2 > w1 && h2 > h1) {
				c++;
			}
		}
		result.push_back(c);
	}


	for (int e : result) {
		cout << e << " ";
	}
}