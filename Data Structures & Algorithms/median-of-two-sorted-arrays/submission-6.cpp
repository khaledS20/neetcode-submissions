// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         vector<int> merged;
//         merged.reserve(m + n);

//         int i = 0, j = 0;

//         // Merge like merge sort
//         while (i < m && j < n) {
//             if (nums1[i] < nums2[j]) {
//                 merged.push_back(nums1[i++]);
//             } else {
//                 merged.push_back(nums2[j++]);
//             }
//         }

//         // Add leftovers
//         while (i < m) merged.push_back(nums1[i++]);
//         while (j < n) merged.push_back(nums2[j++]);

//         int total = m + n;
//         if (total % 2 == 1) {
//             return merged[total / 2];  // odd length → middle element
//         } else {
//             return (merged[total / 2 - 1] + merged[total / 2]) / 2.0; // even length → average
//         }
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int totalLeft = (m + n + 1) / 2;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = totalLeft - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];

            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } 
            else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } 
            else {
                left = partitionA + 1;
            }
        }

        return 0.0; // Should never reach here
    }
};

