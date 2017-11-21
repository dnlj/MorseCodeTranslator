#pragma once

// STD
#include <string>

// Blackboard
#include <Binary_Search_Tree.h>

// CodeTranslator
#include <MorseCodePair.hpp>

class CodeTranslator {
	public:
		CodeTranslator();

		// string decode(string)
		// string encode(string)

	private:
		using Tree = Binary_Search_Tree<MorseCodePair>;

		/** Stores the tree used for decoding */
		Tree decodeTree;

		//Tree encodeTree;

		/**
		 * @brief Builds the tree needed to decode words.
		 */
		void buildDecodeTree();

		//void buildEncodeTree();
};