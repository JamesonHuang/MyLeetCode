/*************************************************************************
	> File Name:        problem_str.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月08日 星期一 14时42分48秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class MyStrProblem{
public:
    void str_pass_str_pointer(string *s);
    void str_size_test();
    void str_pass_str_refer(string &s);
};

void MyStrProblem::str_pass_str_refer(string &s){
    cout << &s << endl;
    cout << s << endl;
}

/*
（6）传递指针字符串（void fun（string* s））
    A.传递的实际是字符串地址的地址
    B.建议改为引用，即string& s
*/
void MyStrProblem::str_pass_str_pointer(string *s){
    string str = "bbbbb";
    s = &str;
    cout << s << endl;
    cout << *s << endl;
}
/*
 *（4）sizeof(string)与sizeof（int）不同
    A.int分配在栈，string分配空间在堆
    B.string的地址存在栈中
    C.sizeof(string)是string地址的大小
    D.sizeof(string)不同编译器/系统，大小不同
        a.64位linux，g++：8
        b.32位win，vc6.0：16
*/
void MyStrProblem::str_size_test(){
    int i = 19;
    double d = 12.2;
    float f = 11.222;
    char c = 'c';

    string str = "abcddddddddddddddddddef";
    
    cout << "int类型大小: " <<sizeof(i) << endl;            //4
    cout << "double类型大小: " <<sizeof(d) << endl;         //8
    cout << "float类型大小: " << sizeof(f) << endl;         //4
    cout << "char类型大小: " << sizeof(c) << endl;          //1
    
    cout << "=============================" << endl;
    cout << "string类型大小：" << sizeof(str) << endl;      //8
}
