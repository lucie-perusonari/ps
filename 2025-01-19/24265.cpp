#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    *문제 번호 : 24265

    *문제명 : 알고리즘 수업 - 알고리즘의 수행 시간 4

    *문제 설명 : 
          오늘도 서준이는 알고리즘의 수행시간 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.
          
          입력의 크기 n이 주어지면 MenOfPassion 알고리즘 수행 시간을 예제 출력과 같은 방식으로 출력해보자.
          
          MenOfPassion 알고리즘은 다음과 같다.
          
          MenOfPassion(A[], n) {
              sum <- 0;
              for i <- 1 to n - 1
                  for j <- i + 1 to n
                      sum <- sum + A[i] × A[j]; # 코드1
              return sum;
          }

    *입력 : 
          첫째 줄에 입력의 크기 n(1 ≤ n ≤ 500,000)이 주어진다.

    *출력 : 
          첫째 줄에 코드1 의 수행 횟수를 출력한다.
          
          둘째 줄에 코드1의 수행 횟수를 다항식으로 나타내었을 때, 최고차항의 차수를 출력한다. 단, 다항식으로 나타낼 수 없거나 최고차항의 차수가 3보다 크면 4를 출력한다.

*/
int main(){
    long n;
    cin >> n;

    // 위에서 아래로 n-1개의 행이 있다.
    // 각 행의 열은 (n - 행의 인덱스) 만큼 실행된다. n-1이 최대값, 1이 최소값이다.
    // 이는 1에서 n-1까지 이어진 행렬이고, 시작행은 n-1, 마지막행은 1이다.


    cout << (n*(n-1)/2) << endl;
    cout << 2;
}