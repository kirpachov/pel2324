#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int count_patterns(int N, int M, string alph, string s)
{
  vector<pair<string, int>> sfx;
  int ans = 0, max_gap = 1;
  unordered_map<int, array<int, 2>> gaps;
  set<int> alive;
  int left = 0, right = M - 1;
  for (int i = 0; i < M; i++) {
    sfx.push_back(make_pair(s.substr(i), i));
  }

  for (int i = 0; i < M + 1; i++) {
    gaps[i] = {max(i - 1, 0), i + 1};
    alive.insert(i);
  }

  sort(sfx.begin(), sfx.end());

  for (int i = 0; i < M; i++) {
    while (left < right) {
      if (M - sfx[left].second > i && sfx[left].first[i] == s[i])
        break;

      int idx = sfx[left].second;
      int prec = *(prev(alive.lower_bound(idx)));
      int succ = *alive.upper_bound(idx);
      alive.erase(idx);
      gaps[prec][1] = succ;
      max_gap = max(max_gap, succ - prec);
      left++;
    }

    while (left < right) {
      if (M - sfx[right].second > i && sfx[right].first[i] == s[i])
        break;
      int idx = sfx[right].second;
      int prec = *(prev(alive.lower_bound(idx)));
      int succ = *alive.upper_bound(idx);
      alive.erase(idx);
      gaps[prec][1] = succ;
      max_gap = max(max_gap, succ - prec);
      right--;
    }

    if (max_gap <= i + 1)
      ans++;

  }

  return ans;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int N, M;
    string alph, s;
    cin >> N >> M;
    cin >> alph >> s;
    cout << count_patterns(N, M, alph, s) << endl;
  }
  return 0;
}