/*Alogorithm to add 2 polynomials:

Step -1 : 1.Take two temporary pointers t1 and 12
          2.t1 runs on polynomial1
          3.t2 runs on polynomial2

Step -2 :  Run a loop as long as t1 != NULL && t2 != NULL

Step -3 :  Inside the loop
           there are 3 possibilites
       
           Posibility-1:
                 if t1->expo == t2->expo, then create a new_term with
                 coefficient = t1->coeff + t2 ->coeff
                 exponent = either t1->expo or t2->expo
                 and insert it into resultant linked list
                 move t1 to next node
                 move t2 to next node
          posibility-2:
                 if t1->expo > t2->expo,then create a new_term with
                 coefficent = t1->coeff
                 exponent = t1 -> expo
                 and insert it into resultant linked list
                 and only move t1 to next node
          posibility-3:
                if t1->expo < t2->expo,then create a new_term with
                 coefficent = t2->coeff
                 exponent = t2 -> expo
                 and insert it into resultant linked list
                 and only move t2 to next node
                
Step -4 : After coming out of loop, run 2 seperate loops on polynomials to
          insert any left over terms into the resultant linked list
 -----------ALOGORITM FOR POLYNOMIAL MULTIFLICATION-------------
  Step-1 : Take 2 temporary t1 and t2.
  Step-2 : set t1 = poly1 and t2 = poly2
  Step-3 : Take a varaibles res and set it to NULL initially(to store the result)
  Step-4 :
             Run a nested loop
              outer loop on poly1(as long as t!= NULL
                inner loop on poly2(as long as t2 != NULL
                  resultant term's coeff
                  r_coeff = t1.coeff * t2.coeff
                  resultant term's expo
				  r_expo = t1.expo + t2.expo
				  insert the term into resultant polynomial
				  set t2 back to poly2*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	float coeff;
	int expo;
	struct node *next;
};
typedef struct node NODE;
NODE* insert_a_term(NODE *head,float co,int ex) {
	NODE *nn_term = (NODE *)malloc(sizeof(NODE));
	nn_term -> coeff = co;
	nn_term -> expo =ex;
	nn_term -> next =NULL;
	if (head == NULL) {
		head = nn_term;
	}
	else {
		NODE *temp = head;
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = nn_term;
	}
	return head;
}
NODE* create_polynomial() {
	NODE *head = NULL;
	int n,i;
	printf("Enter no of terms: \n");
	scanf("%d",&n);
	for (i = 1;i <= n;i++) {
		float co;
		int ex;
		printf("Enter coeff of term %d: ",i);
		scanf("%f",&co);
		printf("Enter expo of term %d: ",i);
		scanf("%d",&ex);
		head=insert_a_term(head,co,ex);
	}
	return head;
}
void display_polynomial(NODE *head) {
	NODE *temp = head;
	while (temp != NULL) {
		printf("(%.fx^%d)",temp->coeff,temp->expo);
		if (temp->next != NULL) {
			printf(" + ");
		}
		else {
			printf("\n");
		}
		temp = temp -> next;
	}
}
NODE* poly_addition(NODE *poly1,NODE *poly2) {
	NODE *t1 = poly1;
	NODE *t2 = poly2;
	NODE *head = NULL;
	while(t1 != NULL && t2 != NULL) {
		if(t1->expo == t2 -> expo) {
			head = insert_a_term(head,t1->coeff+t2->coeff,t1->expo);
			t1 = t1 ->next;
			t2 = t2->next;
		}
		else if (t1->expo > t2 ->expo) {
			head = insert_a_term(head,t1->coeff,t1->expo);
			t1 = t1 -> next;
		}
		else {
			head = insert_a_term(head,t2->coeff,t2->expo);
			t2 = t2 ->next;
		}
	}
	while(t1 != NULL) {
		head = insert_a_term(head,t1->coeff,t2->expo);
		t1 = t1 -> next;
	}
	while(t2 != NULL) {
		head = insert_a_term(head,t2->coeff,t2->expo);
		t2 = t2 -> next;
	}
	return head;
}
NODE* poly_multiflication(NODE *poly1, NODE *poly2) {
	NODE *t1, *t2;
	t1 = poly1;
	t2 = poly2;
	NODE *res = NULL; //for resultant polynomial
	while (t1 != NULL) {
		while(t2 != NULL) {
			float r_coeff = t1 -> coeff *t2 -> coeff;
			int r_expo = t1 -> expo + t2 -> expo;
			res = insert_a_term(res, r_coeff,r_expo);
			t2 = t2 -> next;
	}
		t1 = t1 ->next;
		t2 = poly2;
	  
	}
	//simplifying
	NODE *temp = res;
	while(temp -> next != NULL) {
		if (temp -> expo == temp -> next -> expo) {
			temp -> coeff += temp -> next -> coeff;
			NODE *dn = temp -> next;
			temp -> next = temp -> next -> next;// connecting
			// free
			free(dn);
		}
		else {
			temp = temp -> next;
		}
	}
	return res;
}
	

int main() {
	printf("Polynomial 1: \n");
	NODE *poly1=create_polynomial();//creating poly1
	printf("Polynomial 2: \n");
	NODE *poly2=create_polynomial();//creating poly2
	//NODE *sum = poly_addition(poly1,poly2);
	NODE *pro = poly_multiflication(poly1,poly2);
	display_polynomial(poly1);
	display_polynomial(poly2);
	//display_polynomial(sum);
	display_polynomial(pro);
}

		               
                 
                 
                 
                 
