#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
#include <deque>

using namespace std;

/*
	*문제 번호 : 1168

	*문제명 : 요세푸스 문제 2

	*문제 설명 :
		  요세푸스 문제는 다음과 같다.

		  1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

		  N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 100,000)

	*출력 :
		  예제와 같이 요세푸스 순열을 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	// 참조 횟수가 1500만회 이하가 되어야 함.
	// 연결 리스트로 구현해도 n*k가 나와버림. 탐색 n번, 인덱스 이동 k번
	// => 이걸 최적화할 수는 없나? k>size가 되었을 때 k%size;를 해주면 빠르게 인덱스가 구해지지 않나? 
	// ==> 이 경우 
	// => 근데 지워진 숫자는 어떻게 알지? => n => n+k;를 했을 때, 그 사이에 얼마나 많은 수를 썼는지 알 수 있어야 함.

	// 왜 deque를 쓰니까 빨라지지?
	deque<int> arr;
	for (int i = 0;i < n;i++) {
		arr.push_back(i + 1);
	}

	int current_index = 0;
	auto ite = arr.begin();

	string result = "<";


	//* 포인트는 current >= size(); 일 때, next를 어떻게 설정하면 좋을까? 
	while (true) {
		int size = arr.size();
		int next_index = current_index + k - 1;

		if (next_index < size) {
			ite = next(ite, k - 1);
			current_index = next_index;
		} else {
			current_index = next_index % size;
			ite = next(arr.begin(), current_index);
		}

		result += to_string(*ite) + ", ";
		ite = arr.erase(ite);

		if (size - 1 == 0) {
			break;
		}
	}

	result.pop_back();
	result.pop_back();
	result += ">";

	cout << result;

}