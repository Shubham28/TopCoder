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

class SentenceDecomposition {
public:
	int decompose(string, vector <string>);
};

int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {

	vector< VI >cost(sentence.size(),VI(sentence.size(),999));

	EFOR(len,1,sentence.size()){
		EFOR(pos,0,sentence.size()-len){

			string subst=sentence.substr(pos,len),csub=subst;
			SORT(csub);
			FOR(c,0,validWords.size()){
				string dup=validWords[c];
				SORT(dup);
				if(dup==csub){
					int cst=0;
					FOR(match,0,validWords[c].size())
						if(validWords[c][match]!=subst[match])
							++cst;
					cost[pos][pos+len-1]=min(cost[pos][pos+len-1],cst);
				}
			}

			FOR(k,0,len-1){
				int brk=cost[pos][pos+k]+cost[pos+k+1][pos+len-1];
				cost[pos][pos+len-1]=min(cost[pos][pos+len-1],brk);
			}
		}
	}
	if(cost[0][sentence.size()-1]<100)
		return cost[0][sentence.size()-1];
	else
		return -1;

}

double test0() {
	string p0 = "neotowheret";
	string t1[] = {"one", "two", "three", "there"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	string p0 = "abba";
	string t1[] = {"ab", "ac", "ad"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string p0 = "thisismeaningless";
	string t1[] = {"this", "is", "meaningful"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string p0 = "ommwreehisymkiml";
	string t1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	string p0 = "ogodtsneeencs";
	string t1[] = {"go", "good", "do", "sentences", "tense", "scen"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	string p0 = "sepawaterords";
	string t1[] = {"separate","words"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	
	time = (int)test0();
	if (time < 0)
		errors = true;
	
	time = (int)test1();
	if (time < 0)
		errors = true;
	
	time = (int)test2();
	if (time < 0)
		errors = true;
	
	time = (int)test3();
	if (time < 0)
		errors = true;
	
	time = (int)test4();
	if (time < 0)
		errors = true;
	
	time = (int)test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!; 
