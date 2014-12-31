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
	int n = 0, i = 0, j = 0, k = 0, num_flag = 0, multiple = 1, tmp = 0;
	scanf("%d", &n);
	int phone[100000][8];
	int flag[100000] = {0}, num_sort[100000] = {0};
	char num[2000];

	for (i = 0; i < n; i++) {
		scanf("%s", num);
		multiple = 1;
		for (j = strlen(num) - 1, k = 0; j >= 0; j--) {
			if (num[j] <= '9' && num[j] >= '0') {
				phone[i][k] = num[j] - 48;
				num_sort[i] += phone[i][k] * multiple;
				multiple *= 10;
				debug_487("%d %d %d\n", phone[i][k], num[j] - 48, num_sort[i]);
				k++;
			} else if (num[j] <= 'O' && num[j] >= 'A') {
				phone[i][k] = (num[j] - 'A') / 3 + 2;
				num_sort[i] += phone[i][k] * multiple;
				multiple *= 10;
				debug_487("%d %d %d\n", phone[i][k], num[j] - 65, num_sort[i]);
				k++;
			} else if (num[j] <= 'S' && num[j] >= 'P') {
				phone[i][k] = 7;
				num_sort[i] += phone[i][k] * multiple;
				multiple *= 10;
				debug_487("%d %d %d\n", phone[i][k], num[j] - 65, num_sort[i]);
				k++;
			} else if (num[j] <= 'Y' && num[j] >= 'T') {
				phone[i][k] = (num[j] - 'T') / 3 + 8;
				num_sort[i] += phone[i][k] * multiple;
				multiple *= 10;
				debug_487("%d %d %d\n", phone[i][k], num[j] - 65, num_sort[i]);
				k++;
			}
		}
	}

	sort(num_sort, num_sort + n);
//	qsort (num_sort, n, sizeof(int), (int (*) (const void *, const void *)) strcmp);

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
				num_flag++;
				continue;
			}
			break;
		}
		if (flag[i] > 0) {
//			cout << num_sort[i] / 10000 << "-" << num_sort[i] % 10000 << " " << flag[i] + 1 << endl;
			printf("%03d-%04d %d\n", num_sort[i] / 10000, num_sort[i] % 10000, flag[i] + 1);
		}
		i = j - 1;
	}

	if (num_flag == 0) {
		cout << "No duplicates." << endl;
	}

	return 0;
}
