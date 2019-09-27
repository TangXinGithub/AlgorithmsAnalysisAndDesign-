
#include <iostream>
using namespace std;





int nineNine(int n) { //传来的是位数，如99是2位

	return  (n * pow(10, n - 1));
	//返回位数对应的个数，如 999999    就是按公式算
}

void arrayofoperating(int count, int numbercount[]) {  //数组加；因为是9999,所以每个都加

	for (size_t i = 0; i < 10; i++)
	{
		numbercount[i] = numbercount[i] + count;
	}


}

int getcurrentyweisu(int page, int n) {  //获得当前位数
	int weisu = 0;
	while (n != 0)
	{
		if (n == 1)weisu = page % 10;
		page = page / 10;
		n--;
	}
	return weisu;
}



void bole2(int start, int end, int c[]) {

	if (end == 0) c[0]++;
	else

		for (int i = start; i <= end; i++) {
			int tmp = i;
			while (tmp) {
				c[tmp % 10]++;
				tmp /= 10;
			}
		}


}


void  wei(int n, int numbercount[], int p) {

	//循环每一位数
	int h = n;
	for (size_t i = n; i > 2; i--)
	{
		int howmany = getcurrentyweisu(p, n);//获取当前位数的值

		if (howmany > 0)
		{
			arrayofoperating(howmany * nineNine(n - 1), &numbercount[0]);// 还要乘以howmany，多少个999



			//要加上的数字
			int j = n;

			for (size_t i = 1; i <= howmany; i++)
			{


				if (i == howmany)
				{
					int   w = (pow(10, j - 1));
					numbercount[i] = numbercount[i] + p % w + 1;// 因为会增加9开头的都算9, +1是9000

				}
				else {

					numbercount[i] = numbercount[i] + pow(10, n - 1);   //13100 12100 11100  这里的，2，1 ，0 是出现1000次的 ，而3 是根据后面的数

				}



			}


			n--;//下一位数

		}
		else
		{
			numbercount[howmany] -= pow(10, n - 1);//零开头出现了1000次是多的

			int   w = (pow(10, n - 1));
			numbercount[0] += p % w;              //零也要加上后面数
			numbercount[0]++;//本身为零加1
			n--;//后面位数都是零的,直接减一，不影响后面
		}

	}
	//最后两位数
	int howmany = getcurrentyweisu(p, 2);//获取当前位数的值
	if (howmany == 0)numbercount[0] -= 10;

	bole2(1, p % 100, &numbercount[0]);


	//C++中^符号表示：按位异或运算符。
}

void bole(int n) {//暴力法

	int c[10] = { 0 };


	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp) {
			c[tmp % 10]++;
			tmp /= 10;
		}
	}
	for (int i = 0; i <= 9; i++) {
		cout << c[i] << endl;
	}



}






int main()
{
	int n = 0;//位数

	int c[10] = { 0 };
	int page;
	int jiu = 9;
	cin >> page;
	int p = page;
	while (page != 0)
	{

		page /= 10;
		n++;

	}

	if (n == 1) { //位数小于3的直接暴力法,小于其它的也行，因为数小没有什么区别

		bole(p);

	}
	else
	{

		wei(n, &c[0], p);  //位数拆分, 大于三位数的

		//输出
		for (int i = 0; i <= 9; i++) {
			cout << c[i] << endl;
		}


	}

	cout << endl;
	bole(p); //对比正确与否，可注释


}
