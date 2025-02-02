#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 9095

	*문제명 : 1, 2, 3 더하기

	*문제 설명 :
		  정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.


			1+1+1+1
			1+1+2
			1+2+1
			2+1+1
			2+2
			1+3
			3+1


		  정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

	*출력 :
		  각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

*/

unordered_map<int, unordered_map<int, int>> cache;

int compute(int n, int k = 0) {
	if (cache.count(n) && cache[n].count(k)) {
		return cache[n][k];
	}

	n = n - k;

	if (n == 0) {
		return 1;
	} else if (n < 0) {
		return 0;
	} else {
		int result = compute(n, 1) + compute(n, 2) + compute(n, 3);

		cache[n + k][k] = result;
		return result;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << compute(n) << endl;
	}



}