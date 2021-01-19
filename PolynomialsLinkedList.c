// Library files import
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Structure for holding the coefficient and power of a node
struct Poly_Node {
    int coef;
    int pow;
    struct Poly_Node* next;
};

// Function to create new node
void create_poly(int x, int y, struct Poly_Node** P) {
    struct Poly_Node *r, *z;
    z = *P;
    if (z == NULL) {
        r = (struct Poly_Node*)malloc(sizeof(struct Poly_Node));
        r->coef = x;
        r->pow = y;
        *P = r;
        r->next = (struct Poly_Node*)malloc(sizeof(struct Poly_Node));
        r = r->next;
        r->next = NULL;
    }
    else {
        r->coef = x;
        r->pow = y;
        r->next = (struct Poly_Node*)malloc(sizeof(struct Poly_Node));
        r = r->next;
        r->next = NULL;
    }
}

int main(void) {
	
	struct Poly_Node *poly1 = NULL;
	
	create_poly(2, 3, &poly1);
    create_poly(4, 1, &poly1);
    create_poly(2, 0, &poly1);
	
    return 0;
}
