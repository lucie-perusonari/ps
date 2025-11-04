#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
*문제 번호 : 11005

*문제 설명 : 
    10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.

    10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

    A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35
*입력 : 
    첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.
*출력 : 
    첫째 줄에 10진법 수 N을 B진법으로 출력한다.
*/

//* 최대 36진법까지 가능함. 
//* 낮은 자리 숫자에서 높은 자리 숫자로 올라가는 풀이.
char converter(int n){

    if(n<10){
        return n+48;
    }

    return n+55;
};

int main() {
    int n, b;
    string a = "";
    cin >> n >> b;

    //* 첫째 자리부터 시작해서 마지막 자리까지.
    while(n>0){
        a += converter(n%b);
        n/=b;
    }

    reverse(a.begin(), a.end());

	cout << a;

}