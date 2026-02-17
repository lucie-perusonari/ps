#include<bits/stdc++.h>

using namespace std;

int n, m;

int graph[501][501];
queue<int> q;
int dist[501];
int main() {
	cin >> n >> m;


	fill(dist, dist + 501, -1);
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// 자신의 친구와 친구의 친구를 초대.

	// 상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다.
	// 이 리스트를 바탕으로 결혼식에 초대할 "사람의 수"를 구하는 프로그램을 작성하시오.

	int result = 0;

	dist[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int j = 1;j <= n;j++) {
			if (graph[v][j] == 0 || dist[j] != -1) continue;
			dist[j] = dist[v] + 1;
			q.push(j);
		}
	}

	for (int i = 0;i < 501;i++) {
		if (dist[i] >= 0 && dist[i] <= 2) result++;
	}


	cout << result - 1;
}