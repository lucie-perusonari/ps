#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//*문제 번호 : 9086번 - 문자열
//*문제 설명 : 
// 문자열을 입력으로 주면 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램을 작성하시오.

//입력 : 
//입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 
//각 테스트 케이스는 한 줄에 하나의 문자열이 주어진다. 
//문자열은 알파벳 A~Z 대문자로 이루어지며 알파벳 사이에 공백은 없으며 문자열의 길이는 1000보다 작다.

//출력 : 
//각 테스트 케이스에 대해서 주어진 문자열의 첫 글자와 마지막 글자를 연속하여 출력한다.

int main()
{
    int a;
    cin >> a;
    vector<string> str_arr(0); //빈 벡터 생성.
    for(int i=0;i<a;i++){
        string str;
        cin >> str;
        str_arr.push_back(str); //벡터에 데이터 추가.
    }
    //벡터를 순회하면서 데이터를 하나씩 출력.
    for(int i=0;i<str_arr.size();i++){
        string str = str_arr[i];
        cout << str[0] << str[str.length()-1] << endl;
    }
    return 0;
}