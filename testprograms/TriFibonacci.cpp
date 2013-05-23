#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

class TriFibonacci {
public:
	int complete(vector <int>);
};

int TriFibonacci::complete(vector <int> A) {
	long ret;
	if(A[0]==-1){
		A[0]=A[3]-A[2]-A[1];
		ret=A[0];
	} else if(A[1]==-1){
		A[1]=A[3]-A[2]-A[0];
		ret=A[1];
	} else if(A[2]==-1){
		A[2]=A[3]-A[1]-A[0];
		ret=A[2];
	}

	FOR(i,3,A.size()){
		if(A[i]==-1){
			A[i]=A[i-1]+A[i-2]+A[i-3];
			ret=A[i];
		}
	}
	
	bool cond=true;
	FOR(i,3,A.size()){
		if(A[i]!=(A[i-1]+A[i-2]+A[i-3])){
			cond=false;
			return -1;
		}
	}
	if(ret>0)
		return ret;
	else 
		return -1;	
}

double test0() {
	int t0[] = {1,2,3,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TriFibonacci * obj = new TriFibonacci();
	clock_t start = clock();
	int my_answer = obj->complete(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	int t0[] = {10, 20, 30, 60, -1 , 200};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TriFibonacci * obj = new TriFibonacci();
	clock_t start = clock();
	int my_answer = obj->complete(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 110;
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
	int t0[] = {1, 2, 3, 5, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TriFibonacci * obj = new TriFibonacci();
	clock_t start = clock();
	int my_answer = obj->complete(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	int t0[] = {1, 1, -1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TriFibonacci * obj = new TriFibonacci();
	clock_t start = clock();
	int my_answer = obj->complete(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test4() {
	int t0[] = {-1, 7, 8, 1000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TriFibonacci * obj = new TriFibonacci();
	clock_t start = clock();
	int my_answer = obj->complete(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 999985;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
