#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

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

class MazeMaker {
public:
	int longestPath(vector <string>, int, int, vector <int>, vector <int>);
	
	void placing(VS &maze,vector< VI >&dist,VI &mRow,VI &mCol,int pos) {
		
		bool ch=false;
		FOR(r,0,maze.size())
			FOR(c,0,maze[r].size()){
				if(dist[r][c]==pos){
					
					FOR(i,0,mRow.size()){
						if(r+mRow[i]>=0 && r+mRow[i]<maze.size() && c+mCol[i]>=0 && c+mCol[i]<maze[r].size() && maze[r+mRow[i]][c+mCol[i]]=='.')
							maze[r+mRow[i]][c+mCol[i]]='X',dist[r+mRow[i]][c+mCol[i]]=pos+1,ch=true;	
					}
				}
			}
			
		if(ch)
			placing(maze,dist,mRow,mCol,pos+1);
			
		return ;
	}
};

int MazeMaker::longestPath(vector <string> maze, int sR, int sC, vector <int> mRow, vector <int> mCol) {

	int pos=0,ret=0;
	VI tmp(maze[0].size(),-1);
	vector< VI >dist(maze.size(),tmp);
	dist[sR][sC]=0,maze[sR][sC]='X';
	
	placing(maze,dist,mRow,mCol,pos);
	
	FOR(r,0,maze.size())
		FOR(c,0,maze[r].size())
			if(maze[r][c]=='.')
				return -1;
			else
				ret=max(ret,dist[r][c]);
				
	return ret;
}

double test0() {
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int t3[] = {1,0,-1,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0,1,0,-1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
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
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int t3[] = {1, 0, -1, 0, 1, 1, -1, -1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, 1, 0, -1, 1, -1, 1, -1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 2;
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
	string t0[] = {"X.X",
 "...",
 "XXX",
 "X.X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int t3[] = {1, 0, -1, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, 1, 0, -1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
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
	string t0[] = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 5;
	int p2 = 0;
	int t3[] = {1, 0, -1, 0,-2, 1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, -1, 0, 1, 3, 0};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 7;
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
	string t0[] = {"......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 0;
	int t3[] = {1, 0, 1, 0, 1, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, 1, 0, 1, 0, 1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 6;
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
double test5() {
	string t0[] = {"..X.X.X.X.X.X."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 0;
	int t3[] = {2,0,-2,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0,2,0,-2};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
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
