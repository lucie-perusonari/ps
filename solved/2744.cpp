#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    *문제 번호 : 2744

    *문제명 : 대소문자 바꾸기

    *문제 설명 :
          영어 소문자와 대문자로 이루어진 단어를 입력받은 뒤, 대문자는 소문자로, 소문자는 대문자로 바꾸어 출력하는 프로그램을 작성하시오.

    *입력 :
          첫째 줄에 영어 소문자와 대문자로만 이루어진 단어가 주어진다. 단어의 길이는 최대 100이다.

    *출력 :
          첫째 줄에 입력으로 주어진 단어에서 대문자는 소문자로, 소문자는 대문자로 바꾼 단어를 출력한다.

*/
int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      string str;
      cin >> str;

      for (auto& c : str) {
            // 대문자
            if (c < 'a') {
                  c = (c - 'A' + 'a'); // 대문자이면, 
                  // 소문자.
            } else {
                  c = (c - 'a' + 'A');
            }
      }

      cout << str;
}