#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class MazeWanderingEasy {
public:
	int decisions(vector <string>);
	
	int recur( vector <string>&maze, int row,int col, bool &cond ) {

		int count=0,temp,no=0;
		bool ch=false;
		
		if(maze[row][col]=='*'){
			cond=true;
			return 0;
		}
		
		maze[row][col]='X';
			
		if( (row-1)>=0 )
			if( maze[row-1][col]=='.' || maze[row-1][col]=='*' ){
				temp=recur(maze,row-1,col,ch);
				++no;
				if(ch){
					count=count+ temp;
					cond=true;
				}
			}

		if( (col-1)>=0 )
			if( maze[row][col-1]=='.' || maze[row][col-1]=='*' ){
				ch=false;
				++no;
				temp=recur(maze,row,col-1,ch);
				if(ch){
					count=count+ temp;
					cond=true;
				}
			}

		if( (row+1)<maze.size() )
			if( maze[row+1][col]=='.' || maze[row+1][col]=='*' ){
				ch=false;
				++no;
				temp=recur(maze,row+1,col,ch);
				if(ch){
					count=count+ temp;
					cond=true;
				}
			}
					
		if( (col+1)<maze[0].size() )
			if ( maze[row][col+1]=='.' || maze[row][col+1]=='*' ){
				ch=false;
				++no;
				temp=recur(maze,row,col+1,ch);
				if(ch){
					count=count+ temp;
					cond=true;
				}
			}

		if(no>1){
			if(cond)
				return (count+1);
			else
				return 1;
		}
		else if(no==1)
			return count;
		else 
			return 0;
	}
	
};

int MazeWanderingEasy::decisions(vector <string> maze) {
	int r,c;
	for(int i=0;i<maze.size();i++){
		for(int j=0;j<maze[i].size();j++){
			if(maze[i][j]=='M'){
				r=i,c=j;
				break;
			}
		}
	}
	bool ch=false;
	return ( recur( maze,r,c,ch ) );
};


double test0() {
	string t0[] = {"*.M"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWanderingEasy * obj = new MazeWanderingEasy();
	clock_t start = clock();
	int my_answer = obj->decisions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"*.M",
 ".X."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWanderingEasy * obj = new MazeWanderingEasy();
	clock_t start = clock();
	int my_answer = obj->decisions(p0);
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
double test2() {
	string t0[] = {"...",
 "XMX",
 "..*"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWanderingEasy * obj = new MazeWanderingEasy();
	clock_t start = clock();
	int my_answer = obj->decisions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {".X.X......X",
 ".X*.X.XXX.X",
 ".XX.X.XM...",
 "......XXXX."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWanderingEasy * obj = new MazeWanderingEasy();
	clock_t start = clock();
	int my_answer = obj->decisions(p0);
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
double test4() {
	string t0[] = {"..........*",
 ".XXXXXXXXXX",
 "...........",
 "XXXXXXXXXX.",
 "M.........."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWanderingEasy * obj = new MazeWanderingEasy();
	clock_t start = clock();
	int my_answer = obj->decisions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
}

//Powered by [KawigiEdit] 2.0!
