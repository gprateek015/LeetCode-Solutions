class NumArray {
    vector<int> Trie;
    int size;
    void build(vector<int>& nums, int start, int end, int treeNode) {
        if(start==end) {
            Trie[treeNode] = nums[start];
            return;
        }
        int mid = (start+end)/2;
        build(nums, start, mid, 2*treeNode);
        build(nums, mid+1, end, 2*treeNode+1);
        Trie[treeNode] = Trie[2*treeNode] + Trie[2*treeNode+1];
    }
    void upd(int index, int val, int start, int end, int treeNode) {
        if(start == end && start == index) {
            Trie[treeNode] = val;
            return;
        }
        int mid = (start+end)/2;
        if(index<=mid) {
            upd(index, val, start, mid, 2*treeNode);
        } else {
            upd(index, val, mid+1, end, 2*treeNode+1);
        }
        Trie[treeNode] = Trie[2*treeNode] + Trie[2*treeNode+1];
    }
    int query(int left, int right, int start, int end, int treeNode) {
        if(left<=start && end<=right) 
            return Trie[treeNode];
        if(end<left || start>right) 
            return 0;
        int mid = (start+end)/2;
        int ans = query(left, right, start, mid, 2*treeNode);
        ans += query(left, right, mid+1, end, 2*treeNode+1);
        return ans;
    }
public:
    NumArray(vector<int>& nums) {
        Trie = vector<int>(4*nums.size());
        size = nums.size();
        build(nums, 0, nums.size()-1, 1);
    }
    
    void update(int index, int val) {
        upd(index, val, 0, size-1, 1);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, size-1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */