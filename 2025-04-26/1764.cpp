#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>


using namespace std;

/*
    *문제 번호 : 1764

    *문제명 : 듣보잡

    *문제 설명 :
          김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

    *입력 :
          첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

          듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

    *출력 :
          듣보잡의 수와 그 명단을 사전순으로 출력한다.

*/
int main() {
      vector<string> result = {};

      unordered_map<string, bool> map_name = {};

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      int n, m;

      cin >> n >> m;

      // 배열로 풀면 지저분할 거 같은데, 500000, 500000이라 탐색하기도 쉽지 않을 듯.

      while (n--) {
            string name;
            cin >> name;

            map_name.insert({ name, true });
      }

      while (m--) {
            string name;
            cin >> name;

            if (map_name.count(name) == true) {
                  result.push_back(name);
            };
      }

      sort(result.begin(), result.end());

      cout << result.size() << endl;

      for (const auto& name : result) {
            cout << name << endl;
      }
}