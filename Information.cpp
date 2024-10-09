#include "Information.h"

void Information::addToken(const std::string& token, const Memory& memory) {
	if (tokens.size() >= MAX_TOKENS) {
		throw std::runtime_error("SYNTAX ERROR"); 
	}
	if (token == "AC") {
		if ((memory.get_size()!=0) && (tokens.size() == 0)) {
			memory.allclear();
			//std::cout <<"ANS=" << memory.get_last_ans() << std::endl;
			throw std::runtime_error("ANS=0");
		}
		else throw std::runtime_error("SYNTAX ERROR");
	}
	if (token == "EXIT") {
		if (tokens.size() == 0) {
			exit(0);
		}
		else throw std::runtime_error("SYNTAX ERROR");
	}

	if (token == "ANS") {
		if (memory.get_size() > 0)
		{
			tokens.push_back(memory.get_last_ans());
			return;
		}
		else throw std::runtime_error("SYNTAX ERROR");
	}
	if (token == "+" || token == "-" || token == "*" || token == "/") {
		tokens.push_back(token);
		return;
	}
	if (token[0] == '~') {
		if (not isdigit(token[1])) {//||!std::all_of(token.begin() + 1, token.end(), ::isdigit)
            
			throw std::runtime_error("SYNTAX ERROR");
		}
		int value = std::stoi(token.substr(1));
		if (value < -99999 || value > 99999) {
			throw std::runtime_error("OVERFLOW");
		}
		tokens.push_back(token);
		return;
	}

	if (std::all_of(token.begin(), token.end(), ::isdigit)) {
		try
		{
			int value = std::stoi(token);
			if (value < -99999 || value > 99999) {
				throw std::runtime_error("OVERFLOW");
			}
		}
		catch (const std::out_of_range& e) {
			throw std::runtime_error("OVERFLOW");
		}
		tokens.push_back(token);
		return;
	}
	throw std::runtime_error("SYNTAX ERROR");
}

const std::vector<std::string>& Information::getTokens() const {
	return tokens;
}
int Information::get_length() const {
	return tokens.size();
}
 