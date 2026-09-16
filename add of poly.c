#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

int readPolynomial(struct Term p[]) {
    int t;
    printf("Enter the number of terms: ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &p[i].coeff, &p[i].exp);
    }
    return t;
}

int addPolynomials(struct Term p1[], int t1, struct Term p2[], int t2, struct Term p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].exp > p2[j].exp) {
            p3[k] = p1[i];
            i++;
            k++;
        } else if (p1[i].exp < p2[j].exp) {
            p3[k] = p2[j];
            j++;
            k++;
        } else {
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            if (p3[k].coeff != 0) {
                k++;
            }
        }
    }

    while (i < t1) {
        p3[k] = p1[i];
        i++;
        k++;
    }

    while (j < t2) {
        p3[k] = p2[j];
        j++;
        k++;
    }

    return k;
}

void displayPolynomial(struct Term p[], int t) {
    for (int i = 0; i < t; i++) {
        printf("%dx^%d", p[i].coeff, p[i].exp);
        if (i < t - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term p1[50], p2[50], p3[100];
    int t1, t2, t3;

    printf("For First Polynomial:\n");
    t1 = readPolynomial(p1);

    printf("\nFor Second Polynomial:\n");
    t2 = readPolynomial(p2);

    t3 = addPolynomials(p1, t1, p2, t2, p3);

    printf("\nFirst Polynomial: ");
    displayPolynomial(p1, t1);

    printf("Second Polynomial: ");
    displayPolynomial(p2, t2);

    printf("Resultant Polynomial: ");
    displayPolynomial(p3, t3);

    return 0;
}
