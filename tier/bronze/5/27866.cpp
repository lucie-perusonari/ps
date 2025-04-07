#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//*문제 번호 : 27866번 - 문자와 문자열 
//*문제 설명 :
// 첫째 줄에 영어 소문자와 대문자로만 이루어진 단어 S가 주어진다. 단어의 길이는 최대 1000이다.
// 둘째 줄에 정수 i가 주어진다. (1<=i<=S);

int main()
{
    string a;
    int index;
    cin >> a >> index;

    cout << a[index - 1];

    return 0;
}