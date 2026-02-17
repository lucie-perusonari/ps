#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[500000];

int lower_bound(int t, int len) {
	int l = 0;
	int r = len;

	while (l < r) {
		int m = (l + r) / 2;
		// arr[m] == t. 즉 값을 찾는 경우 r을 당김.
		if (arr[m] >= t) r = m;
		else l = m + 1;
	}

	return l;

}

int upper_bound(int t, int len) {
	int l = 0;
	int r = len;

	while (l < r) {
		int m = (l + r) / 2;

		// arr[m] == t. 즉 값을 찾는 경우 l을 당김.
		if (arr[m] > t) r = m;
		else l = m + 1;
	}

	return l;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	string result = "";

	for (int i = 0;i < n;i++) cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;

	for (int i = 0;i < m;i++) {
		int e;
		cin >> e;

		auto it1 = lower_bound(e, n);
		auto it2 = upper_bound(e, n);

		cout << it2 - it1 << ' ';
	}

}