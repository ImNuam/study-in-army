/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int>::iterator expos=nums1.begin();
    //     for(int i=0; i< n; i++){
    //         int tmp = nums2[i];
    //         for(vector<int>::iterator it=expos; it!=nums1.end(); it++){
    //             if(tmp<*(it+1)){
    //                 it=nums1.insert(it, tmp);
    //                 expos=it;
    //                 break;
    //             }
    //         }
    //     }

        for(int i=0; i<n; i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    



};
// @lc code=end

