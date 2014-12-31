#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double n = 0.00;
	int k = 0, num = 0;
	while (cin >> n) {
		if (0 == n)
			break;
		k = 2;
		num = 0;
		while(n > 0.00) {
			n -= 1.00 / k;
			num++;
			k++;
//			printf("n = %lf %d card(s)\n", n, num);
		}
		printf("%d card(s)\n", num);
	}

	return 0;
}
