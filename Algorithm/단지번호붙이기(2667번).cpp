#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<string> arr;
bool visited[25][25];
vector<int> cnt_vec;
int cnt;

void dfs(int x, int y, int N) {
	cnt++;
	visited[x][y] = true;

	for (int i=0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (arr[nx][ny] == '1' && visited[nx][ny] == false)
			dfs(nx, ny,N);
	}
}

int main() {
	int N = 0;
	cin >> N;
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		arr.push_back(line);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1' && visited[i][j] == false) {
				cnt = 0;
				dfs(i, j, N);
				cnt_vec.push_back(cnt);
			}
		}
	}

	sort(cnt_vec.begin(), cnt_vec.end());
	cout << cnt_vec.size() << endl;
	for (int i : cnt_vec) {
		cout << i << endl;
	}
}