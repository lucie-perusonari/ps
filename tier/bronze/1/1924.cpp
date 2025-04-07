#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
	*문제 번호 : 1924

	*문제명 : 2007년

	*문제 설명 :
		  오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

	*입력 :
		  첫째 줄에 빈 칸을 사이에 두고 x(1 ≤ x ≤ 12)와 y(1 ≤ y ≤ 31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

	*출력 :
		  첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

*/
vector<string> DAY_NAME = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
map<int, int> MONTH_DAY = {
	{1, 31},
	{3, 31},
	{5, 31},
	{7, 31},
	{8, 31},
	{10, 31},
	{12, 31},
	{4, 30},
	{6, 30},
	{9, 30},
	{11, 30},
	{2, 28}
};

// month와 day로 이루어진 이중 배열이라고 생각하면, 매 월 1일의 인덱스는 (이전 달들의 일수의 합) 임.
int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, d;

	cin >> m >> d;

	int count = 0;
	for (int i = 1; i < m; i++) {
		count += MONTH_DAY[i];
	}

	count += d - 1; // 현재 일 수를 인덱스로 전환하기 위해 -1을 해줌.

	cout << DAY_NAME[count % 7];

}