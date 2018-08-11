class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null)
            return 0;
        int length = 1;
        for (int i = 1; i < nums.length; i++)
            if (nums[i] != nums[i-1])
                nums[length++] = nums[i];
        return length;
    }
}