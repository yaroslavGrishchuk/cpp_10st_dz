#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<pair <double, double> > data;


void metric_1 () {
    sort(data.begin(), data.end(),
            [](const pair<double, double>& a, const pair<double, double>& b){ return a.first < b.first; });
}

void metric_2() {
    sort(data.begin(), data.end(),
         [](const pair<double, double>& a, const pair<double, double>& b){ return a.second < b.second; });
}

void metric_3() {
    sort(data.begin(), data.end(),
         [](const pair<double, double>& a, const pair<double, double>& b)
         { return sqrt(a.second * a.second + a.first * a.first) < sqrt(b.second * b.second + b.first * b.first); });
}

int main() {
    int metric;
    int limitation;
    vector<vector <pair <double, double > > > answer;
    cin >> metric >> n >> limitation;
    double a,b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        data.emplace_back(a,b);
    }

    assert(n == 0 || n == 1 || n == 2 || limitation > 0);
    if (metric == 0) {
        metric_1();
    } else if (metric == 1) {
        metric_2();
    } else metric_3();

    int m = n % limitation == 0? n / limitation : n / limitation + 1;
    for (int i = 0; i < m; i++) {
        answer.push_back(vector<pair<double, double> >());
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < limitation; j++) {
            if (i * limitation + j == n) {
                break;
            }
            answer[i].push_back(data[i * limitation + j]);
        }
    }


    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << '{' << answer[i][j].first << ", " << answer[i][j].second << '}' << ' ';
        }
        cout << endl;
    }
}