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

// Function Adding two polynomial numbers
void add_poly(struct  Poly_Node* R, struct  Poly_Node* P, struct  Poly_Node* Q) {
    while (R->next && P->next) {
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st as it is and move its pointer
        if (R->pow > P->pow) {
            Q->pow = R->pow;
            Q->coef = R->coef;
            R = R->next;
        }
 
        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd as it is and move its pointer
        else if (R->pow < P->pow) {
            Q->pow = P->pow;
            Q->coef = P->coef;
            P = P->next;
        }
 
        // If power of both polynomial numbers is same then
        // add their coefficients
        else {
            Q->pow = R->pow;
            Q->coef = R->coef + P->coef;
            R = R->next;
            P = P->next;
        }
 
        // Dynamically create new node
        Q->next
            = (struct Poly_Node*)malloc(sizeof(struct Poly_Node));
        Q = Q->next;
        Q->next = NULL;
    }
    while (R->next || P->next) {
        if (R->next) {
            Q->pow = R->pow;
            Q->coef = R->coef;
            R = R->next;
        }
        if (P->next) {
            Q->pow = P->pow;
            Q->coef = P->coef;
            P = P->next;
        }
        Q->next
            = (struct Poly_Node*)malloc(sizeof(struct Poly_Node));
        Q = Q->next;
        Q->next = NULL;
    }
}

// Display Polynomial
void display_poly(struct Poly_Node *P) {
    while (P->next != NULL) {
        printf("%dx^%d", P->coef, P->pow);
        P = P->next;
        if (P->coef >= 0) {
            if (P->next != NULL)
                printf("+");
        }
    }
}

int main(void) {
	
	struct Poly_Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
	
	create_poly(2, 3, &poly1);
    create_poly(4, 1, &poly1);
    create_poly(2, 0, &poly1);
    
    printf("\nFirst Polynomial: ");
    display_poly(poly1);
    printf("\n");
    
    create_poly(1, 3, &poly2);
    create_poly(1, 1, &poly2);
    create_poly(2, 0, &poly2);
    
    printf("Second Polynomial: ");
    display_poly(poly2);
    
    poly = (struct Poly_Node*)malloc(sizeof(struct Poly_Node));
 
    add_poly(poly1, poly2, poly);
 
    printf("\n\nSum of the two Polynomial: ");
    display_poly(poly);
	
	
    return 0;
}
