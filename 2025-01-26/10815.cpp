#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

/*
	*문제 번호 : 10815

	*문제명 : 숫자 카드

	*문제 설명 :
		  숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

		  셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

	*출력 :
		  첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//* set을 이용한 풀이. "집합"이라고 하면 set을 사용하자.
	int n, m;

	cin >> n;

	set<int> number_set;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;

		number_set.insert(number);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int number;
		cin >> number;

		cout << number_set.count(number) << " ";
	}


	//* 맵을 이용한 풀이.
		// int n, m;

		// cin >> n;

		// map<int, int> number_map;

		// for (int i = 0; i < n; i++) {
		// 	int number;
		// 	cin >> number;

		// 	number_map[number];
		// }

		// cin >> m;

		// for (int i = 0; i < m; i++) {
		// 	int number;
		// 	cin >> number;

		// 	cout << number_map.count(number) << " ";
		// }

		//* 시간 초과가 발생함. 왜? 


	//* vector를 이용한 풀이.
		// int n, m;

		// cin >> n;

		// vector<int> numbers;

		// for (int i = 0; i < n; i++) {
		// 	int number;
		// 	cin >> number;

		// 	numbers.push_back(number);
		// }

		// cin >> m;

		// for (int i = 0; i < m; i++) {
		// 	int number;
		// 	cin >> number;

		// 	int result = find(numbers.begin(), numbers.end(), number) == numbers.end() ? 0 : 1;

		// 	cout << result << " ";
		// }

	//* 카운팅 배열.
		// int n, m;

		// cin >> n;

		// int counter[20000001] = { 0, };

		// for (int i = 0; i < n; i++) {
		// 	int number;
		// 	cin >> number;

		// 	counter[10000000 + number] = 1;
		// }

		// cin >> m;

		// for (int i = 0; i < m; i++) {
		// 	int number;
		// 	cin >> number;

		// 	cout << counter[10000000 + number] << " ";
		// }



}