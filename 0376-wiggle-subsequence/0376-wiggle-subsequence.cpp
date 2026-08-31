class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up=0;
        int down=0;
        bool ctr=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]>0)down=up+1;
            else if(nums[i]-nums[i+1]<0)up=down+1;
        }
        return max(up,down)+1;
    }
};