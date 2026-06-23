from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {} ##Dictionary => key: number , value: index
        for i, num in enumerate(nums):
            complement = target - num

            #Check if the complement is already seen
            if complement in num_map:
                return[num_map[complement],i]
            
            #Otherwise, save the current number in the hash map
            num_map[num] = i
        return []

