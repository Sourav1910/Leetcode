//  Subarray Sum Equals K
//  https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/

/*
Approach used:
1.Store the sum of elements from 0th position to current position in a sum vector
2.Loop through the array and calculate the difference between ith and jth element,also check if ith value equals to k
3.If it equals k then increment count
4.Return count
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum;
        int s=0,count=0;
        for(int i:nums){
            s+=i;
            sum.push_back(s); 
        }
        if(nums.size()==1 && nums[0]==k)
            count=1;
        else{
            for(int i=0;i<nums.size()-1;i++){
                if(sum[i]==k)
                    count++;
                for(int j=i+1;j<nums.size();j++){
                    if(sum[j]-sum[i]==k)
                        count++;
                }
            }
            if(sum[nums.size()-1]==k)
                count++;
        }
        return count;
    }
};
