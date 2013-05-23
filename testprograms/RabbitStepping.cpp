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

class RabbitStepping {
public:
	string put;
	double ans,denom;
	int N,tot;
	int pos[18];
	double getExpected(string, int);

	void calExp() {
		++denom;
		int rab[2][tot],cnt=0;
		FOR(fill,0,N)
			if(pos[fill]>0)
				rab[0][cnt++]=fill;

		int done=0,chn=0;

		while(done<N-2){
			FOR(chk,0,tot){
				if(rab[chn][chk]!=-1){
					if(rab[chn][chk]==0)
						rab[chn^1][chk]=1;
					else if(rab[chn][chk]>=N-done-2)
						rab[chn^1][chk]=rab[chn][chk]-1;
					else if(put[rab[chn][chk]]=='W')
						rab[chn^1][chk]=rab[chn][chk]-1;
					else if(put[rab[chn][chk]]=='B')
						rab[chn^1][chk]=rab[chn][chk]+1;
					else
						rab[chn^1][chk]=((done==0)?rab[chn][chk]-1:rab[chn^1][chk]);
				} else
					rab[chn^1][chk]=rab[chn][chk];
			}

			done+=1,chn^=1;
			FOR(rem,0,tot){
				FOR(copy,rem+1,tot)
					if(rab[chn][rem]==rab[chn][copy])
						rab[chn][rem]=-1,rab[chn][copy]=-1;
				if(rab[chn][rem]+done>=N)
					rab[chn][rem]=-1;
			}
		}

		FOR(fav,0,tot)
			if(rab[chn][fav]!=-1)
				ans+=1;
		return;
	}

	void possible(int put) {
		if(put==0)
			memset(pos,-1,sizeof(pos));
		int strt=-1;
		RFOR(srch,N-1,0)
			if(pos[srch]>=0){
				strt=srch;
				break;
			}

		FOR(all,strt+1,N)
			if(pos[all]==-1){
				pos[all]=put+1;

				if(put+1==tot){
					calExp();
				} else
					possible(put+1);
				pos[all]=-1;
			}

		return;
	}
};

double RabbitStepping::getExpected(string field, int r) {
	put=field,ans=0.0,tot=r,denom=0.0;
	N=SZ(field);
	possible(0);
	return ans/double(denom);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	RabbitStepping *obj;
	double answer;
	obj = new RabbitStepping();
	clock_t startTime = clock();
	answer = obj->getExpected(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	
	string p0;
	int p1;
	double p2;
	
	{
	// ----- test 0 -----
	p0 = "WRBRW";
	p1 = 4;
	p2 = 0.8;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "WWB";
	p1 = 2;
	p2 = 1.3333333333333333;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "WW";
	p1 = 1;
	p2 = 1.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "BBBBBBBBBB";
	p1 = 4;
	p2 = 0.9523809523809523;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "RRBRRWRRBRRW";
	p1 = 8;
	p2 = 0.9696969696969697;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
