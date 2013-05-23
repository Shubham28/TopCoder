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

class Desertification {
public:
	int desertArea(vector <string>, int);
	
	void desert(VS &island, int r, int c) {
		if(r>=1)
			island[r-1][c]='D';
		if(c>=1)
			island[r][c-1]='D';
		if(r<island.size()-1)
			island[r+1][c]='D';
		if(c<island[r].size()-1)
			island[r][c+1]='D';
		return;
	}
};

int Desertification::desertArea(vector <string> island, int T) {
	int count=0;
	VI row,col;
	if(T>=100)
		T=100;
	
	for(long i=1;i<=T;i++){
		row.clear();
		col.clear();
	
		FOR(r,0,island.size())
			FOR(c,0,island.size())
				if(island[r][c]=='D'){
					PB(row,r);
					PB(col,c);
				}

		FOR(j,0,row.size())
			desert(island,row[j],col[j]);
	}
	FOR(r,0,island.size())
		FOR(c,0,island[r].size())
			if(island[r][c]=='D')
				++count;
				
	return count;
}

double test0() {
	string t0[] = {"FFDD"};

	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	Desertification * obj = new Desertification();
	clock_t start = clock();
	int my_answer = obj->desertArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	string t0[] = {"FFF",
 "FDF",
 "FFF"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	Desertification * obj = new Desertification();
	clock_t start = clock();
	int my_answer = obj->desertArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	string t0[] = {"FFFFF",
 "FFDFF",
 "FFFFD",
 "FFFFF",
 "FFFFF"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	Desertification * obj = new Desertification();
	clock_t start = clock();
	int my_answer = obj->desertArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 17;
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
	string t0[] = {"FFFFFF",
 "FFFFFF",
 "FFFFFF",
 "FFFFFF"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000000000;
	Desertification * obj = new Desertification();
	clock_t start = clock();
	int my_answer = obj->desertArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
double test4() {
	string t0[] = {"FFFFFDFFFF",
 "FDFDFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "DDFFFFFFFF", 
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "FFFFFFFDFF",
 "FFFFFFFDFF",
 "FFFFDDFFFF"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	Desertification * obj = new Desertification();
	clock_t start = clock();
	int my_answer = obj->desertArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 90;
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
double test5() {
	string t0[] = {"FFFFFDFFFF",
 "FDFDFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "DDFFFFFFFF", 
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "FFFFFFFDFF",
 "FFFFFFFDFF",
 "FFFFDDFFFF"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 98765432;
	Desertification * obj = new Desertification();
	clock_t start = clock();
	int my_answer = obj->desertArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 100;
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
	
/*	time = test1();
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
		errors = true;*/
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;	system("pause");
}

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!; 
