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
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>

using namespace std;

class CubeWalking {
public:
	string finalPosition(string);
};

string CubeWalking::finalPosition(string movement) {
	VS ar;
	PB( ar,"RBR" );
	PB( ar,"BGB" );
	PB( ar,"RBR" );
		
	int posx=1,posy=1;
	int movx=-1,movy=0;
	int count=40;
	
	FOR( i,0,movement.size() ){
		if( movement[i]=='L' )
			++count;
		else if( movement[i]=='R' )
			--count;
	
		if( count%4==1 )
			movx=0,movy=-1;
		else if( count%4==2 )
			movx=1,movy=0;
		else if( count%4==3 )
			movx=0,movy=1;
		else if( count%4==0 )
			movx=-1,movy=0;
 
		if( movement[i]=='W' ){
			posx+=movx,posy+=movy;
			if( posx==-1 )
				posx=2;
			if( posy==-1 )
				posy=2;
			if( posx==3 )
				posx=0;
			if( posy==3 )
				posy=0;
		}
	}
	if( ar[posx][posy]=='R' )
		return "RED";
	else if( ar[posx][posy]=='B' )
		return "BLUE";
	else if( ar[posx][posy]=='G' )
		return "GREEN";
	
}

double test0() {
	string p0 = "LLRR";
	CubeWalking * obj = new CubeWalking();
	clock_t start = clock();
	string my_answer = obj->finalPosition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "GREEN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "WWWWWWWWWWWW";
	CubeWalking * obj = new CubeWalking();
	clock_t start = clock();
	string my_answer = obj->finalPosition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "GREEN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "WLWRW";
	CubeWalking * obj = new CubeWalking();
	clock_t start = clock();
	string my_answer = obj->finalPosition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "RED";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "WWLLWRWLWLLRWW";
	CubeWalking * obj = new CubeWalking();
	clock_t start = clock();
	string my_answer = obj->finalPosition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "BLUE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
