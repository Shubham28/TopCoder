#include <vector>
#include <map>
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
#define LL long long

using namespace std;

class WordsGame {
public:
	int minimumSwaps(vector <string>, string);

	int swapping(string &final,string &pos) {
		
		int swaps=0;
		FOR(c,0,final.size()){
		
			if(pos[c]!=final[c]){
				FOR(sw,c+1,final.size())
					if(pos[sw]==final[c]){
						char tmp=pos[c];
						pos[c]=pos[sw],pos[sw]=tmp;
					}
				++swaps;
			}
		}
		return swaps;
	}

};

int WordsGame::minimumSwaps(vector <string> grid, string word) {
	int count=INT_MAX;
	
	FOR(r,0,grid.size()){
		string copy=grid[r],wcopy=word;
		
		SORT(copy);
		SORT(wcopy);
		if(copy==wcopy){
			string pos=grid[r];
			count=min(count,swapping(word,pos));
		}
	}
	
	FOR(c,0,grid.size()){
		
		string copy="",wcopy=word;
		FOR(r,0,word.size())
			copy+=grid[r][c];
		
		SORT(copy);
		SORT(wcopy);

		if(copy==wcopy){
			string pos="";
			FOR(cop,0,word.size())
				pos+=grid[cop][c];
				
			count=min(count,swapping(word,pos));
		}
	}
	if(count==INT_MAX)
		return -1;
	return count;
}

double test0() {
	string t0[] = {"Mu",
 "uM"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "Mu";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
double test1() {
	string t0[] = {"sdf",
 "bca",
 "hgf"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "abc";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
	string t0[] = {"cdf",
 "bca",
 "agf"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "abc";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
double test3() {
	string t0[] = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "bkHg";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
double test4() {
	string t0[] = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "oDmWcJHGNk";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	string t0[] = {"ab",
 "bA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "aB";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!; 
