/*************************************************************************
	> File Name:        Solution for Reverse Words in a String
	> Description:      
                        （1）问题描述：
                            A.給一字符串
                            B.将字符串中的单词逆转
                            C."the sky is blue" ==> "blue is sky the"
                            D.不使用额外空间
    > Conclusion:           
                        （1）策略一：反转法
                            A.思路：
                                a.每个单词都反转一次
                                b.反转整个字符串
                            B.消除头部空格
                            C.消除尾部空格
                            D.消除word间重复的空格
                            E.反转每个单词，最后反转整个字符串
                        （1.5）优化策略：
                            A.思路：同一
                            B.消除重复元素
                            C.判断首尾有无空格，有则删之
                            D.反转每个单词，最后反转整个字符串
                        
                        （2）C++获取字符串长度：
                            A.两种方式:str.length()/str.size()
                            B.使用C版本的string头文件，则调用strlen()
                            C.返回字符串实际长度，即不包括结束符

                        （3）C++去除首尾空格：
                            A.C++中没有相关的trim()方法
                            B.使用stl的相关函数实现
                            C.使用<ctype.h>(<cctype>)中的isspace遍历实现

                        （4）sizeof(string)与sizeof（int）不同
                            A.int分配在栈，string分配空间在堆
                            B.string的地址存在栈中
                            C.sizeof(string)是string地址的大小
                            D.sizeof(string)不同编译器/系统，大小不同
                                a.64位linux，g++：8
                                b.32位win，vc6.0：16
                        
                        （6）传递指针字符串（void fun（string* s））
                            A.传递的实际是字符串地址的地址
                            B.建议改为引用，即string& s

                        （7）string.erase()使用
                            A.erase(pos):       删除pos处的一个字符
                            B.erase(pos,n):     删除pos处开始的n个字符
                            C.erase(first,last) 删除first到last之间的字符
                            D.first,last,pos为迭代器
	> Author:           rh_Jameson
	> Created Time:     2014年12月07日 星期日 17时10分20秒
 ************************************************************************/
#include<string>
#include<cctype>

#include <algorithm> 
#include <functional> 
#include <locale>

using namespace std;

class Solution {
public:

    //反转函数
    void reverse(int p, int q, string& s){
        char tmp;
        while(p < q){
            tmp = s[p];
            s[p++] = s[q];
            s[q--] = tmp;
        }
    }

//======================反转法原始版：Accepted,44ms======================//
    void reverseWordsOrigin(string &s) {
        int p = 0, q = p;
        
        //去除首部空格
        while(s[0] == ' '){
            if(s == ""){
                break;
            }
            s.erase(s.begin());

        }
        //去除尾部空格
        while(s[s.size() - 1] == ' '){
            if(s == ""){
                break;
            }
            s.erase(s.end() - 1);
        }
        //去除单词间重复空格
        while(p < s.size()){
            if(s[p] == ' ' && s[p] == s[p + 1]){
                s.erase(s.begin() + p);
                continue;
            }
            p++;
        }
        p = 0;
        int len = s.size(); 
        //逐个单词反转
        while(q < len){
            if(s[q] != ' '){
                if(q == len - 1){
                    reverse(p, q, s);
                }
                q++;
            }
            else{
                reverse(p, q - 1, s);
                p = ++q;

            }
        }
        //对整个字符串进行反转
        reverse(0, len - 1, s);
    }

//======================反转法首尾消除优化版：Accepted,44ms======================//

    // trim from start
    inline string &ltrim(string &s) {
            s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
            return s;
    }
    // trim from end
     inline string &rtrim(string &s) {
            s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
            return s;
    }
    // trim from both ends
    inline string &trim(string &s) {
            return ltrim(rtrim(s));
    }
    //main
    void reverseWordsOpt(string &s) {
        int p = 0, q = p;        
        //去除首尾空格
        trim(s);
        //去除单词间重复空格
        while(p < s.size()){
            if(s[p] == ' ' && s[p] == s[p + 1]){
                s.erase(s.begin() + p);
                continue;
            }
            p++;
        }
        p = 0;              //重置索引p
        int len = s.size(); 
        //逐个单词反转
        while(q < len){
            if(s[q] != ' '){
                if(q == len - 1){
                    reverse(p, q, s);
                }
                q++;
            }
            else{
                reverse(p, q - 1, s);
                p = ++q;

            }
        }
        //对整个字符串进行反转
        reverse(0, len - 1, s);
    }



//======================反转法重复消除优化版：Accepted,44ms======================//
    void reverseWords(string &s) {
        int p = 0, q = p;        
        //去除单词间重复空格
        while(p < s.size()){
            if(s == "" ){
                break;
            }
            if(s[p] == ' ' && s[p] == s[p + 1]){
                s.erase(s.begin() + p);
                continue;
            }
            p++;
        }

        if(s[0] == ' '){
            s.erase(s.begin());
        }
        if(s[s.size() - 1] == ' '){
            s.erase(s.end() - 1);
        }
        p = 0;                      //重置p
        
        int len = s.size(); 
        //逐个单词反转
        while(q < len){
            if(s == ""){
                break;
            }
            if(s[q] != ' '){
                if(q == len - 1){
                    reverse(p, q, s);
                }
                q++;
            }
            else{
                reverse(p, q - 1, s);
                p = ++q;

            }
        }
        //对整个字符串进行反转
        reverse(0, len - 1, s);
    }
};
