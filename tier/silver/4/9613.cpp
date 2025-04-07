#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 9613

	*문제명 : GCD 합

	*문제 설명 :
		  양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1,000,000을 넘지 않는다.

	*출력 :
		  각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
*/

int euclid(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}

	return euclid(b, r);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr;
		while (n--) {
			int a;
			cin >> a;

			arr.push_back(a);
		}

		long long result = 0;
		for (int i = 0;i < arr.size();i++) {
			for (int k = i + 1;k < arr.size();k++) {
				result += euclid(max(arr[i], arr[k]), min(arr[i], arr[k]));
			}
		}

		cout << result << "\n";
	}

}