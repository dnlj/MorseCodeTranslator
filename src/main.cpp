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

void checkDecode(const std::string& code, const std::string& word, bool show) {
	static CodeTranslator trans;
	auto res = trans.decode(code);

	if (res != word || show) {
		std::cout << std::boolalpha << (res == word) << std::endl;
	}
}

void testDecode(bool show) {
	checkDecode("", "", show);
	checkDecode(".", "e", show);
	checkDecode("_", "t", show);
	checkDecode("._", "a", show);
	checkDecode("_.", "n", show);

	checkDecode("_.. __.", "dg", show);
	checkDecode("._ .__. .__. ._.. .", "apple", show);
	checkDecode("_.. ___ __.", "dog", show);
	checkDecode(".. _.. ___ ..._ .___", "idovj", show);
}

int main() {
	testMorseCodePair(false);
	testDecode(false);

	getchar();
	return 0;
}