#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
{
    int size = sizeof(nums)/sizeof(nums[0]);
    int a,b;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <size; j++)
        {
            if (nums[i]+nums[j] == target)
            {
                a = i;
                b = j;
            }
            else
            {
               j++; 
            }
        } 
        i++;  
    }
    return {a,b};
}
};

int main (){
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = s.twoSum(nums,target);
    for (int i: result)
    {
        cout<<i<<endl;
    }
}