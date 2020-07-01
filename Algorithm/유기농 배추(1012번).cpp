#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector<int>> graph;
vector<int> num;
vector<vector<bool>>visited;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int M, int N) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (graph[nx][ny] == 1 && visited[nx][ny] == false) {
			dfs(nx, ny, M, N);
		}
	}
}
int main() {
	int T;
	cin >> T;
	int cnt = 0;
	while (T > 0) {
		T--;
		int M, N, K;
		cin >> M >> N >> K;
		
		graph.clear();
		visited.clear();
		
		graph.resize(M); // 이전 순번 내용 clear
		visited.resize(M); // 이전 순번 내용 clear

		for (int i = 0; i < M; i++) {
			graph[i].resize(N);
			visited[i].resize(N);
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1 && visited[i][j] == false) {
					cnt++;
					dfs(i, j, M, N);
				}
			}
		}
		num.push_back(cnt);
		cnt = 0;
	}

	for (int elem : num) {
		cout << elem << endl;
	}
}