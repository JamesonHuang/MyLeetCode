/*************************************************************************
	> File Name:        1_1.problem1_strAppend_const_char*.cpp
	> Description:      
                        （1）使用string的append方法
                        （2）char* vs const char*
    > Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月02日 星期二 17时18分14秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//=====================char* vs const char*======================//
void char_int_pointer()
{
    char* cp = new char(10);
    
    //不报错 
    for(int i = 0; i < 10; ++i )
    {
        *(cp + i) = 'a';
    }
    for(int i = -1; i < 10; ++i )
    {
        *(cp + i) = 'd';
    }
   
    //g++或者较新的gcc中，char*这样赋值,会报警告
    //cp = "hello";               //赋值警告，cp是char*类型变量，"hello"是string常量
    //cp = "abcde";               //不报错
    //*(cp + 1 ) = 'o';           //报错,段错误，修改常量！  
    

    cout << cp << endl;
    
    //g++中如此声明木有警告！
    const char* ccp = new char(10);
    ccp = "ccp_hello";
    cout << ccp << endl;

    
}

//========================使用string的append方法========================//
string strAppend()
{
    const char* ch = new char(10);
    ch = "hello";
    string str = "str_";
    str.append( ch );
    return str;
}


int main()
{
    cout << strAppend() << endl;
    char_int_pointer(); 
    return 0;
}
