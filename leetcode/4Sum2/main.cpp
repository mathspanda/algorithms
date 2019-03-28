class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		map<int, int> two_map;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				int temp = A[i] + B[j];
				if (two_map.find(temp) != two_map.end()) {
					two_map[temp] = two_map[temp] + 1;
				} else {
					two_map[temp] = 1;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < C.size(); i++) {
			for (int j = 0; j < D.size(); j++) {
				int temp = C[i] + D[j];
				if (two_map.find(-temp) != two_map.end()) {
					count += two_map[-temp];
				}
			}
		}
		return count;
    }
};
