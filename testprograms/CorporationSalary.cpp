#include <vector>
#include <map>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

class CorporationSalary {
public:
	long long totalSalary(vector <string>);
	void recur( VS &rel,int r, vector<long long>&sal ) {
		long long sum=0;
		bool cond=false;
		
		FOR(c,0,rel[r].size()){
			if(rel[r][c]=='Y'){
				if(sal[c]==-1)
					recur(rel,c,sal);
				sum+=sal[c];
				cond=true;
			}
		}
		if(!cond)
			sal[r]=1;
		else 
			sal[r]=sum;
	}
};

long long CorporationSalary::totalSalary(vector <string> relations) {
	vector<long long>sal(relations.size(),-1);
	
	FOR(r,0,relations.size()){
		if(sal[r]==-1)
			recur(relations,r,sal);
	}
	long long sum=0;
	FOR(i,0,sal.size())
		sum+=sal[i];
		
	return sum;
}

//Powered by [KawigiEdit] 2.0!
