#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    *문제 번호 : 9506

    *문제명 : 약수들의 합

    *문제 설명 : 

        어떤 숫자 n이 자신을 제외한 모든 약수들의 합과 같으면, 그 수를 완전수라고 한다.

        예를 들어 6은 6 = 1 + 2 + 3 으로 완전수이다.

        n이 완전수인지 아닌지 판단해주는 프로그램을 작성하라.

    *입력 : 

        입력은 테스트 케이스마다 한 줄 간격으로 n이 주어진다. (2 < n < 100,000)

        입력의 마지막엔 -1이 주어진다.

    *출력 : 

        테스트케이스 마다 한줄에 하나씩 출력해야 한다.

        n이 완전수라면, n을 n이 아닌 약수들의 합으로 나타내어 출력한다(예제 출력 참고).

        이때, 약수들은 오름차순으로 나열해야 한다.

        n이 완전수가 아니라면 n is NOT perfect. 를 출력한다.

*/

/*
    vector를 사용하지 않은 풀이법.
*/
int main(){
    while(true){
        int n;
        cin >> n;

        if(n==-1) break;

        int divisor = 1;
        int sum = 0;
        string result = "";

        // *검증을 위해 미리 검사함.
        while(n>divisor){
            if(n%divisor == 0) {
                sum+=divisor;
            };

            divisor++;
        }

        // *케이스에 맞으면 출력을 함.
        if(n==sum){
            divisor = 1;
            cout << n;
            while(n>divisor){
                if(n%divisor == 0) {
                    if(divisor==1){
                        cout << " = " << divisor; 
                    }else{
                        cout << " + " << divisor; 
                    }
                };

                divisor++;
            }
        }else{
            cout << n << " is NOT perfect."<<endl;
        }
    }
}