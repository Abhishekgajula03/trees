class Solution {
  public:
  bool helper(Node*node,vector<int>v,int x){ 
      if(!node){return false;}
      v.push_back(node->data);
      if(node->val==x){return true;}

      if(helper(node->left,ans,v)||helper(node->right,ans,v)){return true;};
      v.pop_back();
      rteurn false;
  }
    vector<int> Paths(Node* root,int x) {
        // code here
        vector<int>a;
        if(root==NULL){return a;}
        helper(root,a,x);
        return a;
    }
};
