#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
//*문제 번호 : 2745 - 진법 변환.

//*문제 설명 : 
    // B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.
    // 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
    // A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

//입력 : 

//출력 : 

int main()
{
    string n;
    int b;
    cin >> n >> b;

    vector<int> n_vector(0); //n_vector는 n의 각 자리수를 자연수로 변환한 것. 
    int result = 0;
    for(int i=0;i<n.size();i++){
        int a;
        if(n[i]>64){
            a = n[i] - 'A' + 10;
        }else{
            a = n[i]-'0';
        };
        n_vector.push_back(a);
    }

    reverse(n_vector.begin(), n_vector.end());
    for(int i=0;i<n_vector.size();i++){
        result += n_vector[i]*pow(b, i);
    }

    cout << result;

    return 0;
}