/*
    Don't think this problem  would require any explanation
*/
class Solution {
  public:
    string armstrongNumber(int n){
        int sum = 0, n1 = n;
        while (n1) {
            int ld_ = n1 % 10;
            sum += (ld_ * ld_ * ld_);
            n1 /= 10;
        }
        if (sum == n) return "Yes";
        return "No";
    }
};
