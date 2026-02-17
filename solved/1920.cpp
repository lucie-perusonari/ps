#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100000];
int find_list[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0;i < n;i++) cin >> arr[i];

	// 이분 탐색은 "정렬된 배열" 에서만 수행 가능. 
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> find_list[i];

		// STL의 binary_search를 사용한 예시.
		cout << binary_search(arr, arr + n, find_list[i]) << "\n";
	}

}