/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述
                            A.给定两条已排序链表
                            B.合并为一条已排序的新链表
	> Conclusion:          

    > Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 11时36分52秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<ctime>
#include "LinkList.h"

using namespace std;


class Solution {
    
public:

//===============================自敲代码：AC=================================//
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *new_list = new ListNode(-1), *head = new_list, *tmp;
        while(l1 || l2){
            if(!l1){
                new_list->next = l2;
                break;
            }
            if(!l2){
                new_list->next = l1;
                break;
            }
            if(l1->val < l2->val){
                tmp = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                tmp = new ListNode(l2->val);
                l2 = l2->next;
            }
            new_list->next = tmp;
            new_list = new_list->next;
        }
        return head->next;
    }

 //===============================参考代码=================================//
    ListNode *mergeTwoListsByOthers(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr)   return l2;
        if(l2 == nullptr)   return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        for(; l1 != nullptr && l2 != nullptr; p = p->next){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }
            else{
                p->next = l1;
                l1 = l1->next;
            }
        }
        p->next = (l1 != nullptr ? l1 : l2);
        return dummy.next;
    }   

};

#endif
