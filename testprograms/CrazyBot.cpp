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

class CrazyBot {
public:
	double getProbability(int, int, int, int, int);

	double permute(char wrds[14],int count,int n,double ea,double we,double so,double no) {		

		double prob=0,val=1;
		if(n>count){
			for(int i=1;i<=4;i++){
				if(i==1)
					wrds[count]='E';
				else if(i==2)
					wrds[count]='W';
				else if(i==3)
					wrds[count]='S';
				else if(i==4)
					wrds[count]='N';
				prob=prob+ permute(wrds,count+1,n,ea,we,so,no);
			}
		}
		if(n==count){
			int pos[28][28];
			for(int r=0;r<28;r++)
				for(int c=0;c<28;c++)
					pos[r][c]=0;
					
			pos[13][13]=1;
			
			int x=0,y=0;
			for(int i=0;i<n;i++){
			
				if(wrds[i]=='W'){
					--x;
					val=val* (we/100);
				}
				else if(wrds[i]=='E'){
					++x;
					val=val* (ea/100);
				}
				else if(wrds[i]=='S'){
					--y;
					val=val* (so/100);
				}
				else if(wrds[i]=='N'){
					++y;
					val=val* (no/100);
				}
				
				if(pos[13+x][13+y]==1)
					return 0;
				else 
					pos[13+x][13+y]=1;
			}
			return val;
		}
		return prob;
	}
		
};

double CrazyBot::getProbability(int n, int east, int west, int south, int north) {
	char wrds[14];
	return permute(wrds,0,n,east,west,south,north);
};


double test0() {
	int p0 = 1;
	int p1 = 25;
	int p2 = 25;
	int p3 = 25;
	int p4 = 25;
	CrazyBot * obj = new CrazyBot();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 25;
	int p2 = 25;
	int p3 = 25;
	int p4 = 25;
	CrazyBot * obj = new CrazyBot();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 0.75;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 7;
	int p1 = 50;
	int p2 = 0;
	int p3 = 0;
	int p4 = 50;
	CrazyBot * obj = new CrazyBot();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 14;
	int p1 = 50;
	int p2 = 50;
	int p3 = 0;
	int p4 = 0;
	CrazyBot * obj = new CrazyBot();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 1.220703125E-4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 14;
	int p1 = 25;
	int p2 = 25;
	int p3 = 25;
	int p4 = 25;
	CrazyBot * obj = new CrazyBot();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 0.008845493197441101;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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
