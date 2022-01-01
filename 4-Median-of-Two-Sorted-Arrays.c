/*
 * 4. Median of Two Sorted Arrays --- Hard
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 * Constraints:
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -106 <= nums1[i], nums2[i] <= 106
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = 0, j = 0, index = 0;
    int temp[2000] = { 0 };

    if (nums1Size == 0) {
        if (nums2Size % 2 == 0)
            return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2;
        return (double)nums2[(nums2Size - 1) / 2];
    }

    if (nums2Size == 0) {
        if (nums1Size % 2 == 0)
            return (double)(nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2;
        return (double)nums1[(nums1Size - 1) / 2];
    }

    while (i < nums1Size) {
        if (nums1[i] <= nums2[j]) {
            temp[index++] = nums1[i++];
            continue;
        }

        temp[index++] = nums2[j++];
        if (j == nums2Size)
            break;
    }

    while (i < nums1Size)
        temp[index++] = nums1[i++];

    while (j < nums2Size)
        temp[index++] = nums2[j++];
    
    if (index % 2 == 0)
        return (double)(temp[index / 2 - 1] + temp[index / 2]) / 2;
    return (double)temp[(index - 1) / 2];
}
