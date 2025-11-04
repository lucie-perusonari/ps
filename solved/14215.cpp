#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

/*
    *문제 번호 : 14215

    *문제명 : 세 막대

    *문제 설명 :
        영선이는 길이가 a, b, c인 세 막대를 가지고 있고, 각 막대의 길이를
   마음대로 줄일 수 있다.

        영선이는 세 막대를 이용해서 아래 조건을 만족하는 삼각형을 만들려고 한다.

        각 막대의 길이는 양의 정수이다
        세 막대를 이용해서 넓이가 양수인 삼각형을 만들 수 있어야 한다.
        삼각형의 둘레를 최대로 해야 한다.
        a, b, c가 주어졌을 때, 만들 수 있는 가장 큰 둘레를 구하는 프로그램을
   작성하시오.

    *입력 :
        첫째 줄에 a, b, c (1 ≤ a, b, c ≤ 100)가 주어진다.

    *출력 :
        첫째 줄에 만들 수 있는 가장 큰 삼각형의 둘레를 출력한다.

*/
int main() {
    int a, b, c;

    cin >> a >> b >> c;

    vector<int> edge = { a, b, c };

    sort(edge.begin(), edge.end());

    int largest_edge = edge.at(2);

    int other_edges_sum = edge.at(0) + edge.at(1);


    //* 가장 긴 변이 두 변의 합보다 크다면, 두 변의 합에서 -1을 해서 변의 길이를 맞춰줌.
    if (largest_edge >= other_edges_sum) {
        largest_edge = other_edges_sum - 1;
        cout << largest_edge + other_edges_sum;
    } else {
        cout << largest_edge + other_edges_sum;
    }


}