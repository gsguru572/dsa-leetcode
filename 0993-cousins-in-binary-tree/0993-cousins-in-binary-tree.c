
/**
 * Definition for a binary tree node.
  * struct TreeNode {
   *     int val;
    *     struct TreeNode *left;
     *     struct TreeNode *right;
      * };
       */

       int findDepth(struct TreeNode* root, int x, int* parent) {
           if (root == NULL)
                   return -1;

                       if (root->left && root->left->val == x) {
                               *parent = root->val;
                                       return 1;
                                           }

                                               if (root->right && root->right->val == x) {
                                                       *parent = root->val;
                                                               return 1;
                                                                   }

                                                                       int leftParent = -1;
                                                                           int rightParent = -1;

                                                                               int left = findDepth(root->left, x, &leftParent);
                                                                                   if (left != -1) {
                                                                                           *parent = leftParent;
                                                                                                   return left + 1;
                                                                                                       }

                                                                                                           int right = findDepth(root->right, x, &rightParent);
                                                                                                               if (right != -1) {
                                                                                                                       *parent = rightParent;
                                                                                                                               return right + 1;
                                                                                                                                   }

                                                                                                                                       return -1;
                                                                                                                                       }

                                                                                                                                       bool isCousins(struct TreeNode* root, int x, int y) {
                                                                                                                                           int parentX = -1;
                                                                                                                                               int parentY = -1;

                                                                                                                                                   int depthX = findDepth(root, x, &parentX);
                                                                                                                                                       int depthY = findDepth(root, y, &parentY);

                                                                                                                                                           return depthX == depthY && parentX != parentY;
                                                                                                                                                           }
                                                                                                                                                           