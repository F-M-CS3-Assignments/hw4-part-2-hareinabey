//Author: Harein Abeysekera
// 03/30/25

#include <iostream>
#include "bdc.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//No need for dynamic programming
// Convert a vector of integers to a formatted string
string vec_to_string(vector<int> v){
    string s = "[";
    for (int i = 0; i < v.size(); i++){
        s += to_string(v[i]);
        if (i < v.size() - 1){
            s += ", ";
        }
    }
    s += "]";
    return s;
}