void build_segment_tree(vector<int> &value, vector<int> &nums, int pos, 
                        int left, int right) {
    if (left == right) {
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value, nums, 2 * pos + 1, left, mid);
    build_segment_tree(value, nums, 2 * pos + 2, mid + 1, right);
    value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
}

int sum_range_segment_tree(vector<int> &value, int pos, 
                           int left, int right, 
                           int qleft, int qright) {
    if (qleft > right || qright < left) {
        return 0;
    }
    if (left >= qleft && right <= qright) {
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value, 2 * pos + 1, left, mid, qleft, qright) + 
        sum_range_segment_tree(value, 2 * pos + 2, mid + 1, right, qleft, qright);
}

void update_segment_tree(vector<int> &value, int pos, 
                         int left, int right, 
                         int index, int newv) {
    if (left == right && left == index) {
        value[pos] = newv;
        return;
    }
    int mid = (left + right) / 2;
    if (index <= mid) {
        update_segment_tree(value, 2 * pos + 1, left, mid, index, newv);
    } else {
        update_segment_tree(value, 2 * pos + 2, mid + 1, right, index, newv);
    }
    value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        _tree = vector<int>(nums.size() * 4, 0);
        _end = nums.size() - 1;
        build_segment_tree(_tree, nums, 0, 0, _end);
    }
    
    void update(int i, int val) {
        update_segment_tree(_tree, 0, 0, _end, i, val);
    }
    
    int sumRange(int i, int j) {
        return sum_range_segment_tree(_tree, 0, 0, _end, i, j);
    }
private:
    vector<int> _tree;
    int _end;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
