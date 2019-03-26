class Solution {
public:
    bool isHappy(int n) {
        std::set<int> num;
        num.insert(n);
        while (n != 1) {
            int temp = n, sum = 0;
            while (temp) {
                sum += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            if (num.find(sum) != num.end()) {
                return false;
            }
            num.insert(sum);
            n = sum;
        }
        return true;
    }
};
