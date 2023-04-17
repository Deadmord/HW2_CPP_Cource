#pragma once

#include "HW2_CPP_Cource.h"
#include <iostream>
#include <vector>
#include <algorithm> //for sorting array

using namespace std;

#ifndef SET_H
#define SET_H
class Set
{
public:
    Set(size_t sn, int* s);
    ~Set();

    std::vector<int>* combination(unsigned r);
    std::vector<int>* permutation(unsigned r);

private:
    void fill_combinations(vector<int>& arr, vector<int>& temp, vector<int>* array_Comb_ptr, int index, int n, int r, int last);
    void fill_permutations(vector<int>& arr, vector<int>& temp, vector<int>* array_Comb_ptr, int index, int n, int r);

private:
    size_t size_;
    int* array_;
    vector<int> array_container;

    size_t size_Comb;
    double num_Comb;
    vector<int>* array_Comb;

    size_t size_Perm;
    double num_Perm;
    vector<int>* array_Perm;
};
#endif // SET_H
