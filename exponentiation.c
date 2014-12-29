#include <iostream>
//#include <stdio.h>
#include <cstring>

using namespace std;

//#define EXPONENTIATION_DEBUG

#ifdef EXPONENTIATION_DEBUG
#define debug_exponentiation(fmt, args...) \
	printf("%d: " fmt, __LINE__, ##args) 
#else
#define debug_exponentiation(fmt, args...)
#endif

int main()
{
	char s[6];
	int n = 0;
	while(cin >> s >> n) {
		int s_tmp[5], n_tmp[1000] = {0}, num[1000] = {0};
		int i = 0, j = 0, k = 0, tmp = 0, len = 0, len_s = 0, len_last = 0, len_now = 0, len_tmp = 0, dot_num = 6, num_right = 0,
			num_left = 0, left_flag = 0, right_flag = 0, dot_flag = 0, zero_flag = 0;

		len = strlen(s);
		/* Calculate how many on the left of the decimal point */
		for(i = 0; i < len; i++) {
			if('.' == s[i]) {
				dot_num = i;
			} else if (i <= dot_num && (s[i] != '0' || 1 == left_flag)){
				left_flag = 1;
				num_left++;
				debug_exponentiation("num_left = %d\n", num_left);
			}
		}
		/* Calculate how many on the right of the decimal point */
		for(i = len - 1; i > dot_num; i--) {
			if('0' == s[i] && 0 == right_flag) {
				continue;
			} else {
				right_flag = 1;
				num_right++;
			}
		}

		len_s = num_left + num_right;
		debug_exponentiation("dot_num = %d num_left = %d num_right = %d\n", dot_num, num_left, num_right);
		for (i = dot_num - num_left, j = 0; i < len; i++) {
			if(s[i] == '.')
				continue;
			num[j] = s[i] - 48;
			s_tmp[j] = s[i] - 48;
			debug_exponentiation("num[%d] = %d s_tmp[%d] = %d\n", j, num[j], j, s_tmp[j]);
			j++;
		}
		if (0 == num_left)
			dot_num = 0;

		if(0 == n) {
//			printf("1\n");
			cout << "1" << endl;
		} else if (0 == len_s) {
//			printf("0\n");
			cout << "0" << endl;
		} else if (1 == n) {
			for(i = 0, j = dot_num - num_left; i < len_s; i++, j++) {
				if ((i < dot_num) && 0 == s_tmp[i] && 0 == zero_flag) {
					continue;
				}
				zero_flag = 1;
				
				if (j == dot_num) {
//					printf(".");
					cout << ".";
					i--;
					dot_num = 6;
					continue;
				}
//				printf("%d", s_tmp[i]);
				cout << s_tmp[i];
			}
//			printf("\n");
			cout << endl;
		} else {
			len_last = len_s;

			for (i = 0; i < n - 1; i++) {
				debug_exponentiation("len_last = %d len_s = %d\n", len_last, len_s);
				for (j = 0; j < len_last; j++) {
					if (0 == num[j]) {
						continue;
					} else {
						break;
					}
				}
				len_tmp = len_now = len_last - j + len_s;
				debug_exponentiation("len_last = %d len_s = %d len_now = %d\n", len_last, len_s, len_now);
				for (k = len_last - 1; k >= 0; k--) {
					tmp = (--len_now);
					for (j = len_s - 1; j >= 0; j--, tmp--) {
						n_tmp[tmp] += (num[k] * s_tmp[j]);
					}
				}

				len_now = len_tmp;
				for (j = len_now - 1; j >= 0; j--) {
					if(n_tmp[j] > 9) {
						debug_exponentiation("n_tmp[%d] = %d\n", j, n_tmp[j]);
						n_tmp[j - 1] += n_tmp[j] / 10;
						n_tmp[j] = n_tmp[j] % 10;
						debug_exponentiation("n_tmp[%d] = %d\n", j, n_tmp[j]);
					}
				}
				debug_exponentiation("result_tmp : ");
				for (j = 0; j < len_now; ++j)
				{
					num[j] = n_tmp[j];
//					cout <<n_tmp[j];
					if(i < n - 2)
						n_tmp[j] = 0;
				}
				len_last = len_now;
//				cout << endl;
			}
			debug_exponentiation("dot_num = %d len_now = %d\n", dot_num, len_now);
			debug_exponentiation("result : ");
			len_tmp = len_now;
			if (len_now < num_right * n)
				len_now = num_right * n;
			for (j = 0; j < len_tmp; j++)
			{
				if ((j < len_now - (num_right * n)) && 0 == n_tmp[j] && 0 == zero_flag) {
					continue;
				}
				zero_flag = 1;
				if ((j == len_now - (num_right * n)) && 0 == dot_flag) {
//					printf(".");
					cout << ".";
					j--;
					dot_num = 6;
					dot_flag = 1;
					if (len_tmp < num_right * n) {
						for(k = 0; k < num_right * n - len_tmp; k++)
//							printf("0");
							cout << "0";
					}
					continue;
				}
//				printf("%d", n_tmp[j]);
				cout << n_tmp[j];

				n_tmp[j] = 0;
			}
//			printf("\n");
			cout << endl;
		}
	}
	
	return 0;
}
