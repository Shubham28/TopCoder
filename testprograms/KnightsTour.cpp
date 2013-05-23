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

class KnightsTour {
public:
	int visitedPositions(vector <string>);
	long access( VS &board ,int &row, int &col , VI &newr, VI &newc ){
	
		newr.clear(),newc.clear();
		if(row-2>=0 && col-1>=0 && board[row-2][col-1]!='*'){
				PB(newr,row-2);
				PB(newc,col-1);
			}
		if(row-2>=0 && col+1<board[0].size() && board[row-2][col+1]!='*'){
			PB(newr,row-2);
			PB(newc,col+1);
			}
		if(row-1>=0 && col-2>=0  && board[row-1][col-2]!='*'){
			PB(newr,row-1);
			PB(newc,col-2);
			}
		if(row-1>=0 && col+2<board[0].size() && board[row-1][col+2]!='*'){
			PB(newr,row-1);
			PB(newc,col+2);
			}
		if(row+1<board.size() && col-2>=0 && board[row+1][col-2]!='*'){
			PB(newr,row+1);
			PB(newc,col-2);
			}
		if(row+1<board.size() && col+2<board[0].size() && board[row+1][col+2]!='*'){
			PB(newr,row+1);
			PB(newc,col+2);
			}
		if(row+2<board.size() && col-1>=0 && board[row+2][col-1]!='*'){
			PB(newr,row+2);
			PB(newc,col-1);
			}
		if(row+2<board.size() && col+1<board[0].size() && board[row+2][col+1]!='*'){
			PB(newr,row+2);
			PB(newc,col+1);
			}
		return ( newr.size() );
	}
};

int KnightsTour::visitedPositions(vector <string> board) {
	int ro,co;
	long count=1;
	
	FOR(r,0,board.size())
		FOR(c,0,board[r].size())
			if(board[r][c]=='K'){
				ro=r,co=c;
				break;
			}
			
	VI newr,newc;
	while( access(board,ro,co,newr,newc)>0 ){
		board[ro][co]='*';
		
		int min=64;
		FOR(i,0,newr.size()){
			
			VI cnewr,cnewc;
			long numb=access(board,newr[i],newc[i],cnewr,cnewc);
			
			if( min>numb )
				ro=newr[i],co=newc[i],min=numb;
			else if( min==numb ){
				if(ro>newr[i])
					ro=newr[i],co=newc[i];
				else if(ro==newr[i]){
					if(co>newc[i])
						co=newc[i];
				}
			}
		}
		board[ro][co]='*';
		++count;
	}
	return count;
}

double test0() {
	string t0[] = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightsTour * obj = new KnightsTour();
	clock_t start = clock();
	int my_answer = obj->visitedPositions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 39;
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
	string t0[] = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightsTour * obj = new KnightsTour();
	clock_t start = clock();
	int my_answer = obj->visitedPositions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 64;
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
	string t0[] = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightsTour * obj = new KnightsTour();
	clock_t start = clock();
	int my_answer = obj->visitedPositions(p0);
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
double test3() {
	string t0[] = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightsTour * obj = new KnightsTour();
	clock_t start = clock();
	int my_answer = obj->visitedPositions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 17;
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
double test4() {
	string t0[] = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	KnightsTour * obj = new KnightsTour();
	clock_t start = clock();
	int my_answer = obj->visitedPositions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 27;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	system("pause");
}

//Powered by [KawigiEdit] 2.0!
