#include <iostream>
#include <string.h>

using namespace std;

int N, answer;
int begin_x, begin_y, end_x, end_y;
int client_x[10], client_y[10];
bool visited[10];

void initialize() {
	answer = 987654321;
	memset(client_x, 0, sizeof(client_x));
	memset(client_y, 0, sizeof(client_y));
	memset(visited, false, sizeof(visited));
}

void input() {
	cin >> N;
	
	cin >> begin_x >> begin_y >> end_x >> end_y;

	for (int i = 0; i < N; i++) {
		cin >> client_x[i] >> client_y[i];
	}
}

int cal_dist(int x1, int y1, int x2, int y2) {
	int d = 0;

	if (x1 > x2)
		d = x1 - x2;
	else d = x2 - x1;

	if (y1 > y2)
		d += y1 - y2;
	else d += y2 - y1;

	return d;
}

void DFS(int x, int y, int dist, int cnt) {
	if (cnt == N) {
		int d = cal_dist(x, y, end_x, end_y);
		dist += d;

		if (answer > dist)
			answer = dist;

		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;

		int d = cal_dist(x, y, client_x[i], client_y[i]);
		
		visited[i] = true;
		DFS(client_x[i], client_y[i], dist + d, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();
		DFS(begin_x, begin_y, 0, 0);

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}