#define REP(i,a,b) for(int i=a;i<=b;i++)
class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 二分法，存在重复值时退化到暴力
        if (numbers.size() == 0) {
            return 0;
        }
        int left = 0, right=numbers.size()-1;
        while(left<right) {
            int mid = left + (right-left)/2;
            if (numbers[mid]<numbers[right]) {
                right = mid;
            } else if (numbers[mid]>numbers[right]) {
                left = mid+1;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};
