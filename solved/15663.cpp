#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

int n, m;

vector<int> arr;
vector<int> stack;
vector<bool> isVisited;

void dfs(int m) {
	if (m == 0) {
		for (int a : stack) {
			cout << a << " ";
		}

		cout << "\n";
		return;
	}

	vector<bool> isUsed(10001, false);

	for (int i = 0;i < n;i++) {
		if (isVisited[i] == true) continue;

		int e = arr[i];
		if (isUsed[e] == true) continue;

		isVisited[i] = true;
		isUsed[e] = true;

		stack.push_back(e);
		dfs(m - 1);
		stack.pop_back();
		isVisited[i] = false;

	}

}


int main() {
	cin >> n >> m;

	arr = vector<int>(n);
	isVisited = vector<bool>(n, false);


	for (int i = 0;i < n;i++) {
		int e;
		cin >> e;
		arr[i] = e;
	}

	sort(arr.begin(), arr.end());

	dfs(m);
}