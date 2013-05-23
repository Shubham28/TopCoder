#include <vector>
#include <list>
#include <map>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bitset>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );

using namespace std;

class ArithmeticProgression {
public:
	double minCommonDifference(int, vector <int>);
};

double ArithmeticProgression::minCommonDifference(int a0, vector <int> seq) {
	if( seq.size()==0 )
		return 0;
	if(seq[0]<a0)
		return -1;
	
	long double dif=seq[0]-a0;
	long double midec=0,madec=1;
	
	FOR(i,1, seq.size() ){
		if(seq[i]<seq[i-1])
			return -1;
		
		long double mi=max( midec, (seq[i]- (a0 + dif*(i+1) ) )/(i+1) );
		long double ma=min( madec, (seq[i]+1- (a0 + dif*(i+1) ) )/(i+1) );
		
		if(mi>=ma || ma<mi)
			return -1;
		
		midec=mi,madec=ma;
		
	}
	if(midec>=1)
		return -1;
	else
		return (dif+midec);	
}


double test0() {
	int p0 = 0;
	int t1[] = {6, 13, 20, 27};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ArithmeticProgression * obj = new ArithmeticProgression();
	clock_t start = clock();
	double my_answer = obj->minCommonDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 6.75;
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
	int p0 = 1;
	int t1[] = {2, 3, 4, 5, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ArithmeticProgression * obj = new ArithmeticProgression();
	clock_t start = clock();
	double my_answer = obj->minCommonDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
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
	int p0 = 3;
	vector <int> p1;
	ArithmeticProgression * obj = new ArithmeticProgression();
	clock_t start = clock();
	double my_answer = obj->minCommonDifference(p0, p1);
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
double test3() {
	int p0 = 3;
	int t1[] = {3, 3, 3, 3, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ArithmeticProgression * obj = new ArithmeticProgression();
	clock_t start = clock();
	double my_answer = obj->minCommonDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.2;
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
double test4() {
	int p0 = 1;
	int t1[] = {-3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ArithmeticProgression * obj = new ArithmeticProgression();
	clock_t start = clock();
	double my_answer = obj->minCommonDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = -1.0;
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
double test5() {
	int p0 = 0;
	int t1[] = {6, 14};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ArithmeticProgression * obj = new ArithmeticProgression();
	clock_t start = clock();
	double my_answer = obj->minCommonDifference(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = -1.0;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
