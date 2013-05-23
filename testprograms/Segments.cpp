#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Segments {
public:
	string intersection(vector <int>, vector <int>);
};

string Segments::intersection(vector <int> s1, vector <int> s2) {

	int touch=0;
	if( s1[0]==s1[2] ){
		for(int i=min(s1[1],s1[3]);i<=max(s1[1],s1[3]);i++){
		
			if( s2[0]==s2[2] ){
				for(int j=min(s2[1],s2[3]);j<=max(s2[1],s2[3]);j++){
					if( s1[0]==s2[0] && i==j )
						++touch;
				}
			} else {
				for(int j=min(s2[0],s2[2]);j<=max(s2[0],s2[2]);j++){
					if( s1[0]==j && i==s2[1] )
						++touch;
				}
			}
		}
	} else { 
		for(int i=min(s1[0],s1[2]);i<=max(s1[0],s1[2]);i++){
		
			if( s2[0]==s2[2] ){
				for(int j=min(s2[1],s2[3]);j<=max(s2[1],s2[3]);j++){
					if( i==s2[0] && s1[1]==j )
						++touch;
				}
			} else {
				for(int j=min(s2[0],s2[2]);j<=max(s2[0],s2[2]);j++){
					if( i==j && s1[1]==s2[1] )
						++touch;
				}
			}
		}
	}
	
	if(touch==0)
		return "NO";
	else if(touch==1)
		return "POINT";
	else
		return "SEGMENT";
		
}


double test0() {
	int t0[] = {0, 0, 0, 1}	;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 0, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Segments * obj = new Segments();
	clock_t start = clock();
	string my_answer = obj->intersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, 0, 0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 1, 0, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Segments * obj = new Segments();
	clock_t start = clock();
	string my_answer = obj->intersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "POINT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, -1, 0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1, 0, 1, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Segments * obj = new Segments();
	clock_t start = clock();
	string my_answer = obj->intersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "POINT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, 0, 2, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 0, 10, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Segments * obj = new Segments();
	clock_t start = clock();
	string my_answer = obj->intersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "SEGMENT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {5, 5, 5, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6, 6, 6, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Segments * obj = new Segments();
	clock_t start = clock();
	string my_answer = obj->intersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {10, 0, -10, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5, 0, -5, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Segments * obj = new Segments();
	clock_t start = clock();
	string my_answer = obj->intersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "SEGMENT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
