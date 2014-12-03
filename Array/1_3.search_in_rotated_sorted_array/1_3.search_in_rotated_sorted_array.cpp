/*************************************************************************
	> File Name:        1_3.search_in_rotated_sorted_array.cpp
	> Description:      
	                    （1）给定一旋转数组（数组分两段，各段均已排序）
                        （2）段边界点不确定
                        （3）给一关键字，查询数组中是否有该关键字
                        （4）有则返回下标，无则返回-1
                        （5）假设数组中无重复元素
                        （6）A = [4,5,6,7,0,1,2]
    > Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月03日 星期三 16时16分33秒
 ************************************************************************/

#include<iostream>
using namespace std;


int binary_search(int A[], int &max, int &min, int &mid, int target)
{
    if(target > A[mid])
    {
        min = mid;
    }
    else
    {
        max = mid;
    }
    mid = (min + max) / 2;
}

int search(int A[],int n,int target)
{
    if(n <= 0)
    {
        return -1;
    }
    
    int front = 0;
    int rear = n - 1;
    int mid = ( front + rear ) / 2;
    
    /*获取边界值leftMax*/
    while(A[mid] < A[mid - 1] || A[mid] < A[mid + 1])
    {
        if(A[mid] >= A[front])
        {
            front = mid;
        }
        else
        {
            rear = mid;
        }
        mid = (front + rear) / 2;
    }
    
    //初始化边界值
    int leftMin = 0, leftMax, rightMin, rightMax = n-1;
    leftMax = mid;
    rightMin = leftMax + 1;
    mid = 0;

    if(target > A[leftMin])                //折半查找需封装
    {
        mid = (leftMin + leftMax) / 2;
        while( (target != A[mid] && mid != leftMin) || (target != A[mid] && mid != leftMax) )  //条件语句待优化
        {
            binary_search(A, leftMax,leftMin,mid,target);
        }
    }
    else if(target == A[leftMin])
    {
        return leftMin;
    }
    else
    {
        mid = (rightMin + rightMax) / 2;
        while( (target != A[mid] && mid != rightMin) || (target != A[mid] && mid != rightMax)  )
        {
            binary_search(A, rightMax, rightMin, mid, target);
        } 
    
    }
    if(target != A[mid])
    {
        return -1;
    }
    else
    {
        return mid;
    } 

}

int main()
{
    int A[7] = {4,5,6,7,0,1,2};
    cout << search(A, 7, 2) << endl;
    return 0;
}

