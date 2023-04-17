#include "Set.h"

using namespace std;


    Set::Set(size_t sn, int* s) : size_(sn), array_(new int[size_]), array_container(sn), array_Comb(nullptr), array_Perm(nullptr)
    {
        while (sn)
        {
            sn--;
            array_container[sn] = s[sn];
            array_[sn] = s[sn];
        }

        num_Comb = num_Perm = 0;
        size_Comb = size_Perm = 0;
    }

    Set::~Set()
    {
        delete[] array_;
        delete[] array_Comb;
        delete[] array_Perm;
    }

    vector<int> * Set::combination(unsigned r)
    {
        if ((size_Comb != r) && size_Comb);
        {                       //filling the array
            size_Comb = r;
            num_Comb = number_of_combinations(size_, size_Comb, true);

            delete[] array_Comb;

            //array_Comb = new vector<int>(size_Comb)[(int)num_Comb];
            vector<int>* array_Comb = new vector<int>[num_Comb];
            for (int i = 0; i < num_Comb; i++) {
                array_Comb[i] = vector<int>(size_Comb);
            }

            sort(array_, array_ + size_); //sort array for successful combinations;

            vector<int> temp(r);
            fill_combinations(array_container, temp, array_Comb, 0, size_, size_Comb, 0);
        }

        return array_Comb;
    }

    vector<int>* Set::permutation(unsigned r)
    {
        if ((size_Perm != r) && size_Perm);
        {                       //filling the array
            size_Perm = r;
            num_Perm = number_of_permutations(size_, size_Perm, true);

            delete[] array_Perm;

            //array_Comb = new vector<int>(size_Comb)[(int)num_Comb];
            vector<int>* array_Perm = new vector<int>[num_Perm];
            for (int i = 0; i < num_Perm; i++) {
                array_Perm[i] = vector<int>(size_Perm);
            }

            vector<int> temp(r);
            fill_permutations(array_container, temp, array_Perm, 0, size_, size_Perm);
        }

        return array_Perm;
    }

    void Set::fill_combinations(vector<int>& arr, vector<int>& temp, vector<int>* array_Comb_ptr, int index, int n, int r, int last) 
    {

        // print the combination if it full
        if (index == r) {
            for (int i = 0; i < r; i++) {
                cout << temp[i] << " ";
                (*array_Comb_ptr)[i] = temp[i];
            }
            cout << endl;
            array_Comb_ptr++;
            return;
        }
        
        //each next element not should be less then prev (elements sorted)
        for (int i = last; i < n; i++) {
            temp[index] = arr[i]; //fill place in combination
            fill_combinations(arr, temp, array_Comb_ptr, index + 1, n, r, i); //recursion for fill next places
            while (i < n - 1 && arr[i] == arr[i + 1]) { //skip the same elements in array
                i++;
            }
        }
    }

    void Set::fill_permutations(vector<int>& arr, vector<int>& temp, vector<int>* array_Perm_ptr, int index, int n, int r)
    {

        // print the permutation if it full
        if (index == r) {
            for (int i = 0; i < r; i++) {
                cout << temp[i] << " ";
                (*array_Perm_ptr)[i] = temp[i];
            }
            cout << endl;
            array_Perm_ptr++;
            return;
        }

        for (int i = 0; i < n; i++) {
            temp[index] = arr[i];
            fill_permutations(arr, temp, array_Perm_ptr, index + 1, n, r); //recursion for fill next places
        }
    }
