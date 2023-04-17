//The modele with functions for math calculation
#include <math.h>

unsigned long long factorial_ull(unsigned n) //ull type overflow after 20!
{
	unsigned long long res(1);

	if (n) 
	{
		do res *= n;
		while (--n);
	}

	return res;
}

double factorial_d(unsigned n) //double type overflow after 170! but w/o errors
{
	double res(1);

	if (n)
	{
		do res *= n;
		while (--n);
	}

	return res;
}

double factorial_rec(unsigned n) //stack owerflow near 4000!
{
	//if (n)
	//	return n * factorial_rec(n - 1);
	//else
	//	return 1;

	return n ? n * factorial_rec(n - 1) : 1;
}

double number_of_combinations(unsigned n, unsigned r, bool rep = 0)
{
	if (n)
	{
		if (rep)
			return factorial_d(n + r - 1) / (factorial_d(r) * factorial_d(n - 1));
		else
			return factorial_d(n) / (factorial_d(r) * factorial_d(n - r));
	}
}

double number_of_permutations(unsigned n, unsigned r, bool rep = 0)
{
	if (n)
	{
		if (rep)
			return pow(n, r);
		else
			return factorial_d(n) / factorial_d(n - r);
	}
}

