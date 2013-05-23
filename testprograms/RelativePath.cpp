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

class RelativePath {
public:
	string makeRelative(string, string);
};

string RelativePath::makeRelative(string path, string currentDir) {
	string ret="",tmp="";
	
	if( currentDir=="/" ){
		tmp=tmp+ path.substr(1,path.size()-1);
		return tmp;
	}
	currentDir.erase(0,1),path.erase(0,1);
	currentDir+="/",path+="/";
	VS pat,cur;

	FOR(p,0,path.size()){
		if(path[p]=='/'){
			PB(pat,tmp);
			tmp="";
		} else
			tmp=tmp+path[p];
	}
	tmp="";
	FOR(c,0,currentDir.size()){
		if(currentDir[c]=='/'){
			PB(cur,tmp);
			tmp="";
		} else
			tmp=tmp+currentDir[c];
	}
	int pos;
	bool cond=false;
	FOR(i,0,cur.size()){
		if( cur[i]!=pat[i] ){
			pos=i;
			cond=true;
			FOR(j,i,cur.size()){
				ret=ret+"../";
				++i;
			}
		}
	}
	if(!cond)
		pos=cur.size();
		
	FOR(i,pos,pat.size())
		ret=ret+pat[i]+"/";
		
	ret.erase( ret.size()-1,1 );
	return ret;
}
	

double test0() {
	string p0 = "/home/top/data/file";
	string p1 = "/home/user/pictures";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "../../top/data/file";
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
	string p0 = "/home/user/movies/title";
	string p1 = "/home/user/pictures";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "../movies/title";
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
	string p0 = "/file";
	string p1 = "/";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "file";
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
	string p0 = "/a/b/a/b/a/b";
	string p1 = "/a/b/a/a/b/a/b";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "../../../../b/a/b";
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
	string p0 = "/root/root/root";
	string p1 = "/root";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "root/root";
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

//Powered by [KawigiEdit] 2.0!
