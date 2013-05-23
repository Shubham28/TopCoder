#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define P_B(A,B) A.push_back(B);

using namespace std;

class GrabbingTaxi {
public:
	int minTime(vector <int>, vector <int>, int, int, int, int);
};

int GrabbingTaxi::minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime) {

	vector<long>taxit( tXs.size(),LONG_MAX );
	long walkt=( abs(gX) + abs(gY) )*walkTime;

	FOR(i,0,tXs.size() )
		taxit[i]=( abs(tXs[i]) + abs(tYs[i]) )*walkTime + ( abs(tXs[i]-gX) + abs(tYs[i]-gY) )*taxiTime;
		
	sort( taxit.begin(),taxit.end() );
	
	if( tXs.size()>0 )
		return ( min(walkt,taxit[0]) );
	else 
		return walkt;
}


double test0() {
	vector <int> p0;
	vector <int> p1;
	int p2 = 3;
	int p3 = 2;
	int p4 = 10;
	int p5 = 2;
	GrabbingTaxi * obj = new GrabbingTaxi();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 50;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {-2, -2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, -2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = -4;
	int p3 = -2;
	int p4 = 15;
	int p5 = 3;
	GrabbingTaxi * obj = new GrabbingTaxi();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 42;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	int p3 = 0;
	int p4 = 10;
	int p5 = 20;
	GrabbingTaxi * obj = new GrabbingTaxi();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 50;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {34, -12, 1, 0, 21, -43, -98, 11, 86, -31};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {11, 5, -68, 69, -78, -49, -36, -2, 1, 70};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = -97;
	int p3 = -39;
	int p4 = 47;
	int p5 = 13;
	GrabbingTaxi * obj = new GrabbingTaxi();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 2476;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {82, -60, 57, 98, 30, -67, 84, -42, -100, 62};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-7, 90, 53, -56, -15, -87, 22, -3, -61, -30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 21;
	int p3 = 15;
	int p4 = 53;
	int p5 = 2;
	GrabbingTaxi * obj = new GrabbingTaxi();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 1908;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
