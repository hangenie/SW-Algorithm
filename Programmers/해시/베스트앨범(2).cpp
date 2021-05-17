#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> a, const pair<string, int> b) {
	return a.second > b.second;
}
bool cmp2(const pair<int, int> a, const pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> play_times;
	map<string, vector<pair<int, int>>> music;

	// �帣�� ���Ƚ�� ����
	for (int i = 0; i < genres.size(); i++) {
		play_times[genres[i]] += plays[i];
		music[genres[i]].push_back(make_pair(plays[i], i));
	}

	// ���Ƚ���� �������� �������� ����
	vector<pair<string, int>> pt(play_times.begin(), play_times.end());
	sort(pt.begin(), pt.end(), cmp);


	for (int i = 0; i < pt.size(); i++) {
		vector<pair<int, int>> temp = music[(pt[i].first)];

		// �뷡 �ΰ� ��� answer�� �߰�
		sort(temp.begin(), temp.end(), cmp2);

		for (int k = 0; k < 2 && k < temp.size(); k++) {
			answer.push_back(temp[k].second);
		}
	}

	return answer;
}