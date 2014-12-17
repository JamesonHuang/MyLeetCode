/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 11时35分56秒
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
     Linklist link_list_struct;
     //Error test cases from leetcode.com
     //Test cases
    
    ListNode *head = new ListNode(0);
    //构建链表
    link_list_struct.constructLinkList(head);
    link_list_struct.printLinkList(head);
    //消除重复元素
    //solution.removeDuplicatesFromLinklist(head);
    solution.deleteDuplicates(head);
    link_list_struct.printLinkList(head);
    
    return 0;
}
