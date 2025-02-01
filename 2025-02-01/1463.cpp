#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

/*
	*문제 번호 : 1463

	*문제명 : 1로 만들기

	*문제 설명 :
		  정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.


			X가 3으로 나누어 떨어지면, 3으로 나눈다.
			X가 2로 나누어 떨어지면, 2로 나눈다.
			1을 뺀다.


		  정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

	*입력 :
		  첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

	*출력 :
		  첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

*/

//* 10^6이라는 말은 100만이라는 뜻. 1500만번 시행 이내에 답 내야함.
//* 재귀를 사용하는 게 좋을 듯. 
//* 세 가지 경우의 수가 있으니까, 각 재귀 함수들이 연산을 실행하고, 숫자와 연산 종류를 캐싱.
//* 마지막으로 각 분기 중에서 가장 적은 값을 return;
//* 되도록이면 각 함수들이 자신이 갖고 있는 가장 작은 분기의 실행 횟수를 return 해줬으면 좋겠다.

unordered_map<int, int> cache;
int min_depth = 1000001;

//* 좀 더 깔끔하게 비교할 순 없나?
int check(int depth1, int depth2, int n) {
	int min_value = min(depth1, depth2);
	if (cache.count(n) == 0 && cache[n] > n) {
		cache.insert({ n, min_value });
	}
	return min_value;
}

int compute(int n, int operation = -1, int depth = 0) {
	if (operation == -1) {
		if (n == 1) return 0;

		return check(compute(n, 0, depth),
			compute(n, 1, depth), n);
	}

	//* 일정 깊이 이상 탐색할 수 없으니 depth는 최소값만 들어올 수 있음.
	if (depth == min_depth) {
		return 1000001;
	}

	if (operation == 0 && n % 3 == 0) {
		n = n / 3;
	} else if (operation == 1 && n % 2 == 0) {
		n = n / 2;
	} else { //* 2, 3임에도 불구하고 실패한 경우.
		n -= 1;
	}

	depth++; //* n값이 바뀌었으니 반영.

	//* 여기서 성공했을 경우 최소값이라는 뜻. 캐싱해줌.
	if (n == 1) {
		if (min_depth > depth) {
			min_depth = depth;
		}
		return depth;
	}

	return check(compute(n, 0, depth),
		compute(n, 1, depth), n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int depth = compute(n);
	cout << depth;
}