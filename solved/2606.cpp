#include <bits/stdc++.h>

using namespace std;

int graph[101][101];
int visited[101];
queue<int> q;

int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int st = 1;

	visited[st] = true;
	q.push(st);

	int result = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		result++;

		for (int i = 1;i <= n;i++) {
			if (graph[v][i] == 0 || visited[i] == true) continue;
			visited[i] = true;
			q.push(i);
		}
	}

	cout << result - 1;
}