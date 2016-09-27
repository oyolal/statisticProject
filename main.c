//
//  main.c
//  Statistic Project
//
//  Created by Ömer Yolal on 4/30/16.
//  Copyright © 2016 Ömer Yolal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int min,med,mod,max;
    int arr[11];
    printf("Enter the minimum number please: ");
    scanf("%d", &min);
    arr[0] = min;
    printf("Enter the maximum number please: ");
    scanf("%d", &max);
    while(max < min){
    //Not allowing user to input impossible case for max, which max is less than min
        printf("The maximum number you have entered cannot be less than minimum number.\n");
        printf("Please re-enter maximum number: ");
        scanf("%d", &max);
    }
    arr[10] = max;
    printf("Enter the median please: ");
    scanf("%d", &med);
    //median which is middle number cannot be less than min or more than max so i am forcing user to
    //enter suitable number
    while (med < min || med > max) {
        printf("Median cannot be less than min or more than max.\n");
        printf("Please re-enter median: ");
        scanf("%d", &med);
    }
    arr[5] = med;
    printf("Please enter the mode: ");
    scanf("%d", &mod);
    //mod cannot be more than max number or less than min so i am forcing user to
    //enter suitable number
    while(mod > max || mod < min){
        printf("Mode cannot be less than min or more than max.\n");
        printf("Please re-enter mode: ");
        scanf("%d", &mod);
    }
    //assigning numbers before median to mod if mod is less than median
    if (mod < med){
        arr[1] = arr[2] = arr[3] = arr[4] = mod;
        arr[6] = arr[7] = med;
        arr[8] = arr[9] = max;
    //assigning numbers after median to mod if mod is more than median
    }else if(mod > med){
        arr[9] = arr[6] = arr[7] = arr[8] = mod;
        arr[1] = arr[2] = min;
        arr[3] = arr[4] = med;
    //if median and mode are equal filling the data set with that number
    }else{
        for (int i=1; i<10; i++) {
            arr[i] = mod;
        }
    }
    //Excluding impossible casses
    if((med == max && mod < med) || (med == min && mod > med)){
        printf("Impossible Data-Set");
    }else{
        printf("Your data-set is: \n");
        for (int j=0; j<11; j++){
            printf(" %d ", arr[j]);
        }
    }
    return 0;
}
