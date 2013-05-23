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
#define LL long long
#define PII pair<int,int>

using namespace std;

int dx[]={0,1};
int dy[]={1,0};

class AvoidRoads {
public:
	long long numWays(int, int, vector <string>);
};

long long AvoidRoads::numWays(int W, int H, vector <string> bad) {
	LL ways[105][105];
	MEM(ways,0);

	int fr1,fr2,to1,to2;
	ways[0][0]=1;

	EFOR(x,0,W){
		EFOR(y,0,H){
			PII prs=PII(x,y);

			FOR(d,0,2){
				int tx=x+dx[d],ty=y+dy[d];
				if(tx>=0 && tx<=W && ty>=0 && ty<=H){
					PII nxt=PII(tx,ty);

					bool posb=1;
					FOR(chk,0,SZ(bad)){
						PII fr,to;
						sscanf(bad[chk].c_str(),"%d %d %d %d",&fr1,&fr2,&to1,&to2);
						fr=PII(fr1,fr2);
						to=PII(to1,to2);

						if((prs==fr && nxt==to) || (prs==to && nxt==fr)){
							posb=0;
							break;
						}
					}
					if(posb)
						ways[tx][ty]+=ways[x][y];
				}
			}
		}
	}
	return ways[W][H];
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <string> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AvoidRoads *obj;
	long long answer;
	obj = new AvoidRoads();
	clock_t startTime = clock();
	answer = obj->numWays(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <string> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	p0 = 6;
	p1 = 6;
	string t2[] = {"0 0 0 1","6 6 5 6"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 252ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	p2.clear() /*{}*/;
	p3 = 2ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 35;
	p1 = 31;
	p2.clear() /*{}*/;
	p3 = 6406484391866534976ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 2;
	string t2[] = {"0 0 1 0","1 2 2 2","1 1 2 1"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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