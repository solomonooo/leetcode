/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

class Solution {
public:
    /*
    另一种解法
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m == 0 && n == 0)
            return -1;
        if ((m+n) & 1 > 0) {
            return findKth(nums1, 0, nums2, 0, (m+n+1)/2);
        }


        return (findKth(nums1, 0, nums2, 0, (m+n+1)/2) + findKth(nums1, 0, nums2, 0, (m+n+2)/2))/2.0;
    } 

    //一个一个归并遍历太慢，我们可以一次跳k/2个距离
    //选择nums1和nums2中小的那个往前跳
    //k: 第k个元素
    int findKth(vector<int>& nums1, int cur1, vector<int>& nums2, int cur2, int k){
        int m = nums1.size() - cur1;
        int n = nums2.size() - cur2;
        if(m == 0)
            return nums2[cur2+k-1];
        else if (n == 0)
            return nums1[cur1+k-1];
        if(k == 1)
            return min(nums1[cur1], nums2[cur2]);
        //k不可能=0，因为k=k-k/2,除非k=0,否则等式无法成立
        int i = min(m, k/2), j = min(n, k/2);
        if(nums1[cur1+i-1] > nums2[cur2+j-1])
            return findKth(nums1, cur1, nums2, cur2+j, k-j);
        else
            return findKth(nums1, cur1+i, nums2, cur2, k-i);
        return 0;
    }
    */

    //这是一个find kth的问题
    //需要先判断奇偶，因为如果是偶数，我们需要找到2个数，然后求均值
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m == 0 && n == 0)
            return -1;
        int cur1 = 0, cur2 = 0;
        int mid1 = findKth(nums1, cur1, nums2, cur2, (m+n+1)/2);
        if (((m+n) & 1) > 0) {
            return mid1;
        }
        int next1 = cur1 < m ? nums1[cur1] : INT_MAX;
        int next2 = cur2 < n ? nums2[cur2] : INT_MAX;
        return (mid1 + min(next1, next2)) / 2.0;
    } 

    //一个一个归并遍历太慢，我们可以一次跳k/2个距离
    //选择nums1和nums2中小的那个往前跳
    //k: 第k个元素
    int findKth(vector<int>& nums1, int& cur1, vector<int>& nums2, int& cur2, int k){
        int m = nums1.size() - cur1;
        int n = nums2.size() - cur2;
        //二分查找，最后只有3种情况
        //nums1到了头，m=0
        //nums2到了头，n=0
        //k=1, 如果k>1，显然还可以二分查找
        if(m == 0) {
            cur2 += k;
            return nums2[cur2-1];
        }
        else if (n == 0) {
            cur1 += k;
            return nums1[cur1-1];
        }
        if(k == 1) {
            return nums1[cur1] < nums2[cur2] ? nums1[cur1++] : nums2[cur2++];
        }
        //k不可能=0，因为k=k-k/2,除非k=0,否则等式无法成立
        int i = min(m, k/2), j = min(n, k/2);
        if(nums1[cur1+i-1] > nums2[cur2+j-1]) {
            cur2 += j;
            return findKth(nums1, cur1, nums2, cur2, k-j);
        }else{
            cur1 += i;
            return findKth(nums1, cur1, nums2, cur2, k-i);
        }
        return 0;
    }
};

// @lc code=end

