#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	*문제 번호 : 11576

	*문제명 : Base Conversion

	*문제 설명 :
		  타임머신을 개발하는 정이는 오랜 노력 끝에 타임머신을 개발하는데 성공하였다. 미래가 궁금한 정이는 자신이 개발한 타임머신을 이용하여 500년 후의 세계로 여행을 떠나게 되었다. 500년 후의 세계에서도 프로그래밍을 하고 싶었던 정이는 백준 사이트에 접속하여 문제를 풀기로 하였다. 그러나 미래세계는 A진법을 사용하고 있었고, B진법을 사용하던 정이는 문제를 풀 수가 없었다. 뛰어난 프로그래머였던 정이는 A진법으로 나타낸 숫자를 B진법으로 변환시켜주는 프로그램을 작성하기로 하였다.

		  N진법이란, 한 자리에서 숫자를 표현할 때 쓸 수 있는 숫자의 가짓수가 N이라는 뜻이다. 예를 들어 N이 17일 때 한 자릿수에서 사용할 수 있는 수는 0, 1, 2, ... , 16으로 총 17가지가 된다.

	*입력 :
		  입력의 첫 줄에는 미래세계에서 사용하는 진법 A와 정이가 사용하는 진법 B가 공백을 구분으로 주어진다. A와 B는 모두 2이상 30이하의 자연수다.

		  입력의 두 번째 줄에는 A진법으로 나타낸 숫자의 자리수의 개수 m(1 ≤ m ≤ 25)이 주어진다. 세 번째 줄에는 A진법을 이루고 있는 숫자 m개가 공백을 구분으로 높은 자릿수부터 차례대로 주어진다. 각 숫자는 0이상 A미만임이 보장된다. 또한 수가 0으로 시작하는 경우는 존재하지 않는다.

		  A진법으로 나타낸 수를 10진법으로 변환하였을 때의 값은 양의 정수이며 2^20보다 작다.

	*출력 :
		  입력으로 주어진 A진법으로 나타낸 수를 B진법으로 변환하여 출력한다.

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;

	// A 진법의 원본이 2^20을 넘지 않을 테니 우선 10진법으로 변환부터 해볼까?

	int decimal = 0;
	// m-1을 base로 볼 수 있음. => 그렇다면 바로 빼준 다음에 쓰면 될 듯.
	// m이 0일 때 마지막으로 값을 채운 뒤 종료됨.
	while (m--) {
		int num;
		cin >> num; //* 각각 높은 자리수부터 출력 됨.
		decimal += pow(a, m) * num;
	}

	// 0인 경우에 조기 리턴.
	if (decimal == 0) {
		cout << decimal;
		return 0;
	}

	// decimal이 2^20이라는 조건이 있으나 진법이 2진법으로 되면 정수형으로는 나타낼 수 없을 것임.
	// 그것을 고려하면 어쩔 수 없이 문자열을 사용해서 표현해야만 함.
	// 인덱스를 정확하게 잡아서 배열로 표현할 수 있을까? => 별로 좋은 방법이 아닌 거 같음.

	vector<int> numbers;

	while (decimal > 0) {
		numbers.push_back(decimal % b);
		decimal /= b;
	}

	// 배열을 뒤집음.
	reverse(numbers.begin(), numbers.end());

	for (const auto& number : numbers) {
		cout << number << " ";
	}
}