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

class PrimeSoccer {
public:
	double getProbability(int, int);
};

double PrimeSoccer::getProbability(int sOfTA, int sOfTB) {
	double skillOfTeamA=(double)sOfTA/100.0,skillOfTeamB=(double)sOfTB/100.0;
	vector< VD >goalsA(19,VD(19,0)),goalsB(19,VD(19,0));

	FOR(c,0,19)
		goalsA[0][c]=1,goalsB[0][c]=1;

	FOR(rnd,0,18){
		EFOR(pos,0,rnd){
			goalsA[rnd+1][pos]=goalsA[rnd+1][pos]+goalsA[rnd][pos]*(1-skillOfTeamA);
			goalsA[rnd+1][pos+1]=goalsA[rnd+1][pos+1]+goalsA[rnd][pos]*skillOfTeamA;
		
			goalsB[rnd+1][pos]=goalsB[rnd+1][pos]+goalsB[rnd][pos]*(1-skillOfTeamB);
			goalsB[rnd+1][pos+1]=goalsB[rnd+1][pos+1]+goalsB[rnd][pos]*skillOfTeamB;
		}
	}

	double PrimeA=0,PrimeB=0;
	FOR(c,0,19)
		if(c==2 || c==3 || c==5 || c==7 || c==11 || c==13 || c==17){
			PrimeA+=goalsA[18][c];
			PrimeB+=goalsB[18][c];
		}

	return PrimeA+PrimeB-PrimeA*PrimeB;
}

double test0() {
	int p0 = 50;
	int p1 = 50;
	PrimeSoccer * obj = new PrimeSoccer();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.5265618908306351;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 100;
	int p1 = 100;
	PrimeSoccer * obj = new PrimeSoccer();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 12;
	int p1 = 89;
	PrimeSoccer * obj = new PrimeSoccer();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.6772047168840167;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
