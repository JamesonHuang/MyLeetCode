/*************************************************************************
	> File Name:        1_2.remove_duplicatesII.cpp
	> Description:      
                        （1）给一个已排序数组
                        （2）删除重复次数大于2的元素
                        （3）返回删除后数组的长度
                        （4）不能使用额外空间
                        （5）A = [1,1,1,2,2,3] ==> A.len = 5,A = [1,1,2,2,3]

	> Conclusion:
                        （1）条件选==还是！=，代码复杂度可能天差地别
	> Author:           rh_Jameson
	> Created Time:     2014年12月03日 星期三 13时23分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

//============================原始版本：Accepted,88 ms==================================//
int removeDuplicates(int A[],int n)
{
    int count = 1;                  //计数变量
    int index = 0;                  //慢游标
    
    if(n <= 0)                      //判空，非法
    {
        return 0;
    }

    for(int i = 1; i < n; ++i) 
    {
        /*慢游标指向值不等于快游标指向值时*/
        if(A[index] != A[i])       
        {
            A[++index] = A[i];          //慢游标前进一位，将快游标指向值赋给慢游标指向值
            if(count != 1)              //重置count
            {
                count = 1;
            }
        }

        /*慢游标指向值等于快游标指向值时*/
        else if(count == 1)             //第一次出现重复的处理
        {
            count++;
            A[++index] = A[i];
            
        }
        else                            //多次重复的处理
        {
            count++;
        }
    }
    return index + 1;
}

//============================优化条件语句版本：Wrong==================================//
int removeDuplicatesOpt(int A[],int n)
{
    int count = 1;                  //计数变量
    int index = 0;                  //慢游标
    
    if(n <= 0)                      //判空，非法
    {
        return 0;
    }

    for(int i = 1; i < n; ++i) 
    {
        if(A[index] == A[i])
        {
            count++;
            if(count == 2)
            {
                A[++index] == A[i];
            }
        }
        else
        {
            A[++index] = A[i];
            count = 1;
        }
    }
    return index + 1;
}



int main()
{
    int A[4] ={1,1,1,1};
//    int A[6] = {1,1,1,2,2,3};
    cout << removeDuplicatesOpt(A, 4);
    return 0;
}
