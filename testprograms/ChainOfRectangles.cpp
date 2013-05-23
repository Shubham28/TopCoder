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

class ChainOfRectangles {
public:
	int getMaximalArea(vector <int>, vector <int>, string);
};

int ChainOfRectangles::getMaximalArea(vector <int> width, vector <int> height, string color) {
	vector<int>are(3,0);
	
	FOR( i,0,color.size()-1 ){
		if(color[i]=='R')
			are[0]=are[0]+(width[i]*height[i])-(width[i+1]*height[i+1]);
		else if(color[i]=='G')
			are[1]=are[1]+(width[i]*height[i])-(width[i+1]*height[i+1]);
		else if(color[i]=='B')
			are[2]=are[2]+(width[i]*height[i])-(width[i+1]*height[i+1]);
	}
	if( color[ color.size()-1 ]=='R' )
		are[0]=are[0]+ width[ color.size()-1 ]*height[ color.size()-1 ];
	else if( color[ color.size()-1 ]=='G' )
		are[1]=are[1]+ width[ color.size()-1 ]*height[ color.size()-1 ];
	else if( color[ color.size()-1 ]=='B' )
		are[2]=are[2]+ width[ color.size()-1 ]*height[ color.size()-1 ];
		
	sort( are.begin(),are.end() );
	return are[2];
}


double test0() {
	int t0[] = {10000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "R";
	ChainOfRectangles * obj = new ChainOfRectangles();
	clock_t start = clock();
	int my_answer = obj->getMaximalArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 100000000;
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
	int t0[] = {10, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "GB";
	ChainOfRectangles * obj = new ChainOfRectangles();
	clock_t start = clock();
	int my_answer = obj->getMaximalArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 75;
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
	int t0[] = {10, 9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {8, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "GB";
	ChainOfRectangles * obj = new ChainOfRectangles();
	clock_t start = clock();
	int my_answer = obj->getMaximalArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 63;
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
	int t0[] = {10, 8, 6, 4, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9, 7, 5, 3, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "GBRRG";
	ChainOfRectangles * obj = new ChainOfRectangles();
	clock_t start = clock();
	int my_answer = obj->getMaximalArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 36;
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
