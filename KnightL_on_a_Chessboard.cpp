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
#include <string>
#include <set>
#include <queue>

using namespace std;

/*
 * 
 */


int minimumKnightMoves(int a, int b, int n){
    set<vector<int> > setMoves;
    queue<vector<int> > queueMoves;
    vector<int> initialStateSet {0,0};
    vector<int> initialStateQueue {0,0,0};
    
    setMoves.insert(initialStateSet);
    queueMoves.push(initialStateQueue);
    
    
    while(!queueMoves.empty()){
        vector<int> move = queueMoves.front();
        queueMoves.pop();
        
        //if it is solution
        if(move[0] == n-1 && move[1] == n-1)
            return move[2];
        
        if(move[0]+a < n && move[1]+b < n){
            vector<int> checkMove {move[0]+a, move[1]+b};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]+a, move[1]+b, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }
        if(move[0]-a >=0 && move[1]+b < n){
            vector<int> checkMove {move[0]-a, move[1]+b};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]-a, move[1]+b, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }
        if(move[0] + a < n && move[1] - b >=0){
            vector<int> checkMove {move[0]+a, move[1]-b};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]+a, move[1]-b, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }
        if(move[0] - a >= 0 && move[1] - b >= 0){
            vector<int> checkMove {move[0]-a, move[1]-b};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]-a, move[1]-b, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }     
       if(move[0] + b < n && move[1] + a < n){
            vector<int> checkMove {move[0]+b, move[1]+a};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]+b, move[1]+a, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        } 
       if(move[0] - b >= 0 && move[1] + a < n){
            vector<int> checkMove {move[0]-b, move[1]+a};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]-b, move[1]+a, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }     
       if(move[0] + b < n && move[1] - a >= 0){
            vector<int> checkMove {move[0]+b, move[1]-a};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]+b, move[1]-a, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }          
       if(move[0] - b >=0 && move[1] - a >= 0){
            vector<int> checkMove {move[0]-b, move[1]-a};
            if(setMoves.find(checkMove) == setMoves.end()){
                vector<int> tmpState {move[0]-b, move[1]-a, move[2]+1};
                queueMoves.push(tmpState);
                setMoves.insert(checkMove);                
            }
        }   
    }
    return -1; 
}


int main(int argc, char** argv) {
    
    int n;
    cin >> n;    
    
    for (int i = 0; i < n-1; i++) {
        cout << minimumKnightMoves(i+1,1,n);
        for (int j = 1; j < n-1; j++) {
           cout << " " << minimumKnightMoves(i+1,j+1,n);
        }
        cout << endl;
    }
    return 0;
}

