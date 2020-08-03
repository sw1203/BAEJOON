#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int N, M, V; //N:정점의 수, M: 간선의 수, V:탐색을 시작할 정점
vector<vector<int>> graph;
vector<bool> visit;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = false;
	while (!q.empty()) { //queue가 비어있지 않으면 실행
		start = q.front(); // queue의 맨 앞 가져오기
		cout << start << " ";
		q.pop();
		for (int i : graph[start]) {
			if (visit[i]) {
				q.push(i);
				visit[i] = false;
			}
		}
	}
}
void dfs(int start) {
	cout << start << " ";
	visit[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int there = graph[start][i];
		if (visit[there] == false) dfs(there);
	}
}

int main() {
	cin >> N >> M >> V;
	graph.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);//양방향
		graph[v].push_back(u); //양방향
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	cout << endl;
	bfs(V);
	cout << endl;
	return 0;
}

