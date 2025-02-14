#include <iostream>
#include <vector>
#include <string>

using namespace std;



// 0<k<i
// i의 자리는 k 범위의 최대값이 담김.
// 반대로 k의 최소값은 계속해서 갱신됨.
// i의 값을 k범위와 비교해서 조건에 맞는 위치에 놓는 방식.
vector<int> insert_sort(vector<int> pointer) {
	for (int i = 1;i < pointer.size();i++)
	{
		for (int k = 0;k < i;k++) {
			int temp = pointer[k];
			// 현재 i 값이 더 크다면 두 배열 값의 자리를 바꿈.
			// pointer[k]의 범위는 오름차순으로 정렬됨.
			// 이 때 pointer[i]는 pointer[k]의 범위에서 최대 값이 담기게 됨.
			if (pointer[i] < pointer[k]) {
				pointer[k] = pointer[i];
				pointer[i] = temp;
			}
		}
	}

	return pointer;

}

int main() {
	vector<int> v = { 5,4,1,2,6,8,9,7,0,3 };

	vector<int> result = insert_sort(v);
}