#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//*문제 번호 : 2444번 - 별 찍기 - 7
//*문제 설명 : 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
//입력 : 
//첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

//출력 : 
//첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

int main()
{
    int a;
    cin >>a;
    //1. input이 5가 들어왔다면, end 9가 된다.
    //2. 따라서 총 반복 횟수는 기본 0~8까지 총 9회가 된다.
    //3. end/2는 4로 정확히 index의 중앙값이다. 0123 / 4 / 5678
    //4. i가 0과 8일 때 오직 j는 4일 때만 출력이 가능하다. => (4-0), (4-8) => 4 => 중앙값과 (j/2) 차가 0일 때
    //5. i가 1과 7일 때 j는 3,4,5일 때 출력이 가능하다. => (4-1), (4-7) => 3 ==> 중앙값과 차가 1 이하일 때 
    //6. i가 2과 8일 때 j는 2,3,4,5,6일 때 출력이 가능하다.
    //7. 출력의 최대치는 0, 8일 때 최소이고, 4일 때 최대이다.
    int end = (a*2)-1; // 5 >> end == 9         //반드시 홀수가 됨.
    int median = end/2;
    for(int i=0;i<end;i++){
        int allow = median-abs(median-i); // 
        //이 for문은 최대 end번, 최소 end - abs(end/2-i)번 반복되어야 한다.
        //a가 5일때, end는 9 => 최대 9번, 최소 5번
        for(int j=0;j<end-abs(median-i);j++){ 
            if(abs(median-j)<=allow){ // allow는 오차 범위.
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}