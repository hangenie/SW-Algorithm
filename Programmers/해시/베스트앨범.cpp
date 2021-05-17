#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}
bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> play_times;
    vector<pair<int, int>> music;

    // 장르별 재생횟수 정리
    for (int i = 0; i < genres.size(); i++) {
        if (play_times.find(genres[i]) != play_times.end()) {
            play_times[genres[i]] += plays[i];
        }
        else {
            play_times.insert(make_pair(genres[i], plays[i]));
        }
    }

    // 재생횟수를 기준으로 내림차순 정렬
    vector<pair<string, int>> pt(play_times.begin(), play_times.end());
    sort(pt.begin(), pt.end(), cmp);

    for (int i = 0; i < pt.size(); i++) {
        for (int j = 0; j < genres.size(); j++) {
            if (pt[i].first == genres[j]) {
                music.push_back(make_pair(j, plays[j]));
            }
        }

        // 노래 두곡 골라서 answer에 추가
        sort(music.begin(), music.end(), cmp2);

        for (int k = 0; k < 2 && k < music.size(); k++) {
            answer.push_back(music[k].first);
        }

        music.erase(music.begin(), music.end());
    }

    return answer;
}