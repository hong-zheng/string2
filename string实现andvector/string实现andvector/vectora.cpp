#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <vector>
using namespace std;


void test(){
	vector<char> vc;// Ҳ���Թ����ַ����ַ���
	// ��string����û��ƴ�Ӳ�����û��\0��β�������ַ�

	// ��ʽʵ���������Ͳ���
	vector<int> vi;
	vector<string> vs;

	vector<int> v4(10, 5);// 10��5
	string s2 = "211425142";
	// vector������\0
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
		resize(n,val) : �������val��������ʹ��Ĭ��ֵ����������-->0���Զ�������-->�����޲ι���
		vector : ���ݣ�����ǿգ�����Ϊ0
				PJ�������ݰ��մ���1.5���� ��SGIһ����2��
	*/
	// ����
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
		reserve:ֻ��������������������
	*/
	vector<int> v;
	size_t cap = v.capacity();
	v.reserve(100);
	cap = v.capacity();
	v.reserve(10);
	cap = v.capacity();

	int* pi = v.data(); // ������ָ��

}

void test6(){
	vector<int> v;
	// release : ���Ծ�ʧЧ
	// ��Щֻ���ڵ��԰汾�Ż�����,Debug�汾
	// Խ���׳��쳣
	int ret= v[0]; // ���� ��assert��
	//Խ���׳��쳣
	int ret1 = v.at(0);// ���쳣
}

void test7(){
/*
	������ʧЧ��
	1���ռ䷢���˱仯���ͻص���ԭ���ĵ�����ʧЧ��push_back,insert,reserve,resize,assign
	2��λ�ô�λ��ɾ��Ԫ�صȣ�����ʹ������ʧЧ��erase
	������ָ���λ�ã��ռ䱻�ͷŻ��߱��һ�����ɷ��ʵ�λ��
	
	��˵�������ʹ�õ�ʱ����Ҫ���¸�ֵ
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
	//it = v.erase(it); // ��ȡɾ���ķ���ֵ
	//it = v.erase(it);  ��ȡɾ���ķ���ֵ,����˴�ɾ���������һ��Ԫ�أ�Ҫע�ⷵ�ص�����һ��Ԫ�أ���Ϊnullptr��������������
	it = v.insert(it, 0);

	// �����ʽ
	// ���»�ȡ������
	// ��ɾ���ӿ�:begin,end
	// erase��ֱ�ӻ�ȡ����ֵ���䷵��ֵΪָ��ɾ����һ��Ԫ�صĵ�����
	// Ǳ�����⣺�������ĵ�����Ϊ���һ��Ԫ�صĵ���������ȡ�ķ���ֵҲ��һ�����ܷ��ʵ�λ��
	// ����֮�����ܽ����öԷ���ֵ
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
	swap(v, v2); // �ڲ�����vector�ĳ�Ա����swap���
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
	v.emplace(v.begin(), B(5, 6)); // ����+����

	// emplace: ����
	B b2(4,5);
	v.push_back(b2);
	v.emplace_back(b);
	v.emplace_back(7, 7); // ����+����+�����Ĺ��ܾͰ�����������

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