#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
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

class MountainRoad {
public:
	double findDistance(vector <int>, vector <int>);
};

double MountainRoad::findDistance(vector <int> start, vector <int> finish) {
	double mi=1000,ma=-1000;

	FOR(c,0,start.size())
		mi=min(mi,(double)start[c]);

	FOR(c,0,finish.size())
		ma=max(ma,(double)finish[c]);

	return (sqrt(2)*abs(ma-mi));
}

double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MountainRoad * obj = new MountainRoad();
	clock_t start = clock();
	double my_answer = obj->findDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 8.485281374238571;
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
	int t0[] = {0,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,9,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MountainRoad * obj = new MountainRoad();
	clock_t start = clock();
	double my_answer = obj->findDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 12.727922061357857;
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
	int t0[] = {1,4,5,6,-10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {101,102,101,100,99};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MountainRoad * obj = new MountainRoad();
	clock_t start = clock();
	double my_answer = obj->findDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 158.39191898578665;
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
	int t0[] = {-5,-3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-2,-2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MountainRoad * obj = new MountainRoad();
	clock_t start = clock();
	double my_answer = obj->findDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 4.242640687119286;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Author: Shubham Gupta
//Powered by [KawigiEdit] 2.0!; 
