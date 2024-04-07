// Es bestand darin, in einer Zeichenkette "ss" durch "ß" zu ersetzen.

// make eszett && ./eszett

#include "base.h"

String replace(String str) {
	const static String sz = "ß"; // Aufpassen! Die sind 2 bytes bzw. 2 chars: 195 and 159
	printf("First char of ß: %d\t|\t", sz[0] & 0xff);
	printf("Second char of ß: %d\n", sz[1] & 0xff);
	// todo: implement
	String result = (String) xmalloc(strlen(str)+1);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 's' && str[i+1] == 's' ) {
			result[i] = sz[0];
			result[i+1] = sz[1];
			i++;
		} else result[i] = str[i];
	}
	result[strlen(str)] = '\0';

	return result;
}

void test(void) {
	test_equal_s(replace(""), "");

	test_equal_s(replace("ss"), "ß");
	test_equal_s(replace("xyss"), "xyß");
	test_equal_s(replace("ssssss"), "ßßß");
	test_equal_s(replace("abcssde"), "abcßde");

	test_equal_s(replace("s s"), "s s");
	test_equal_s(replace("ss ss"), "ß ß");
}

int main(void) {
	test();
	return 0;
}