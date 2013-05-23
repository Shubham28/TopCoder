#include <vector>
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

class SpiralWalking {
public:
	int totalPoints(vector <string>);
};

int SpiralWalking::totalPoints(vector <string> levelMap) {

	int r[4],c[4],x=0,y=0,count=0;
	r[0]=0,r[1]=1,r[2]=0,r[3]=-1;
	c[0]=1,c[1]=0,c[2]=-1,c[3]=0;
	long sum=0;

	while(true){
		if( x+r[count]==-1 || x+r[count]==levelMap.size() || y+c[count]==-1 || y+c[count]==levelMap[0].size() || levelMap[x+r[count]][y+c[count]]=='.' ){
			++count,count%=4;
			if( 0<=(x+r[count]) && (x+r[count])<levelMap.size() && 0<=(y+c[count]) && (y+c[count])<levelMap[0].size() && levelMap[x+r[count]][y+c[count]]=='.' )
				return ( sum+(levelMap[x][y]-48) );
				
			levelMap[x][y]=-1,x+=r[count],y+=c[count];
		} else{
			sum+=( levelMap[x][y]-48 );
			levelMap[x][y]='.',x+=r[count],y+=c[count];
		}
	}
	return sum;	
}

double test0() {
	string t0[] = {"111",
 "111",
 "111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SpiralWalking * obj = new SpiralWalking();
	clock_t start = clock();
	int my_answer = obj->totalPoints(p0);
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
double test1() {
	string t0[] = {"101",
 "110"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SpiralWalking * obj = new SpiralWalking();
	clock_t start = clock();
	int my_answer = obj->totalPoints(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"00",
 "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SpiralWalking * obj = new SpiralWalking();
	clock_t start = clock();
	int my_answer = obj->totalPoints(p0);
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
	string t0[] = {"86850",
 "76439",
 "15863",
 "24568",
 "45679",
 "71452",
 "05483"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SpiralWalking * obj = new SpiralWalking();
	clock_t start = clock();
	int my_answer = obj->totalPoints(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 142;
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
