#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <deque>

using namespace std;

/*
    *문제 번호 : 1260

    *문제명 : DFS와 BFS

    *문제 설명 :
          그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

    *입력 :
          첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

    *출력 :
          첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/

map<int, vector<int> > graph;
vector<bool> is_dfs_checked(1001, false);

string result = "";

void dfs(int a) {
      if (is_dfs_checked[a] == true) {
            return;
      }

      result.append(to_string(a));
      result.append(" ");
      is_dfs_checked[a] = true;

      if (graph.count(a) == false) {
            return;
      }

      for (const auto& entry : graph[a]) {
            dfs(entry);
      }
}

deque<int> bfs_queue = {};
vector<bool> is_bfs_checked(1001, false);

void bfs(int a) {
      bfs_queue.push_back(a);
      is_bfs_checked[a] = true;

      while (true) {
            if (bfs_queue.empty() == true) {
                  break;
            }

            int b = bfs_queue.front();
            bfs_queue.pop_front();

            // cout << b << " ";
            result.append(to_string(b));
            result.append(" ");

            for (auto entry : graph[b]) {
                  if (is_bfs_checked[entry] == true) {
                        continue;
                  }
                  is_bfs_checked[entry] = true;
                  bfs_queue.push_back(entry);
            }
      }
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      // 
      int n, m, v;
      cin >> n >> m >> v;


      // 간단하게 탐색만 구현해보자.
      while (m--) {
            int a, b;
            cin >> a >> b;

            if (graph.count(a) == false) {
                  graph[a] = {};
            }

            if (graph.count(b) == false) {
                  graph[b] = {};
            }

            // 양방향 연결.
            // 중복이 생기는 것을 염두해야할 것 같음.
            graph[a].push_back(b);
            graph[b].push_back(a);
      }

      for (auto& entry : graph) {
            sort(entry.second.begin(), entry.second.end());
      }

      dfs(v);
      result.pop_back();
      result += "\n";

      bfs(v);
      result.pop_back();
      cout << result;
}