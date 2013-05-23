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
#define SORT(A) sort( A.begin(),A.end() );

using namespace std;

class TheNewHouseDivOne {
public:
	double distance(vector <int>, vector <int>, int);
};

double TheNewHouseDivOne::distance(vector <int> x, vector <int> y, int k) {
	
	vector<double>dis;
	double mi=INT_MAX;
	for(double r=-50;r<=50;r=r+.5){
		for(double c=-50;c<=50;c=c+.5){
		
			dis.clear();
			FOR(i,0,x.size() )
				dis.push_back( abs(r-x[i]) + abs(c-y[i]) );

				SORT( dis );				
//				cout<<dis[0]<<" "<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<endl;

				mi=min( mi,dis[k-1] );
		}
	}
	return mi;
}


double test0() {
	int t0[] = {-1, -1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1, 1, -1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	TheNewHouseDivOne * obj = new TheNewHouseDivOne();
	clock_t start = clock();
	double my_answer = obj->distance(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 2.0;
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
	int t0[] = {-1, -1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1, 1, -1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	TheNewHouseDivOne * obj = new TheNewHouseDivOne();
	clock_t start = clock();
	double my_answer = obj->distance(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.0;
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
	int t0[] = {4, 4, 4, 4, 4, 3, 3, 5, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7, 7, 7, 4, 4, 5, 6, 5, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 9;
	TheNewHouseDivOne * obj = new TheNewHouseDivOne();
	clock_t start = clock();
	double my_answer = obj->distance(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.5;
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
double test3() {
	int t0[] = {30, -15, 24, -23, 43, -8, -6, -47, 23, -11, 43, 6, -18, 44, -46, 16, 32, 31, 13, 9, 22, 25, 4, -44, 38, -41, -20, 41, -35, 7, 25, 39, -36, -20, -5, -38, -15, -22, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-45, -7, -33, 31, -8, -33, -20, -14, -50, -48, -31, 35, -24, -31, -11, 41, -41, -11, 46, -1, -5, 5, -39, -26, -40, -9, 16, 38, -30, 34, 46, -17, -27, 33, -38, 28, 46, -16, -46};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 13;
	TheNewHouseDivOne * obj = new TheNewHouseDivOne();
	clock_t start = clock();
	double my_answer = obj->distance(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 32.0;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
