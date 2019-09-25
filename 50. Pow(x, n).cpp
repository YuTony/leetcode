//https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, long long n) {
      if (n < 0)
        return 1 / myPow(x, -n);
      if (n == 0)
        return 1;
      if (n % 2 == 1)
        return x * myPow(x, n - 1);
      double tmp = myPow(x, n / 2);
      return tmp * tmp;
    }
};