#pragma once
#include <iostream>
#include <vector>

unsigned long long factorial_ull(unsigned n);
double factorial_d(unsigned n);
double factorial_rec(unsigned n);

double number_of_combinations(unsigned n, unsigned r, bool rep = 0);

double number_of_permutations(unsigned n, unsigned r, bool rep = 0);