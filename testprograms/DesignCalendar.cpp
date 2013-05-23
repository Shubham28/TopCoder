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

using namespace std;

class DesignCalendar {
public:
	int shortestPeriod(int, int);
	
	int gcd(int num1,int num2) {	
		if(num1==1)
			return 1;
		else if( num2%num1==0 )
			return num1;
		else 
			gcd( num2%num1 , num1 );
	}
};

int DesignCalendar::shortestPeriod(int dayLength, int yearLength) {
	long long int rem= yearLength- ( (int)(yearLength/dayLength) * (dayLength) );

	if(rem==0)
		return 1;
		
	return rem/( gcd(rem,dayLength) ) ;
}




//Powered by [KawigiEdit] 2.0!
