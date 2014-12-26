#include <iostream>
#include <stdio.h>
using namespace std;

#define EXPONENTIATION_DEBUG

#ifdef EXPONENTIATION_DEBUG
#define debug_exponentiation(fmt, args...) \
	printf("%d: " fmt, __LINE__, ##args) 
#else
#define debug_exponentiation(fmt, args...)
#endif

int main()
{
	char s[6];
	int s_tmp[5];
	int n_tmp[1000] = {0};
	int num[1000] = {0};
	int n = 0, i = 0, j = 0, k = 0, tmp = 0, len_s = 0, len_num = 0, len_last = 0, len_now = 0, len_tmp = 0, flag = -1, dot_num = 1000, num_right = 0;
	while(cin >> s >> n) {
		for(i = 0; i < 6; i++) {
			if(s[i] == '0' || s[i] == '.') {
//				cout << i << s[i] << endl;
				continue;
			} else {
				break;
			}
		}
		if(6 == i) {
			cout << "0" << endl;
		} else {
			for (i = 5; i >= 0; i--) {
				if ('0' == s[i]) {
					continue;
				} else {
					num_right = i;
					break;
				}
			}
			debug_exponentiation("num_right = %d\n", num_right);
			if (s[0] == '0') {
				dot_num = 1;
				for (i = 2, j = 0; i <= num_right; i++) {
					if(s[i] == '0')
						continue;
					num[j] = s[i] - 48;
					s_tmp[j] = s[i] - 48;
					debug_exponentiation("num[%d] = %d s_tmp[%d] = %d\n", j, num[j], j, s_tmp[j]);
					j++;
				}
				len_last = len_s = len_num = j;

				for (i = 0; i < n - 1; i++) {
					debug_exponentiation("len_num = %d len_last = %d len_s = %d\n", len_num, len_last, len_s);
					for (j = 0; j < len_last; j++) {
						if (0 == num[j]) {
							continue;
						} else {
							break;
						}
					}
					len_tmp = len_now = len_last - j + len_s;
					debug_exponentiation("len_num = %d len_last = %d len_s = %d len_now = %d\n", len_num, len_last, len_s, len_now);
					for(k = len_last - 1; k >= 0; k--) {
						tmp = (--len_now);
						for (j = len_s - 1; j >= 0; j--, tmp--) {
//						debug_exponentiation("%d n_tmp[%d] = %d num[%d] = %d s_tmp[%d] = %d\n", __LINE__, tmp, n_tmp[tmp], k, num[k], j, s_tmp[j]);
							n_tmp[tmp] += (num[k] * s_tmp[j]);
//						debug_exponentiation("%d n_tmp[%d] = %d\n", __LINE__, tmp, n_tmp[tmp]);
						}
					}

					len_now = len_tmp;
					for(j = len_now - 1; j >= 0; j--) {
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
				debug_exponentiation("result : ");
				for (j = len_now - 1; j >= 0; j--) {
					if (n_tmp[j] == 0) {
						len_now--;
					} else {
						break;
					}
				}
				debug_exponentiation("dot_num = %d len_num = %d\n", dot_num, len_num);
				cout <<".";
				k = n * (num_right - 1);
				for (j = 0; j < k; j++)
				{
					while (len_now < n * (num_right - 1)) {
						cout << "0";
						k--;
						len_now++;
						debug_exponentiation("len_now = %d\n", len_now);
						continue;
					}
					cout << n_tmp[j];

					n_tmp[j] = 0;
				}
				cout << endl;
			} else {
				for (i = num_right, j = num_right - 1; i >=0; i--, j--) {
					if (s[i] == '.') {
						dot_num = (num_right - i) * n;
						j++;
						debug_exponentiation("dot_num = %d\n", dot_num);
						continue;
					}
					num[j] = s[i] - 48;
					s_tmp[j] = s[i] - 48;
					debug_exponentiation("s[%d] = %d s_tmp[%d] = %d\n", i, s[i], j, s_tmp[j]);
				}
				len_last = len_s = len_num = num_right;

				for (i = 0; i < n - 1; i++) {
					debug_exponentiation("%d len_num = %d len_last = %d len_s = %d\n", __LINE__, len_num, len_last, len_s);
					for (j = 0; j < len_last; j++) {
						if (0 == num[j]) {
							continue;
						} else {
							break;
						}
					}
					len_tmp = len_now = len_last - j + len_s;
					debug_exponentiation("%d len_num = %d len_last = %d len_s = %d len_now = %d\n", __LINE__, len_num, len_last, len_s, len_now);
					for(k = len_last - 1; k >= 0; k--) {
						tmp = (--len_now);
						for (j = len_s - 1; j >= 0; j--, tmp--) {
							n_tmp[tmp] += (num[k] * s_tmp[j]);
						}
					}

					len_now = len_tmp;
					for(j = len_now; j >= 0; j--) {
						if(n_tmp[j] > 9) {
//					debug_exponentiation("%d num_tmp[%d] = %d", __LINE__, tmp, num_tmp[tmp]);
							n_tmp[j - 1] += n_tmp[j] / 10;
							n_tmp[j] = n_tmp[j] % 10;
//					debug_exponentiation("%d num_tmp[%d] = %d", __LINE__, tmp, num_tmp[tmp]);
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
				debug_exponentiation("result : ");
				for (j = len_now - 1; j >= 0; j--) {
					if (n_tmp[j] == 0) {
						len_last--;
						len_now--;
					} else {
						break;
					}
				}
				debug_exponentiation("dot_num = %d len_last = %d len_now = %d\n", dot_num, len_last, len_now);
				for (j = 0; j < len_last; j++) {
					if (n_tmp[j] == 0) {
						len_now--;
					} else {
						dot_num = len_now - dot_num;
						len_now++;
						break;
					}
				}
				debug_exponentiation("dot_num = %d len_last = %d len_now = %d\n", dot_num, len_last, len_now);
				for (j = 0; j < len_now; j++) {
					if (n_tmp[j] == 0) {
						debug_exponentiation("dot_num = %d len_num = %d j = %d num_tmp[j] %d\n", dot_num, len_num, j, n_tmp[j]);
						dot_num++;
					} else {
						break;
					}
				}
				debug_exponentiation("dot_num = %d len_now = %d j = %d\n", dot_num, len_now, j);
				for (k = 0; j < len_now && k < len_now - 1; j++, k++)
				{
					if(j == dot_num) {
						cout <<".";
						j--;
						len_now++;
						dot_num = 1000;
						continue;
					}
					cout << n_tmp[j];
					n_tmp[j] = 0;
				}
				cout << endl;
			}
		}
		}
	return 0;
}
