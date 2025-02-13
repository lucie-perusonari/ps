#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
	*문제 번호 : 2133

	*문제명 : 타일 채우기

	*문제 설명 :
		  3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

	*입력 :
		  첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

	*출력 :
		  첫째 줄에 경우의 수를 출력한다.

*/

unordered_map<int, int> cache_3;

int n;

//* 2칸짜리 블록과 2n+2칸 짜리 블록이 존재함.
int compute_3(int n) {
	if (n % 2 == 1) {
		return 0;
	}

	if (n < 0) {
		return 0;
	}

	if (n == 0) {
		return 1;
	}

	if (cache_3.count(n)) {
		return cache_3[n];
	}

	for (int i = 4;i <= n;i += 2) {
		cache_3[n] += compute_3(n - i) * 2;
	}

	cache_3[n] += compute_3(n - 2) * 3;

	return cache_3[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; // n을 짝수라고 가정 함.

	cout << compute_3(n);
	// 위나 아래에 반드시 2*1 타일이 존재해야 함. 
}