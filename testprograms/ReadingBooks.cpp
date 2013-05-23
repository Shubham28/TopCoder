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

class ReadingBooks {
public:
	int countBooks(vector <string>);
};

int ReadingBooks::countBooks(vector <string> readParts) {
	long count=0;
	
	FOR(i,0,readParts.size()-2){
	
		bool in=false,st=false,ed=false;
		FOR(j,i,i+3){
	
			if( readParts[j]=="introduction" )
				in=true;
			else if( readParts[j]=="edification" )
				st=true;
			else if( readParts[j]=="story" )
				ed=true;
		}
		if(in && st && ed ){
			++count;
			i=i+2;
		}
	}
	return count;
}


double test0() {
	string t0[] = {"introduction", "story", "introduction", "edification"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ReadingBooks * obj = new ReadingBooks();
	clock_t start = clock();
	int my_answer = obj->countBooks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"introduction", "story", "edification", "introduction", "story", "edification"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ReadingBooks * obj = new ReadingBooks();
	clock_t start = clock();
	int my_answer = obj->countBooks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"introduction", "story", "introduction", "edification", "story", "introduction"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ReadingBooks * obj = new ReadingBooks();
	clock_t start = clock();
	int my_answer = obj->countBooks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"introduction", "story", "introduction", "edification", "story",
 "story", "edification", "edification", "edification", "introduction",
 "introduction", "edification", "story", "introduction", "story",
 "edification", "edification", "story", "introduction", "edification",
 "story", "story", "edification", "introduction", "story"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ReadingBooks * obj = new ReadingBooks();
	clock_t start = clock();
	int my_answer = obj->countBooks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
