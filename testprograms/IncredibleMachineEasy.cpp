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

class IncredibleMachineEasy {
public:
	double gravitationalAcceleration(vector <int>, int);
};

double IncredibleMachineEasy::gravitationalAcceleration(vector <int> height, int T) {
	
	double sum=0;
	for(int i=0;i<height.size();i++){
		sum=sum+ sqrt( (double)height[i] );
	}
	sum=sum*sum;
	return ( (2*sum)/ (double)(T*T) );
}


//Powered by [KawigiEdit] 2.0!
