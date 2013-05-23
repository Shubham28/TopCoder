#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <bitset>

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

class ProductTriplet {
public:
	long long countTriplets(int, int, int, int, int, int);
	LL min(LL A,LL B) {
		return ( (A<=B)?A:B );
	}
	
	LL max(LL A,LL B) {
		return ( (A>=B)?A:B );
	}
};

long long ProductTriplet::countTriplets(int minx, int maxx, int miny, int maxy, int minz, int maxz) {
	LL low,high,ret=0;

	for(LL x=minx;x<=maxx && x*x<=maxz;x++){
		low=max(x,max(miny-1,(minz-1)/x));
		high=min(maxy,maxz/x);
		if(high>low)
			ret+=(high-low);
	}
	
	for(LL y=miny;y<=maxy && y*y<=maxz;y++){
		low=max(y,max(minx-1,(minz-1)/y));
		high=min(maxx,maxz/y);
		if(high>low)
			ret+=(high-low);
	}
	
	for(LL a=max(minx,miny);a<=min(maxx,maxy) && a*a<=maxz;a++)
		if(minz<=a*a && a*a<=maxz)
			++ret;

	return ret;
}

bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, long long p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	ProductTriplet *obj;
	long long answer;
	obj = new ProductTriplet();
	clock_t startTime = clock();
	answer = obj->countTriplets(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	int p5;
	long long p6;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 2;
	p2 = 3;
	p3 = 3;
	p4 = 6;
	p5 = 6;
	p6 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	p2 = 3;
	p3 = 3;
	p4 = 7;
	p5 = 7;
	p6 = 0ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = 8;
	p2 = 4;
	p3 = 5;
	p4 = 27;
	p5 = 35;
	p6 = 4ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1;
	p1 = 458;
	p2 = 1;
	p3 = 458;
	p4 = 1;
	p5 = 458;
	p6 = 2877ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 8176;
	p1 = 184561;
	p2 = 1348;
	p3 = 43168;
	p4 = 45814517;
	p5 = 957843164;
	p6 = 2365846085ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}

// Author: Shubham Gupta
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
