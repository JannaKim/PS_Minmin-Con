#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    int n = weights.size();
    vector<vector<double>> graph(n);
    
    for(double i = 0; i < n; ++i){
        double win_rate = 0; // double!
        double tot = 0;
        double heavy_rate = 0;
        for(int j = 0; j < n; ++j)
            if(head2head[i][j] == 'W') {
                ++win_rate;
                ++tot;
                if(weights[i] < weights[j]) ++heavy_rate;
            }
            else if(head2head[i][j] == 'L') ++tot;
        graph[i] = {(tot - win_rate) / tot, n - heavy_rate, 150.0 - weights[i], i + 1};
    }
    
    sort(graph.begin(), graph.end());
    vector<int> answer(n);
    for (int i = 0; i < n ; ++i) 
          answer[i] = graph[i][3];
    
    return answer;
}