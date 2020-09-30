//  Subarray Sum Equals K
//  https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/

/*
Approach used: O(N^2) - Complexity
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
                    count=count+1;
                for(int j=i+1;j<nums.size();j++){
                    if(sum[j]-sum[i]==k)
                        count=count+1;
                }
            }
            if(sum[nums.size()-1]==k)
                count=count+1;
        }
        return count;
    }
};

//Optimized Approach
/*
Approach used: O(N) - Complexity
We have to find subarrays having sum equal to sum variable 
1.currsum variable stores the sum of all nos till that position
2.res variable stores the counter/ans
3.if currsum == sum then we increase res by 1
4.Then we need to find whether the (currsum - sum) is present in the map and if so then increase the res value by the value stored in map for a key
5.In the end we add the currsum to the map and increase the value by 1
*/

#include <bits/stdc++.h> 
using namespace std; 
int findSubarraySum(int arr[], int n, int sum) 
{ 
	unordered_map<int, int> prevSum; 
	int rest = 0; 
	int currsum = 0; 
	for (int i = 0; i < n; i++) {  
		currsum += arr[i]; 
		if (currsum == sum) 
			rest++;		 
		if (prevSum.find(currsum - sum) != prevSum.end()) 
			rest = rest+(prevSum[currsum - sum]);
		prevSum[currsum]=prevSum[currsum]+1; 
	} 
	return rest; 
} 

int main() 
{ 
	int arr[] = { 10, 2, -2, -20, 10 }; 
	int sum = -10; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findSubarraySum(arr, n, sum); 
	return 0; 
} 

