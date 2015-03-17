/*************************************************************************
	> File Name:        main_test for rotated Str
	> Description:  
                        测试左旋转字符串
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月07日 星期日 14时08分01秒
 ************************************************************************/

#include<iostream>
#include <string>

#include "Solution.h"
/*
#include <vector>
#include <map>
#include <algorithm>
*/

using namespace std;

int main()
{
    Solution solution;
        //Test cases
    {
        string str = "abcdefg";
        cout << solution.strRotate(str,2) << endl;
    }

    {
        string str = "1234567";
        cout << solution.strRotate(str,3) << endl;
    }

    {
        string str = "12";
        cout << solution.strRotate(str,1) << endl;
    }
    {
        string str = "12 345";
        cout << solution.strRotate(str,1) << endl;
    }    
    return 0;
}
