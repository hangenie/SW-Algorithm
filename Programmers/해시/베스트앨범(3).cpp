#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> genre_sum;
	map<string, vector<int>> genre_plays;

	for (int i = 0; i < genres.size(); i++) {
		genre_sum[genres[i]] += plays[i];
		genre_plays[genres[i]].push_back(i);
	}

	vector<pair<string, int>> reorder(genre_sum.begin(), genre_sum.end());
	sort(reorder.begin(), reorder.end(), cmp);

	for (auto iter = reorder.begin(); iter != reorder.end(); iter++) {
		string genre;
		vector<pair<int, int>> v;

		genre = iter->first;
		
		for (int i = 0; i < genre_plays[genre].size(); i++) {
			v.push_back(make_pair(genre_plays[genre][i], plays[genre_plays[genre][i]]));
		}
		sort(v.begin(), v.end(), cmp2);

		if (v.size() < 2) {
			answer.push_back(v[0].first);
		}
		else {
			answer.push_back(v[0].first);
			answer.push_back(v[1].first);
		}
	}
    
    return answer;
}