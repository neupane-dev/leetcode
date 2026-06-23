import unittest
from leetcode_1 import Solution

class TestTwoSum(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example_1(self):
        self.assertEqual(self.sol.twoSum([2,7,11,15],9),[0,1])
    
    def test_example_2(self):
        self.assertEqual(self.sol.twoSum([3, 2, 4], 6), [1, 2])


if __name__ == '__main__':
    unittest.main()
