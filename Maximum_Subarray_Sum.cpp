//   Maximum Subarray Sum
//  https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/

//Use Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far=nums[0],sum_so_far=nums[0],max_negative=nums[0],c=0;
        if(nums[0]<0){
            max_so_far=0;
            sum_so_far=0;
            c++;
        }
        for(int i=1;i<nums.size();i++){
            sum_so_far+=nums[i];
            if(nums[i]>max_negative)
                max_negative=nums[i];
            if(sum_so_far<0)
                sum_so_far=0;
            if(sum_so_far>max_so_far)
                max_so_far=sum_so_far;
            if(nums[i]<0)
                c++;
        }
        if(c==nums.size())
            return max_negative;
        return max_so_far;
    }
};
