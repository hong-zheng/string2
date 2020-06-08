#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <vector>
using namespace std;


void test(){
	vector<char> vc;// 也可以管理字符，字符串
	// 与string区别：没有拼接操作，没有\0结尾的特殊字符

	// 显式实例化，泛型参数
	vector<int> vi;
	vector<string> vs;

	vector<int> v4(10, 5);// 10个5
	string s2 = "211425142";
	// vector不包括\0
	vector<char> v5(s2.begin(), s2.end());

	vector<char> v6(v5);
}

void test2(){

	string s("1234567890");
	vector<char> v(s.begin(), s.end());

	vector<char>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()){
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<char>::iterator it = v.begin();
	while (it != v.end()){
		cout << *it << " ";
		++it;
	}

	cout << endl;
	for (char& ch : v){
		cout << ch << " ";
		ch = 'b';
	}
	cout << endl;

	for (size_t i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template<class T>
void printVec(const vector<T>& v){
	vector<T>::const_iterator cit = v.begin();
	while (cit != v.cend()){
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	//vector<T>::const_reverse_iterator crit = v.crbegin();
	//while (crit != v.crend()){
	//	cout << *crit << " ";
	//	++crit;
	//}
}
void test3(){
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v(a,a+10);

	char a2[10] = "12567890";
	vector<char> v1(a2, a2 + 10);
	string a3[] = {"122","sef","ewrfs"};

	vector<string> v2(a3, a3 + 3);
	printVec(v);
	printVec(v1);
	printVec(v2);

	v.resize(15);
	v2.resize(15);
	v1.resize(20);
}

void test4(){
	/*
		resize(n,val) : 如果不给val参数，则使用默认值：内置类型-->0，自定义类型-->调用无参构造
		vector : 增容，如果是空，容量为0
				PJ版中增容按照大于1.5进行 ，SGI一般是2倍
	*/
	// 增容
	vector<int> v;
	size_t sz = v.size();
	size_t cap = v.capacity();
	cout << cap << endl;
	for (int i = 0; i < 200; i++){
		v.push_back(i);
		if (cap != v.capacity()){
			cap = v.capacity();
			cout << cap << endl;
		}
	}
}
void test5(){
	/*
		reserve:只增加容量，不减少容量
	*/
	vector<int> v;
	size_t cap = v.capacity();
	v.reserve(100);
	cap = v.capacity();
	v.reserve(10);
	cap = v.capacity();

	int* pi = v.data(); // 返回首指针

}

void test6(){
	vector<int> v;
	// release : 断言就失效
	// 这些只是在调试版本才会有用,Debug版本
	// 越界抛出异常
	int ret= v[0]; // 断言 ，assert、
	//越界抛出异常
	int ret1 = v.at(0);// 抛异常
}

void test7(){
/*
	迭代器失效：
	1、空间发生了变化，就回导致原来的迭代器失效：push_back,insert,reserve,resize,assign
	2、位置错位，删除元素等，都会使迭代器失效：erase
	迭代器指向的位置，空间被释放或者变成一个不可访问的位置
	
	因此迭代器在使用的时候需要重新赋值
*/
	vector<int> v;
	v.insert(v.begin(), 1);
	vector<int>::iterator it = v.begin(); //1
	cout << *it << endl;//1
	v.insert(v.begin(), 5,1);
	//cout << *it << endl;//? UB
	int a[] = { 12, 3, 4, 5, 6 };
	v.insert(v.begin(), a,a+3);//[)
	//cout << *it << endl;//? UB
	printVec(v);
	v.resize(2);
	it = v.begin();
	//it = v.erase(it); // 获取删除的返回值
	//it = v.erase(it);  获取删除的返回值,如果此处删除的是最后一个元素，要注意返回的是下一个元素，则为nullptr，解引用则会出错
	it = v.insert(it, 0);

	// 解决方式
	// 重新获取迭代器
	// 非删除接口:begin,end
	// erase：直接获取返回值，其返回值为指向被删除下一个元素的迭代器
	// 潜在问题：如果传入的迭代器为最后一个元素的迭代器，获取的返回值也是一个不能访问的位置
	// 换言之：不能解引用对返回值
}
void test8(){
	vector<int> v;
	v.insert(v.begin(), 10, 5);
	vector<int>::iterator it = v.begin();
	cout << "before erase:>" << endl;
	printVec(v);
	while (it != v.end()){
		it = v.erase(it);
	}
	cout << "after erase:>" << endl;
	printVec(v);
}

void test9(){
	vector<int> v(5, 2);
	vector<int> v2(5, 1);
	swap(v, v2); // 内部调用vector的成员函数swap完成
	v.swap(v2);
}

class B{
public:
	B(int a, int b)
		:_a(a)
		, _b(b)
	{

	}
private:
	int _a;
	int _b;
};

void test10(){
	vector<B> v;
	B b(1, 2);
	v.insert(v.begin(), b);
	v.emplace(v.begin(), 3, 4);
	v.emplace(v.begin(), B(5, 6)); // 构造+插入

	// emplace: 安放
	B b2(4,5);
	v.push_back(b2);
	v.emplace_back(b);
	v.emplace_back(7, 7); // 构造+插入+函数的功能就包括创建对象

	vector<bool> vbool;

}
int main(){
	test8();
	//test7();
	//test4();
	//test3();
	//test2();
	//test();
	while (1);
	return 0;
}