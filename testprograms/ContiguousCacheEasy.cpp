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

class ContiguousCacheEasy {
public:
	int bytesRead(int, int, vector <int>);
};

int ContiguousCacheEasy::bytesRead(int n, int k, vector <int> addresses) {
	int mi=0,ma=k-1;
	VB ch(n);
	FOR(c,0,k)
		ch[c]=true;

	long count=0;
		
	FOR(i,0,addresses.size()){
		if(mi>addresses[i]){
			ma=ma-(mi-addresses[i]);
			mi=addresses[i];
		} else if(ma<addresses[i]){
			mi=mi+(addresses[i]-ma);
			ma=addresses[i];
		}
		VB tmp(n);
		EFOR(c,mi,ma)
			tmp[c]=true;
			
		FOR(c,0,n)
			if(tmp[c] && !ch[c])
				++count;
		
		FOR(c,0,n)
			ch[c]=tmp[c];
	}
	return count;
}

double test0() {
	int p0 = 100;
	int p1 = 5;
	int t2[] = {6, 0, 3, 20, 22, 16};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCacheEasy * obj = new ContiguousCacheEasy();
	clock_t start = clock();
	int my_answer = obj->bytesRead(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 13;
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
	int p0 = 100;
	int p1 = 1;
	int t2[] = {0, 4, 6, 6, 4, 10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCacheEasy * obj = new ContiguousCacheEasy();
	clock_t start = clock();
	int my_answer = obj->bytesRead(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 1000;
	int p1 = 999;
	int t2[] = {0, 4, 123, 987, 999, 500, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCacheEasy * obj = new ContiguousCacheEasy();
	clock_t start = clock();
	int my_answer = obj->bytesRead(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
