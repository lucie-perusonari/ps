#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 10810번 공 넣기.
// 첫째 줄에 N (1 ≤ N ≤ 100)과 M (1 ≤ M ≤ 100)이 주어진다.
// 둘째 줄부터 M개의 줄에 걸쳐서 공을 넣는 방법이 주어진다. 각 방법은 세 정수 i j k로 이루어져 있으며, i번 바구니부터 j번 바구니까지에 k번 번호가 적혀져 있는 공을 넣는다는 뜻이다. 
// 예를 들어, 2 5 6은 2번 바구니부터 5번 바구니까지에 6번 공을 넣는다는 뜻이다. (1 ≤ i ≤ j ≤ N, 1 ≤ k ≤ N)
// 도현이는 입력으로 주어진 순서대로 공을 넣는다.

int main()
{
    int n,m;
    cin >>n >> m;
    vector<int> arr(n);
    for(int index=0;index<m;index++){
        int i,j,k;
        cin >> i >> j >> k;
        i--;j--;

        //인덱스 i와 인덱스 j까지의 값을 k로 바꿔주는 반복문.
        for(int arrIndex = i; arrIndex<=j;arrIndex++){
            arr[arrIndex] = k;
        }
    }

    for(int i=0;i<arr.size();i++){
        cout << arr[i]<<" ";
    }

    return 0;
}