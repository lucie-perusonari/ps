#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    *문제 번호 : 1541

    *문제명 : 잃어버린 괄호

    *문제 설명 :
          세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

          그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

          괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

    *입력 :
          첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

    *출력 :
          첫째 줄에 정답을 출력한다.

*/

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      // 수는 0으로 시작할 수 있고 5자리 이하. 반드시 양수. 수는 50 개 이하.
      // 중요한 건 '괄호'를 쳐서 숫자가 최소가 되어야 함. 그런데 결합법칙 때문에 괄호가 의미 없지 않나?
      // 아 괄호를 치면 양수를 음수로 만들 수 있구나.

      // 그렇다면 -가 등장할 때마다 괄호를 쳐야겠다. 숫자를 체크하고 다음 부호를 확인한다.
      // 이 때 3가지 경우의 수가 있을 것이다.
      // 1. +인 경우. -> 단순히 더한다. 그리고 버퍼를 초기화한다.
      // 2. -인 경우. -> 부호를 바꾸고 더한다. 그리고 버퍼를 초기화한다.
            // 2.1. 앞선 부호가 +인 경우 먼저 더한다. 그리고 부호를 바꾼다.
            // 2.2. 앞선 부호가 -인 경우 부호를 바꾸지 않고 더한다.
      // 3. EOF인 경우. -> 부호에 따라서 연산한다.

      // => 식의 앞에 전부 부호가 붙어있는 형태로 생각하고 접근하자.
      //  첫번째 항을 제외하고 부호가 +로 바뀌는 경우가 존재할까?
            // 존재하지 않음. 한 번 -가 되면, 그 이후에 부호를 바꿀 수 없음.

      // 이런 류의 문제는 첫번째와 마지막을 신경써줘야 함.

      string str = "";
      string decimal_buffer = "";

      int sign = 1;
      int result = 0;
      getline(cin, str);


      for (const char& c : str) {
            if (c == '+' || c == '-') {
                  if (c == '-') {
                        if (sign == 1) {
                              result += stoi(decimal_buffer) * sign;
                              sign = sign * -1; // 부호 바꾸기.
                        } else {
                              result += stoi(decimal_buffer) * sign;
                        }
                  } else {
                        result += stoi(decimal_buffer) * sign;
                  }
                  decimal_buffer = "";
            } else {
                  decimal_buffer += c;
            }
      }

      result += stoi(decimal_buffer) * sign;

      cout << result;

}