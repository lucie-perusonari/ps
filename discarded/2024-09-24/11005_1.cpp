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
//* 높은 자리 숫자에서 낮은 자리 숫자로 내려가는 풀이.
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

    //* 여기서 포인트는 n을 b진법으로 변환해야한다는 것이다.
    /*
        1. 진법을 n번 만큼 실행할 수는 없다. 그렇다면 10초 이상 소요될 수 있다.
        2. n을 b라는 숫자로 이루어진 다항식으로 변환하면 된다.
        3. 가장 먼저 b를 몇 번 제곱해야 n보다 커지는 지를 알아내야한다.
    */

   	int digit = 0; // * n은 과연 b의 몇 승으로 표현할 수 있는가? 확인하기 위해 사용.

   	while(n>=pow(b,digit)) digit++; //* 조건을 만족하는 digit을 쓰면 무조건 n보다 클 수 밖에 없음.

	while(--digit>=0){
		if(n>=pow(b,digit)){
			a += converter(floor(n/pow(b,digit)));
			n-=floor(n/pow(b,digit))*pow(b,digit);
		}else{
			a += "0";
		}
	};

	cout << a;

}