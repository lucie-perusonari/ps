#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//10811번 : 바구니 뒤집기
//첫째 줄에 N (1 ≤ N ≤ 100)과 M (1 ≤ M ≤ 100)이 주어진다.
//둘째 줄부터 M개의 줄에는 바구니의 순서를 역순으로 만드는 방법이 주어진다. 방법은 i j로 나타내고, 왼쪽으로부터 i번째 바구니부터 j번째 바구니의 순서를 역순으로 만든다는 뜻이다. (1 ≤ i ≤ j ≤ N)
//도현이는 입력으로 주어진 순서대로 바구니의 순서를 바꾼다.

int main()
{
    int n,m;
    cin >>n >>m;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        arr[i] = i+1; // 바구니 번호.
    }

    for(int i=0;i<m;i++){
        int start, end;
        cin >> start >> end;
        start--;end--; // 인덱스에 맞게 -1 해줌.

        //(end-start+1)/2는 (end-start+1)의 연산 횟수를 +1회 한다.
        //배열을 반으로 갈라서 결과적으로 짝수는 짝수 번, 홀수는 홀수 번 반복한다. => 홀수는 /2를 하면 반드시 1을 잃어버리므로, +1을 해주는 것.
        for(int j = 0;j<(end-start+1)/2;j++){ 
            if(start == end) continue;
            int start_value = arr[start + j];
            int end_value = arr[end-j];
            arr[end-j] =start_value;
            arr[start + j] = end_value;       
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}