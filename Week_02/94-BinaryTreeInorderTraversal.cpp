//二叉树中序遍历

/*
解法1：递归

中序：左根右
1、递推公式：left root（打印/输出） right 
2、终止条件：node为空
3、返回值：无需返回值
*/

class Solution {
public:
    //递归函数: root:根节点， result：存储遍历结点的值
    void inorder(TreeNode* root, vector<int> & result) {
        //终止条件：节点为null，无需返回值 
        if (root == NULL) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

/*
解法2：迭代（模拟系统栈）
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        //stack不为空说明还有结点的右子树需要遍历
        while (!s.empty() || root != NULL) {
            //先根后左子树全部入栈
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }
            //此时root=null说明上一个结点没有左子树，左子树走到了尽头
            //1、左出栈，此时root=null，所以root.right也为null
            //2、执行最外层while循环，根出栈，此时出栈的结点的right可能存在
            //3、如果存在，将右入栈，再出栈
            //3、如果不存在，重复步骤2
            root = s.top(); s.pop();
            result.push_back(root->val);//将出栈结点的值存入结果数组中
            root = root->right;
        }
        return result;
    }
};

/*
解法3：莫里斯遍历（找前驱节点）
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //存储返回结果数组
        vector<int> result;
        //记录前驱结点
        TreeNode *predecessor = nullptr;
        while (root != nullptr) {
            //如果有左孩子，则该root结点一定有前驱结点
            if (root->left != nullptr) {
            //查找当前root的前驱节点：1、当前root结点先向左走一步 2、然年一直往右走到尽头
                predecessor = root->left;
                //是前驱结点的条件：predecessor->right == nullptr || predecessor->right == root
                //如果不是前驱结点
                while (predecessor->right != nullptr && predecessor->right != root ) {
                    predecessor = predecessor->right;
                }
                //找到前驱结点，将前驱结点的右指针指向当前root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                //说明左子树已经遍历完，开始遍历右子树。需要断开前驱结点的右指针连接，恢复二叉树
                else if (predecessor->right == root) {
                    predecessor->right = nullptr;
                    result.push_back(root->val);
                    root = root->right;
                }
            }
            //如果没有左孩子，则打印当前root结点，直接访问右孩子
            else {
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};