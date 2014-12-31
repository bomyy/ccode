#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double num[12], sum = 0.00;
	int i = 0;

	for (i = 0; i < 12; i++) {
		cin >> num[i];
		sum += num[i];
	}
	
	printf("$%.2lf\n", sum / 12);
	return 0;
}
