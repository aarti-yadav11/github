#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (newNode == NULL) return;

    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->exp >= exp) {
        current = current->next;
    }

    if (current->exp == exp) {
        current->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = poly;
    int first = 1;

    while (temp != NULL) {
        if (temp->coeff != 0) {
            if (!first && temp->coeff > 0) {
                printf(" + ");
            } else if (temp->coeff < 0) {
                printf(" - ");
            }

            int absCoeff = abs(temp->coeff);
            
            if (absCoeff != 1 || temp->exp == 0) {
                printf("%d", absCoeff);
            }

            if (temp->exp > 0) {
                printf("x");
                if (temp->exp > 1) {
                    printf("^%d", temp->exp);
                }
            }
            first = 0;
        }
        temp = temp->next;
    }
    printf("\n");
}

void freePolynomial(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node* poly = NULL;
    int numTerms, coeff, exp;

    printf("Enter the number of terms: ");
    if (scanf("%d", &numTerms) != 1) return 1;

    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        if (scanf("%d %d", &coeff, &exp) != 2) return 1;
        insertTerm(&poly, coeff, exp);
    }

    printf("The polynomial is: ");
    printPolynomial(poly);

    freePolynomial(poly);
    return 0;
}
