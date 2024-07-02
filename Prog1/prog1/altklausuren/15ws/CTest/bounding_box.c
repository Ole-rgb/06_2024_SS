/*
Compile: make bounding_box
Run: ./bounding_box
make bounding_box && ./bounding_box
*/

#include "base.h"         // http://hci.uni-hannover.de/files/prog1lib/base_8h.html
#include "list.h"         // http://hci.uni-hannover.de/files/prog1lib/list_8h.html
#include "pointer_list.h" // http://hci.uni-hannover.de/files/prog1lib/string__list_8h.html

typedef enum {
    RECTANGLE, CIRCLE
} ShapeTag;

typedef struct {
    int x, y; // top left corner (x, y)
    int w, h; // width, height
} Rectangle;

typedef struct {
    int x, y; // center (x, y)
    int r;    // radius
} Circle;

Rectangle make_rectangle(int x, int y, int w, int h) {
    Rectangle r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    return r;
}

Circle make_circle(int x, int y, int r) {
    Circle c;
    c.x = x;
    c.y = y;
    c.r = r;
    return c;
}

void print_rectangle(Rectangle r) {
    printf("Rectangle(%d, %d, %d, %d)\n", r.x, r.y, r.w, r.h);
}

void print_circle(Circle c) {
    printf("Circle(%d, %d, %d)\n", c.x, c.y, c.r);
}

typedef struct {
    ShapeTag tag;
    union {
        Rectangle r;
        Circle c;
    };
} Shape;

Shape *new_shape_rectangle(int x, int y, int w, int h) {
    Shape *s = xcalloc(1, sizeof(Shape));
    s->tag = RECTANGLE;
    s->r = make_rectangle(x, y, w, h);
    return s;
}

Shape *new_shape_circle(int x, int y, int r) {
    Shape *s = xcalloc(1, sizeof(Shape));
    s->tag = CIRCLE;
    s->c = make_circle(x, y, r);
    return s;
}

void print_shape(Shape *s) {
    switch (s->tag) {
        case RECTANGLE:
            printf("rectangle(%d, %d, %d, %d)\n", s->r.x, s->r.y, s->r.w, s->r.h);
            break;
        case CIRCLE :
            printf("circ(%d, %d, %d)\n", s->c.x, s->c.y, s->c.r);
            break;
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Rectangle bounding_box_shape(Shape *s) {
    if(s->tag == RECTANGLE) {
		return s->r;
	} else {
		return make_rectangle(s->c.x - s->c.r, s->c.y - s->c.r, 2 * s->c.r, 2 * s->c.r);

	}
}

void scale_shape(Shape *s, double factor) {
    if (s->tag == RECTANGLE) {
    	s->r.w = s->r.w * factor;
		s->r.h = s->r.h * factor;
    } else {
		s->c.r = s->c.r * factor;
	}
}

Rectangle bounding_box_rectangles(Rectangle a, Rectangle b) {
    int x = min(a.x, b.x);
	int y = min(a.y, b.y);

	int wx = max(a.x + a.w, b.x + b.w);
	int hy = max(a.y + a.h, b.y + b.h);

    return make_rectangle(x, y, wx - x, hy - y);
}

Rectangle bounding_box_list(List list) {
	Rectangle out = make_rectangle(0, 0, 0, 0);
	ListIterator it = l_iterator(list);
	for (Shape* s = l_get(list, 0); l_has_next(it); s = l_next(&it)) {
		if (s->tag == CIRCLE) {
			printf("Circle\n");
		} else {
			printf("RECTANGLE\n");
			if (s->tag == RECTANGLE) {
				printf("Confirmed\n");
			}
		}
	}
	// for (int i = 0; i < l_length(list); i++) {
    // 	if (i == 0) {
    // 		out = bounding_box_shape(l_get(list, i));
    // 	} else {
	// 		out = bounding_box_rectangles(bounding_box_shape(l_get(list, i)), out);
	// 	}
    // }
	// printf("%i %i %i %i", out.x, out.y, out.w, out.h);
    return out;
}

bool equals_shape(Shape *s, Shape *t) {
    if (s->tag != t->tag) return false;
    switch (s->tag) {
        case RECTANGLE:
            return s->r.x == t->r.x && s->r.y == t->r.y && s->r.w == t->r.w && s->r.h == t->r.h;
        case CIRCLE:
            return s->c.x == t->c.x && s->c.y == t->c.y && s->c.r == t->c.r;
    }
    return false;
}

bool equals_rectangle(Rectangle *s, Rectangle *t) {
    return s->x == t->x && s->y == t->y && s->w == t->w && s->h == t->h;
}

void bounding_box_shape_test(void) {
    Shape *s = new_shape_rectangle(10, 10, 20, 20);
    Rectangle actual = bounding_box_shape(s);
    Rectangle expected = make_rectangle(10, 10, 20, 20);
    check_expect_struct(&actual, &expected, equals_rectangle);
    free(s);

    s = new_shape_circle(10, 10, 20);
    actual = bounding_box_shape(s);
    expected = make_rectangle(-10, -10, 40, 40);
    check_expect_struct(&actual, &expected, equals_rectangle);
    free(s);
}

void scale_shape_test(void) {
    Shape *actual = new_shape_rectangle(10, 15, 20, 25);
    scale_shape(actual, 2.0);
    Shape *expected = new_shape_rectangle(10, 15, 40, 50);
    check_expect_struct(actual, expected, equals_shape);
    free(actual); free(expected);

    actual = new_shape_circle(10, 14, 20);
    scale_shape(actual, 3.0);
    expected = new_shape_circle(10, 14, 60);
    check_expect_struct(actual, expected, equals_shape);
    free(actual); free(expected);
}

void bounding_box_rectangles_test(void) {
    Rectangle actual = bounding_box_rectangles(
        make_rectangle(10, 20, 30, 40),
        make_rectangle(40, 30, 20, 10));
    Rectangle expected = make_rectangle(10, 20, 50, 40);
    check_expect_struct(&actual, &expected, equals_rectangle);

    actual = bounding_box_rectangles(
        make_rectangle(10, 20, 30, 40),
        make_rectangle(20, 30, 1, 1));
    expected = make_rectangle(10, 20, 30, 40);
    check_expect_struct(&actual, &expected, equals_rectangle);
}

void bounding_box_list_test(void) {
    List list = pl_create();
    pl_append(list, new_shape_circle(20, 30, 10));
    pl_append(list, new_shape_rectangle(90, 80, 10, 20));
    Rectangle actual = bounding_box_list(list);
    Rectangle expected = make_rectangle(10, 20, 90, 80);
    check_expect_struct(&actual, &expected, equals_rectangle);
    pl_free(list);

    list = pl_create();
    pl_append(list, new_shape_circle(24, 30, 5));
    pl_append(list, new_shape_rectangle(9, 10, 20, 20));
    pl_append(list, new_shape_circle(90, 90, 10));
    pl_append(list, new_shape_rectangle(20, 10, 5, 5));
    pl_append(list, new_shape_rectangle(40, 40, 10, 2));
    pl_append(list, new_shape_rectangle(50, 50, 10, 10));
    pl_append(list, new_shape_circle(59, 60, 10));
    actual = bounding_box_list(list);
    expected = make_rectangle(9, 10, 91, 90);
    check_expect_struct(&actual, &expected, equals_rectangle);
    pl_free(list);
}

int main(void) {
    base_init();
    base_set_memory_check(true);
    bounding_box_shape_test();
    scale_shape_test();
    bounding_box_rectangles_test();
    bounding_box_list_test();
    return 0;
}
