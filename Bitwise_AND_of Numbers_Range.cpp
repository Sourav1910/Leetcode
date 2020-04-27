//   Bitwise AND of Numbers Range
//   https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/

/*Approach
1.Start comparing the bits from the left of m and n.
2.Till the bits are same copy them to the answer.
3.Break when bits are different
4.Return ans;

Basic concept is that between given 2 no.s there will be one no having trailing zeros after the common bits
which makes the right side zero as it is an and operation
Eg:-

0010100 000011000000000000000-m
0010100 000000000000000000000
0010100 111111111111111000000-n


*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=0;
        for(int bit=30;bit>=0;bit--){
            if((m & (1<<bit))!= (n & (1<<bit)))
                break;
            else
                ans|=m &(1<<bit);
        }
        return ans;
    }
};
