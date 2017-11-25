// STD
#include <fstream>

// CodeTranslator
#include <CodeTranslator.hpp>

CodeTranslator::CodeTranslator() {
	buildEncodeDecode();
}

std::string CodeTranslator::decode(const std::string& word) {
	std::string result = "";

	auto last = word.cbegin();
	auto curr = last;

	// Add space separated letters
	while (curr != word.cend()) {
		if (*curr == ' ') {
			result += decodeTree.find({std::string{last, curr}, ""})->letter;
			last = curr + 1;
		}

		++curr;
	}

	// Add the final letter
	result += decodeTree.find({std::string{last, curr}, ""})->letter;

	return result;
}

std::string CodeTranslator::encode(const std::string& word) const {
	std::string result = "";

	auto curr = word.cbegin();

	// Convert from a-z to Morse code
	while (curr != word.cend()) {
		char ch = tolower(*curr);
		auto found = encodeMap.find(std::string{ch});
		
		// Make sure we have valid letter
		if (found == encodeMap.cend()) {
			throw std::runtime_error{"Unknown letter " + ch};
		}

		result += found->second + ' ';
		++curr;
	}

	// Remove trailing space
	if (!result.empty()) {
		result.pop_back();
	}

	return result;
}

void CodeTranslator::buildEncodeDecode() {
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
		encodeMap[it->letter] = it->code;
	}
}
