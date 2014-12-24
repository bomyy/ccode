#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0, j = 0, len1 = 0, len2 = 0, len3 = 0, temp = 0,flag = 1;
	char strNum1[1000],strNum2[1000],strNum3[2000];
	int nNum[1000]={0};

	printf("第一个大数1:\n");
	gets(strNum1);//输入
	printf("第二个大数2:\n");
	gets(strNum2);//输入

	len1 = strlen(strNum1);//长度
	len2 = strlen(strNum2);
	len3 = len1+len2+1;
	temp = len3;

	//相乘-----原理见分析
	for (i = len2-1; i >= 0; --i)//strNum2
	{
		temp = (--len3);
		for (j = len1-1; j >= 0; --j)//strNum1
		{
			nNum[temp--] += (strNum2[i]-'0') * (strNum1[j]-'0');
		}
	}

	len3 = len1+len2+1;

	//进位---原理见分析
	for (i = len3; i > 0; --i)
	{
		while (nNum[i]>9)
		{
			nNum[i-1]+=nNum[i]/10;
			nNum[i] = nNum[i]%10;
		}
	}

	//输出结果
	printf("相乘后的结果:\n");
	for (i = 0; i < len3; ++i)
	{
		if (nNum[i] == 0 && flag == 1)//舍去前面没必要的0
		{
			continue;
		}
		else
		{
			flag = 0;
		}
		printf("%d",nNum[i]);
	}
	printf("\nlen3 = %d\n", len3);
	return 0;
}
