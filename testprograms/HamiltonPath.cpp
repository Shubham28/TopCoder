#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

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

class HamiltonPath {
public:
	int countPaths(vector <string>);
	
	bool travr(VS &roads, string &comb, int &ch) {
		
		int count=0;
		FOR(c,0,comb.size()-1)
			if( roads[ (int)comb[c]-48 ][ (int)comb[c+1]-48 ]=='Y' )
				++count;
		
			if(count==ch)
				return true;
			else
				return false;
	}
};

int HamiltonPath::countPaths(vector <string> roads) {
	string comb="";
	long long ret=0;
	int ro=0;
	
	FOR(c,0,roads.size())
		comb+=(char)(c+48);
		
	FOR(r,0,roads.size())
		FOR(c,0,roads[r].size())
			if(roads[r][c]=='Y')
				++ro;
		
	ro/=2;
	
	do{
		if( travr(roads,comb,ro) )
			++ret;
	} while( next_permutation(comb.begin(),comb.end()) );

	return ret;
		
}


double test0() {
	string t0[] = {"NYN",
 "YNN",
 "NNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"NYY",
 "YNY",
 "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
double test3() {
	string t0[] = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Author: Shubham Gupta
//Powered by [KawigiEdit] 2.0!; 
