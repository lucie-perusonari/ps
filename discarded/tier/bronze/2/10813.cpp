#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m; // 시작이 1이 아닌 n, m은 굳이 --하지 않는다. 
    cin >> n >> m;
    vector<int>arr(n);
    
    //전제 조건에 맞게 초기화.
    for(int i=0;i<arr.size();i++){
        arr[i] = i+1;
    }

    // cout << "중간 검사 : ";
    // for(int i=0;i<arr.size();i++){ 
    //     cout << arr[i];    
    // }

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--; //인덱스에 맞게 -1 해 줌.

        int temp_a = arr[b];
        int temp_b = arr[a];
        arr[a] = temp_a;
        arr[b] = temp_b;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}