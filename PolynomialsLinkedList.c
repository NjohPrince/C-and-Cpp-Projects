// Including Library files to be used 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Structure for holding the coefficient and power of a node
struct Poly_Node {
    int coef;
    int pow;
    struct Poly_Node *next;
};

void create_poly(struct Poly_Node **P) {
    int flag; //A flag to control if the user is done entering terms
    int coef, pow;
    struct Poly_Node * tmp_node; //To hold the temporary last address
    tmp_node = (struct Poly_Node *)malloc(sizeof(struct Poly_Node)); //create the first node
    *P = tmp_node; //Store the head address to the reference variable
    do {
        //Get the coefficient and power
        printf("\nEnter the coefficient of then term: ");
        scanf("%d", &coef);
        tmp_node->coef = coef;
        printf("Enter the power of the term: ");
        scanf("%d", &pow);
        tmp_node->pow = pow;
 
        //Now increase the Linked on user condition
        tmp_node->next = NULL;
 
        //Ask user for continuation
        printf("\nAdd another term to the polynomial list?(Yes = 1 / N0 = 0): ");
        scanf("%d", &flag);
        
        //Grow the linked list on condition
        if(flag) {
            tmp_node->next = (struct Poly_Node *) malloc(sizeof(struct Poly_Node)); //Grow the list
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}

void add_poly(struct Poly_Node **R, struct Poly_Node *P, struct Poly_Node *Q) {
    struct Poly_Node * tmp_node; //Temporary storage for the linked list
    tmp_node = (struct Poly_Node*) malloc(sizeof(struct Poly_Node));
    tmp_node->next = NULL;
    *R = tmp_node; //Copy the head address to the result linked list
 
    //Loop while both of the linked lists have value
    while(P && Q) {
        if (P->pow > Q->pow) {
            tmp_node->pow = P->pow;
            tmp_node->coef = P->coef;
            P = P->next;
        }
        else if (P->pow < Q->pow) {
            tmp_node->pow = Q->pow;
            tmp_node->coef = Q->coef;
            Q = Q->next;
        }
        else {
            tmp_node->pow = P->pow;
            tmp_node->coef = P->coef + Q->coef;
            P = P->next;
            Q = Q->next;
        }
 
        //Grow the linked list on condition
        if(P && Q) {
            tmp_node->next = (struct Poly_Node*) malloc(sizeof(struct Poly_Node));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
 
    //Loop while either of the linked lists has value
    while(P || Q) {
        //We have to create the list at beginning
        //As the last while loop will not create any unnecessary node
        tmp_node->next = (struct Poly_Node*) malloc(sizeof(struct Poly_Node));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
 
        if(P) {
            tmp_node->pow = P->pow;
            tmp_node->coef = P->coef;
            P = P->next;
        }
        if(Q) {
            tmp_node->pow = Q->pow;
            tmp_node->coef = Q->coef;
            Q = Q->next;
        }
    }
 
    printf("Addition Complete\n");
}

//Evaluation of the Polynomial
int eval_poly(struct Poly_Node *P, int val)
{
	struct Poly_Node *tmp_node;
	tmp_node = P;
	int result = 0;
	while(tmp_node != NULL) 
	{
		result += tmp_node->coef * pow(val, tmp_node->pow);
		tmp_node = tmp_node->next;
	}
	return result;
}

// Display polynomial
void display_poly(struct Poly_Node *P) {
	if(P == NULL){
		printf("has no terms yet\n");
	}else{
	    while(P != NULL) {
	        printf("%dx^%d", P->coef, P->pow);
	        P = P->next;
	        if(P != NULL)
	            printf(" + ");
	    }
	}
}

// Display Polynomial's degree
int degree_poly(struct Poly_Node *P) {
	struct Poly_Node *tmp_node;
	tmp_node = P;
	int max = 0;
    while (tmp_node != NULL) {
        if(tmp_node->pow > max)
        	max = tmp_node->pow;
        tmp_node = tmp_node->next;
    }
    return max;
}

// main function 
int main(void) {
	
	struct Poly_Node *poly_1 = NULL, *poly_2 = NULL, *poly_sum = NULL, *poly_prod = NULL;
	
	printf("Polynomials Using A Linked List\n");
	printf("-------------------------------\n\n");
	int choice = 1, numOfTerms, i, x;
	do{
		printf("1. Create Polynomials P(x) and Q(x)\n");
		printf("2. Display P(x)\n");
		printf("3. Display Q(x)\n");
		printf("4. Display degree of P(x)\n");
		printf("5. Display degree of Q(x)\n");
		printf("6. Evaluate P(x) at a certain value of x\n");
		printf("7. Evaluate Q(x) at a certain value of x\n");
		printf("8. Add P(x) and Q(x)\n");
		printf("9. Multiply P(x) and Q(x)\n");
		printf("0. Terminate Program\n\n");
		
		printf("Choose an option: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch(choice){
			case 1:
				printf("Creating P(x)\n");
				printf("-------------\n");
			    create_poly(&poly_1);
			    printf("\nCreating Q(x)\n");
				printf("-------------\n");
			    create_poly(&poly_2);
        		printf("\nDone creating Polynomials\n\n");
				break;
			case 2:
				printf("Polynomial P(x): ");
				display_poly(poly_1);
				printf("\n\n");
				break;
			case 3:
				printf("Polynomial Q(x): ");
				display_poly(poly_2);
				printf("\n\n");
				break;
			case 4:
				printf("P(x) is a polynomial of degree: %d\n\n", degree_poly(poly_1));
				break;
			case 5:
				printf("Q(x) is a polynomial of degree: %d\n\n", degree_poly(poly_2));
				break;
			case 6:
				if(poly_1 == NULL){
					printf("Polynomial P(x) has no terms yet\n\n");
				}else{
					printf("Enter the value of x for evaluation of P(x): ");
					scanf("%d", &x);
					printf("After evaluating P(%d), answer is: %d\n", x, eval_poly(poly_1, x));
				}
				break;
			case 7:
				if(poly_2 == NULL){
					printf("Polynomial Q(x) has no terms yet\n\n");
				}else{
					printf("Enter the value of x for evaluation of Q(x): ");
					scanf("%d", &x);
					printf("After evaluating Q(%d), answer is: %d\n", x, eval_poly(poly_2, x));
				}
				break;
			case 8:
				if(poly_2 == NULL || poly_1 == NULL){
					printf("Please create polynomials first\n\n");
				}else{
					add_poly(&poly_sum, poly_1, poly_2);
					printf("\nResult of addition of P(x) and Q(x): ");
					display_poly(poly_sum);
					printf("\n\n");
				}
				break;
			case 9:
				break;
			case 0:
				printf("Program Terminated...\n");
				break;
			default:
				printf("Invalid Option... Please kindly select from the available options\n\n");
		}
	} while(choice != 0);
	
    return 0;
}
