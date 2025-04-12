#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
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




struct Node {
      int node_index;
      vector<Node> edge(0);

      Node(int index = 0) {
            node_index = index;
      }
};

vector<Node> graph = { Node() };
vector<bool> dfs_check(1001, 0);
vector<bool> bfs_check(1001, 0);

vector<int> dfs_stack(0);
deque<int> bfs_queue(0);

bool is_dfs_checked(int index) {
      if (dfs_check.at(index) == true) {
            return true;
      } else {
            return false;
      }
}

void dfs(int index) {


      Node current_node = graph[index];
      vector<Node> current_edge = current_node.edge;

      int current_index = current_node.node_index;

      dfs_check[current_index] = true;

      // 초기 노드를 초기화 및 더 탐색할 수 없으므로 출력.
      if (current_node.edge.empty() == true) {
            cout << current_index << " ";
            return;
      }

      // 자기 자신이 아직까지 탐색이 필요하다는 것을 등록함.
      dfs_stack.push_back(current_index);

      Node next_node = current_node.edge.front();
      int next_index = 0;

      // 1. 그래프의 특성상 한 번만 노드에 들어가면, 노드는 완벽하게 탐색할 수 있을 것 같음. (동적 계획법과 비슷한 논리.)
      // 2. 그런데 이걸 DFS라고 부를 수 있나? 만일 BFS를 구현해야한다고 치면 어떻게 접근해야하지?

      // 현재 노드와 연결된 모든 간선을 탐색 함.
      while (next_index < current_node.edge.size()) {
            if (is_dfs_checked(next_index) == true) {
                  continue;
            }

            // dfs는 
            dfs(next_index);

            next_index++;
      }

      // 마지막으로
      dfs_check[current_index] = true;
      dfs_stack.pop_back();

      cout << current_index << " ";

      return;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      // 
      int n, m, v;
      cin >> n >> m >> v;

      for (int i = 0;i < m;i++) {
            graph.push_back(Node(i + 1)); // 노드 번호 = 인덱스로 초기화 함.
      }



      while (m--) {
            int start, end;
            cin >> start >> end;

            // start >= 1, end >= 1
            bool is_duplicated = false;
            for (const auto& next_node : graph[start].edge) {
                  // 중복 노드가 존재하는 경우.
                  if (next_node.node_index == end) {
                        is_duplicated = true;
                  }
            }

            if (is_duplicated == true) {
                  continue;
            }

            graph[start].edge.push_back(Node(end));
      }

      for (const auto& node : graph) {
            sort(node.edge.begin(), node.edge.end(), [](Node a, Node b) { return a.node_index < b.node_index; });
      }

      // 각각 DFS, BFS를 수행한 결과를 출력하면 됨. 공백으로 구분자로 사용.
      dfs(v);

}