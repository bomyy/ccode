#include <stdio.h>
#include <string.h>

//#define TEST_DEBUG

#ifdef TEST_DEBUG
#define debug_test(fmt, args...) \
	printf("%d: " fmt, __LINE__, ##args) 
#else
#define debug_test(fmt, args...)
#endif

int main()
{
	int num[1000], num_tmp[1000] = {0};
	int i = 1, j = 0, k = 0, tmp_len1 = 0, len1 = 1, len2 = 1, len3 = 1, tmp = 0, tmp_i = 0, flag = 1;

	num[0] = 1;
	
	for (i = 1; i <= 99; i += 2) {
		printf("i = %d\n", i);
		flag = 1;
		tmp_len1 = len3;
		for (j = 0; j < len3; j++) {
			if (0 == num[j]) {
				continue;
			} else {
				len1 = len3 - j;
				break;
			}
		}

		debug_test("len1 = %d len3 = %d i = %d\n",
			   len1, len3, i);
		tmp = i;
		len2 = 1;
		while(tmp / 10 != 0) {
			len2++;
			tmp /= 10;
		}
		len3 = len1 + len2;
		debug_test("len1 = %d len2 = %d len3 = %d\n", len1, len2, len3);
		/* For multiplication */
		tmp_i = i;
		for(k = len2 - 1; k >= 0; k--) {
			tmp = (--len3);
			debug_test("tmp = %d tmp_i = %d\n", tmp, tmp_i);
			for (j = tmp_len1 - 1; j >= tmp_len1 - len1; j--, tmp--) {
				debug_test("num_tmp[%d] = %d num[%d] = %d\n",
					   tmp, num_tmp[tmp], j, num[j]);
				num_tmp[tmp] += num[j] * (tmp_i % 10);
				debug_test("num_tmp[%d] = %d num[%d] = %d\n",
				       tmp, num_tmp[tmp], j, num[j]);
			}
			tmp_i /= 10;
		}

		/* For rounding */
		len3 = len1 + len2;
		tmp = len3 - 1;
		for(j = tmp; j >= 0; j--) {
			if(num_tmp[j] > 9) {
				num_tmp[j - 1] += num_tmp[j] / 10;
				num_tmp[j] = num_tmp[j] % 10;
			}
		}

		tmp = len3 - 1;
		for(j = tmp; j >= 0; j--) {
			debug_test("num[%d] = %d num_tmp[%d] = %d\n",
				   j, num[j], j, num_tmp[j]);
			num[j] = num_tmp[j];
			num_tmp[j] = 0;
			debug_test("num[%d] = %d num_tmp[%d] = %d\n",
			       j, num[j], j, num_tmp[j]);
		}
		/* For print */
		debug_test("len1 = %d len2 = %d len3 = %d \nResult : ", len1, len2, len3);
		for (j = 0; j < len3; j++) {
			if (num[j] == 0 && flag == 1) {
				continue;
			} else {
				flag = 0;
			}
			printf("%d", num[j]);
		}
		printf("\n\n");
	}

	return 0;
}
