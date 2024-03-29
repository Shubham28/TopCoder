#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

class SquareConstruction {
public:
	vector <string> construct(int, int, int, int, int);
};

vector <string> SquareConstruction::construct(int N, int a, int b, int c, int d) {
	vector< VI >cells(N,VI(N,-1));
	int fill=1,inx=0,iny=0;

	cells[inx][iny]=fill,fill+=1;
	while(true){
		inx=(inx+a)%N,iny=(iny+b)%N;

		if(cells[inx][iny]==-1)
			cells[inx][iny]=fill,fill+=1;
		else {
			inx=(inx+c)%N,iny=(iny+d)%N;

			if(cells[inx][iny]==-1)
				cells[inx][iny]=fill,fill+=1;
			else
				break;
		}
	}

	VS ans(N,"");
	FOR(row,0,N){
		FOR(col,0,N){
			int num=cells[row][col];
			char buff[10];
			sprintf(buff,"%d",num);
			string tmp(buff);
			ans[row]+=(tmp+" ");
		}
		ans[row].erase(SZ(ans[row])-1);
	}
	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, vector <string> p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	SquareConstruction *obj;
	vector <string> answer;
	obj = new SquareConstruction();
	clock_t startTime = clock();
	answer = obj->construct(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p5.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p5[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p5.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p5[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	vector <string> p5;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	string t5[] = {"1 -1 -1 -1 -1","-1 -1 -1 -1 -1","-1 -1 -1 -1 -1","-1 -1 -1 -1 -1","-1 -1 -1 -1 -1"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	p1 = 1;
	p2 = 1;
	p3 = 2;
	p4 = 2;
	string t5[] = {"1 -1 -1 -1 -1","-1 2 -1 -1 -1","-1 -1 3 -1 -1","-1 -1 -1 4 -1","-1 -1 -1 -1 5"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 1;
	p2 = 1;
	p3 = 1;
	p4 = 0;
	string t5[] = {"1 22 18 14 10","6 2 23 19 15","11 7 3 24 20","16 12 8 4 25","21 17 13 9 5"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 0;
	p2 = 1;
	p3 = 2;
	p4 = 3;
	string t5[] = {"1 2 3 4 5","17 18 19 20 16","8 9 10 6 7","24 25 21 22 23","15 11 12 13 14"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 6;
	p1 = 1;
	p2 = 2;
	p3 = 2;
	p4 = 2;
	string t5[] = {"1 -1 15 -1 11 -1","12 -1 2 -1 16 -1","17 -1 7 -1 3 -1","4 -1 18 -1 8 -1","9 -1 5 -1 13 -1","14 -1 10 -1 6 -1"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1;
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	string t5[] = {"1"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
// Author: Shubham Gupta
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
