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
const int N = 10000; // matrix size
double a[N], b[N][N], sum[N] = {0};

void inits(int n) // generate a N∗N matrix
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			b[i][j] = i + j;

}

int main()
{
	fill(a, a + N, 1);
	long long head, tail, freq; // timers
	inits(N);
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER *) & head);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum[j] += a[i] * b[i][j];
	//unroll优化算法
	/* for (int i = 0; i < N; i++)
	{
		int j = 0;
		for (; j + 3 < N; j += 4)
		{
			sum[j] += a[i] * b[i][j];
			sum[j + 1] += a[i] * b[i][j + 1];
			sum[j + 2] += a[i] * b[i][j + 2];
			sum[j + 3] += a[i] * b[i][j + 3];
		}
	}

}
逐列访问平凡算法
for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++)
		sum[i] += b[j][i] * a[j];
}*/

//cache优化算法
for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		sum[j] += a[i] * b[i][j];
	
	// end time
	QueryPerformanceCounter((LARGE_INTEGER *) & tail);
	cout << "Col: " << (tail -head) * 1000.0 / freq
		<< "ms" << endl;
}