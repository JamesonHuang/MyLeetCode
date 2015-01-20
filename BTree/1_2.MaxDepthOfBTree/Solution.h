/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述
                            A.求二叉树最大深度
               
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
    int maxDepth(TreeNode *root) {
        /* 递归形式*/
        int depth = 0;
        if(root != NULL){
            int l_child_depth = maxDepth(root->left);
            int r_child_depth = maxDepth(root->right);
            return l_child_depth >= r_child_depth ? l_child_depth + 1 : r_child_depth + 1;
        }
        return depth;
        
};

#endif
