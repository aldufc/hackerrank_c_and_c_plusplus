#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
 * 
 */

vector<vector<pair<int,int>> > graph;
vector<int> visited;
vector<int> bestValue;

int main(int argc, char** argv) {
    int N, M;
    int U,V,C;
    int cost;
    cin >> N >> M;
    
    graph.resize(N);
    visited.resize(N);
    bestValue.resize(N);
    
    
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> C;
        graph[U-1].push_back(make_pair(V-1, C));
        graph[V-1].push_back(make_pair(U-1, C));
    }
    
    for (int i = 0; i < visited.size(); i++) {
        visited[i] = 0;
        bestValue[i] = INT_MAX;
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > priorityQueue; 
    
    visited[0] = 1;
    for (int i = 0; i < graph[0].size(); i++) {
        priorityQueue.push(make_pair(graph[0][i].second, graph[0][i].first));
    }
    cost = 0;
    while(!priorityQueue.empty()){
        pair<int,int> u = priorityQueue.top();
        priorityQueue.pop(); // retiro o elemento;
        if(visited[u.second]) continue;
        cost += u.first;
        visited[u.second] = 1;
        for (int i = 0; i < graph[u.second].size(); i++) {
            if(!visited[graph[u.second][i].first] && bestValue[graph[u.second][i].first] > graph[u.second][i].second){
                bestValue[graph[u.second][i].first] = graph[u.second][i].second;
                priorityQueue.push(make_pair(graph[u.second][i].second, graph[u.second][i].first));
            }
        }
    }
    
    cout << cost << endl;

    
    return 0;
}
