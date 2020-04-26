//  Leftmost Column with at Least a One
//  https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

/*
Approach used:
1.Start from the last column of 1st row and go towards the left
2.If 1 is found then keep going left and on encountering 0 go to the next row
3.Keep updating the ans variable with the min column found till now
4.Return the ans
*/
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int row = binaryMatrix.dimensions()[0], column = binaryMatrix.dimensions()[1];
        int curr_col=column-1, ans=column;
        for(int i =0; i< row;i++){
            while(curr_col>=0 && binaryMatrix.get(i,curr_col)!=0){
                ans=min(ans,curr_col);
                curr_col--;
            }
        }
        if(ans==column)
            return -1;
        return ans;
    }
};
