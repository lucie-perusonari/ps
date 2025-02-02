#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 11726

	*문제명 : 2×n 타일링

	*문제 설명 :
		  2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

		  아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

	*입력 :
		  첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

	*출력 :
		  첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

*/

unordered_map<int, unordered_map<int, int>> cache;

int compute(int n, int k = 0) {
	if (cache.count(n) * cache[n].count(k)) {
		return cache[n][k];
	}

	//* 예외 케이스. 처리해주지 않음.
	if (n == 1 && k == 2) {
		return 0;
	}

	//* 블록으로 공간을 사용함.
	switch (k)
	{
		case 1:
			n = n - 1;
			break;
		case 2:
			n = n - 2;
			break;
	}

	//* 할당이 끝난 경우.
	if (n == 0) {
		return 1;
	}

	int result = compute(n, 1) + compute(n, 2);

	//* 일일이 다 더한 다음에 나눗셈을 하면 오버플로우가 일어남.
	if (result > 10007) {
		result -= 10007;
	}

	//* 나는 compute(n, k)의 결과 값을 캐싱해주고 싶다. 
	//* 그러므로 n + k로 원래 n값을 복구하고, 그 뒤에 넣어준다.
	cache[n + k][k] = result;

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	/*
		간단하게 n 크기의 공간에 1과 2를 채워넣을 수 있는 경우의 수를 살펴보면 된다.
		문제는 1과 2가 선택 됨에 따라서 이후의 분기도 차이가 난다는 것.
		그렇다면 이진 트리를 이용하자.
	*/

	cout << compute(n);

}