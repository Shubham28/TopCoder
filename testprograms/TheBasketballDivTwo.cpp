#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
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

class TheBasketballDivTwo {
public:
	int find(vector <string>);
};

int TheBasketballDivTwo::find(vector <string> table) {

	int count=0;
	VI wins(table.size(),0);
	
	FOR(r,0,table.size())
		FOR(c,0,table[r].size()){
			if(table[r][c]=='W')
				++wins[r];
			else if(table[r][c]=='L')
				++wins[c];
			else if(table[r][c]=='?')
				++count;
		}
		
	if(count==0){
		SORT(wins);
		return wins[wins.size()-1];
	}

	long comb=(long)( pow(2.0,count+0.0) +1e-7 );
	int ret=9999;
	
	for(long i=0;i<comb;i++){

		VI cwins(wins);

		bitset<25>seq(i);
		int pos=0;

		FOR(r,0,table.size())
			FOR(c,0,table[r].size()){
				if(table[r][c]=='?'){
					if(seq[pos])
						++cwins[r];
					else
						++cwins[c];
					++pos;
				}
			}

		SORT(cwins);
		ret=min(ret,cwins[cwins.size()-1]);
	}
	return ret;
}

double test0() {
	string t0[] = {"X?", "?X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"XW", "LX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"XWL", "?XW", "WLX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"XW?", "LX?", "??X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!;
