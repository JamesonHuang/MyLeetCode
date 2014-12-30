/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月19日 星期五 20时41分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include "Solution.h"
#include "LinkList.h"
using namespace std;

int main()
{
     Solution solution;
     //Error test cases from leetcode.com
     //Test cases
     /*{ 
        ListNode *head = new ListNode(1);
        ListNode *res = solution.deleteDuplicates(head);
        Linklist *list = new Linklist();
        list->printLinkList(head); 
     }*/
     {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(2);
        ListNode *res = solution.deleteDuplicates(head);
        Linklist *list = new Linklist();
        list->printLinkList(head); 
     }
    return 0;
}
