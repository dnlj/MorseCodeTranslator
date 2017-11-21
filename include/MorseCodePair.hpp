#pragma once

// STD
#include <string>

/**
 * @brief Used to store a Morse code and a letter.
 */
class MorseCodePair {
	public:
		/** The Morse code representation of MorseCodePair::letter */
		std::string code;

		/** The letter represented by MorseCodePair::code */
		std::string letter;
};

/**
 * @brief Checks if @p left is less than @p right.
 * @param[in] left The left hand side item to compare.
 * @param[in] right The right hand side item to compare.
 * @return True if @p left is less than @p right, and otherwise false.
 */
bool operator<(const MorseCodePair& left, const MorseCodePair& right);

/**
 * @brief Outputs a string representation of this Morse code.
 * @param[in,out] os The stream to output to.
 * @param[in] code The code to output.
 * @return The stream that was output to. (@p os).
 */
std::ostream& operator<<(std::ostream& os, const MorseCodePair& code);