#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;


	vector<int> seq;
	vector<int> stk;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		seq.push_back(t);
	}

	int next = 1;

	// 스택은 기본적으로 작은 값이 아래에 남게 된다.
	// 그리고 p보다 작은 값을 출력하고 싶으면 스택에 남아있어야 한다.
	string buffer = "";
	for (int i = 0;i < n;i++) {
		int s = seq[i];

		while (s >= next) {
			stk.push_back(next++);
			buffer += "+\n";
		}

		if (stk.back() != s) {
			cout << "NO";
			return 0;
		}

		// 문제 이해를 잘못했음. 현 시점의 스택이 출력 가능한지를 보는 것이었음.
		buffer += "-\n";
		stk.pop_back();

	}

	cout << buffer;
}