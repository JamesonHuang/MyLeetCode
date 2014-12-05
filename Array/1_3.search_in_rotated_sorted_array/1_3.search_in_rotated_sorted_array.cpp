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
                        （1）策略：     
                            A.折半获取边界最大值
                            B.判断关键字在哪一段顺序序列上
                            C.在目标顺序序列上折半查找关键字

                        （2）折半查找算法实现需注意的细节及优化
                            A.两种情况[0,n),[0,n]
                            B.注意（min + max）/ 2溢出问题
                            C.折半改变min或max时，防止出现死循环

                        （3）该策略复杂度为logn，但要两次折半来
                             实现，非最优解法
                        
                        （4）一次折半优化策略：
                            A.折半mid,比较A[mid]和target
                            B.mid将数组分两段，判断target是在哪一段
                            C.target没找到或first与last未交错，循环A,B
	> Author:           rh_Jameson
	> Created Time:     2014年12月03日 星期三 16时16分33秒
 ************************************************************************/

#include<iostream>
using namespace std;


//====================两次折半版本：Accepted，16 ms=========================//

//折半查找关键字
int binary_search(int A[], int &max, int &min, int target)
{
    int mid;
    while(min <= max)
    {
        //mid = (min + max) / 2;                //常规折半
        mid = min + (max - min) / 2;            //防止（min + max）溢出
        if(target > A[mid])
        {
            min = mid + 1;
        }
        else if(target < A[mid])
        {
            max = mid - 1;
        }
        else
        {
            return mid;
        }        
    }
    return -1;
}

//折半获取边界最大值leftMax
int binary_getMax(int A[], int &front, int &rear)
{
    int mid;

    while(front <= rear)
    {
        //mid = (front + rear) / 2;
        mid = front + (rear - front) / 2;               //防止溢出        
        //找到最大值，直接跳出循环
        if( A[mid] > A[mid - 1] && A[mid] > A[mid + 1] ||
            front == rear - 1 && A[mid] > A[mid + 1] ||
            front == mid && rear == mid )
        {
            break;
        }
        //mid非最大值，进行折半
        if(A[mid] >= A[front])
        {
            front = mid + 1;
        }
        else
        {
            rear = mid - 1;
        }
    }
    return mid;
}

int search(int A[],int n,int target)
{
    if(n <= 0)                                          //处理非法
    {
        return -1;
    }
    
    int front = 0;
    int rear = n - 1;
    
    //初始化边界值
    int leftMin = 0, leftMax, rightMin, rightMax = n-1;
    
    leftMax = binary_getMax(A, front, rear);               //折半获取边界最大值
    rightMin = leftMax + 1;
    
    //判断目标值在哪一段顺序序列上
    if(target > A[leftMin])                //折半查找需封装
    {
        return binary_search(A, leftMax,leftMin,target);    //折半查找左侧顺序序列
    }    
    else if(target == A[leftMin])
    {
        return leftMin;
    }
    else
    {
       return binary_search(A, rightMax, rightMin, target); //折半查找右侧顺序序列
    }
}



//==========================一次折半版本：Accepted,40ms===============================//
//折半mid,比较target，A[mid]
int searchOnce(int A[], int n, int target)
{
    int first = 0, mid, last = n - 1;
    while(first <= last)                                //first，last未交错，继续循环
    {
        mid = first + (last - first) / 2;
        if(target == A[mid])
        {
            return mid;
        }
        if(target == A[first])
        {
            return first;
        }
        else if(A[mid] >= A[first])
        {
            if(target > A[first] && target < A[mid])
            {
                last = mid - 1;    
            }
            else
            { 
                first = mid + 1;
            }                   
        }
        else
        {
            if(target < A[first] && target > A[mid])
            {
                first = mid + 1;
            }
            else
            {
                last = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    //int A[7] = {4,5,6,7,0,1,2};
    int A[2] = {3,1};

    cout << searchOnce(A, 2, 1) << endl;
    return 0;
}

