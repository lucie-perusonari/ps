#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 11004

	*문제명 : K번째 수

	*문제 설명 :
		  수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.

		  둘째에는 A1, A2, ..., AN이 주어진다. (-109 ≤ Ai ≤ 109)

	*출력 :
		  A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, seq;
	cin >> n >> seq;

	vector<int> arr;

	while (n--) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	cout << arr[seq - 1];

}