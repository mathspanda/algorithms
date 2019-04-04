class Solution {
public:
    int calculate(string s) {
    	const int STATE_BEGIN = 0, STATE_NUM = 1, STATE_OP = 2;
    	int state = STATE_BEGIN;
        stack<int> number_stack;
        stack<char> operation_stack;
        int compute_flag = 0;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
        	if (s[i] == ' ') {
        		continue;
        	}
        	switch (state) {
        	case STATE_BEGIN:
        		if (s[i] >= '0' && s[i] <= '9') {
        			state = STATE_NUM;
        		} else {
        			state = STATE_OP;
        		}
        		i--;
        		break;
        	case STATE_NUM:
        		if (s[i] >= '0' && s[i] <= '9') {
        			num = num * 10 - '0' + s[i];
        		} else {
        			number_stack.push(num);
        			if (compute_flag == 1) {
        				compute(number_stack, operation_stack);
        			}
        			num = 0;
        			i--;
        			state = STATE_OP;
        		}
        		break;
        	case STATE_OP:
        		if (s[i] >= '0' && s[i] <= '9') {
        			state = STATE_NUM;
        			i--;
        		} else if (s[i] == '+' || s[i] == '-') {
        			operation_stack.push(s[i]);
        			compute_flag = 1;
        		} else if (s[i] == ')') {
        			compute(number_stack, operation_stack);
        		} else {
        			compute_flag = 0;
        		}
        		break;
        	}
        }
        if (num != 0) {
        	number_stack.push(num);
        	compute(number_stack, operation_stack);
        }
        return number_stack.empty() ? 0 : number_stack.top();
    }
private:
	void compute(stack<int> &num_stack, stack<char> &op_stack) {
		if (op_stack.empty()) {
			return;
		}
		int num2 = num_stack.top();
		num_stack.pop();
		int num1 = num_stack.top();
		num_stack.pop();
		char op = op_stack.top();
		op_stack.pop();
		if (op == '+') {
			num_stack.push(num1 + num2);
		} else if (op == '-') {
			num_stack.push(num1 - num2);
		}
	}
};
