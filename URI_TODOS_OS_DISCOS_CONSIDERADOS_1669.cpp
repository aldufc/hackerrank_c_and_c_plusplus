#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <climits>
#define BRANCO 0
#define CINZA 1
#define PRETO 3

using namespace std;

/*
 * 
 */

vector<vector<int> > graph;
vector<int> color;
vector<int> DVD;
vector<int> father;
vector<int> maxChange;

void dfs(int current_vertex){
    color[current_vertex] = CINZA;
    for (int i = 0; i < graph[current_vertex].size(); i++) {
        if(color[graph[current_vertex][i]] == BRANCO){
            dfs(graph[current_vertex][i]);
        }
        if(maxChange[current_vertex] <= maxChange[graph[current_vertex][i]]){
            maxChange[current_vertex] = maxChange[graph[current_vertex][i]] + (DVD[current_vertex]!=DVD[graph[current_vertex][i]]);
        }
    }
    color[current_vertex] = PRETO;
}

int main(int argc, char** argv) {
    int N1, N2, D;
    int X,Y;
    cin >>  N1 >> N2 >> D;
    while (!(N1 == 0 && N2 == 0 && D==0)) {
        graph.clear();
        graph.resize(N1+N2);
        DVD.resize(N1+N2);
        father.resize(N1+N2);
        color.resize(N1+N2);
        maxChange.resize(N1+N2);
        for (int i = 0; i < N1+N2; i++) {
            DVD[i] = (i < N1) ? 1 : 2;
            father[i] = -1;
            color[i] = BRANCO;
            maxChange[i] = 1;  //inicialmente todo mundo precisa de troca
        }
        for (int i = 0; i < D; i++) {
            cin >> X >> Y;
            graph[Y-1].push_back(X-1);
            father[X-1] = Y-1;
        }
        
        for (int i = 0; i < graph.size(); i++) {
            if(father[i] == -1){
                dfs(i);
            }
        }
        int maxSequenceDVD1,maxSequenceDVD2;
        maxSequenceDVD1= 0;
        maxSequenceDVD2=0;
        for (int i = 0; i < N1+N2; i++) {
            if(father[i] == -1 && DVD[i] == 1 && maxSequenceDVD1 < maxChange[i])
                maxSequenceDVD1 = maxChange[i];
            if(father[i] == -1 && DVD[i] == 2 && maxSequenceDVD2 < maxChange[i])
                maxSequenceDVD2 = maxChange[i];            
        }
        
        if(maxSequenceDVD1 == maxSequenceDVD2)
            cout << maxSequenceDVD1 + 2 << endl;
        else{
            int max = (maxSequenceDVD1 > maxSequenceDVD2) ? maxSequenceDVD1 : maxSequenceDVD2;
            cout << max + 1 << endl;
        }
        cin >> N1 >> N2 >> D;
    }

    return 0;
}
