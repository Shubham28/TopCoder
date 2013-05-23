#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <set>
#include <bitset>

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

class TheMoviesLevelThreeDivTwo {
public:
	int find(vector <int>, vector <int>);
};

int TheMoviesLevelThreeDivTwo::find(vector <int> timeJ, vector <int> timeB) {
	int N=SZ(timeJ);
	VI done(N,0);
	int cnt=0;
	int global=max(accumulate(ALL(timeJ),0),accumulate(ALL(timeB),0));

	VI john(N),brus(N);
	int jSize,bSize,jFrnt,bFrnt;

	FOR(mask,1,(1<<N)-1){

		jSize=0,bSize=0,jFrnt=0,bFrnt=0;
		FOR(give,0,N){
			if((mask>>give)&1==1){
				john[jSize]=give;
				jSize+=1;
			} else {
				brus[bSize]=give;
				bSize+=1;
			}
			done[give]=0;
		}

		int jnM=john[jFrnt],brM=brus[bFrnt];
		int jT=timeJ[jnM],bT=timeB[brM];
		done[jnM]+=1,++done[brM];
		jFrnt+=1,bFrnt+=1;;

		EFOR(tim,1,global+1){
			jT-=1,bT-=1;
			if(jT==0)
				if(done[jnM]==1){
					brus[bSize]=jnM;
					bSize+=1;
				}

			if(bT==0)
				if(done[brM]==1){
					john[jSize]=brM;
					jSize+=1;
				}

			if(jT==0){
				if(jFrnt==jSize)
					break;

				jnM=john[jFrnt],jT=timeJ[jnM];
				done[jnM]+=1,jFrnt+=1;

			} if(bT==0) {
				if(bFrnt==bSize)
					break;

				brM=brus[bFrnt],bT=timeB[brM];
				done[brM]+=1,bFrnt+=1;
			}
		}

		while(jFrnt<jSize){
			++done[john[jFrnt]];
			jFrnt+=1;
		}
		while(bFrnt<bSize){
			++done[brus[bFrnt]];
			bFrnt+=1;
		}

		int tmp=0;
		FOR(chk,0,N)
			tmp+=((done[chk]==2)?1:0);

		if(tmp==N)
			++cnt;
	}
	return cnt;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheMoviesLevelThreeDivTwo *obj;
	int answer;
	obj = new TheMoviesLevelThreeDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;

	{
	// ----- test 0 -----
	int t0[] = {4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {1,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {10,10,10,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,1,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {1,2,3,4,5,6,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,6,5,4,3,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 98;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
