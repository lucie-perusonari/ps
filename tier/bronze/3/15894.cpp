#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    *문제 번호 : 15894

    *문제명 : 수학은 체육과목 입니다

    *문제 설명 : "한 변의 길이가 1인 정사각형을 아래 그림과 같이 겹치지 않게 빈틈없이 계속 붙여 나간다. 가장 아랫부분의 정사각형이 n개가 되었을 때, 실선으로 이루어진 도형의 둘레의 길이를 구하시오."

        가장 아랫부분의 정사각형 개수가 주어지면 그에 해당하는 답을 출력하는 프로그램을 만들어 형석이를 도와주자!

    *입력 : 첫 번째 줄에 가장 아랫부분의 정사각형 개수 n이 주어진다. (1 ≤ n ≤ 10^9) // * n이 10억이 될 수 있으므로 int의 범위를 벗어남.

    *출력 : 첫 번째 줄에 형석이가 말해야 하는 답을 출력한다.

*/
int main() {
    long n = 0;

    cin >> n;

    long result = 4 * n; //* 사각형 위, 아래, 양 옆의 합.

    cout << result;
}