/*************************************************************************
	> File Name:        Solution for rotated Str
	> Description:      （1）问题描述：
                            A.给定一字符串
                            B.将串的前若干个元素移到串的尾部
                            C."abcdefg",2  ==> "cdefgab"

	> Conclusion:           
                        （1）旋转字符串策略一：暴力移位（By一个字符）
                            A.A[0]存入临时变量tmp
                            B.数组其余元素放到数组后面
                            C.旋转几位，就执行几次A,B

                        （2）三步反转法
                            A.要旋转的位置将串分为两段
                            B.将这两段分别进行反转
                            C.对整个字符串反转
          
	> Author:           rh_Jameson
	> Created Time:     2014年12月07日 星期日 14时09分38秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * By One Var
     */
    string strRotateByOneVar(string str,int cnt)
    {
        int len = str.size();           //串长
        
        /*cnt小于等于0,或大于等于串长,
         *直接返回原字符串
         */
        if(cnt <= 0 || cnt >= len){
            return str;
        }
        char tmp;                       //临时字符
        while(cnt--){
            tmp = str[0];
            for(int i = 0; i < len; ++i){
                str[i] = str[i + 1];
            }
            str[len - 1] = tmp;
        }
        return str;
    }
     
    /*
     * 三步反转法
     */
    string strRotate(string str,int cnt)
    {
        int len = str.size();           //串长
        
        /*cnt小于等于0,或大于等于串长时,
         *直接返回原字符串
         */
        if(cnt <= 0 || cnt >= len){
            return str;
        }
        reverse(0, cnt - 1, str);
        reverse(cnt, len - 1, str);
        reverse(0, len - 1, str);        

        return str;
    }
    //反转函数
    string reverse(int p, int q,string& str)
    {
        char tmp;
        while(p < q){
            tmp = str[p];
            str[p++] = str[q];
            str[q--] = tmp;
        }
        return str;
    }
};
