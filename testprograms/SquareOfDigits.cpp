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

class SquareOfDigits {
public:
	int getMax(vector <string>);
};

int SquareOfDigits::getMax(vector <string> data) {

	for(int si=min( data.size(),data[0].size() )-1 ;si>=0;si--){
		
		EFOR( rpos,0,data.size()-si-1 ){
			EFOR( cpos,0,data[0].size()-si-1 ){		cout<<si<<"  "<<rpos<<"  "<<cpos<<endl;
				if( data[rpos][cpos]==data[rpos][cpos+si] && data[rpos][cpos]==data[rpos+si][cpos] && data[rpos][cpos]==data[rpos+si][cpos+si] )
					return (si+1)*(si+1);
			}
		}
	}
	
}


double test0() {
	string t0[] = {"12",
 "34"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SquareOfDigits * obj = new SquareOfDigits();
	clock_t start = clock();
	int my_answer = obj->getMax(p0);
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
	string t0[] = {"1255",
 "3455"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SquareOfDigits * obj = new SquareOfDigits();
	clock_t start = clock();
	int my_answer = obj->getMax(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"42101",
 "22100",
 "22101"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SquareOfDigits * obj = new SquareOfDigits();
	clock_t start = clock();
	int my_answer = obj->getMax(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 9;
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
	string t0[] = {"1234567890"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SquareOfDigits * obj = new SquareOfDigits();
	clock_t start = clock();
	int my_answer = obj->getMax(p0);
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
double test4() {
	string t0[] = {"9785409507",
 "2055103694",
 "0861396761",
 "3073207669",
 "1233049493",
 "2300248968",
 "9769239548",
 "7984130001",
 "1670020095",
 "8894239889",
 "4053971072"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SquareOfDigits * obj = new SquareOfDigits();
	clock_t start = clock();
	int my_answer = obj->getMax(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 49;
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
