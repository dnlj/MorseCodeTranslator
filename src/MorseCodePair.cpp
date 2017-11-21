// CodeTranslator
#include <MorseCodePair.hpp>

bool operator<(const MorseCodePair& left, const MorseCodePair& right) {
	auto leftCurr = left.code.cbegin();
	auto leftEnd = left.code.cend();
	auto rightCurr = right.code.cbegin();
	auto rightEnd = right.code.cend();

	// Check each character of each code
	while (leftCurr != leftEnd && rightCurr != rightEnd) {
		if (*leftCurr < *rightCurr) {
			return true;
		}

		if (*leftCurr > *rightCurr) {
			return false;
		}

		++leftCurr;
		++rightCurr;
	}

	// Check any remaining characters (this happens when left and right are of differing length)
	if (leftCurr != leftEnd) {
		return *leftCurr == '.';
	}

	if (rightCurr != rightEnd) {
		return *rightCurr == '_';
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const MorseCodePair& code) {
	return os << "(" << code.code << ", " << code.letter << ")";
}