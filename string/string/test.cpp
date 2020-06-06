#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;



void test(){

	string s;
	s.push_back('a');//"a"
	s.append(2, 'b');
	s.append("cde");

	string s2;
	s2.append(s);

	string s4;
	s4 += '1';
	s4 += "234";
}

void test2(){
	string s = "1234567890";
	s.replace(3, 5, "a"); // "123a90"

	string s1 = "hong";
	s.swap(s1);
	cout << s << ":" << s1<<endl;
	swap(s1,s);
	cout << s << ":" << s1 << endl;
}

void testfind(){
	string s;
	s = "abc defc def ghij klmnw xyzmnvw xyz";
	size_t pos1 = s.find('d'); // 正向查找,找到第一个位置结束
	size_t rpos = s.find('x');// 反向查找，找到第一个位置结束
	
	string file1 = "test.tar.gz.zip";
	size_t pos = file1.rfind('.');
	string subs = file1.substr(pos + 1, file1.size()-pos+1);
	cout << subs << endl;
// find 找不到返回一个npos,静态变量
	cout << string::npos << endl;//4G 表示找不到，默认一个字符串的大小小于4G
	// substr 结合find来使用
	// substr(pos,len) : 如果len大于从pos到结束位置的字符串长度，则把剩余末尾的元素都截取掉
	size_t postr = s.find("c");
	cout << postr << endl;
}

// 关系符重载
void testoperator(){
	string s = "9";
	string s2 = "123";
	string s3 = "1234";
	bool ret = s > s2;
	cout << ret << endl;
	ret = s2 > s3;
	cout << ret << endl;
	ret = s > s3;
	cout << ret << endl;
}

void testinputotput(){
	string s;
	//cout << s;
	//getline(cin, s);
	
	// 指定分隔符
	getline(cin, s, ',');
	getline(cin, s, ',');
	getline(cin, s, ',');
	getline(cin, s, ',');
	cout << s << endl;
}
void main(){

	testinputotput();
	// C++ 中的字符串是一个封装的字符串类型string,而C中的字符串是裸奔的
	//testoperator();
	//testfind();
	//test2();

	while(1);
}
