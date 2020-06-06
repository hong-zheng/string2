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
	size_t pos1 = s.find('d'); // �������,�ҵ���һ��λ�ý���
	size_t rpos = s.find('x');// ������ң��ҵ���һ��λ�ý���
	
	string file1 = "test.tar.gz.zip";
	size_t pos = file1.rfind('.');
	string subs = file1.substr(pos + 1, file1.size()-pos+1);
	cout << subs << endl;
// find �Ҳ�������һ��npos,��̬����
	cout << string::npos << endl;//4G ��ʾ�Ҳ�����Ĭ��һ���ַ����Ĵ�СС��4G
	// substr ���find��ʹ��
	// substr(pos,len) : ���len���ڴ�pos������λ�õ��ַ������ȣ����ʣ��ĩβ��Ԫ�ض���ȡ��
	size_t postr = s.find("c");
	cout << postr << endl;
}

// ��ϵ������
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
	
	// ָ���ָ���
	getline(cin, s, ',');
	getline(cin, s, ',');
	getline(cin, s, ',');
	getline(cin, s, ',');
	cout << s << endl;
}
void main(){

	testinputotput();
	// C++ �е��ַ�����һ����װ���ַ�������string,��C�е��ַ������㱼��
	//testoperator();
	//testfind();
	//test2();

	while(1);
}
