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

class Undo {
public:
	string getText(vector <string>, vector <int>);
};

string Undo::getText(vector <string> commands, vector <int> times) {

	VB cmd(commands.size());
	VB incl(commands.size(),true);
	
	vector<char>steps(commands.size());
	
	FOR(i,0,commands.size()){
		if( commands[i].substr(0,4)=="type" )
			cmd[i]=true;
		else
			cmd[i]=false,incl[i]=false;
			
		steps[i]=commands[i][5];
	}

	
	for(int i=commands.size()-1;i>=0;i--){
		if(!cmd[i]){
		
			int pre=atoi( commands[i].substr(5,commands[i].size()-5).c_str() );
			int k=i-1;
			while(k>=0){
				if( (times[i]-times[k])<=pre ){
					incl[k]=false,cmd[k]=true;
					--k;
				} else
					break;
			}
		}
	}
	
	string ret;
	FOR(i,0,commands.size())
		if(incl[i])
			PB(ret,steps[i]);
	
	return ret;			
}

double test0() {
	string t0[] = {"type a", "type b", "type c", "undo 3"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1, 2, 3, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Undo * obj = new Undo();
	clock_t start = clock();
	string my_answer = obj->getText(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "a";
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
	string t0[] = {"type a", "type b", "undo 2", "undo 2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1,2,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Undo * obj = new Undo();
	clock_t start = clock();
	string my_answer = obj->getText(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "a";
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
	string t0[] = {"type a", "undo 1", "undo 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Undo * obj = new Undo();
	clock_t start = clock();
	string my_answer = obj->getText(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "a";
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
double test3() {
	string t0[] = {"type a", "type b", "type c", "undo 10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1, 2, 3, 1000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Undo * obj = new Undo();
	clock_t start = clock();
	string my_answer = obj->getText(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "abc";
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
double test4() {
	string t0[] = {"undo 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Undo * obj = new Undo();
	clock_t start = clock();
	string my_answer = obj->getText(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
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
