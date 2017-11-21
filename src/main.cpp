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

int main() {
	testMorseCodePair(false);
	CodeTranslator trans;

	getchar();
	return 0;
}