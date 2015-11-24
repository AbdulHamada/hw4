// filter.cxx.cpp : Defines the entry point for the console application.
//visual studio.

//#include "stdafx.h"
#include<iostream>
#include <cmath>
#include <fstream>
#include <string> //Strings are objects that represent sequences of characters.

using namespace std;
// the first function 

void read(double*const p, const int N, const string data)
 {
	ifstream in(data.c_str());
	for (int i = 0; i<N; i++)
		 {
		in >> p[i];
		 }
	in.close();
 } 
// the second function
void filter(double* const p, const int N)
 {
	double x = p[0];
	double y = p[1];
	double pn = (p[N - 2] + p[N - 1] + x) / 3;
	p[0] = (p[N - 1] + x + y) / 3;
	for (int i = 1; i<N; i++)
		 { y = p[i];
	p[i] = (x + p[i] + p[i + 1]) / 3;
	x = y;
	}
	p[N - 1] = pn;
	}
// the third function
void print_p(double* p, const int N)
 {
	ofstream out("hamada.txt");
	for (int i = 0; i<N; i++)
		 { out << p[i] << endl; }
	out.close();
	}


int main() {

	const int N = 237;
	const string data = "noisy.txt";
	double*p = new double[N];
	const int n = 15; 

	read(p, N, data);

	for (int i = 1; i<n; i++)
		 filter(p, N);
	
		print_p(p, N);
	
		
		
		delete[] p;
	
//	system("pause");
	
	return 0;
}
