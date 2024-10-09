#include "calculator.h"

int Calculator::calculate(const std::vector<std::string>& tokens,Memory& memory) {
	std::stack<int> stack;

	for (auto& token : tokens) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (stack.size() < 2) {
				throw std::runtime_error("SYNTAX ERROR");
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(performOperation(token, a, b));
		}
		else {
			int value;
			if (token[0] == '~') {
				value = -std::stoi(token.substr(1));
			}
			else {
				value = std::stoi(token);
			}
			if (value < -99999 || value > 99999) {
				throw std::runtime_error("OVERFLOW");
			}
			stack.push(value);
		}
	}

	if (stack.size() != 1) {//ç≈å„écÇ¡ÇΩàÍÇ¬ÇÃêîíl
		throw std::runtime_error("SYNTAX ERROR");
	}

	int result = stack.top();
	if (result < -99999 || result > 99999) {
		throw std::runtime_error("OVERFLOW");
	}

	memory.addANS(result); 
	return result;
}

int Calculator::performOperation(const std::string& op, int a, int b) {
	long long result = 0;

	if (op == "+") {
		result = static_cast<long long>(a) + b;
	}
	else if (op == "-") {
		result = static_cast<long long>(a) - b;
	}
	else if (op == "*") {
		result = static_cast<long long>(a) * b;
	}
	else if (op == "/") {
		if (b == 0) {
			throw std::runtime_error("SYNTAX ERROR");
		}
		result = std::round(static_cast<long double>(a) / static_cast<long double>(b));
	}

	if (result < -99999 || result > 99999) {
		throw std::runtime_error("OVERFLOW");
	}

	return static_cast<int>(result);
}
