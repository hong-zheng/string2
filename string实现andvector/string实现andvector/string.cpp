//#define _CRT_SECURE_NO_WARNINGS 1
//#include <string>
//#include <iostream>
//using namespace std;
//class String{
//public:
//	// 这种构造函数存在解引用空指针异常
//	//String()
//	//:_str(nullptr)
//	//,_size(0)
//	//, _capacity(0)
//	//{
//	//}
//	String()
//		:_str(new char[16])
//		, _size(0)
//		, _capacity(0)
//	{
//		_str[_size] = '\0';//_size表示有效字符的个数，这个位置中放的是'\0'
//		_capacity = 15;
//	}
//	// 全缺省构造2
//	//String(char* str)
//	//	:_str(str)
//	//	, _size(strlen(str))
//	//	, _capacity(strlen(str))
//	//{
//	//}
//	// 改动2
//	String(const char* str){
//		_size = strlen(str);
//		_str = new char[_size + 1]; //根据大小申请空间，自己复制得有一份，拷贝所得
//		strcpy(_str, str);
//		_capacity = _size;
//	}
//	// 深拷贝版本1
//	// 拷贝构造之后的资源都不同，释放不会出现问题，都会有独立的资源
//	//String(const String& str)
//	//	:_str(new char[str._capacity+1])
//	//	, _size(str._size)
//	//	, _capacity(str._capacity)
//	//{
//	//	// 资源拷贝,此处完成了深拷贝
//	//	strcpy(_str, str._str);
//	//	cout << "String(const String& str)" << endl;
//	//}
//	// 深拷贝版本2
//	// 拷贝构造：现代写法，也是深拷贝，代码复用
//	String(const String& str)
//		// 给初始值，否则临时对象调用析构的时候会出问题
//		:_str(nullptr)
//		, _size(0)
//		, _capacity(0)
//	{
//		String tmp(str._str);
//		Swap(tmp);
//	}
//	// 复制运算符深拷贝的现代写法,代码复用
//	// 拷贝构造，传值的时候进行拷贝构造，创建当前的一个局部对象，
//	// 交换局部对象，调用局部对象的析构函数，释放资源
//	//String& operator=(String str){
//	//	Swap(str);
//	//	return *this;
//	//}
//	// 引用的时候注意只读不可改
//	String& operator=(const String& str){
//		String tmp(str);
//		Swap(tmp);
//		return *this;
//	}
//	//// 深拷贝的交换：效率低，不建议这也写
//	//void SWAP(String& str){
//	//	//拷贝构造
//	//	String tmp = str;
//	//	// 赋值运算符
//	//	str = *this;
//	//	// 赋值运算符
//	//	*this = tmp;
//	//}
//
//	// 并非手动深拷贝，但是完成了深拷贝的内容，实现了深拷贝
//	void Swap(String& str){
//		// 交换，并不会赋值
//		swap(_str, str._str);
//		swap(_size, str._size);
//		swap(_capacity, str._capacity);
//	}
//	//String& operator=(const String& str){
//	//	if (this != &str) // 不是自我进行赋值
//	//	{
//	//		// 开空间
//	//		char* tmp = new char[str._capacity + 1];
//	//		// 内容拷贝
//	//		strcpy(tmp, str._str);
//	//		// 释放原有空间
//	//		delete[] _str;
//
//	//		// 浅拷贝，通过以上资源的拷贝称为深拷贝，赋值运算符
//	//		_str = tmp;
//	//		_size = str._size;
//	//		_capacity = str._capacity;
//	//	}
//	//	return *this;
//	//}
//	// 此处不能用于构造2，释放代码区的内容，delete只能释放堆中的内容
//	~String()
//	{
//		if (_str){
//			delete[] _str;
//			_size = _capacity = 0;
//			_str = nullptr;
//		}
//		cout << "~String()" << endl;
//	}
//
//	// 只有const对象才能直接调用const函数
//	// 返回一个const指针，因此返回的const指针不可以改动
//	const char* c_str() const{
//		return _str;
//	}
//	// 插入一个字符
//	void pushBack(const char& ch){
//		// 检查容量
//		if (_size == _capacity){
//			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
//			reserve(newC);
//		}
//		// 尾插
//		_str[_size] = ch;
//		// 更新size
//		++_size;
//		// 补一个'\0'
//		_str[_size] = '\0';
//	}
//	void reserve(size_t n){
//		if (n > _capacity){
//			// 开空间+1-->存放'\0'
//			char* tmp = new char[n + 1];
//			// 拷贝
//			strcpy(tmp, _str);
//			// 释放原有空间
//			delete[] _str;
//			_str = tmp;
//			// 更新容量
//			_capacity = n;
//		}
//	}
//	// 遍历,实现迭代器
//	// 使用方式类似于指针
//	// 迭代器：一种访问容器元素的机制，体现封装的特性，不需要关注容器的实现细节，就可以直接访问（可读可写）元素
//	// 使用方式：类似于指针的操作
//	// 1、解引用 --> 获取指向位置的内容
//	// 2、位置移动 --> 指向其他位置
//
//	// string : 迭代器，通过指针实现
//	typedef char* iterator;
//	typedef const char* const_iterator;
//	iterator begin(){
//		// 第一个元素的位置
//		return _str;
//	}
//	iterator end(){
//		// 最后一个元素的下一个位置
//		return _str + _size;
//	}
//	// 只读迭代器
//	const_iterator begin() const{
//		//第一个元素的位置
//		return _str;
//	}
//	const_iterator end() const{
//		//最后一个元素的后一个位置
//		return _str + _size;
//	}
//	char& operator[](size_t pos){
//		if (pos < _size){
//			return _str[pos];
//		}
//	}
//	// 返回值是一个const类型，整个函数也是const类型，在里面不能修改成员变量以及调用非const成员函数
//	const char& operator[](size_t pos) const{
//		if (pos < _size){
//			return _str[pos];
//		}
//	}
//	size_t size() const{
//		return _size;
//	}
//	// 尾插一个字符串
//	void Append(const char* str){
//		int len = strlen(str);
//		// 检查容量
//		if (_size + len > _capacity){
//			// 必须要保证所开字符串长度
//			reserve(_size + len);
//		}
//		// 尾插
//		strcpy(_str + _size, str);
//		// 修改size
//		_size += len;
//	}
//	String& operator+=(const char& ch){
//		pushBack(ch);
//		return *this;
//	}
//	String& operator+=(const char* str){
//		Append(str);
//		return *this;
//	}
//	void insert(size_t pos, const char& ch){
//		if (pos > _size) return; // 此时非连续
//		// 检查容量
//		if (_size == _capacity){
//			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
//			reserve(newC);
//		}
//		// 移动元，从后向前移动[pos,_size]，首先移动最右端字符，防止覆盖
//		size_t end = _size;
//		//while (end >= pos){ // 此处有BUG，size_t本就>=0,当pos为0时就产生死循环
//		//	_str[end + 1] = _str[end];
//		//	--end;
//		//}
//		while (end > pos){
//			_str[end] = _str[end - 1];
//			--end;
//		}
//		//插入
//		_str[pos] = ch;
//
//		++_size;
//	}
//	void insert(size_t pos, const char* str){
//		if (pos > _size) return;
//		int len = strlen(str);
//		if (_size + len > _capacity){
//			reserve(_size + len);
//		}
//		// 移动元素 (pos,_size)
//		// size --> size+len , pos -->pos+len
//		size_t end = _size + len;
//		while (end > pos + len - 1){
//			_str[end] = _str[end - len];
//			--end;
//		}
//		// 插入
//		// strcpy 会拷贝'\0'，因此不可用
//		for (int i = 0; i < len; i++){
//			_str[i + pos] = str[i];
//		}
//		_size += len;
//	}
//
//	void resize(size_t n, const char& ch = '\0'){
//		// 当需要的空间小于容量时才会去开空间
//		if (n > _capacity){
//			reserve(n);
//		}
//		// 默认值，类似于默认值，将新开出来的空间赋值
//		if (n > _size){
//			memset(_str + _size, ch, n - _size);
//		}
//		// 更换容量
//		_size = n;
//		// 尾部置\0，表示一个字符串
//		_str[_size] = '\0';
//	}
//	// 删除一个字符，不需要任何参数
//	void popBack(){
//		erase(_size - 1, 1);
//	}
//
//	void erase(size_t pos, size_t len){
//		// 删除一个区间
//		if (pos < _size){
//			// 判断删除的长度是否大于从pos位置开始得剩余字符串的长度
//			if (pos + len >= _size){
//				_size = pos;
//				_str[_size] = '\0';
//			}
//		}
//		else{
//			// 移动元素
//			// 从前至后移动
//			// 此处在 _size 处会将 \0 移过去
//			// 移动元素：[pos+len,size] --> [pos,size-len]
//			for (int i = pos + len; i <= _size; i++){
//				_str[pos++] = _str[i];
//			}
//			_size -= len; // 删除len各元素
//		}
//	}
//
//	size_t find(const char* str){
//		// 查找字符串在本串中的首地址,注意：是第一次出现的首地址
//		char* ptr = strstr(_str, str);
//		if (ptr)
//			return ptr - _str;
//		else
//			return npos;
//
//	}
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//public:
//	static const size_t npos;
//};
//
//const size_t String::npos = -1;
//
//
//// 写在类外少使用，效率不高
//
//ostream& operator<<(ostream& cout , const String& str){
//
//	//cout << str.c_str();
//	//return cout;
//	
//	// 需要输出的字符个数为size，不能遇到\0就结束输出
//	for (const auto& ch : str){
//		cout << ch;
//	}
//
//	// operator
//	for (size_t i = 0; i < str.size(); i++)
//		cout << str[i];
//
//	//迭代器
//	String::const_iterator it = str.begin();
//	while (it != str.end()){
//		cout << *it;
//		++it;
//	}
//	return cout;
//}
//
//String operator+(const String& s, const String& str){
//	String tmp(s);
//	tmp += str.c_str();
//	return tmp;
//}
//
//String operator+(const String& s, const char* str){
//	String ret(s);
//	ret += str;
//	return ret;
//}
//
//String operator+(const String& s, const char& ch){
//	String ret(s);
//	ret += ch;
//	return ret;
//}
//void test(){
//	String s("0123");
//	s.resize(10);
//	cout << s << "end"<<endl;
//
//	string s1("0123");
//	s1.reserve(10);
//	cout << s1 << "end" << endl;
//}
//void test1(){
//	String s("0123");
//	String s1("456");
//	String s2 = s + s1;
//	cout << s2 << endl;
//}
//int madin(){
//	test1();
//	//test();
//	while (1);
//	return 0;
//}