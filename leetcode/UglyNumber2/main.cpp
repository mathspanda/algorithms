class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> num;
        int index_2 = 0, index_3 = 0, index_5 = 0;
        int min = 1;
        num.push_back(1);
        for (int i = 2; i <= n; i++) {
        	while (num[index_2] * 2 <= min) index_2++;
        	while (num[index_3] * 3 <= min) index_3++;
        	while (num[index_5] * 5 <= min) index_5++;
        	min = min3(num[index_2] * 2, num[index_3] * 3, num[index_5] * 5);
        	num.push_back(min);
        }
        return num[num.size() - 1];
    }
 private:
 	int min3(int a, int b, int c) {
 		int min;
 		min = a < b ? a : b;
 		min = min < c ? min : c;
 		return min;
 	}
};
