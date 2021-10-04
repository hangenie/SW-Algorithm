#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N, answer = 0;
bool visited[7] = { false };
unordered_map<string, bool> all;


bool is_prime(int num) {
    if (num <= 1) return false;
    
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

void DFS(string numbers, string num, bool visited[], int cnt) {
	if (num != "" && all.find(num) == all.end()) {
		all.insert(make_pair(num, true));
	}

	if (cnt == N) {
		return;
	}


	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		if (cnt == 0 && numbers[i] == '0') continue;

		visited[i] = true;
		num.push_back(numbers[i]);
		DFS(numbers, num, visited, cnt + 1);
		num.pop_back();
		visited[i] = false;
	}
}

int solution(string numbers) {
    N = numbers.size();

	DFS(numbers, "", visited, 0);

	for (auto iter = all.begin(); iter != all.end(); iter++) {
		if (is_prime(stoi(iter->first))) {
			answer++;
		}
    }
    
    return answer;
}