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
//* 생각해보니 3^n*2^m + a 를 구하는 문제네? 
//* 근데 여기에서 n+m+a가 최소가 되는 수를 구하면 됨. 


/**
 * 1. 각 분기마다 연산이 실행된다. n이 아니라면 depth를 추가하고, 다른 연산들을 검토한다.
 * 2. 트리의 최하위에서는 1이 등장한다. 이 지점에서 depth를 반환한다.
 * 3. check는 트리 최하위에서 반환된 결과들을 모아서 캐싱한다. n일 때, 최소 depth가 얼마인지 기록한다.
 *
 */

 // depth와 n을 캐싱하자.
unordered_map<int, unordered_map<int, bool>> cache;

int min_depth = 0;

int mod3(int n) {
	if (n % 3 == 0) {
		return n / 3;
	} else {
		return n - 1;
	}
}

int mod2(int n) {
	if (n % 2 == 0) {
		return n / 2;
	} else {
		return n - 1;
	}
}

//* 이것이 최악의 경우를 담아줌. 
void set_max_depth(int n) {
	while (n != 1) {
		n = mod2(n);
		min_depth++;
	}
}

//* 다른 재귀 트리의 값을 확인한 뒤에 재귀를 실행할지 말지를 정해야 함.
void compute(int n, int operation = -1, int depth = 0) {
	if (operation == -1) {
		compute(n, 0, depth);
		compute(n, 1, depth);
	}

	depth++; //* 본인의 depth를 먼저 추가해줌. opration이 -1이 아니라면 시작하자마자 depth를 상승시키고 시작할 것.

	//* 최소 깊이 이상 탐색할 필요는 없음.
	if (depth > min_depth) {
		return;
	}

	if (operation == 0) {
		n = mod3(n);
	} else {
		n = mod2(n);
	}

	//* 계산하기 전의 n값에 대해서 캐싱됨. 어쨌든 동일한 depth에서 한 번만 실행되게 만들어주자.
	if (cache[n][depth] == true) {
		return;
	} else {
		cache[n][depth] = true;
	}

	//* depth를 반환하기 전에 최소 값을 기록해줌.
	if (n == 1) {
		min_depth = depth;
		return;
	}

	//* n일 때, 재귀를 실행할지 말지를 정해야 함. 위의 캐싱을 통해서 구현. 
	compute(n, 0, depth);
	compute(n, 1, depth);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	set_max_depth(n);
	compute(n);

	cout << min_depth;
}