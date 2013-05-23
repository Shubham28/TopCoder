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
#define VB vector<bool>

using namespace std;

class FactoVisors {
public:
	int getNum(vector <int>, vector <int>);

	
	long long pGCD( long long fir,long long sec ){

		if(sec%fir==0)
			return fir;
		else
			return pGCD(sec%fir,fir);
	}

	long long GCD( VI &multiples ) {

		if( multiples.size()==1 )
			return multiples[0];
		else {
			long long fir=multiples[0],sec;

			for(long long i=1;i<multiples.size();i++){
				sec=multiples[i];
				fir=pGCD( min(fir,sec),max(fir,sec) ) ;
			}
			return fir;
		}
	}
	
	long long LCM( VI &numb ) {	

		if( numb.size()==1 )
			return numb[0];
		else {
			long long fir=numb[0],sec;
			
			for(long long i=1;i<numb.size();i++){
				sec=numb[i];
				fir=(fir*sec)/pGCD( min(fir,sec),max(fir,sec) ) ;
			}
			return fir;
		}
	}
};

int FactoVisors::getNum(vector <int> divisors, vector <int> multiples) {
	SORT(divisors);
	SORT(multiples);
	
	FOR(i,1,divisors.size())
		if(divisors[i]==divisors[i-1]){
			divisors.erase( divisors.begin()+i );
			--i;
		}
	
	FOR(i,1,multiples.size())
		if(multiples[i]==multiples[i-1]){
			multiples.erase( multiples.begin()+i );
			--i;
		}
				
	long st=LCM(divisors);
	long end=GCD(multiples);
	long long prod=1,num=end/st;
	
	if(end%st!=0)
		return 0;
	else {
	
		for(long i=2;i*i<=num;i++){
		
			bool cond=false;
			long long count=0;
			while(num%i==0){
				num/=i;
				++count;
				cond=true;
			}
			if(cond)
				prod=prod*(count+1);
		}
		if(num!=1)
			return (prod*2);
		else
			return prod;
	}
}

double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
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
double test1() {
	int t0[] = {6,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {18};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = {6,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {96,180};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
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
double test3() {
	int t0[] = {2,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {256};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	int t0[] = {1000,10000,100000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 25;
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
