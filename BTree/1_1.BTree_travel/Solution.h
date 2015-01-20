/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述
                            A.二叉树前、中、后、层次遍历
               
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
    vector<int> res;
    //前序遍历
    vector<int> preorderTraversal(TreeNode *root) {
        /* 递归形式 */
		if(root != NULL){
			res.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		return res;
        
        
        /* 栈的实现形式 */
        stack<TreeNode*> SForBTree;
        while(root != NULL || !SForBTree.empty() ){
            if(root != NULL){
                res.push_back(root->val);
                SForBTree.push(root);
                root = root->left;
            }
            else{
                root = SForBTree.top();
                SForBTree.pop();
                root = root->right;
            }
        }
        return res;
        
        
        /* 栈实现形式二*/
        stack<TreeNode*> SForBTree;
        TreeNode *p = root, *tmp;
        if(p != NULL)
            SForBTree.push(p);
        while(!SForBTree.empty() ){
            p = SForBTree.top();
            res.push_back(p->val);
            SForBTree.pop();

            if(p->right){
                SForBTree.push(p->right);
            }
            if(p->left){
                SForBTree.push(p->left);
            }
        }
        return res;
        
        /* Morris遍历 */
    	TreeNode *cur = root, *pre;
    	while(cur){
    		if(!cur->left){
    			res.push_back(cur->val);
    			cur = cur->right;
    		}
    		else{
    			pre = cur->left;
    			while(pre->right != NULL && pre->right != cur){
    				pre = pre->right;
    			}
    			if(pre->right == NULL){
    				pre->right = cur;
    				res.push_back(cur->val);
    				cur = cur->left;
    			}
    			else{
    				pre->right = NULL;
    				cur = cur->right;
    			}
    		}
    	}
    	return res;
    }

    //中序遍历
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        
        /* 递归形式 */
        if(p != NULL){
				inorderTraversal(p->left);
				res.push_back(p->val);				
				inorderTraversal(p->right);
		}
        return res;
        
        /* 栈的实现形式 */
        stack<TreeNode*> SForBTree;
		while(p != NULL || !SForBTree.empty() ){
			if(p != NULL){
				SForBTree.push(p);
				p = p->left;
			}
			else{
				p = SForBTree.top();
				res.push_back(p->val);
				SForBTree.pop();
				p = p->right;
			}
		}
		return res;
		
		//morris遍历
		TreeNode *cur = p, *pre;
		while(cur){
			if(cur->left == NULL){
				res.push_back(cur->val);
				cur = cur->right;
			}
			else{
				pre = cur->left;
				while(pre->right != NULL && pre->right != cur){
					pre = pre->right;
				}
				if(pre->right == NULL){
					pre->right = cur;
					cur = cur->left;
				}
				else{
					pre->right = NULL;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;
    }

    //后序遍历
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *p = root;
       
        /*递归形式实现*/
        if(p != NULL){
            postorderTraversal(p->left);
            postorderTraversal(p->right);
            res.push_back(p->val);
        }
        return res;
        
        
        /* 栈形式实现，该代码应该可以转作非递归销毁二叉树 */
        stack<TreeNode* > SForBTree;
        TreeNode *pre;
        while(p || !SForBTree.empty() ){
            if(p){
                SForBTree.push(p);
                p = p->left;
            }
            else{
                p = SForBTree.top();
                if(p->right && p->right != pre ){   //有右子树且右子树未被访问过
                    p = p->right;
                }
                else{
                    res.push_back(p->val);
                    pre = p;
                    SForBTree.pop();
                    p = NULL;           //!!!须置空，否则陷入死循环
                                        //反复出栈 / 入栈
                }
            }
        }
        return res;
        
        //双栈形式实现
        stack<TreeNode*> s1, s2;
        if(p != NULL)   s1.push(p);
        while(!s1.empty()){
            p = s1.top();
            s1.pop();
            s2.push(p);

            if(p->left){
                s1.push(p->left);
            }
            if(p->right){
                s1.push(p->right);
            }
        }
        while(!s2.empty()){
            p = s2.top();
            res.push_back(p->val);
            s2.pop();
        }
        return res;
    }

    //层次遍历
    vector<vector<int> > levelOrder(TreeNode *root) {
    	TreeNode *p = root, *tmp;
    	vector<int> level;
    	queue<TreeNode*> cur, next;
    	if(p != NULL){
    	    cur.push(p);
    	}
    	while(cur.size() ){
    		while(cur.size()){
    		    tmp = cur.front();
    		    cur.pop();
    		    level.push_back(tmp->val);
    		    
    		    if(tmp->left != NULL){
    			    next.push(tmp->left);
        		}
        		if(tmp->right != NULL){
        			next.push(tmp->right);
        		}
    		}
		    res.push_back(level);
		    level.clear();
		    swap(next, cur);
    		
    	}
    	return res;
    }

    //层次遍历II
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	TreeNode *p = root, *tmp;
    	vector<int> level;
    	queue<TreeNode*> cur, next;
    	if(p != NULL){
    	    cur.push(p);
    	}
    	while(cur.size() ){
    		while(cur.size()){
    		    tmp = cur.front();
    		    cur.pop();
    		    level.push_back(tmp->val);
    		    
    		    if(tmp->left != NULL){
    			    next.push(tmp->left);
        		}
        		if(tmp->right != NULL){
        			next.push(tmp->right);
        		}
    		}
		    res.push_back(level);
		    level.clear();
		    swap(next, cur);
    		
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
};

#endif
