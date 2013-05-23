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

class Inventory {
public:
	int monthlyOrder(vector <int>, vector <int>);
};

int Inventory::monthlyOrder(vector <int> sales, vector <int> daysAvailable) {

	double sum=0,ave,count=0;
	
	FOR(i,0,sales.size()){
		if(daysAvailable[i]!=0){
			sum=sum + ( ( (double)sales[i] / (double)daysAvailable[i] )*30 );
			++count;
		}
	}
	
	ave=sum/count;
	ave=ave-(1e-9);
	if( ave!=(int)ave ){	
		return (ave+1);	}
	else
		return ave;
		
}


double test0() {
	int t0[] = {5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Inventory * obj = new Inventory();
	clock_t start = clock();
	int my_answer = obj->monthlyOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	int t0[] = {75,120,0,93};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {24,30,0,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Inventory * obj = new Inventory();
	clock_t start = clock();
	int my_answer = obj->monthlyOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 103;
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
	int t0[] = {8773};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {16};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Inventory * obj = new Inventory();
	clock_t start = clock();
	int my_answer = obj->monthlyOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 16450;
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
	int t0[] = {1115,7264,3206,6868,7301}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,3,9,4,18};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Inventory * obj = new Inventory();
	clock_t start = clock();
	int my_answer = obj->monthlyOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 36091;
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

//Powered by [KawigiEdit] 2.0!
