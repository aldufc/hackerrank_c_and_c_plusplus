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
    list<char> normalForm;
    string input;
    cin >> input;
    normalForm.push_back(input[0]);
    for (int i = 1; i < input.size(); i++) {
        if(normalForm.back() == input[i])
            normalForm.pop_back();
        else
            normalForm.push_back(input[i]);
    }
    if(normalForm.size() == 0)
        cout << "Empty String" << endl;
    else{
        for(list<char>::iterator it = normalForm.begin(); it != normalForm.end(); it++)
            cout << *it;
        cout << endl;        
    }

}

