#include <vector>
#include <list>
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

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );

using namespace std;

class StrongPrimePower {
public:
	vector <int> baseAndExponent(string);
	bool prime( long long num ) {	cout<<" prime "<<num<<endl;
		long count=0;
		
		for( long long i=1;i*i<=num;i++)
			if(num%i==0)
				++count;
				
		if(count==1)
			return true;
		else 
			return false;
	}

};

vector <int> StrongPrimePower::baseAndExponent(string n) {
	long long num=0;
	vector<int>ret;
	
	FOR(i,0,n.size())
		num=num*10 + ( (int)n[i]-48 );

	long q=2;
	long double p=(long double)pow( (double)num, (double)(1/q) );
cout<<" p "<<p<<" q "<<q<<"\n";
/*	while( p>=2 ){
		long long power=(long long)p;		cout<<" ini "<<power<<endl;
		
		FOR(i,1,q)
			power=power*(long long)p;
cout<<" fin "<<power<<endl;		
		if( power == num ){		cout<<" equal "<<endl;
			if( prime( (long long)p ) ){		cout<<"\n enter "<<p<<"\n";
				PB(ret, (long long)p );
				PB(ret, (long long)q );
				return ret;
			}
		}
		++q;
		p=(long double)pow( (double)num, (double)(1/q) );
	}*/
	return ret;
}

//Powered by [KawigiEdit] 2.0!
