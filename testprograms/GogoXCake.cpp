#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SZ(A) int(A.size())
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define LL long long

using namespace std;

class GogoXCake {
public:
	string solve(vector <string>, vector <string>);
};

string GogoXCake::solve(vector <string> ck, vector <string> cut) {
	int R=SZ(ck),C=SZ(ck[0]);
	int M=SZ(cut),N=SZ(cut[0]);

	int fir=find(ALL(cut[0]),'.')-cut[0].begin();

	FOR(rw,0,R)
		FOR(cl,0,C){
			if(cl<fir || C-cl<N-fir || rw+M>R)
				continue;

			if(ck[rw][cl]=='.'){
				int shf=cl-fir;

				bool psb=1;
				FOR(y,0,M)		FOR(x,0,N)
					if(ck[rw+y][shf+x]=='X' && cut[y][x]=='.'){
						psb=0;
						break;
					}

				if(!psb)
					continue;

				FOR(y,0,M)		FOR(x,0,N)
					if(ck[rw+y][shf+x]=='.' && cut[y][x]=='.')
						ck[rw+y][shf+x]='X';
			}
		}

	FOR(rw,0,R)
		if(find(ALL(ck[rw]),'.')!=ck[rw].end())
			return "NO";

	return "YES";
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	GogoXCake *obj;
	string answer;
	obj = new GogoXCake();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <string> p0;
	vector <string> p1;
	string p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"X.X","...","...","X.X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".X","..","X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"..XX","...X","X...","XX.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..",".."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...X..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".X.","X.X",".X."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"XXXXXXX","X.....X","X.....X","X.....X","XXXXXXX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".X.","XXX",".X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"..","X.",".X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..",".X","X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"X..",".XX",".XX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".XX",".XX","X.."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	string t0[] = {".xxx","xxx.","...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"x..x"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(7, p0, p1, true, p2) && all_right;
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
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!