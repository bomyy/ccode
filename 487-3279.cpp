#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

//#define DEBUG

#ifdef DEBUG
#define debug_487(fmt, args...) \
	printf("%d: " fmt, __LINE__, ##args) 
#else
#define debug_487(fmt, args...)
#endif

using namespace std;

int main()
{
	int n = 0, num_pri = 0, i = 0, j = 0, k = 0, num_flag = 0, multiple = 1, tmp = 0;
	scanf("%d", &n);
//	printf("%d", n);
//	cin >> n;
//	cout << n << endl;
	int phone[n][7];
	int flag[1000] = {0}, num_sort[1000] = {0};
	char num[20];

	num_pri = n;
	for (i = 0; i < n; i++) {
		scanf("%s", num);
//		cin >> num;
		for (j = 0, k = 0; j < strlen(num); j++) {
			if (num[j] <= '9' && num[j] >= '0') {
				phone[i][k] = num[j] - 48;
				debug_487("%d %d %d\n", __LINE__, phone[i][k], num[j] - 48);
				k++;
			} else if (num[j] <= 'O' && num[j] >= 'A') {
				phone[i][k] = (num[j] - 'A') / 3 + 2;
				debug_487("%d %d %d\n", __LINE__, phone[i][k], num[j] - 65);
				k++;
			} else if (num[j] <= 'S' && num[j] >= 'P') {
				phone[i][k] = 7;
				debug_487("%d %d %d\n", __LINE__, phone[i][k], num[j] - 65);
				k++;
			} else if (num[j] <= 'Y' && num[j] >= 'T') {
				phone[i][k] = (num[j] - 'T') / 3 + 8;
				debug_487("%d %d %d\n", __LINE__, phone[i][k], num[j] - 65);
				k++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		multiple = 1;
//		num_sort[i] = 0;
		for (j = 6; j >= 0; j--) {
			num_sort[i] += phone[i][j] * multiple;
			multiple *= 10;
		}
//		cout << num_sort[i] << endl;
	}

	sort(num_sort, num_sort + n);
#if 0
	for (i = 0; i < n; i++) {
		cout << num_sort[i] << endl;
	}
#endif
	for (i = 0; i < n; i++) {
		tmp = num_sort[i];
		for(j = i + 1; j < n; j++) {
			if (tmp == num_sort[j]) {
				flag[i]++;
				continue;
			}
			break;
		}
		if (flag[i] > 0) {
			cout << num_sort[i] / 10000 << "-" << num_sort[j] % 10000 << " " << flag[i] + 1 << endl;
		}
		i = j - 1;
	}
	return 0;
}
