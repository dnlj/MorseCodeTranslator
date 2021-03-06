// STD
#include <iostream>

// Blackboard
#include <Binary_Search_Tree.h>

// CodeTranslator
#include <MorseCodePair.hpp>
#include <CodeTranslator.hpp>

void checkMorseCodePair(const MorseCodePair& left, const MorseCodePair& right, bool expected, bool show) {
	auto result = left < right;

	if (result != expected || show) {
		std::cout << std::boolalpha << (result == expected) << '\n';
	}
}

void testMorseCodePair(bool show) {
	checkMorseCodePair(MorseCodePair{".", ""}, MorseCodePair{".", ""}, false, show);
	checkMorseCodePair(MorseCodePair{".", ""}, MorseCodePair{"._",""},  true, show);
	checkMorseCodePair(MorseCodePair{".", ""}, MorseCodePair{"_", ""},  true, show);
	checkMorseCodePair(MorseCodePair{".", ""}, MorseCodePair{"__",""},  true, show);
	
	checkMorseCodePair(MorseCodePair{"..", ""}, MorseCodePair{".", ""}, true, show);
	checkMorseCodePair(MorseCodePair{"..", ""}, MorseCodePair{"._",""}, true, show);
	checkMorseCodePair(MorseCodePair{"..", ""}, MorseCodePair{"_", ""}, true, show);
	checkMorseCodePair(MorseCodePair{"..", ""}, MorseCodePair{"__",""}, true, show);
	
	checkMorseCodePair(MorseCodePair{"_", ""}, MorseCodePair{".", ""}, false, show);
	checkMorseCodePair(MorseCodePair{"_", ""}, MorseCodePair{"._",""}, false, show);
	checkMorseCodePair(MorseCodePair{"_", ""}, MorseCodePair{"_", ""}, false, show);
	checkMorseCodePair(MorseCodePair{"_", ""}, MorseCodePair{"__",""},  true, show);
	
	checkMorseCodePair(MorseCodePair{"__", ""}, MorseCodePair{".", ""}, false, show);
	checkMorseCodePair(MorseCodePair{"__", ""}, MorseCodePair{"._",""}, false, show);
	checkMorseCodePair(MorseCodePair{"__", ""}, MorseCodePair{"_", ""}, false, show);
	checkMorseCodePair(MorseCodePair{"__", ""}, MorseCodePair{"__",""}, false, show);
	
	checkMorseCodePair(MorseCodePair{"._", ""}, MorseCodePair{".", ""}, false, show);
	checkMorseCodePair(MorseCodePair{"._", ""}, MorseCodePair{"._",""}, false, show);
	checkMorseCodePair(MorseCodePair{"._", ""}, MorseCodePair{"_", ""},  true, show);
	checkMorseCodePair(MorseCodePair{"._", ""}, MorseCodePair{"__",""},  true, show);
	
	checkMorseCodePair(MorseCodePair{"_.", ""}, MorseCodePair{".", ""}, false, show);
	checkMorseCodePair(MorseCodePair{"_.", ""}, MorseCodePair{"._",""}, false, show);
	checkMorseCodePair(MorseCodePair{"_.", ""}, MorseCodePair{"_", ""},  true, show);
	checkMorseCodePair(MorseCodePair{"_.", ""}, MorseCodePair{"__",""},  true, show);
}

void checkDecode(const std::string& code, const std::string& word, bool show, bool shouldThrow = false) {
	static CodeTranslator trans;
	bool threw = false;
	std::string res;

	try {
		res = trans.decode(code);
	} catch (...) {
		threw = true;
	}

	if (shouldThrow && !threw) {
		std::cout << code << " did not throw" << std::endl;
		return;
	} else if (!shouldThrow && threw) {
		std::cout << code << " was not expecting throw" << std::endl;
		return;
	}

	if (res != word || show) {
		std::cout << std::boolalpha << (res == word) << std::endl;
	}
}

void testDecode(bool show) {
	// Valid inputs
	checkDecode("", "", show);
	checkDecode(".", "e", show);
	checkDecode("_", "t", show);
	checkDecode("._", "a", show);
	checkDecode("_.", "n", show);
	
	checkDecode("_.. __.", "dg", show);
	checkDecode("._ .__. .__. ._.. .", "apple", show);
	checkDecode("_.. ___ __.", "dog", show);
	checkDecode(".. _.. ___ ..._ .___", "idovj", show);
	
	// Invalid inputs
	checkDecode("1", "", show, true);

	checkDecode(".1", "", show, true);
	checkDecode("_1", "", show, true);
	checkDecode("1.", "", show, true);
	checkDecode("1_", "", show, true);

	checkDecode(".1.", "", show, true);
	checkDecode(".1_", "", show, true);
	checkDecode("_1_", "", show, true);
	checkDecode("_1.", "", show, true);

	checkDecode("x", "", show, true);

	checkDecode(".x", "", show, true);
	checkDecode("_x", "", show, true);
	checkDecode("x.", "", show, true);
	checkDecode("x_", "", show, true);

	checkDecode(".x.", "", show, true);
	checkDecode(".x_", "", show, true);
	checkDecode("_x_", "", show, true);
	checkDecode("_x.", "", show, true);
}

void checkEncode(const std::string& code, const std::string& word, bool show, bool shouldThrow = false) {
	static CodeTranslator trans;
	bool threw = false;
	std::string res;

	try {
		res = trans.encode(word);
	} catch (...) {
		threw = true;
	}

	if (shouldThrow && !threw) {
		std::cout << word << " did not throw" << std::endl;
		return;
	} else if (!shouldThrow && threw) {
		std::cout << word << " was not expecting throw" << std::endl;
		return;
	}
	
	if (res != code || show) {
		std::cout << std::boolalpha << (res == code) << std::endl;
	}
}

void testEncode(bool show) {
	// Lowercase
	checkEncode("", "", show);
	checkEncode(".", "e", show);
	checkEncode("_", "t", show);
	checkEncode("._", "a", show);
	checkEncode("_.", "n", show);

	checkEncode("_.. __.", "dg", show);
	checkEncode("._ .__. .__. ._.. .", "apple", show);
	checkEncode("_.. ___ __.", "dog", show);
	checkEncode(".. _.. ___ ..._ .___", "idovj", show);

	// Uppercase
	checkEncode("", "", show);
	checkEncode(".", "E", show);
	checkEncode("_", "T", show);
	checkEncode("._", "A", show);
	checkEncode("_.", "N", show);

	checkEncode("_.. __.", "DG", show);
	checkEncode("._ .__. .__. ._.. .", "APPLE", show);
	checkEncode("_.. ___ __.", "DOG", show);
	checkEncode(".. _.. ___ ..._ .___", "IDOVJ", show);

	// Invalid inputs
	checkEncode("", "&", show, true);
	checkEncode("", "&az", show, true);
	checkEncode("", "a&z", show, true);
	checkEncode("", "az&", show, true);
}

int main() {
	// Run tests
	testMorseCodePair(false);
	testDecode(false);
	testEncode(false);

	// Example usage
	CodeTranslator trans;
	std::string code = "._ .__. .__. ._.. .";
	std::string word = "apple";

	try {
		std::cout << "Decode: \"" << code << "\" = \"" << trans.decode(code) << "\"\n";
		std::cout << "Encode: \"" << word << "\" = \"" << trans.encode(word) << "\"" << std::endl;
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		throw ex;
	}

	// Wait for user input before closing
	std::cout << "\nDone." << std::endl;
	getchar();
	return 0;
}