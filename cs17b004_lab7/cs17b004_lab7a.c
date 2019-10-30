#include<stdio.h>
#include<stdlib.h>
#define NUMRESOURCE 4
#define NUMPROCESS  3

static int total = NUMRESOURCE + NUMPROCESS;

void randomRequest(int RAGraph[total][total]) {
    srand(04);
    for(int i = 0; i < NUMPROCESS; i++) for(int j = NUMPROCESS; j < total; j++) 
        if(!RAGraph[j][i]) RAGraph[i][j] = rand() % 2;
        
}

void randomAllocation(int RAGraph[total][total]) {
    srand(04);
    for(int i = NUMPROCESS; i < total; i++) {
        int temp = rand() % 2;
        RAGraph[i][rand() % NUMPROCESS] = temp;
    }
}

int detectDeadlock(int RAGraph[total][total]) {
    
    int workForGraph[NUMPROCESS][NUMPROCESS];
    for(int i = 0; i < NUMPROCESS; i++) for(int j = 0; j < NUMPROCESS; j++) workForGraph[i][j] = 0;
    
    for(int i = 0; i < NUMPROCESS; i++) for(int j = NUMPROCESS; j < total; j++) {
        if(RAGraph[i][j]) {
            for(int k = 0; k < NUMPROCESS; k++) {
                if(RAGraph[j][k]) {
                    workForGraph[i][k] = 1;
                    break;
                }
            }
        }
    }
    
    printf("WORK FOR GRAPH:\n");
    for(int i = 0; i < NUMPROCESS; i++) {
        for(int j = 0; j < NUMPROCESS; j++) printf("%d ", workForGraph[i][j]);
        printf("\n");
    }
    printf("\n\n");

    int workForGraph2[NUMPROCESS][NUMPROCESS];
    for(int i = 0; i < NUMPROCESS; i++) for(int j = 0; j < NUMPROCESS; j++) workForGraph2[i][j] = workForGraph[i][j];
    
    int workForGraph3[NUMPROCESS][NUMPROCESS];
    for(int i = 0; i < NUMPROCESS; i++) for(int j = 0; j < NUMPROCESS; j++) workForGraph3[i][j] = 0;

    int isDeadlock = 0;
    for(int i = 2; i <= NUMPROCESS; i++) {
        for(int j = 0; j < NUMPROCESS; j++) {
            for(int k = 0; k < NUMPROCESS; k++) {
                for(int l = 0; l < NUMPROCESS; l++) {
                    workForGraph3[j][k] += workForGraph2[j][l] * workForGraph[l][k];
                }
                if(j == k && workForGraph3[j][k]) {
                    isDeadlock = 1;
                    break;
                }
            }
        }
        for(int i = 0; i < NUMPROCESS; i++) for(int j = 0; j < NUMPROCESS; j++) workForGraph2[i][j] = workForGraph3[i][j];
    }
    return isDeadlock;

}

int main() {
    int RAGraph[total][total];
    for(int i = 0; i < total; i++) for(int j = 0; j < total; j++) RAGraph[i][j] = 0;
    randomAllocation(RAGraph);
    randomRequest(RAGraph);
    
    printf("\nRAGraph:\n");
    for(int i = 0; i < total; i++) {
        for(int j = 0; j < total; j++) printf("%d ", RAGraph[i][j]);
        printf("\n");
    }
    printf("\n");

    if(detectDeadlock(RAGraph)) printf("Deadlock Present\n");
    else printf("Deadlock Absent\n");

    printf("\n");

    return 0;
}