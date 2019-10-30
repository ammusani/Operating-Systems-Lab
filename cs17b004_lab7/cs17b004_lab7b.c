#include<stdio.h>
#include<stdlib.h>
#define n 5
#define m 3
int main() {

    srand(04);

    int max[n][m];
    int allocate[n][m];
    int available[m];
    int need[n][m];

    printf("\nMAX RESOURCE:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            max[i][j] = rand() % 30;
            printf("%d\t", max[i][j]);
        }
        puts("");
    }

    printf("\nALLOCATION:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(max[i][j]) {
                allocate[i][j] = rand() % (max[i][j] + 1);
            }
            else allocate[i][j] = 0;
            
            need[i][j] = max[i][j] - allocate[i][j];
            printf("%d\t", allocate[i][j]);
        }
        puts("");
    }
    
    printf("\nAVAILABLE:\n");
    for(int i = 0; i < m; i++) {
        available[i] = rand() % 25;
        printf("%d\t", available[i]);
    }
    puts("");

    int fin[n] = {0};
    int count = 0;
    int l = 0;
    int soln[n] = {0};

    while(l < n) {
        int flag = 0;
        int flag2; 
        for(int i = 0; i < n; i++) {
            
            if(!fin[i]) {
                flag2 = 0;
                for(int j = 0; j < m; j++) {
                    if(need[i][j] > available[j]) {
                        flag2 = 1;
                        break;
                    }
                }
                if(!flag2) {
                    soln[l] = i;
                    l++;
                    
                    for(int o = 0; o < m; o++) 
                        available[o] = available[o] + allocate[i][o];
                    fin[i] = 1;
                    flag = 1;
                    count++;
                }
            }
        }
        if(!flag) break;
    }
    if(count == n) {
        printf("\nSAFE\n");
        printf("Process[%d]", soln[0]  + 1);
        for(int i = 1; i < n; i++) printf(" -> Process[%d]", soln[i] + 1);
        puts("");
    }
    else printf("\nUNSAFE\n");
}