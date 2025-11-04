#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//*문제 번호 : 10988번 - 팰린드롬인지 확인하기
//*문제 설명 : 알파벳 소문자로만 이루어진 단어가 주어진다. 이때, 이 단어가 팰린드롬인지 아닌지 확인하는 프로그램을 작성하시오.
//팰린드롬이란 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말한다. 
//level, noon은 팰린드롬이고, baekjoon, online, judge는 팰린드롬이 아니다.

//입력 : 
//첫째 줄에 단어가 주어진다. 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.

//출력 : 
//첫째 줄에 팰린드롬이면 1, 아니면 0을 출력한다.
int main()
{
    string str;
    cin >> str;
    
    //짝수인 경우.
    string before;
    string after;
    int median = str.size()/2; //중앙 값.
    int max = str.size()-1;

    //최소값에서 중앙값으로
    //최대값에서 중앙값으로
    //홀수인 경우 중앙값은 검증하지 않음.
    for(int i=0;i<median;i++){
        before.push_back(str[i]);
        after.push_back(str[str.size()-1-i]);
    }

    if(before.compare(after) ==0){
        cout << 1;
    }else{
        cout << 0;
    }

    
    return 0;
}