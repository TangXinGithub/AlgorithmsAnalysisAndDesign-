// FibonacciSequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<ctime>
using namespace std;



long fibonacci(long n)
{
	if (n <= 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

//尾递归 https://blog.csdn.net/mengxiangjia_linxi/article/details/78158819
 unsigned long FibonacciTailRecursive(unsigned long n, unsigned  long first, unsigned long second)
{
	if (n == 1) return first;
	if (n == 2) return second;
	return FibonacciTailRecursive(n - 1, second, second + first);
}

void main() {

	time_t t;


	unsigned long n;  //无符号版本和有符号版本的区别就是无符号类型能保存2倍于有符号类型的数据，
	while (scanf_s("%d", &n) != EOF)
	{
		long start = time(&t);

		cout << FibonacciTailRecursive(n,1,1) << endl;

		time_t s;
		long end = time(&s);
		cout << "time:" << end - start << "s" << endl;
	}
}