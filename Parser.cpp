#include "Parser.h"

Information Parser::parse(const std::string& input,const Memory& memory) {
	Information info;
	//std::regex regex(R"((\d+[a-zA-Z]+|[a-zA-Z]+\d+|\d+|~\d+|[+\-*/]|[a-zA-Z]+|~+))");
	std::regex regex(R"((\d+[a-zA-Z]+|[a-zA-Z]+\d+|\d+|~+\d+|[+\-*/]|[a-zA-Z]+))");//不再处理~在字符后面的情况
	auto words_begin = std::sregex_iterator(input.begin(), input.end(), regex);
	auto words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::string token = (*i).str();
		std::transform(token.begin(), token.end(), token.begin(), ::toupper);
		info.addToken(token,memory);//passing memory to get ANS
	}
	return info;
}


