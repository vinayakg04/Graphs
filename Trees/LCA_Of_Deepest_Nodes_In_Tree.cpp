class Solution {
public:
    int depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=depth(root->left);
        int right=depth(root->right);
        return 1+max(left,right);
    }

    TreeNode* deepNodes(TreeNode* root,int depth,int max_depth){
        if(!root) return NULL;

        if(depth==max_depth-1){

            return root;
        }

        TreeNode* left=deepNodes(root->left,depth+1,max_depth);
        TreeNode* right=deepNodes(root->right,depth+1,max_depth);

        if(left!=NULL && right!=NULL){
            return root;
        }else if(left){
            return left;
        }else{
            return right;
        }



    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL){
            return root;
        }

        vector<TreeNode*> result;
        int max_depth=depth(root);

        // deepNodes(root,0,max_depth);

        return deepNodes(root,0,max_depth);
    }
};
