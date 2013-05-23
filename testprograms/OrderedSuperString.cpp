#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define ALL(A) A.begin(),A.end()

using namespace std;

class OrderedSuperString {
public:
	int getLength(vector <string>);
};

int OrderedSuperString::getLength(vector <string> words) {
	string ret=words[0];
	int pos=0;
	
	FOR(r,1,words.size()){
	
		bool cond=false;
		FOR(i,pos,ret.size()){
			if( ret.substr(i, min(ret.size()-i,words[r].size() ) ) == words[r].substr(0, min(ret.size()-i,words[r].size()) ) ){
				pos=i;
				ret+= words[r].substr( min(ret.size()-i,words[r].size()), words[r].size()-min(ret.size()-i,words[r].size()) );
				cond=true;
				break;
			}
		}
		if(!cond){
			ret+=words[r],pos=ret.size()-1;
		}
	}
	return ret.size();
}
double test0() {
	string t0[] = {"abc","ca"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
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
double test1() {
	string t0[] = {"a","a","b","a"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
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
	string t0[] = {"abcdef", "ab","bc", "de","ef"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	string t0[] = {"ab","bc", "de","ef","abcdef"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
