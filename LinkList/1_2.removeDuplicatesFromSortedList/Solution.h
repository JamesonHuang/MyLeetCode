/*************************************************************************
	> File Name:        Solution.h
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月19日 星期五 19时56分30秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include "LinkList.h"
using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head){
       if(!head){
            return NULL;
        }
        bool flag = false;
        ListNode *pre = new ListNode(0), *p_slow = head, *p_fast;
        pre->next = head;
        for(p_fast = head->next; p_fast != NULL; p_fast = p_fast->next){
            if(p_slow->val != p_fast->val){
                if(!flag){
                    pre = p_slow;
                    p_slow = p_slow->next;
                }
                else{
                    pre->next = p_fast;
                    if(p_slow == head);
                        head = p_fast;
                    }
                    p_slow = p_fast;
                    flag = false;
                }
            }
            else{
                flag = true;
            }
        }
        if(flag == true){
            pre->next = p_fast;
            if(p_slow == head){
                return pre->next;
            }
        }
        return head; 
    }
};

#endif
