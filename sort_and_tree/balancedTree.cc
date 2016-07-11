/**
 * check if its balancedTree
 */
bool isBalanced(TreeNode node){
    if(node == null){
        return true;
    }
    else{
        bool left = isBalanced(node.left);
        bool right = isBalanced(node.right);
        if(left<0 || right<0) return false;
        else{
            if(Math.abs(left-right) > 1) return false;
            else return Math.max(left+1, right+1);
        }
    }
}
