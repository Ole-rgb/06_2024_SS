/*
make document_list_iterator && ./document_list_iterator
*/

#include "base.h"

// Represents a single line of a document.
typedef struct Line {
    char* chars; // null-terminated string
    struct Line* next; // the next line (or NULL)
} Line;

// Creates a new line.
Line* new_line(char* chars, Line* next) {
    require_not_null(chars);
    Line* l = xcalloc(1, sizeof(Line));
    l->chars = chars;
    l->next = next;
    return l;
}

// Represents a document, made up of lines of ASCII letters.
typedef struct {
    Line* first;
    Line* last;
} Document;

// Create a new document.
Document make_document(void) {
    Document d = { NULL, NULL };
    return d;
}

// Appends a new line to the end of the document.
void append_line(Document* doc, char* chars) {
    require_not_null(doc);
    require_not_null(chars);
    Line* line = new_line(chars, NULL);
    if (doc->first == NULL) {
        doc->first = line;
    }
    if (doc->last != NULL) {
        doc->last->next = line;
    }
    doc->last = line;
}

// Represents the state of a document iterator. Iterates character by character.
typedef struct {
    Line* line; // current line (or NULL)
    int column; // zero-based column number (within the current line)
} DocumentIterator;

// Initializes an iterator for the given document.
DocumentIterator make_document_iterator(Document* doc) {
    require_not_null(doc);
    DocumentIterator it = { doc->first, 0 };
    return it;
}

// Checks if the iterator has more characters to return.
bool iter_has_next(DocumentIterator* it) {
    // todo: implement
    return false;
}

// Returns the next character of the document.
char iter_next(DocumentIterator* it) {
    // todo: implement
    return '\0';
}

void test(void) {
    char* letter[] = {
        "Dear Grandma,",
        "",
        "My first semester at the university",
        "is now over. I very much liked",
        "Programming 1. What I did not like",
        "so much was that all courses were",
        "online. All the best!",
        "",
        "Yours,",
        "Otto"
    };
    int n = sizeof(letter) / sizeof(char*);
    Document doc = make_document();
    for (int i = 0; i < n; i++) {
        append_line(&doc, letter[i]);
    }

    DocumentIterator it;

    it = make_document_iterator(&doc);
    while (iter_has_next(&it)) {
        char c = iter_next(&it);
        printc(c);
    }
    println();

    it = make_document_iterator(&doc);
    test_equal_b(iter_has_next(&it), true);
    test_equal_i(iter_next(&it), 'D');
    test_equal_i(iter_next(&it), 'e');
    for (int i = 0; i < 11; i++) {
        iter_next(&it);
    }
    test_equal_i(iter_next(&it), 'M');
    test_equal_i(iter_next(&it), 'y');
    iter_next(&it);
    test_equal_b(iter_has_next(&it), true);
    for (int i = 0; i < 160; i++) {
        iter_next(&it);
    }
    test_equal_b(iter_has_next(&it), false);
}

int main(void) {
    test();
    return 0;
}