#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    *문제 번호 : 24267

    *문제명 : 알고리즘 수업 - 알고리즘의 수행 시간 6

    *문제 설명 :
          오늘도 서준이는 알고리즘의 수행시간 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.

          입력의 크기 n이 주어지면 MenOfPassion 알고리즘 수행 시간을 예제 출력과 같은 방식으로 출력해보자.

          MenOfPassion 알고리즘은 다음과 같다.

          MenOfPassion(A[], n) {
              sum <- 0;
              for i <- 1 to n - 2
                  for j <- i + 1 to n - 1
                      for k <- j + 1 to n
                          sum <- sum + A[i] × A[j] × A[k]; # 코드1
              return sum;
          }

    *입력 :
          첫째 줄에 입력의 크기 n(1 ≤ n ≤ 500,000)이 주어진다.

    *출력 :
          첫째 줄에 코드1 의 수행 횟수를 출력한다.

          둘째 줄에 코드1의 수행 횟수를 다항식으로 나타내었을 때, 최고차항의 차수를 출력한다. 단, 다항식으로 나타낼 수 없거나 최고차항의 차수가 3보다 크면 4를 출력한다.

*/

long complex1(long n) {
    return (n * (n + 1) * ((2 * n) + 1)) / 6;
}

long complex2(long n) {
    return n * (n + 1) / 2;
}

long complex3(long n) {
    return n * n;
}

int main() {
    long n;
    cin >> n;

    long total = 0;

    // for (int i = 1; i <= n - 2; i++) {
    //     for (int j = i + 1; j <= n - 1;j++) {
    //         total += n - j; // k의 실행 횟수. 등차 수열임.
    //     }
    // }

    // for (int i = 1; i <= n - 2; i++) {
    //     total += (n - 1 - i) * (n - i) / 2; // 등차 수열의 합.
                    // (i-n+1) * (i-n)
    //     cout << (n - 1 - i) * (n - i) / 2<< endl;
    // }

    // i에 대한 2차식으로 변형.
    // 1 ~ n-2 인 시그마를 대입. 공식을 이용해서 값을 구함.
    total = (complex1(n - 2) - (2 * n - 1) * complex2(n - 2) + n * (n - 1) * (n - 2)) / 2;

    cout << total << endl;
    cout << 3;

}