class Solution {
  public:
  void helper(Node*node,vector<vector<int>>&ans,vector<int>v){ 
      if(node==NULL){return;}
      v.push_back(node->data);
      if(node->left==NULL&&node->right==NULL){ans.push_back(v);}
      helper(node->left,ans,v);
      helper(node->right,ans,v);
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>a;
        vector<int>res;
        helper(root,a,res);
        return a;
    }
};
