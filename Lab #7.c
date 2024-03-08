//
//  main.c
//  Lab 7
//
//  Created by Axel Diaz Bringuez on 3/8/24.
//

#include <stdio.h>

void bubble(int arr[], int n) {
    int i, p, temp;
    float tot_swap = 0;
    int swaps[n];
    
    for (i = 0; i < n; i++) {
        swaps[i] = 0;
    }
    for (i = 0; i < n - 1; i++) {
        for (p = 0; p < n - i - 1; p++) {
            if (arr[p] > arr[p + 1]) {
                temp = arr[p];
                arr[p] = arr[p + 1];
                arr[p + 1] = temp;
                swaps[p]++;
                tot_swap++;
                if (tot_swap == 7) {
                    temp = arr[p];
                    arr[p] = arr[p + 1];
                    arr[p + 1] = temp;
                    tot_swap += 0.5;
                    for (i = 0; i < n; i++) {
                        printf("%d is swapped %d \n", arr[i], swaps[i]);
                    }
                    printf("Total number of swaps: %.1f\n", tot_swap);
                    return;
                }
            }
        }
    }
    
    // Display number of swaps for each element
    for (i = 0; i < n; i++) {
        printf("%d is swapped %d \n", arr[i], swaps[i]);
    }
    printf("Total number of swaps: %.1f\n", tot_swap);
}

void selection(int arr[], int n) {
    int i, p, index, temp;
    float tot_swap = 0;
    int swaps[n];

    for (i = 0; i < n; i++) {
        swaps[i] = 0;
    }
    for (i = 0; i < n - 1; i++) {
        index = i;
        for (p = i + 1; p < n; p++)
            if (arr[p] < arr[index])
                index = p;
        
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        swaps[index]++;
        tot_swap++;
        if (tot_swap == 7) {  // Set the condition to halt after exactly 7 swaps
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            tot_swap += 0.5;  // Add 0.5 to represent 7.5 swaps
            // Display number of swaps for each element
            for (i = 0; i < n; i++) {
                printf("%d is swapped %d \n", arr[i], swaps[i]);
            }
            printf("Total number of swaps: %.1f\n", tot_swap);
        }
    }
    
    // Display number of swaps for each element
    for (i = 0; i < n; i++) {
        printf("%d is swapped %d \n", arr[i], swaps[i]);
    }
    printf("Total number of swaps: %.1f\n", tot_swap);
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    float n1 = sizeof(arr1) / sizeof(arr1[0]);
    float n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("array #1 bubble sort:\n");
    bubble(arr1, n1);
    printf("\n");
    
    printf("array #2 bubble sort:\n");
    bubble(arr2, n2);
    printf("\n");
    
    printf("array #1 selection sort:\n");
    selection(arr1, n1);
    printf("\n");
    
    printf("array #2 selection sort:\n");
    selection(arr2, n2);
    printf("\n");
    
    return 0;
}
