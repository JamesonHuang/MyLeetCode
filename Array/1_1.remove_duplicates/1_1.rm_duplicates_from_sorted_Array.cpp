/*************************************************************************
	> File Name:        1_1.rm_duplicates_from_sorted_Array.cpp
	> Description:      
                        （1）给一个已排序数组
                        （2）删除重复元素
                        （3）返回删除后数组的长度
                        （4）不能使用额外空间，必须用常量内存
                        （5）A = [1,1,2]   ==>   len = 2, A = [1, 2]
	> Conclusion:
                        （1）注重代码优化
                        （2）简化判定条件
                        （3）快慢游标遍历数组
	> Author:           rh_Jameson
	> Created Time:     2014年12月02日 星期二 12时03分26秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;



//-------------------------------------原始版本：Acceped--------------------------------//

int removeDuplicatesOrigin(int A[],int n)
{
    int p = 0,q = 1;        //游标p，q

    if(n <= 0)              //判空 & 非法
    {
        return 0;
    }
    if(n == 1)              //数组只有一个元素的情况
    {
        return 1;
    }
    while(q != n)          
    {
        if(A[p] != A[q] && p == q - 1)           //A[p]和A[q]不等且p，q相邻时，p，q向前移动一位
        {
            p++;
            q++;
        }
        else if(A[p] != A[q] && p != q - 1)      //A[p]和A[q]不等且p,q不相邻时
        {
            p++;                                 //p向前移动一位
            A[p] = A[q];                         //将数组A下标q的值赋给下标p的值
            q++;                                 //q向前移动一位
        }            
        else if(A[p] == A[q])                      //A[p]和A[q]相等时，q向前移动一位
        {
            q++;
        }
    }
    return p + 1;                                //返回处理后数组的长度
}

//-------------------------------------优化版本：Acceped--------------------------------//
int removeDuplicatesOptimize(int A[],int n)
{
    int p = 0,q = 1;        //游标p，q

    if(n <= 0)              //判空 & 非法
    {
        return 0;
    }
    while(q != n)          
    {
        if(A[p] != A[q])           //A[p]和A[q]不等时，p，q向前移动一位
        {
            
            A[++p] = A[q];         //巧妙优化，p，q相邻，A[q] = A[q],p,q不相邻，A[p] = A[q] 
            q++;
        }
        else if(A[p] == A[q])      //A[p]和A[q]相等时，q向前移动一位
        {
            q++;
        }
    }
    return p + 1;                  //返回处理后数组的长度
}

//-------------------------------------优化版本2：Acceped--------------------------------//
int removeDuplicatesOptimize(int A[],int n)
{
    int p = 0,q = 1;        //游标p，q

    if(n <= 0)              //判空 & 非法
    {
        return 0;
    }
    while(q != n)          
    {
        if(A[p] != A[q])           //A[p]和A[q]不等时，p，q向前移动一位
        {     
            A[++p] = A[q];         //巧妙优化，p，q相邻，A[q] = A[q],p,q不相邻，A[p] = A[q] 
        }
        q++;
    }
    return p + 1;                  //返回处理后数组的长度
}




//==================================参考代码1：Accepted==================================//

/*
 * 该参考代码与上面优化版本的代码思路一直，不再赘释
 */
int removeDuplicatesLeetcode1(int A[],int n)
{
    if(n <= 0)
    {
        return 0;
    }
    int index = 0;
    for(int i = 1; i < n; ++i)
    {
        if( A[index] != A[i] )
        {
            A[++index] = A[i];
        }
    }
    return index + 1;

}


//==================================参考代码2：Accepted==================================//

/*
 * 使用STL distance(),unique()方法
 */
int removeDuplicatesLeetcode2(int A[],int n)
{
    return distance(A, unique(A, A + n) );
}



int main()
{
    //removeDuplicates
    int A[3] = {1,1,2};
    cout << removeDuplicatesLeetcode2(A, 3) << endl;

 
}
