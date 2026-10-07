class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0;
        int l2 = 0;
        vector<int>v;

        while(l1 < nums1.size() && l2 <nums2.size()){
            if(nums1[l1] < nums2[l2]){
                v.push_back(nums1[l1++]);
            }else{
                v.push_back(nums2[l2++]);
            }
        }

        while(l1 < nums1.size())v.push_back(nums1[l1++]);
        while(l2 < nums2.size())v.push_back(nums2[l2++]);

        int n = v.size();

        if(n%2) return (double)v[n/2];

        return (v[n/2] + v[n/2 - 1]) / 2.0;
    }
};
