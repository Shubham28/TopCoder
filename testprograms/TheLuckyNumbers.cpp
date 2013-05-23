#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define sort(A) sort(A.begin(),A.end()) 
#define rep(i,A,B) for( long long int i=A;i<B;i++) 
#define repd(i,A,B) for( long long int i=A;i<=B;i--)
#define repe(i,A,B) for(int i=A;i<=B;i++) 
#define pb(A,B) A.push_back(B)

using namespace std;

class TheLuckyNumbers {
public:
	int count(int, int);
	long long int four(long long int f,int a,int b){
		static long long int c=0;
		if((f>=a) && (f<=b)){
			c++;
		}
		if(((f*10)+4)<=b)
			four((f*10)+4,a,b);
		if(((f*10)+7)<=b)
			four((f*10)+7,a,b);
		return c;
	}
};
int TheLuckyNumbers::count(int a, int b) {
	long long int c=0;
	c+=four(4,a,b)+four(7,a,b);
	return c;
}


//Powered by [KawigiEdit] 2.0!
