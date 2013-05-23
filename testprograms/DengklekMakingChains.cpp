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

class DengklekMakingChains {
public:
	int maxBeauty(vector <string>);
};

int DengklekMakingChains::maxBeauty(vector <string> ch) {
	int N=SZ(ch);
	bool mask[N][3];

	FOR(a,0,N)		FOR(p,0,3)
		mask[a][p]=(ch[a][p]!='.');

	int ini=0,ans=0;
	int L=0,R=0;
	FOR(a,0,N){
		if(ch[a]=="...")
			continue;

		else if(mask[a][0] && mask[a][1] && mask[a][2])
			ini+=((ch[a][0]-'0')+(ch[a][1]-'0')+(ch[a][2]-'0'));

		else if(!mask[a][0] && mask[a][1] && !mask[a][2])
			ans=max(ans,ch[a][1]-'0');

		else if(!mask[a][0] && !mask[a][1] && mask[a][2])
			R=max(R,ch[a][2]-'0');

		else if(!mask[a][0] && mask[a][1] && mask[a][2])
			R=max(R,(ch[a][1]-'0')+(ch[a][2]-'0'));

		else if(mask[a][0] && !mask[a][1] && !mask[a][2])
			L=max(L,ch[a][0]-'0');

		else if(mask[a][0] && mask[a][1] && !mask[a][2])
			L=max(L,(ch[a][0]-'0')+(ch[a][1]-'0'));
	}

	vector< pair<int,int> >mid;
	FOR(a,0,N)
		if(mask[a][0] && !mask[a][1] && mask[a][2])
			PB(mid,make_pair(ch[a][0]-'0',ch[a][2]-'0'));


	int prs=ini+L+R;

	if(SZ(mid)==1)
		prs=max(prs,ini+max(max(L,mid[0].first)+R,L+max(mid[0].second,R)));
	else {
		FOR(l,0,SZ(mid))	FOR(r,0,SZ(mid))
			if(l!=r)
				prs=max(prs,ini+max(L,mid[l].first)+max(R,mid[r].second));
	}

	return max(ans,prs);
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
	DengklekMakingChains *obj;
	int answer;
	obj = new DengklekMakingChains();
	clock_t startTime = clock();
	answer = obj->maxBeauty(p0);
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
	string t0[] = {".15","7..","402","..3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 19;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"..1","7..","567","24.","8..","234"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 36;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"16.","9.8",".24","52.","3.1","532","4.4","111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 28;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"..1","3..","2..",".7."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"412","..7",".58","7.8","32.","6..","351","3.9","985","...",".46"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 58;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"555",".22","11.",".9."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 21;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	string t0[] = {"..2",".21","7..","32.","9.9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 16;
	all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 8 -----
	string t0[] = {"000","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(8, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 9 -----
	string t0[] = {"1.1","1.1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(9, p0, true, p1) && all_right;
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
