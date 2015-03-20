/*************************************************************************
	> File Name:        Solution for Reverse Words in a String
	> Description:      

                        （1）根据中序和后序序列构建二叉树
间
    > Conclusion:           

	> Author:           rh_Jameson
 ************************************************************************/
#include<string>
#include<cctype>

#include <algorithm> 
#include <functional> 
#include <locale>

using namespace std;

class Solution {
public:
/*======================后序 & 中序构建二叉树：Accepted,160ms======================*/
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty())
            return NULL;
        //初始化根结点
        int post_size = postorder.size();
        int root_value = postorder[post_size - 1];
        TreeNode *root = new TreeNode(root_value);
        //只有根结点的情况
        if(postorder.size() == 1 && postorder.size() == inorder.size() && 
            root_value == inorder[0]){
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
        vector<int> tmp_po(postorder.begin(), postorder.begin() + iter);
        if(!tmp_in.empty()){
            root->left = buildTree(tmp_in, tmp_po);
        }
        //创建右子树
        tmp_in.clear();
        tmp_in.assign(inorder.begin() + iter + 1, inorder.end());
        tmp_po.clear();
        tmp_po.assign(postorder.begin() + iter, postorder.end() - 1);
        if(!tmp_in.empty()){
            root->right = buildTree(tmp_in, tmp_po);
        }
        
        return root;
    }
};
