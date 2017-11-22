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
		 * @return The decoded word.
		 */
		std::string decode(const std::string& word);

		// string encode(string)

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