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

class SumOfLuckiness {
public:
	long long theSum(int, int);

	LL ways[11][2][11][11];
	int L;
	char num[11];

/*
	pos: Position of digit we are considering
	smaller: Whether the 1st pos digits make up a number that is smaller than (smaller = 1), or equal to (smaller = 0)
	four: Number of 4s used
	seven: Number of 7s used

	Order can be reduced by considering only the difference of 4s & 7s
*/

	LL addDig(int pos,int sml,int frs,int svn) {
		if(pos==L)
			return abs(frs-svn);

		LL &tmp=ways[pos][sml][frs][svn];
		if(tmp!=-1)
			return tmp;

		tmp=0;
		int lim=sml?'9':num[pos];

		EFOR(nxt,'0',lim)
			tmp+=addDig(pos+1,(sml|(nxt<lim)),frs+(nxt=='4'),svn+(nxt=='7'));

		return tmp;
	}

	LL smLucky(int N) {

		if(N<10){
			if(N<=3)	return 0;
			if(N>=4 && N<7)		return 1;
			if(N>=7)	return 2;
		}

		sprintf(num,"%d",N);
		L=strlen(num);
		MEM(ways,-1);

		return addDig(0,0,0,0);
	}
};

long long SumOfLuckiness::theSum(int A, int B) {
	return smLucky(B)-smLucky(A-1);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	SumOfLuckiness *obj;
	long long answer;
	obj = new SumOfLuckiness();
	clock_t startTime = clock();
	answer = obj->theSum(p0, p1);
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
	
	int p0;
	int p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 10;
	p2 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 40;
	p1 = 47;
	p2 = 8ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 58;
	p1 = 526;
	p2 = 231ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4444;
	p1 = 7777;
	p2 = 2338ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 585858585;
	p1 = 858585858;
	p2 = 287481025ll;
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
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
