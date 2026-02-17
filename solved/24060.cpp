#include <bits/stdc++.h>

using namespace std;

int* arr;

int n, k;
int c = 0, result = -1;

void merge_sort(int s, int e) {
	// 둘이 같다면 종료.
	// 아래에서 오른쪽에 +1을 해주기 때문에 이 단계에서 종료 시켜야 함.
	if (s == e) return;

	// 배열을 좌우로 쪼갬.
	int m = (s + e) / 2;

	// 왼쪽은 s~m 오른쪽은 m+1~e
	int l = s;
	int r = m + 1;

	merge_sort(s, m);
	merge_sort(m + 1, e);

	// 임시 배열 선언
	int* temp = (int*)malloc(sizeof(int) * (e - s + 1));

	int idx = 0;
	while (l <= m && r <= e) {
		if (arr[l] <= arr[r]) temp[idx++] = arr[l++];
		else temp[idx++] = arr[r++];
	}
	while (l <= m) temp[idx++] = arr[l++];
	while (r <= e) temp[idx++] = arr[r++];

	// 합친 배열을 실제로 반영.
	// s에서 시작해서 e가 될떄까지 반복.
	for (int i = 0; i <= e - s;i++) {
		arr[s + i] = temp[i];
		c++;
		if (c == k) {
			result = temp[i];
		}
	}

	free(temp);
}

int main() {

	cin >> n >> k;

	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	merge_sort(0, n - 1);

	free(arr);

	cout << result;
}