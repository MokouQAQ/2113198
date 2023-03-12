#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<iomanip>
#include<deque>
#include<queue>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<numeric>
#include<list>
#include<cmath>
#include <windows.h>
using namespace std;
const int N = 100; // matrix size
double a[N] ;
long long sum,sum1,sum2,sum3,sum4;
void inits(int n) // generate a N∗N matrix
{
	

}
//方法三：递归算法
/*void adds(int n) {
	if (n <= 1)
		return;
	else
	{
		for (int i = 0; i < n / 2; i++)
			a[i] += a[n - i - 1];

		adds(n / 2);
	}

}*/

int main()
{
	sum = 0;
	fill(a, a + N, 1);
	long long head, tail, freq; // timers
	inits(N);
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head);

	//方法一:平凡算法累加
	/*for (int i = 0; i < N; i++)sum += a[i];*/


	//方法二：四路链式累加
	/*for (int i = 1; i <= N - 3; i += 4)
	{
		int sum1 = a[i];
		int sum2 = a[i + 1];
		int sum3 = a[i + 2];
		int sum4 = a[i + 3];
	}
	sum = sum1 + sum2 + sum3 + sum4;
	*/

	// end time
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	cout << "Col: " << (tail - head) * 1000.0 / freq
		<< "ms" << endl;
}
