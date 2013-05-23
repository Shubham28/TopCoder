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

class SilverDistance {
public:
	int minSteps(int, int, int, int);
};

int SilverDistance::minSteps(int sx, int sy, int gx, int gy) {

	gx=gx-sx,sx=0;
	gy=gy-sy,sy=0;

	long steps=0;
	while(gx!=0 || gy!=0){
		if(gx>=1 && gy>=1)
			steps+=1,gx-=1,gy-=1;
		else if(gx<=-1 && gy>=1)
			steps+=1,gx+=1,gy-=1;
		else if(gx>=1 && gy<=-1)
			steps+=1,gx-=1,gy+=1;
		else if(gx<=-1 && gy<=-1)
			steps+=1,gx+=1,gy+=1;
		else if(gx>=2)
			steps+=2,gx-=2;
		else if(gx<=-2)
			steps+=2,gx+=2;
		else if(gx==1)
			steps+=2,gx-=1;
		else if(gx==-1)
			steps+=2,gx+=1;
		else if(gy>=1)
			steps+=1,gy-=1;
		else if(gy<=-2)
			steps+=2,gy+=2;
		else if(gy==-1)
			steps+=3,gy+=1;
	}
	return steps;
}

double test0() {
	int p0 = 1;
	int p1 = 0;
	int p2 = 1;
	int p3 = 9;
	SilverDistance * obj = new SilverDistance();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 9;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 0;
	int p1 = 0;
	int p2 = -4;
	int p3 = 3;
	SilverDistance * obj = new SilverDistance();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 5;
	int p3 = 8;
	SilverDistance * obj = new SilverDistance();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = -487617;
	int p1 = 826524;
	int p2 = 892309;
	int p3 = -918045;
	SilverDistance * obj = new SilverDistance();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1744571;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = -27857;
	int p1 = 31475;
	int p2 = -27857;
	int p3 = 31475;
	SilverDistance * obj = new SilverDistance();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!; 
