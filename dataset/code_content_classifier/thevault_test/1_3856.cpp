vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> q1, q2;
    vector<vector<int> >sol;
    if(A==NULL)
        return sol;
    //Initialisation step: Pusing root into queue
    q1.push(A);
    while(!q1.empty() || !q2.empty()) {
        vector<int> tsol;
        if(!q1.empty()){
            while(!q1.empty()) {
                TreeNode* temp = q1.front();
                if(temp->left!=NULL)
                    q2.push(temp->left);
                if(temp->right!=NULL)
                    q2.push(temp->right);
                tsol.push_back(temp->val);
                q1.pop();
            }
        }
        else{
            while(!q2.empty()) {
                TreeNode* temp = q2.front();
                if(temp->left!=NULL)
                    q1.push(temp->left);
                if(temp->right!=NULL)
                    q1.push(temp->right);
                tsol.push_back(temp->val);
                q2.pop();
            }
        }
        //Pushing values of one level to solution vector of vectors
        sol.push_back(tsol);
    }
    return sol;
}