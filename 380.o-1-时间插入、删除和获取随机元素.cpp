/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> vi;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(vi.find(val) != vi.end())
            return false;
        nums.push_back(val);
        vi.insert({val, nums.size() - 1});
        return true;
    }

    bool remove(int val) {
        if(vi.find(val) == vi.end())
            return false;
        int index = vi[val];
        vi[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        vi.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

