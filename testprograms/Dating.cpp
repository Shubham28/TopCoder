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

class Dating {
public:
	string dates(string, int);
};

string Dating::dates(string circle, int k) {

	int male=0,female=0;
	string ret="";
	
	FOR(i,0,circle.size()){
		if( (int)circle[i]<97 )
			++male;
		else
			++female;
	}

	int least=min(male,female);	
	int pos1=-1,pos2;
	
	VB rem( circle.size() );
	
	while(least>0){
		int cond,check,times=0;
		
		while(times<k){
			++pos1;
			if(pos1==circle.size())
				pos1=0;
			if(!rem[pos1])
				++times;
		}
		cond=(circle[pos1]>=97)?1:-1;
		bool ch=false;

		FOR(i,0,circle.size()){
			check=(circle[i]>=97)?1:-1;
			
			if( check*cond==-1 && !rem[i] ){
				if(!ch){
					pos2=i;
					ch=true;
				}
				pos2=(circle[i]<circle[pos2])?i:pos2;
			}
		}
		rem[pos1]=true,rem[pos2]=true;
		PB( ret,circle[pos1] );
		PB( ret,circle[pos2] );
		PB( ret,' ');
		--least;
	}
	return ( ( min(male,female)==0 )?ret:( ret.erase( ret.size()-1,1 ) ) );
}	

double test0() {
	string p0 = "abXCd";
	int p1 = 2;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "bC dX";
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
	string p0 = "abXCd";
	int p1 = 8;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Xa dC";
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
	string p0 = "HGFhgfz";
	int p1 = 1;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Hf Gg Fh";
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
