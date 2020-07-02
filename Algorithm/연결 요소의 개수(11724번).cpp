#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

void DFS(int node) {
	visit[node] = true;
	for (int i: graph[node]) {
		if (visit[i] == false)
			DFS(i);
	}
}
int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	graph.resize(N+1);
	visit.resize(N+1);
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		graph[U].push_back(V);
		graph[V].push_back(U);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt<<endl;
}