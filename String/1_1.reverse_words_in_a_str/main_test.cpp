/*************************************************************************
	> File Name:        main_test.cpp for reverse words in a str
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月05日 星期五 13时48分22秒
 ************************************************************************/

#include<iostream>
#include <string>
#include "Solution.h"
#include "MyStrProblem.h"

/*
#include <vector>
#include <map>
#include <algorithm>
*/

using namespace std;

void SolutionTest()
{
    //Error test cases from leetcode.com
    Solution solution;
    //Test cases
    {
        string str = "the sky is blue";
        solution.reverseWords(str);
        cout << str << endl;
    }

   {
        string str = "   a   b  ";
        solution.reverseWords(str);
        cout << str << endl;
    }
   {
        string str = "  ";
        solution.reverseWords(str);
        cout << str << endl;
    }

   {
        string str = " 1 ";
        solution.reverseWords(str);
        cout << str << endl;
    }
}

void StrProblemTest()
{
    MyStrProblem msp;
    msp.str_size_test();           //test sizeof(string)
    string s = "hello";
    msp.str_pass_str_pointer(&s);  //test str指针传递    
    string str = "test";
    cout << &str << endl;
    msp.str_pass_str_refer(str);   //test str引用传递
}

int main()
{
    SolutionTest();
    //StrProblemTest();
    return 0;
}
