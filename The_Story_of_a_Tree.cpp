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

using namespace std;

/*
 *
 * nodes[i][j] == 0 no node no guess
 * nodes[i][j] == 1 node but no guess
 * nodes[i][j] == 2 no node but no guess
 * nodes[i][j] == 3 node and guess
 */

vector<list<int> > nodes;
vector<list<int> > guess;
//int nodes[1000][1000];
int visited[100000];
int initialScore[100000];
int scoreAsRoot[100000];

void dfs_phase_1(int currentNode){
    visited[currentNode] = 1;
    for(std::list<int>::iterator it = nodes[currentNode].begin(); it != nodes[currentNode].end(); it++){
        if (!visited[*it]){
            dfs_phase_1(*it);
            int guessScore = (find(guess[currentNode].begin(), guess[currentNode].end(),*it) != guess[currentNode].end() ) ? 1 : 0;
            initialScore[currentNode] += guessScore + initialScore[*it];
        }
    }
}

void dfs_phase_2(int currentNode){
    visited[currentNode] = 1;
    for (std::list<int>::iterator it = nodes[currentNode].begin(); it != nodes[currentNode].end(); it++){ 
        if(!visited[*it]){
            int guessScore_1 = (find(guess[currentNode].begin(), guess[currentNode].end(),*it) != guess[currentNode].end() ) ? 1 : 0;
            int guessScore_2 = (find(guess[*it].begin(), guess[*it].end(),currentNode) != guess[*it].end() ) ? 1 : 0;
            scoreAsRoot[*it] = guessScore_2 + scoreAsRoot[currentNode] - guessScore_1;
            dfs_phase_2(*it);
        }
    }
}

void clearVisited(int n){
    for (int i = 0; i < n; i++) 
        visited[i] = 0;    
}
void clearAndInitialize(int n){
    nodes.clear();
    nodes.resize(n);
    guess.clear();
    guess.resize(n);
    for (int i = 0; i < n; i++){ 
        visited[i] = 0;
        initialScore[i]=0;
        scoreAsRoot[i] = 0;        
//        for (int j = 0; j < n; j++) {
//            nodes[i][j] = 0;
//        }
    }    
}

int mdc(int a, int b){
    if (a % b == 0)
        return b;
    return mdc(b, a%b);
}

int main(int argc, char** argv) {

    int q,n,nEdges;
    int nGuesses, pretendScore, totalVictories;
    cin >> q;

    while(q--){
        cin >> n;
        
        clearAndInitialize(n);
        
        nEdges = n-1;
        while(nEdges--){
            int u,v;
            cin >> u >> v;
            nodes[u-1].push_back(v-1);
            nodes[v-1].push_back(u-1);
        }
        cin >> nGuesses >> pretendScore;
        while(nGuesses--){
            int u, v;
            cin >> u >> v;
            guess[u-1].push_back(v-1);
        }
        dfs_phase_1(0);
        scoreAsRoot[0] = initialScore[0];
        clearVisited(n);
        dfs_phase_2(0);
        totalVictories = 0;
        for (int i = 0; i < n; i++) {
            if (scoreAsRoot[i] >= pretendScore){
                totalVictories++;
            }
        }
        if(totalVictories == 0)
            cout << "0/1" << endl;
        else{
            int divisor = mdc(totalVictories,n);
            totalVictories = totalVictories/divisor;
            n = n/divisor;
            cout << totalVictories << "/" << n << endl;
        }
    }
    
    return 0;
}

