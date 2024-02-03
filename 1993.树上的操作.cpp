/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
public:
    struct Node {
        int user_ = -1;
        int parent_ = -1;
        vector<int> children_;
    };

    LockingTree(vector<int>& parent) {
        tree_.clear();
        tree_.resize(parent.size());
        for (int i = 0; i < parent.size(); i++) {
            tree_[i].parent_ = parent[i];
            if (parent[i] >= 0)
                tree_[parent[i]].children_.push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (num >= tree_.size()) return false;
        auto& node = tree_[num];
        if (node.user_ >= 0) return false;
        node.user_ = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (num >= tree_.size()) return false;
        auto& node = tree_[num];
        if (node.user_ == user) {
            node.user_ = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
         if (num >= tree_.size()) return false;
         auto& node = tree_[num];
         //check parent
         {
            auto* p = &node;
            while (p) {
                if (p->user_ >= 0) return false;
                if (p->parent_ >= 0){
                    p = &tree_[p->parent_];
                }else{
                    p = nullptr;
                }
            }
         }
         //check children
         vector<int> locked_children;
         {
            queue<int> pending;
            for (int i : node.children_) pending.push(i);
            while(!pending.empty()) {
                int cur = pending.front();
                pending.pop();
                if (tree_[cur].user_ >= 0) locked_children.push_back(cur);
                for (int i : tree_[cur].children_) pending.push(i);
            }
         }
         //
         if (locked_children.empty()) return false;
         node.user_ = user;
         for (int i : locked_children) {
            tree_[i].user_ = -1;
         }
         return true;
    }

private:
    vector<Node> tree_;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

