#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int state, pop[100], sz;

void hh() {

  priority_queue<pair<ld, int>> pq;
  int left = sz - state, seats[100];
  for (int i = 0; i < state; ++i) {
    seats[i] = 1;
  }
  for (int i = 0; i < state; ++i) {
    pq.push(make_pair((ld)pop[i] / sqrt(seats[i] * (seats[i] + 1)), i));
  }
  while (left > 0) {
    int temp = pq.top().second;
    ++seats[temp];
    --left;
    pq.pop();
    pq.push(
        make_pair((ld)pop[temp] / sqrt(seats[temp] * (seats[temp] + 1)), temp));
  }
  for (int i = 0; i < state; ++i) {
    cout << seats[i] << endl;
  }
}

int main() {

  cin >> sz >> state;
  for (int i = 0; i < state; ++i) {
    cin >> pop[i];
  }

  hh();
}
