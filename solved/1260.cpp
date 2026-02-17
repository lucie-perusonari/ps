#include <bits/stdc++.h>

using namespace std;

int n, m, v;
int graph[1001][1001];
bool visited_bfs[1001];
bool visited_dfs1[1001];
bool visited_dfs2[1001];

stack<int> S;
queue<int> Q;

void stack_dfs(int st) {
	S.push(st);

	while (!S.empty()) {
		int v = S.top(); S.pop();

		if (visited_dfs1[v] == true) continue;
		visited_dfs1[v] = true;

		cout << v << ' ';

		// 스택이라 낮은 순번부터 방문하고 싶으면 역방향 순회가 필요.
		for (int i = n;i > 0; i--) {
			if (graph[v][i] == 0) continue;

			S.push(i);
		}
	}
}

// 함수의 실행 순서에 따라서 자연스럽게 방문이 진행 됨.
void recursive_dfs(int v) {
	cout << v << " ";
	visited_dfs2[v] = true;

	for (int i = 1;i <= n;i++) {
		if (visited_dfs2[i] == true || graph[v][i] == 0) continue;

		recursive_dfs(i);
	}
}

void bfs(int v) {
	Q.push(v);
	visited_bfs[v] = true;

	while (!Q.empty()) {
		int v = Q.front(); Q.pop();

		cout << v << ' ';

		for (int i = 1;i <= n;i++) {
			if (visited_bfs[i] == true || graph[v][i] == 0) continue;

			Q.push(i);
			visited_bfs[i] = true;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> v;


	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	recursive_dfs(v);

	cout << "\n";

	bfs(v);
}