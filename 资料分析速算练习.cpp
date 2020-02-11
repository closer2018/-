/*资料分析练习速算软件by closer2018*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cctype>
using namespace std;
/*******************************************************************************/
class RapidCalculation {
private:
	double a_, b_;//a_是基期，b_是现期
	double r_, x_;//r_是增长率，x_是增长量
public:
	RapidCalculation();
	double GetA() { return a_; }
	double GetB() { return b_; }
	double GetX() { return x_; }
	double GetR() { return r_; }
	bool Check(double &a, double &x) {//检查是否答案正确
		double tempa = (abs(a - a_)) / a_;
		double tempx = (abs(x - x_)) / x_;
		if (tempa <= 0.03&& tempx <= 0.06)
			return true;
		else
			return false;
	}
};
/*******************************************************************************/
void Quick1();
void Quick2();
void Quick3();
/*******************************************************************************/
int main()
{
	cout << "你好！欢迎来到资料分析速算练习系统." << endl;
	cout << "值为0或者输入q,离开程序。" << endl;
	while (1) {
		srand((unsigned)time(0));
		int i = (rand() % 3) + 1;
		switch (i) {
		case 1:Quick1();
			break;
		case 2:Quick2();
			break;
		case 3:Quick3();
			break;
		default:cout << "程序错误";
			return 0;
		}
	}

	return 0;
}
/*******************************************************************************/
//构造函数
RapidCalculation::RapidCalculation() {
	srand((unsigned)time(0));
	b_ = (double)(rand() % 999) + 1; //现期的范围是0-999;
	int i = (rand() % 2);
	if (i == 1)
		r_ = ((double)(rand() % 99) + 1) / 100;//基期的范围是0-99;
	else
		r_ = -((double)(rand() % 99) + 1) / 100;
	a_ = b_ / (1 + r_);
	x_ = b_ - a_;
}
//速算模块1
void Quick1() {
	cout << endl;
	RapidCalculation obj;
	cout.precision(4);
	cout << "现期B是:" << obj.GetB() << " , ";
	cout << "增长率r是:" << obj.GetR() * 100 << "%" << endl;
	cout << "请输入你算到的基期A和增长量X:";
	double A, X;
	clock_t start = clock();
	cin >> A;
	if (A == 0) exit(0);
	if (A == 'q') exit(0);
	while (cin.get() != '\n')continue;//吃掉回车
	cin >> X;
	clock_t end = clock();
	while (cin.get() != '\n')continue;//吃掉回车
	if (obj.Check(A, X))
		cout << "恭喜你,答案正确!" << endl;
	else
		cout << "对不起,答案错误!" << endl;
	cout << "基期A和增长量X分别是:" << obj.GetA() << " , " << obj.GetX() << endl;
	cout << "你花费的秒数是：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	cout << endl;
}
//速算模块2
void Quick2() {
	cout << endl;
	RapidCalculation obj;
	cout.precision(4);
	cout << "基期A是:" << obj.GetA() << " , ";
	cout << "现期B是:" << obj.GetB() << endl;
	cout << "请输入你算到的A/B的答案(百分制):";
	double answer;
	double tempr = (1.0 / (1.0 + obj.GetR())) * 100;
	clock_t start = clock();
	cin >> answer;
	if (answer == 0) exit(0);
	if (answer == 'q') exit(0);
	while (cin.get() != '\n')continue;//吃掉回车
	clock_t end = clock();
	if (abs((answer - tempr) / tempr) <= 0.03)
		cout << "恭喜你,答案正确!" << endl;
	else
		cout << "对不起,答案错误!" << endl;
	cout << "A/B的答案(百分制)是:" << obj.GetA() * 100 / obj.GetB() << "%" << endl;
	cout << "你花费的秒数是：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	cout << endl;
}
//速算模块3
void Quick3() {
	cout << endl;
	srand((unsigned)time(0));
	int ar[4];
	for (size_t i = 0; i < 4; ++i) {
		ar[i] = (rand() % 999) + 1;
	}
	double temp1 = (double)ar[0] / ar[1];
	double temp2 = (double)ar[2] / ar[3];
	cout << "比较 " << ar[0] << "/" << ar[1] << " 和 ";
	cout << ar[2] << "/" << ar[3] << "的大小." << endl;
	cout << "请输入大于小于号:";
	clock_t start = clock();
	char ch;
	cin >> ch;
	if (ch == 'q') exit(0);
	if (ch == '0') exit(0);
	while (cin.get() != '\n')continue;//吃掉回车
	clock_t end = clock();
	if (temp1 >= temp2) {
		if (ch == '>')
			cout << "恭喜你,答案正确!" << endl;
		else
			cout << "对不起,答案错误!" << endl;
	}
	else {
		if (ch == '<')
			cout << "恭喜你,答案正确!" << endl;
		else
			cout << "对不起,答案错误!" << endl;
	}
	cout << ar[0] << "/" << ar[1] << "是" << temp1 << endl;
	cout << ar[2] << "/" << ar[3] << "是" << temp2 << endl;
	cout << "你花费的秒数是：" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	cout << endl;
}