//
// Created by 春江花朝秋月夜 on 2024/4/4.
//
#include "../cunion.h"

//遍历二叉树
class Tree {
public:
    /**
     * 对当前节点执行前序遍历操作直到尾节点为空为止,中左右
     * @param cur 当前节点
     * @param vec 输出vector
     */
    void travelFrontSal(TreeNode *cur, vector<int> &vec) {
        //确定终止条件
        if (cur == NULL) return;
            //确定单层递归的逻辑
        else {
            vec.push_back(cur->val);
            travelFrontSal(cur->left, vec);
            travelFrontSal(cur->right, vec);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorderRes;
        travelFrontSal(root, preorderRes);
        return preorderRes;
    }

    //中序遍历
    void travelMidSal(TreeNode *cur, vector<int> &ves) {
        //终止条件
        if (cur == NULL) {
            return;
        }
            //左中右;
        else {
            travelMidSal(cur->left, ves);
            ves.push_back(cur->val);
            travelMidSal(cur->right, ves);
        }
    }

    vector<int> midOrderTraversal(TreeNode *root) {
        vector<int> preorderRes;
        travelMidSal(root, preorderRes);
        return preorderRes;
    }

    //后序遍历
    void travelBehindSal(TreeNode *cur, vector<int> &ves) {
        //终止条件
        if (cur == NULL) {
            return;
        }
            //左右中
        else {
            travelBehindSal(cur->left, ves);
            travelBehindSal(cur->right, ves);
            ves.push_back(cur->val);
        }
    }

    vector<int> behindOrderTraversal(TreeNode *root) {
        vector<int> preorderRes;
        travelMidSal(root, preorderRes);
        return preorderRes;
    }

    /**
     * 对每一层干什么事情清楚
     * @param cur
     * @param n
     * @param deep
     */
    void dfs(TreeNode *cur, int n, int deep) {
        if (deep == n) return;
        else {
            cur->left = new TreeNode(cur->val / 2);
            cur->right = new TreeNode(cur->val / 2);
            dfs(cur->left, n, deep + 1);
            dfs(cur->right, n, deep + 1);
        }
    }

    void zeros(TreeNode *cur, int n, int deep) {
        if (n == deep) return;
        else {
            cur->left = new TreeNode(0);
            cur->right = new TreeNode(0);
            zeros(cur->left, n, deep + 1);
            zeros(cur->right, n, deep + 1);
        }
    }

    vector<int> createTree(int n) {
        TreeNode *root = new TreeNode(1 << (n - 1));
//        dfs(root, n, 1);
        zeros(root, n, 1);
        vector<int> resTree = preorderTraversal(root);
        return resTree;
    }
    //递归遍历办法，以中序遍历为例  左中右
    vector<int> travelMidSalWithStack(TreeNode *root){
        TreeNode *cur=root;
        stack<TreeNode *> tempStack;//容器栈
        vector<int> result;//按序存储结果
        while (cur||!tempStack.empty()){
            if (cur!=NULL){
                tempStack.push(cur);
                cur=cur->left;//遍历左边
            }
            else{
                cur=tempStack.top();
                tempStack.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()<=1)
        {
            res.push_back(strs);
            return res;
        }
        /**
         * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
           输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
         */
        unordered_map<string ,vector<int>> characterMap;//eat-[32,26,34] tea -[26,32,34]
        for (int i = 0; i < strs.size(); ++i) {
            string word=strs[i];
            vector<int> characterIndex;
            for (int j = 0; j < word.size(); ++j) {
                characterIndex.push_back(word[i]);
            }
            characterMap.insert(pair<string ,vector<int>>(word,characterIndex));
        }
        int left=0;
        int right=characterMap.size();

        vector<string> mid;
        for (int i = left; i < right-1; ++i) {
            vector<int> leftIndex=characterMap.at(strs[left]);
            vector<int> rightIndex=characterMap.at(strs[left+1]);
            sort(leftIndex.begin(),leftIndex.end());
            sort(rightIndex.begin(),rightIndex.end());
            if (leftIndex.size()!=rightIndex.size())continue;
            else{
                int cnt=0;
                while (cnt<leftIndex.size()){
                    if (leftIndex[cnt]!=rightIndex[cnt])break;
                }
                res.push_back({strs[left],strs[left+1]});
            }
        }
        return res;
    }
};

//int main() {
//    Tree *tree;
//    vector<int> res = tree->createTree(3);
//    for (int item: res) {
//        cout << item << " ";
//    }
//}
