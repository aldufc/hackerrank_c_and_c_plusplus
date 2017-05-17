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
#include <string>
#include <algorithm>
using namespace std;

/*
 *
 */


int main(int argc, char** argv) {
    int T, N, counterExample;
    vector<vector<char> > matrix;
    string input;
    cin >> T;
    while(T--){
        cin >> N;
        matrix.clear();
        matrix.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> input;
            for (int j = 0; j < N; j++) {
                matrix[i].push_back(input[j]);
            }            
            sort(matrix[i].begin(),matrix[i].end());
        }
        counterExample = 0;
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N-1; i++) {
                if(matrix[i][j] > matrix[i+1][j]){
                    counterExample = 1;
                    break;
                }
            }
            if(counterExample)
                break;
        }
        if(counterExample)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    
}

