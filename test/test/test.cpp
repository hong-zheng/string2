#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test(){
	vector<char> vc;

	string s = "abcdefghij";
	vector<char> v5(s.begin(),s.end());

	vector<char> v6(v5); // ��������

	vector<int> v(10, 5);
}

void t2(){
	string s = "hi kl hsd";
	vector<char> v(s.begin(), s.end());

	vector<char>::iterator it = v.begin();

	while (it != v.end()){
		cout << *it << endl;
		++it;
	}
	// ��Χfor
	for (auto& ch : v){
		cout << ch << " ";
	}

	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	vector<char>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend()){
		cout << *rit << " ";
		++rit;
	}
}

template<class T>
void printV(const vector<T>& v){
	vector<T>::const_iterator it = v.cbegin();
	while (it != v.cend()){
		cout << *it << " ";
		++it;
	}
}
//vector ��reserve�������������ֻ����������
// �ռ䷢���仯�ᵼ�µ�������ʧЧ

void test3(){

	vector<int> v;
	v.insert(v.begin(), 1);
	v.insert(v.begin(), 5,0);

	int a[] = { 12, 23, 4, 5, 678, 9 };
	v.insert(v.begin(), a+2,a+5);
}
int main(){
	test();

	while (1);
	return 0;
}

/*

class String{
public:
	// ���ֹ��캯�����ڽ����ÿ�ָ���쳣
	//String()
	//:_str(nullptr)
	//,_size(0)
	//, _capacity(0)
	//{
	//}
	String()
		:_str(new char[16])
		, _size(0)
		, _capacity(0)
	{
		_str[_size] = '\0';//_size��ʾ��Ч�ַ��ĸ��������λ���зŵ���'\0'
		_capacity = 15;
	}
	// ȫȱʡ����2
	//String(char* str)
	//	:_str(str)
	//	, _size(strlen(str))
	//	, _capacity(strlen(str))
	//{
	//}
	// �Ķ�2
	String(const char* str){
		_size = strlen(str);
		_str = new char[_size + 1]; //���ݴ�С����ռ䣬�Լ����Ƶ���һ�ݣ���������
		strcpy(_str, str);
		_capacity = _size;
	}
	// ����汾1
	// ��������֮�����Դ����ͬ���ͷŲ���������⣬�����ж�������Դ
	//String(const String& str)
	//	:_str(new char[str._capacity+1])
	//	, _size(str._size)
	//	, _capacity(str._capacity)
	//{
	//	// ��Դ����,�˴���������
	//	strcpy(_str, str._str);
	//	cout << "String(const String& str)" << endl;
	//}
	// ����汾2
	// �������죺�ִ�д����Ҳ����������븴��
	String(const String& str)
		// ����ʼֵ��������ʱ�������������ʱ��������
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}
	// ���������������ִ�д��,���븴��
	// �������죬��ֵ��ʱ����п������죬������ǰ��һ���ֲ�����
	// �����ֲ����󣬵��þֲ�����������������ͷ���Դ
	//String& operator=(String str){
	//	Swap(str);
	//	return *this;
	//}
	// ���õ�ʱ��ע��ֻ�����ɸ�
	String& operator=(const String& str){
		String tmp(str);
		Swap(tmp);
		return *this;
	}
	//// ����Ľ�����Ч�ʵͣ���������Ҳд
	//void SWAP(String& str){
	//	//��������
	//	String tmp = str;
	//	// ��ֵ�����
	//	str = *this;
	//	// ��ֵ�����
	//	*this = tmp;
	//}

	// �����ֶ�����������������������ݣ�ʵ�������
	void Swap(String& str){
		// �����������ḳֵ
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//String& operator=(const String& str){
	//	if (this != &str) // �������ҽ��и�ֵ
	//	{
	//		// ���ռ�
	//		char* tmp = new char[str._capacity + 1];
	//		// ���ݿ���
	//		strcpy(tmp, str._str);
	//		// �ͷ�ԭ�пռ�
	//		delete[] _str;

	//		// ǳ������ͨ��������Դ�Ŀ�����Ϊ�������ֵ�����
	//		_str = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;
	//	}
	//	return *this;
	//}
	// �˴��������ڹ���2���ͷŴ����������ݣ�deleteֻ���ͷŶ��е�����
	~String()
	{
		if (_str){
			delete[] _str;
			_size = _capacity = 0;
			_str = nullptr;
		}
		cout << "~String()" << endl;
	}
	const char* c_str() const{
		return _str;
	}
	// ����һ���ַ�
	void pushBack(const char& ch){
		// �������
		if (_size == _capacity){
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		// β��
		_str[_size] = ch;
		// ����size
		++_size;
		// ��һ��'\0'
		_str[_size] = '\0';
	}
	void reserve(size_t n){
		if (n > _capacity){
			// ���ռ�+1-->���'\0'
			char* tmp = new char[n + 1];
			// ����
			strcpy(tmp, _str);
			// �ͷ�ԭ�пռ�
			delete[] _str;
			_str = tmp;
			// ��������
			_capacity = n;
		}
	}
	// ����,ʵ�ֵ�����
	// ʹ�÷�ʽ������ָ��
	// ��������һ�ַ�������Ԫ�صĻ��ƣ����ַ�װ�����ԣ�����Ҫ��ע������ʵ��ϸ�ڣ��Ϳ���ֱ�ӷ��ʣ��ɶ���д��Ԫ��
	// ʹ�÷�ʽ��������ָ��Ĳ���
	// 1�������� --> ��ȡָ��λ�õ�����
	// 2��λ���ƶ� --> ָ������λ��

	// string : ��������ͨ��ָ��ʵ��
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin(){
		// ��һ��Ԫ�ص�λ��
		return _str;
	}
	iterator end(){
		// ���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}
	// ֻ��������
	const_iterator begin() const{
		//��һ��Ԫ�ص�λ��
		return _str;
	}
	const_iterator end() const{
		//���һ��Ԫ�صĺ�һ��λ��
		return _str + _size;
	}
	char& operator[](size_t pos){
		if (pos < _size){
			return _str[pos];
		}
	}
	// ����ֵ��һ��const���ͣ���������Ҳ��const���ͣ������治���޸ĳ�Ա�����Լ����÷�const��Ա����
	const char& operator[](size_t pos) const{
		if (pos < _size){
			return _str[pos];
		}
	}
	size_t size() const{
		return _size;
	}
	// β��һ���ַ���
	void Append(const char* str){
		int len = strlen(str);
		// �������
		if (_size + len > _capacity){
			// ����Ҫ��֤�����ַ�������
			reserve(_size + len);
		}
		// β��
		strcpy(_str + _size, str);
		// �޸�size
		_size += len;
	}
	String& operator+=(const char& ch){
		pushBack(ch);
		return *this;
	}
	String& operator+=(const char* str){
		Append(str);
		return *this;
	}
	void insert(size_t pos, const char& ch){
		if (pos > _size) return; // ��ʱ������
		// �������
		if (_size == _capacity){
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		// �ƶ�Ԫ���Ӻ���ǰ�ƶ�[pos,_size]�������ƶ����Ҷ��ַ�����ֹ����
		size_t end = _size;
		//while (end >= pos){ // �˴���BUG��size_t����>=0,��posΪ0ʱ�Ͳ�����ѭ��
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		while (end > pos){
			_str[end] = _str[end - 1];
			--end;
		}
		//����
		_str[pos] = ch;
		++_size;
	}
	void insert(size_t pos, const char* str){
		if (pos > _size) return;
		int len = strlen(str);
		if (_size + len > _capacity){
			reserve(_size + len);
		}
		// �ƶ�Ԫ�� (pos,_size)
		// size --> size+len , pos -->pos+len
		size_t end = _size + len;
		while (end > pos + len - 1){
			_str[end] = _str[end - len];
			--end;
		}
		// ����
		// strcpy �´��'\0'����˲�����
		for (int i = 0; i < len; i++){
			_str[i + pos] = str[i];
		}
		_size += len;
	}

	void resize(size_t n, const char& ch = '\0'){
		//�ж��Ƿ���Ҫ����
		if (n > _capacity){
			reserve(n);
		}
		if (n > _size){
			memset(_str + _size, ch, n - _size);
		}

		// ���_size����Ϊn
		_size = n;
		_str[_size] = '\0';
	}
	void popBack(){
		//if (_size > 0 ){
		//	--_size;
		//	_str[_size] = '\0';
		//}
		erase(_size - 1, 1);
	}

	void erase(size_t pos, size_t len){
		// ɾ��һ��������ַ�����ɾ��һ���Ӵ�
		if (pos < _size){
			// �ж�ɾ���ĳ����Ƿ���ڴ�posλ�ÿ�ʼ��ʣ���ַ�������
			if (pos + len >= _size){
				_size = pos;
				_str[_size] = '\0';
			}
			else{
				// ��ǰ����ƶ����ƶ�Ԫ��[pos+len,size] --> [pos,size-len]
				// ��Ҫ�ƶ�ʣ���Ԫ�أ���ɾ����Ԫ��
				// ����_size���Ͳ����ٲ���0
				for (int i = pos + len; i <= _size; i++){
					_str[pos] = _str[i];
				}
				_size -= len;
			}
		}
	}
	size_t find(const char* str){
		char* ptr = strstr(_str, str);
		if (ptr){
			return ptr - _str;
		}
		else{
			return npos;
		}
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};
const size_t String::npos = -1;
String operator+(const String& s, const String& str){
	String ret(s);
	ret += str.c_str();
	return ret;
	//String tmp(s);
	//for (const auto& ch : str){
	//	tmp.pushBack(ch);
	//}
	//return tmp;
}
//String operator+(const String& s, const char* str){
//	
//}
//String operator+(const String& s, const char& ch){
//	String tmp(s);
//	tmp.pushBack(ch);
//	return tmp;
//}

//ostream& operator<<(ostream& _cout, const String& str){
//	//_cout << str.c_str();
//	// ��Ҫ������ַ�����Ϊsize����������\0�ͽ������
//	for (const auto& ch : str)
//		_cout << ch;
//	return _cout;
//}

void test(){

}
int main(){
	string s;
	//s.pop_back();
	test();
	while(1);
}
void staticnum(){
	static int num = 0 ;
	++num;
	cout << num << endl;
}

int maisn(){
	//int cnt = 10;
	//while (--cnt) staticnum();

	int n=1;
	static int m;
	cout << n <<endl<< m << endl;
	while (1);
	return 0;
}*/