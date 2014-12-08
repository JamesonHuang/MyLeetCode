/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月05日 星期五 13时48分22秒
 ************************************************************************/

#include<iostream>
#include "Solution.h"

/*
#include <vector>
#include <string>
#include <map>
#include <algorithm>
*/

using namespace std;

int main()
{
    Solution solution;
        //Test cases
    {
        int a[] = {1, 1, 1, 2, 2, 3};
        int n = solution.removeDuplicates(a, sizeof(a) / sizeof(a[0]));
        cout << n << endl;
    }
    {
        int a[] = {1, 1, 3, 2};
        int n = solution.removeDuplicates(a, sizeof(a) / sizeof(a[0]));
        cout << n << endl;
    }
    {
        int a[] = {};
        int n = solution.removeDuplicates(a, sizeof(a) / sizeof(a[0]));
        cout << n << endl;
    }
    //Error test cases from leetcode.com
    return 0;
}
