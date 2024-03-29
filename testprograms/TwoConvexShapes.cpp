#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define LL long long

using namespace std;

const LL MOD=1000000007;

class TwoConvexShapes {
public:
	int countWays(vector <string>);
	int grd[51][51];
	int R,C;

	LL ways[55][55][5][2];

	bool posib(int row, int len, bool colr) {
		FOR(j,0,C)
			if( (j+1<=len && grd[row][j]==(!colr) ) || (j+1>len && grd[row][j]==colr) )
				return 0;
		return 1;
	}

	//	State: row that is being painted, prefix length, decreasing/unchanged/increasing length, color of paint
	LL cntWays(int row, int len, int incr, bool nonZ, bool colr) {
		if(row==R)
			return nonZ;

		if(row==1)		incr=0;

		LL &tmp=ways[row][len][incr][nonZ];
		if(tmp!=-1)
			return tmp;

		//	0:unchanged; 1:decreasing; 2:increasing
		if(incr==1)			incr=-1;
		if(incr==2)			incr=1;

		tmp=0;
		if(posib(row,len,colr))
			tmp=cntWays(row+1,len,incr,nonZ,colr);

		if(incr==0 || incr==-1)
			for(int nxt=len-1;nxt>=0;nxt--)
				if(posib(row,nxt,colr)){
					tmp+=cntWays(row+1,nxt,1,nonZ|(nxt>0),colr);
					tmp%=MOD;
				}

		if(incr==0 || incr==1)
			for(int nxt=len+1;nxt<=C;nxt++)
				if(posib(row,nxt,colr)){
					tmp+=cntWays(row+1,nxt,2,1,colr);
					tmp%=MOD;
				}
cout<<row<<","<<len<<","<<incr<<" - "<<colr<<" = "<<tmp<<"\n";
		return tmp;
	}
};

int TwoConvexShapes::countWays(vector <string> grd_) {
	R=SZ(grd_),C=SZ(grd_[0]);

	FOR(i,0,R)		FOR(j,0,C){
		if(grd_[i][j]=='B')				grd[i][j]=0;
		else if(grd_[i][j]=='W')		grd[i][j]=1;
		else
			grd[i][j]='?';		
	}

	MEM(ways,-1);
	LL ans=cntWays(0,0,0,0,0);

	MEM(ways,-1);
	ans+=cntWays(0,0,0,0,1);

	return (int)(ans%MOD);

}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TwoConvexShapes *obj;
	int answer;
	obj = new TwoConvexShapes();
	clock_t startTime = clock();
	answer = obj->countWays(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"?" "?","?" "?"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 14;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"B?","?" "?"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"WWB","WWW","WWW","WWW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"BBBBBB","WWBBBB","WBBBBB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"?BB?","BBBB","?BB?"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW","B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW","BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW","BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW","BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW","BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW","BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW","BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW","BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW","BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW","BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW","BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW","BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW","BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW","BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW","BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW","BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW","BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW","BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW","BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW","BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW","BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW","BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW","BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW","BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW","BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW","BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW","BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW","BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW","BBBBBBBBBBBBBB"
			"BBBBBBBBBBBBBBB?W"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 73741817;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
