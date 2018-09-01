class Solution {
    public int findDuplicate(int[] nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int duplicate = 0;
        while (duplicate != slow) {
            slow = nums[slow];
            duplicate = nums[duplicate];
        }
        return duplicate;
    }
}