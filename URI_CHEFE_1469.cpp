/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alexandre
 *
 * Created on 1 de Setembro de 2017, 14:21
 */

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
#define PRETO 2


using namespace std;

/*
 * 
 */

vector<vector<int> > graph;
vector<int> colorVertex;
vector<int> ageEmployee;
vector<int> nodeEmployee;
vector<int> employeeNode;
int youngest;

void dfs_visit(int current_vertex){
    colorVertex[current_vertex] = CINZA;
    for (int i = 0; i < graph[current_vertex].size(); i++) {
       if(colorVertex[graph[current_vertex][i]] == BRANCO){
            int employee = nodeEmployee[graph[current_vertex][i]];        
            youngest = (youngest > ageEmployee[employee]) ? ageEmployee[employee] : youngest;
            dfs_visit(graph[current_vertex][i]);           
       }
    }
    colorVertex[current_vertex] = PRETO;
}


int main(int argc, char** argv) {
    int N, M, I;
    while(cin >> N >> M >> I){
        graph.clear();
        graph.resize(N);
        colorVertex.resize(N);
        ageEmployee.resize(N);
        nodeEmployee.resize(N);
        employeeNode.resize(N);

        for (int i = 0; i < N; i++) {
            int age;
            cin >> age;
            ageEmployee[i] = age;
            nodeEmployee[i] = i;
            employeeNode[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int A,B;
            cin >> A >> B;
            graph[B-1].push_back(A-1);
        }

        for (int i = 0; i < I; i++) {
            char instruction;
            cin >> instruction;
            if(instruction == 'P'){
                int id;
                cin >> id;
                for (int i = 0; i < N; i++) {
                    colorVertex[i] = BRANCO;
                }

                youngest = INT_MAX;
                dfs_visit(employeeNode[id-1]);
                if(youngest == INT_MAX)
                    cout << "*" << endl;
                else
                    cout << youngest << endl;
            }
            else{
                int id1, id2;
                cin >> id1 >> id2;
                swap(nodeEmployee[employeeNode[id1-1]], nodeEmployee[employeeNode[id2-1]]);
                swap(employeeNode[id1-1], employeeNode[id2-1]);
            }
        }      
    }
    return 0;
}


