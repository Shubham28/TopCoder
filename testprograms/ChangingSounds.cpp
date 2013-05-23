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

using namespace std;

class ChangingSounds {
public:
	int maxFinal(vector <int>, int, int);
};

int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	int ret=-1;
	
	vector< VB >perm(changeIntervals.size()+1,VB(1001,false));
	perm[0][beginLevel]=true;

	FOR(r,0,perm.size()-1)
		EFOR(c,0,maxLevel){
			if(perm[r][c] && c-changeIntervals[r]>=0)
				perm[r+1][c-changeIntervals[r]]=true;
			if(perm[r][c] && c+changeIntervals[r]<=maxLevel)
				perm[r+1][c+changeIntervals[r]]=true;
		}

	EFOR(c,0,maxLevel)
		if(perm[changeIntervals.size()][c])
			ret=max(ret,c);
			
	return ret;
}

double test0() {
	int t0[] = {5, 3, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	int p2 = 10;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {15, 2, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 8;
	int p2 = 20;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 40;
	int p2 = 243;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 238;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
