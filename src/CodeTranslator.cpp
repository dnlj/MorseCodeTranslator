// STD
#include <fstream>

// CodeTranslator
#include <CodeTranslator.hpp>

CodeTranslator::CodeTranslator() {
	buildDecodeTree();
}

void CodeTranslator::buildDecodeTree() {
	const std::string path = "morse.txt";
	std::ifstream file{path};

	if (!file) {
		throw std::runtime_error{"Unable to read file: " + path};
	}

	std::vector<MorseCodePair> pairs;
	pairs.reserve(26);

	// Read the file
	std::string line;
	while (file >> line) {
		if (line.size() < 2) {
			throw std::runtime_error{"Invalid code line: " + line};
		}

		MorseCodePair pair{
			// Get the morse code
			std::string{line.begin() + 1, line.end()},

			// Get the letter
			std::string{line.begin(), line.begin() + 1},
		};

		pairs.push_back(pair);
	}

	// We need to sort by size for correct insertion order
	std::sort(pairs.begin(), pairs.end(), [](const MorseCodePair& left, const MorseCodePair& right) {
		return left.code.size() < right.code.size();
	});

	// Add the root node
	// NOTE: "ROOT" works as the root node because '.' < 'R' < '_' in ascii
	decodeTree.insert(MorseCodePair{"ROOT", ""});

	// Add the letters
	for (auto it = pairs.begin(); it != pairs.end(); ++it) {
		decodeTree.insert(*it);
	}
}