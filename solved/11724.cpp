#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <deque>

using namespace std;

/*
    *문제 번호 : 11724

    *문제명 : 연결 요소의 개수

    *문제 설명 :
          방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

    *입력 :
          첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

    *출력 :
          첫째 줄에 연결 요소의 개수를 출력한다.

*/

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int n, m;

      cin >> n >> m;

      int u, v;

      vector<bool> is_visited = vector<bool>(n + 1, false);
      vector<vector<int>> bfs_vertex(n + 1, vector<int>());
      deque<int> bfs_queue = deque<int>();

      // 간선을 어떤 방식으로 할당하면 좋을까?
      // 1. 벡터를 사용하자.
      while (m--) {
            cin >> u >> v;

            bfs_vertex[u].push_back(v);
            bfs_vertex[v].push_back(u);
      }

      int count = 0;

      // 요약 : 
      // 1. 탐색할 정점을 반복문으로 구함. => 탐색이 완벽하다면, 모든 연결 요소를 확인할 수 있을 것.
      // 2. 탐색하기 전에 먼저 정점이 탐색되었는지 확인해야함.
      // 3. 이후 탐색 여부 확인 => is_visited 체크 => queue에 삽입. 순으로 진행 함.

      for (int i = 1; i <= n; i++) {
            if (is_visited[i] == true) {
                  continue;
            }

            // 탐색이 가능하다는 뜻은 연결 요소가 있다는 뜻.
            count++;

            bfs_queue.push_back(i);
            is_visited[i] = true;

            // 큐에 존재하는 정점에는 중복이 없어야 함. 방법이 뭐가 있을까?
            // 1. is_visited를 queue에 등록하는 순간에 체크하게 한다.
            //    => 그렇다면 큐에 등록되기 전에 탐색이 이루어진 셈치고, 큐에 하위 요소를 추가할 때, 표시해주자.
            //    => "큐에 등록됨" == "탐색하지 않은 정점을 탐색했음."
            // 2. 혹은 중복되지 않는 구조를 구한다.

            // 해당 정점과 이어진 경로를 탐색하기 위해 queue에서 나오는 것.
            // queue에 체크하기 전 이미 탐색이 끝난 것으로  => is_visited는 queue에 푸시하기 전에 체크.
            while (bfs_queue.empty() == false) {
                  int vertex = bfs_queue.front();
                  bfs_queue.pop_front();

                  // 이러면 큐에 깔끔하게 안 들어가겠는데? 중복이 생길 듯?
                  for (const auto& v : bfs_vertex[vertex]) {
                        if (is_visited[v] == true) {
                              continue;
                        }
                        bfs_queue.push_back(v);
                        is_visited[v] = true;
                  }
            }
      }

      // 예제 출력은 제대로 나옴. 고려하지 않은 경우의 수가 있을까?
      // => 결국 입력인 그래프의 형태에 따라서 문제가 발생할 것임. 어떤 그래프의 형태에서 문제가 생길까?
      // 1. 순환? => 이후에 queue에 넣기 전에 is_visited 체크를 할 것인데, 그 때 걸릴 것. 
      // 2. 중복된 간선? => queue에 넣기 전 is_visited 체크를 하기 때문에 queue에 들어갈 수 있는 정점은 고유함.
      cout << count;

}