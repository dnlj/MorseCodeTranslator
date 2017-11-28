#pragma once

// STD
#include <string>
#include <unordered_map>

// Blackboard
#include <Binary_Search_Tree.h>

// CodeTranslator
#include <MorseCodePair.hpp>

class CodeTranslator {
	public:
		CodeTranslator();

		/**
		 * @brief Decodes the Morse code word @p word.
		 * @param[in] word The word to decode.
		 * @throws std::runtime_error When an invalid input is given.
		 * @return The decoded word.
		 */
		std::string decode(const std::string& word) const;

		/**
		 * @brief Encodes @p word to Morse code.
		 * @param[in] word The word to encode.
		 * @throws std::runtime_error When an invalid input is given.
		 * @return The encoded word.
		 */
		std::string encode(const std::string& word) const;

	private:
		/** Stores the tree used for decoding */
		Binary_Search_Tree<MorseCodePair> decodeTree;

		/** Stores the map used for encoding */
		std::unordered_map<std::string, std::string> encodeMap;

		/**
		 * @brief Builds the strucutes needed to encode and decode words.
		 */
		void buildEncodeDecode();
};