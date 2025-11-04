#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//10811번 : 바구니 뒤집기(*기타 )
//첫째 줄에 N (1 ≤ N ≤ 100)과 M (1 ≤ M ≤ 100)이 주어진다.
//둘째 줄부터 M개의 줄에는 바구니의 순서를 역순으로 만드는 방법이 주어진다. 방법은 i j로 나타내고, 왼쪽으로부터 i번째 바구니부터 j번째 바구니의 순서를 역순으로 만든다는 뜻이다. (1 ≤ i ≤ j ≤ N)
//도현이는 입력으로 주어진 순서대로 바구니의 순서를 바꾼다.
int main()
{
    int n,m;
    cin >>n >>m;
    // vector를 이런 형태로 초기화하면, 0으로 초기화된 크기 n의 벡터가 생성된다.
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        arr[i] = i+1; // 바구니 번호.
    }

    for(int i=0;i<m;i++){
        int start, end;
        cin >> start >> end;
        start--;end--; // 인덱스에 맞게 -1 해줌.

        //*배열 뒤집기.
        //1. reverse에는 배열 포인터가 들어가함. 
        //2. 배열의 끝은 (배열 마지막 값 주소+1) 임. 

        //reverse() : 배열 포인터의 범위를 직접 반환하는 방법. 이 시점에서 end < arr.size()이므로 배열의 끝을 알려주기 위해 +1을 한다.
        reverse(&arr[start], &arr[end]+1); 

        //reverse() : 배열의 포인터에 정수를 더하는 방법. 배열의 끝을 알려줘야 하므로 +1을 한다.
        reverse(arr.begin()+start, arr.begin()+end+1); 

        //swap_ranges를 이용하는 방법. end와 start의 값을 모두 담아야하므로 크기 차이에 +1을 해준다. 
        vector<int> swap_vector(end-start+1);
        for(int j=0; j<swap_vector.size(); j++){
            int temp = arr[end-j];
            swap_vector[j] = temp;

            // swap_vector.push_back(temp);
            //↑ 어째서 for문 내에서 push_back()을 함부로 사용하면 안 되는 걸까?
            //1. swap_vector는 0으로 초기화된 (end-start+1)의 크기의 배열이다. 그러므로 애초부터 정확한 값이 swap_ranges()에 반영되지 않는다. 
            //2. swap_vector.size()는 최소 (end-start+1)이다. 그런데 위의 for문은 j<swap_vector.size();을 만족시킬 때까지 실행된다.
            //3. 즉, swap_vector.size()만큼 for문 실행 => for문 내의 push_back();으로 swap_vector.size() 증가 => for문이 끝나지 않음! => Segmentation Fault!
        }
        swap_ranges(swap_vector.begin(), swap_vector.end(), &arr[start]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}