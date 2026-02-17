#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

vector<int> arr = {};
vector<int> stk = {};
vector<bool> isVisited(9, false);

void dfs(int count) {
	// 출력을 위래 stack을 사용함.
	if (count == 0) {
		for (const auto& v : stk) {
			cout << v << " ";
		}
		cout << "\n";
	} else {
		for (int i = 0;i < arr.size();i++) {
			if (isVisited[i]) continue;

			isVisited[i] = true;
			stk.push_back(arr[i]);
			dfs(count - 1);
			stk.pop_back();
			isVisited[i] = false;
		}
	}


}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	while (n--) {
		int t;
		scanf("%d", &t);

		arr.push_back(t);
	}

	for (int i = 0;i < arr.size();i++) {
		for (int j = i + 1;j < arr.size();j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	dfs(m);
}