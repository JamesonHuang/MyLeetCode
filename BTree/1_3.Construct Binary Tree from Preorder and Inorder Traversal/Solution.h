/*************************************************************************
	> File Name:        Solution for Reverse Words in a String
	> Description:      
                        （1）根据前序和中序序列构建二叉树
                        （2）根据中序和后序序列构建二叉树
间
    > Conclusion:           

	> Author:           rh_Jameson
	> Created Time:     2014年12月07日 星期日 17时10分20秒
 ************************************************************************/
#include<string>
#include<cctype>

#include <algorithm> 
#include <functional> 
#include <locale>

using namespace std;

class Solution {
public:
/*======================先序 & 中序构建二叉树：Accepted,160ms======================*/
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        int pre_idx = 0;
        return buildTreeRecursion(preorder, inorder, pre_idx);
    }
    
    TreeNode *buildTreeRecursion(vector<int> &preorder, vector<int> &inorder, int &pre_idx){
        //初始化根结点
        int root_value = preorder[pre_idx];
        TreeNode *root = new TreeNode(root_value);
        //只有根结点的情况
        if(preorder.size() == 1 && preorder.size() == inorder.size() && 
            preorder[pre_idx] == inorder[pre_idx]){
                return root;
            }
        //遍历中序序列，查找根结点位置
        int iter = 0;
        while(iter < inorder.size() && inorder[iter] != root_value){
            ++iter;
        }
        //非法序列处理
        if(iter == inorder.size() && inorder[iter] != root_value){
            return NULL;
        }
        //创建左子树
        vector<int> tmp_in(inorder.begin(), inorder.begin() + iter);
        if(!tmp_in.empty() ){
            ++pre_idx;
            root->left = buildTreeRecursion(preorder, tmp_in, pre_idx);
        }
        tmp_in.clear();     //清除
        //创建右子树
        tmp_in.assign(inorder.begin() + iter + 1, inorder.end() );
        if(!tmp_in.empty() ){
            pre_idx++;
            root->right = buildTreeRecursion(preorder, tmp_in, pre_idx);
        }
        return root;
    }
};
