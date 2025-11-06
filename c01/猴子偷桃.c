#include <stdio.h>
//猴子吃桃公式：昨天的数量 = 2*（今天的余量 +　１）

int ReNum(int day)
{
	if (day == 10) return 1;
	if (day > 0 && day < 10){
		return 2 * (ReNum(day + 1) + 1);
	}else{
		printf("输入错误，天数需不大于10，不小于0！！！");
		return 0;
	}
}

int main()
{
#if 0 //while循环
	
	int sum1 = 1;
	int i = 10;
	while(i != 0)
	{
		printf("第%d天桃子数量为：%d\n",i,sum1);
		sum1 = 2*(sum1 + 1);
		i--;
	}
#endif
#if 0 //for循环
	
	int sum = 1;
	for(int i=10; i>=1; i--)
	{
		printf("第%d天桃子数量为：%d\n",i,sum);
		sum = 2*(sum + 1);
	}
	//printf("第1天桃子数量为：%d\n",sum);
#endif

#if 0 //递归
	printf("第1天桃子数量：%d",ReNum(1));
#endif
	return 0;
}