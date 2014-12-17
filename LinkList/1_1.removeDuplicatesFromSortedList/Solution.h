/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述
                            A.已排序链表
                            B.移除重复节点
	> Conclusion:          
                        （1）策略一：
                            A.链表排序
                            B.通过快慢指针消除重复元素
                        
                        （2）策略二：
                            A.哈希表储存元素
                            B.遍历链表
                            C.遇到重复元素，从链表中删去.
    
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

//=================哈希实现：空间O（M）,时间O（N）====================//
    void removeDuplicatesFromLinklistByHash(ListNode *head){
        //判空
        if(head == NULL){
            cout << "空链表" << endl;
        }
        //哈希实现
        map<int, int> unique_map;
        ListNode *p = head, *tmp = new ListNode(0);
        ListNode *q = head->next;
        unique_map[p->val] = p->val;
        
        for(q = head->next; q != NULL; q = q->next){
            if(unique_map.count(q->val)){
                p->next = q->next;
                tmp = q;
                q = p;
                delete tmp;
            }
            else{
                unique_map[q->val] = q->val;
                p = p->next;
            }
        }
//===================while形式====================//
/*
        while(q != NULL){
            if(unique_map.count(q->val)){
                p->next = q->next;
                tmp = q;
                q = q->next;
                delete tmp;
            }
            else{
                unique_map[q->val] = q->val;
                p = p->next;
                q = q->next;
            }
        }
*/
    }
//=================================两个指针实现版=======================================//
    ListNode *deleteDuplicates(ListNode *head) {        //头结点是第一个结点
        if(head == NULL){
            return NULL;
        }
        ListNode *pre = head, *cur,*tmp = new ListNode(0);
       
        for(cur = head->next; cur; cur = cur->next){
            if(cur->val == pre->val){
                pre->next = cur->next;
                delete cur;             //不安全,待优化
            }
            else{
                pre = cur;
            }
        }
        return head;
        
    }
};

#endif
