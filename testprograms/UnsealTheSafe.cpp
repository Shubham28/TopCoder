#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <bitset>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define LL long long

using namespace std;

class UnsealTheSafe {
public:
	long long countPasswords(int);
};

long long UnsealTheSafe::countPasswords(int N) {
	vector< vector<LL> >S(N,vector<LL>(10,1));
	
	FOR(r,1,N){
		S[r][0]=S[r-1][7],S[r][1]=S[r-1][2]+S[r-1][4],S[r][2]=S[r-1][1]+S[r-1][3]+S[r-1][5];
		S[r][3]=S[r-1][2]+S[r-1][6],S[r][4]=S[r-1][1]+S[r-1][5]+S[r-1][7];
		S[r][5]=S[r-1][2]+S[r-1][4]+S[r-1][6]+S[r-1][8];
		S[r][6]=S[r-1][3]+S[r-1][5]+S[r-1][9],S[r][7]=S[r-1][0]+S[r-1][4]+S[r-1][8];
		S[r][8]=S[r-1][5]+S[r-1][7]+S[r-1][9],S[r][9]=S[r-1][6]+S[r-1][8];
	}
	LL ret=0;
	FOR(i,0,10)
		ret+=S[N-1][i];
	return ret;
}

double test0() {
	int p0 = 2;
	UnsealTheSafe * obj = new UnsealTheSafe();
	clock_t start = clock();
	long long my_answer = obj->countPasswords(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 26LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	UnsealTheSafe * obj = new UnsealTheSafe();
	clock_t start = clock();
	long long my_answer = obj->countPasswords(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 74LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 25;
	UnsealTheSafe * obj = new UnsealTheSafe();
	clock_t start = clock();
	long long my_answer = obj->countPasswords(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 768478331222LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!; 
