/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainarr) {
        int length = mountainarr.length();

        int l = 1,r = length-2,peak = 0;
        while(l <= r){
            int m = (l+r)/2;
            int left = mountainarr.get(m-1);
            int mid = mountainarr.get(m);
            int right = mountainarr.get(m+1);
            if(left < mid && mid < right){
                l = m+1;
            }
            else if(left>mid && mid>right){
                r = m-1;
            }
            else{
                peak = m;
                break;
            }
        }

        l = 0;
        r = peak-1;
        while(l <= r){
            int m = (l+r)/2;
            int val = mountainarr.get(m);
            if(val < target){
                l = m+1;
            }
            else if(val > target){
                r = m-1;
            }
            else{
                return m;
            }
        }

        l = peak;
        r = length-1;
        while(l <= r){
            int m = (l+r)/2;
            int val = mountainarr.get(m);
            if(val > target){
                l = m+1;
            }
            else if(val < target){
                r = m-1;
            }
            else{
                return m;
            }
        }

        return -1;
    }
};