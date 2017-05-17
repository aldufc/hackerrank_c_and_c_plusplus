/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexandre Arruda
 *
 * Created on 28 de Março de 2017, 12:55
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

/*
 *
 */

vector<list<int> > nodes;
int visited[100000];

void clearAndInitialize(int n){
    nodes.clear();
    nodes.resize(n);  
    for (int i = 0; i < n; i++) 
        visited[i] = 0;
}

int dfs(int node){
    int counter = 0;
    visited[node] = 1;
    for(list<int>::iterator it = nodes[node].begin(); it!= nodes[node].end(); it++){
        if(!visited[*it]){
            counter += dfs(*it) + 1;
        }       
    }
    return counter;
}

int main(int argc, char** argv) {
    int q,n,m,cRoad, cLib;
    long long int bestCost;
    cin >> q;
    while(q--){
        cin >> n >> m >> cLib >> cRoad;
        clearAndInitialize(n);
        bestCost = 0;
        while(m--){
            int u,v;
            cin >> u >> v;
            nodes[u-1].push_back(v-1);
            nodes[v-1].push_back(u-1);
        }
        for(int i=0; i < n; i++){
            if(!visited[i]){
                int totalRoads = dfs(i);
                int totalCities = totalRoads+1;
                bestCost += min(totalRoads*cRoad + cLib, totalCities*cLib);
            }
        }
        cout << bestCost << endl;
                
    }
    
    return 0;
}

