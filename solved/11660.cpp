#include <iostream>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<vector<int>> sum(n, vector<int>(n, 0));

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int e;
			cin >> e;
			arr[i][j] = e;
		}

		// 각 행마다 부분합을 구함.
		sum[i][0] = arr[i][0];
		for (int j = 1;j < n;j++) {
			sum[i][j] = sum[i][j - 1] + arr[i][j];
		}
	}

	// 출력 부분.
	// 부분합은 앞 뒤로 뺄 필요는 없음.
	// 1 Base임. 기억했다가 반영하자...
	for (int i = 0;i < m;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int total = 0;
		for (int j = x1 - 1; j < x2; j++) {
			total += sum[j][y2 - 1] - sum[j][y1 - 1];
		}

		cout << total << "\n";
	}

}
