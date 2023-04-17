// HW2_CPP_Cource.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "HW2_CPP_Cource.h"
#include "Set.h"

int main()
{
    int sn = 0;
    int r = 0;
    int* s;
    int* temp;
    std::vector<int>* comb_res;

    std::cout << "Hello!\n";
    std::cout << "Enter array size (n): ";
    std::cin >> sn;
    try {
        s = new int[sn];
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error! Bad allocation mamory: " << e.what() << '\n';
        return 1;
    }

    std::cout << "Enter array elements: ";
    for (int i = 0; i < sn; i++) {
        std::cin >> s[i];
    }

    std::cout << "Enter combinations size (r): ";
    std::cin >> r;
    
    try {
        temp = new int[r];
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error! Bad allocation mamory: " << e.what() << std::endl;
        delete[] s;
        return 1;
    }

    Set Array(sn, s);

    std::cout << "Factorial ull " << sn << " = " << factorial_ull(sn) << "\n";
    std::cout << "Factorial   d " << sn << " = " << factorial_d(sn) << "\n";
    std::cout << "Factorial rec " << sn << " = " << factorial_rec(sn) << "\n";

    std::cout << "number_of_combinations " << r << " in " << sn << " = " << number_of_combinations(sn, r) << "\n";
    std::cout << "number_of_combinations " << r << " in " << sn << " with repetition = " << number_of_combinations(sn, r, true) << "\n";

    comb_res = Array.combination(r);
    std::cout << "\n";

    std::cout << "number_of_permutations " << r << " in " << sn << " = " << number_of_permutations(sn, r) << "\n";
    std::cout << "number_of_permutations " << r << " in " << sn << " with repetition = " << number_of_permutations(sn, r, true) << "\n";

    comb_res = Array.permutation(r);
    std::cout << "\n";

    delete[] s;
    delete[] temp;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
