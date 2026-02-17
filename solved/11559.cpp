#include <bits/stdc++.h>

using namespace std;

// 1. 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.
// 2. 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.
// 3. 터질 수 있는 뿌요가 '여러 그룹이 있다면 동시에 터져야 하고' "여러 그룹이 터지더라도 한번의 연쇄가 추가"된다.

int dx[] = { 1,0,-1,0 };
int dy[] = { 0, 1,0,-1 };

// 연쇄 결과를 반환하기 위해 bool 타입을 사용함.
bool bfs(vector<vector<char>>& grid, pair<int, int> st) {
	auto [st_x, st_y] = st;
	char color = grid[st_x][st_y];

	queue<pair<int, int>> q;
	vector<vector<bool>> visited(12, (vector<bool>(6, false)));
	vector<pair<int, int>> pos; // '.'으로 바꾸기 위한 배열
	int l = 0;

	visited[st_x][st_y] = true;
	l++;
	q.push(st);
	pos.push_back(st);

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (visited[nx][ny] == true || grid[nx][ny] != color) continue;

			visited[nx][ny] = true;
			l++;
			q.push({ nx, ny });
			pos.push_back({ nx, ny });
		}
	}

	if (l >= 4) {
		for (auto [x, y] : pos) {
			grid[x][y] = '.';
		}
		return true;
	}

	return false;
}

// 검증 필요.
void drop(vector<vector<char>>& grid) {
	for (int c = 0;c < 6;c++) {
		vector<char> puyo;

		for (int r = 0;r < 12;r++) {
			if (grid[r][c] != '.') {
				puyo.push_back(grid[r][c]);
				grid[r][c] = '.';
			}
		}

		// 처리하기 전에 grid를 초기화해줘야함.
		for (int i = 0; i < puyo.size();i++) {
			grid[12 - puyo.size() + i][c] = puyo[i];
		}
	}
}

int main() {
	vector<vector<char>> grid(12, vector<char>(6, '.'));

	// 최대 60번 탐색 
	// 최대 15연쇄까지 가능.
	for (int i = 0;i < 12;i++) {
		for (int j = 0;j < 6;j++) {
			cin >> grid[i][j];
		}
	}

	int result = 0;

	while (true) {
		int tmp = result;
		bool bomb = false;
		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 6;j++) {
				if (grid[i][j] == '.') continue;

				bomb = max(bomb, bfs(grid, { i,j }));
			}
		}

		if (bomb == false) {
			cout << result;
			return 0;
		}



		drop(grid);
		result++;
	}


	// 1. 4개 이상이 있다는 것을 어떻게 확인할 수 있을까?
	// => 개수를 모르니까 모든 지도에 대해서 BFS를 돌려야 함. 
	// => bfs의 노드 방문 횟수를 체크하고, 4개 이상이라면, 그 다음 '.'으로 바꿈.

	// 2. 현재 상황에서 지울 수 있는 뿌요를 파악해야한다.
	// 2. 1. 만일 지울 수 없다면 종료한다. 그런데 이를 어떻게 알 수 있을까?
	// 3. 여러 그룹이 있다면 동시에 터져야한다.
	// => 그렇다면 터트린 이후에 정렬을 실행한다. 
	// 4. 뿌요를 떨어뜨려야한다. (이 때, 콤보를 추가한다.)
	// => 뿌요는 범위를 벗어나거나 다른 뿌요를 만날 때까지 내려간다. (굳이 실시간으로 터트릴 필요는 없다.)

}