#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> isVisited(9, false);

void dfs(int count, int t) {
	if (count == 0) {
		for (int i = 1; i <= n;i++) {
			if (isVisited[i] == true) {
				cout << i << " ";
			}
		}
		cout << "\n";
	} else {

		// isVisited를 이용하는 것이 백트래킹의 핵심임.
		// 해당 노드의 탐색이 끝났을 때, false 처리를 해줘서 재방문이 가능하게 만듬.

		for (int i = t + 1;i <= n;i++) {
			if (isVisited[i]) continue;

			isVisited[i] = true;
			dfs(count - 1, i);
			isVisited[i] = false;
		}
	}


}

// dfs를 

int main() {
	cin >> n >> m;

	dfs(m, 0);
}


