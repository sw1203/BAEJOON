#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph;
vector<int> lotto;

void Lotto(int idx1, int idx2, int k) {
	if (idx2 == 6) {
		for (int i : lotto) 
			cout << i << " ";
		cout << endl;
		return;
	}

	for (int i = idx1; i < k; i++) {
		lotto[idx2] = graph[i];
		Lotto(i + 1, idx2 + 1,k);
	}
}
int main() {
	int k;
	while (true) {
		cin >> k;
		if (k == 0) break;
		graph.resize(k);
		lotto.resize(6);
		for (int i = 0; i < k; i++)
			cin >> graph[i];
		Lotto(0, 0, k);
		cout<<endl;
	}
}