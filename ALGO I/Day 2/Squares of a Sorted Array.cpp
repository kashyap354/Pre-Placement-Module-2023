class Solution {
public:
       vector<int> sortedSquares(vector<int>& nums) {
        // Efficient Solution Time O(N) & Auxiliary Space O(1)
        // Two Pointer Method
        int len=nums.size(), lt=0, rt=len;
        vector<int> res;
        // Find index of first positive vector element & position right pointer
        for(int i=0;i<len;i++){
            if(nums[i]>=0){
                rt=i;
                break;
            }
        }
        // Position left pointer at smallest negative vector element
        lt=rt-1;
        while(lt>=0 && rt<=len-1){
        // Compare elements at left & right index and push the square of  
        // the smaller element in the resultant vector in ascending order
        // and reposition the left(decrement) & right(increment) pointers
            if(abs(nums[lt])<nums[rt]){
                res.push_back(nums[lt]*nums[lt]);
                lt--;
            }
            else if(abs(nums[lt])>nums[rt]){
                res.push_back(nums[rt]*nums[rt]);
                rt++;
            }
            else{
                res.push_back(nums[lt]*nums[lt]);
                lt--;
                res.push_back(nums[rt]*nums[rt]);
                rt++;
            }  
        }
        // Push the square of the element in the resultant vector for the
        // case of unvisited elements
        while(lt>-1){
              res.push_back(nums[lt]*nums[lt]);
              lt--;
            } 
        while(rt<len){
              res.push_back(nums[rt]*nums[rt]);
              rt++;
            }
        return res;
    }
};
