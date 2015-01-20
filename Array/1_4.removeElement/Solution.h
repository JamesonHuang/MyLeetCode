/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述：
                            A.给定一个数组和指定值
                            B.删除数组中元素值等于指定值的元素
	> Conclusion:
                        
	> Author:           rh_Jameson
	> Created Time:     2014年12月14日 星期日 22时24分29秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
//#include<hash_map>
using namespace std;

class Solution {
public:

//=====================rmELement：Accepted=====================//‘
    
    int removeElement(int A[], int n, int elem) {
        int p_slow = 0;
        for(int p_fast = 0; p_fast < n; ++p_fast){
            if(A[p_fast] != elem){
                A[p_slow++] = A[p_fast];
            }
        }
        return p_slow;
    }


};

#endif
