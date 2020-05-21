#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<char> &a, vector<int> &perm) {
	for (int i = 0; i < a.size(); i++) {
		if ((a[i] == '<'&&perm[i] > perm[i + 1]) || (a[i] == '>'&&perm[i] < perm[i + 1])) {
			return false;
		}
	}
	return true;
}

int main() {
	int K;
	cin >> K;
	vector<char> a(K);
	for (int i = 0; i < K; i++) {
		cin >> a[i];
	}
	vector<int> min(K + 1);
	vector<int> max(K + 1);

	for (int i = 0; i <= K; i++) {
		min[i] = i;
		max[i] = 9 - i;
	}

	do {
		if (check(a, min))
			break;
	} while (next_permutation(min.begin(), min.end()));//순열

	do {
		if (check(a, max))
			break;
	} while (prev_permutation(max.begin(), max.end())); //순열

	for (int i = 0; i < max.size(); i++) {
		cout << max[i];
	}
	cout << endl;

	for (int i = 0; i < min.size(); i++) {
		cout << min[i];
	}
	cout << endl;
	
	return 0;
}