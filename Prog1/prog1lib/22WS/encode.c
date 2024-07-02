# include "base.h"

/*
Encode verschlüsselt einen String. Jeder Kleinbuchstabe wird um 5 weiter im Alphabet gesetzt, alle anderen Buchstaben bleiben gleich (also a zu f, z zu e).
Ich schreib ein Beispiel in die Test-Funktion (schreib am Besten noch mehr dazu). Der zurückgegebene String von encode soll dynamisch allokiert sein.
*/
char* encode(char* s) {
    char* result = xmalloc(sizeof(s));
    for(int i = 0; s[i] != '\0'; ++i){
        if(s[i] >= 'a' && s[i] < 'v'){
            result[i] = s[i]+5;
        }
        else if(s[i] >= 'v' && s[i] <= 'z'){
            result[i] = s[i]-26+5;
        }else{
            result[i] = s[i];
        }
    }

    return result;
}

void test_encode(void) {
    char* s = "abc :D xyz!!";
    char* d = encode(s);
    test_equal_s(d, "fgh :D cde!!");
    free(d);
}

int main(void) {
    test_encode();
    report_memory_leaks(true);
    return 0;
}
