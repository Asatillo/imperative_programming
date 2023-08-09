#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"


void read(int *slots,  int val, int slot){
    slots[slot] = val;
    //printf("The valuse %d was defined to the slot #%d.\n", val, slot);
}

void add(int *slots, int slot1, int slot2, int slot_result){
    slots[slot_result] = slots[slot1] + slots[slot2];
}

void sub(int *slots, int slot1, int slot2, int slot_result){
    slots[slot_result] = slots[slot1] - slots[slot2];
}

void mul(int *slots, int slot1, int slot2, int slot_result){
    slots[slot_result] = slots[slot1] * slots[slot2];
}

int divide(int *slots, int slot1, int slot2, int slot_result){
    slots[slot_result] = slots[slot1] / slots[slot2];
}

int sum_chosen(int *slots, int *chosen_slots){
    int size = (sizeof(chosen_slots)/sizeof(int));
    int sum = 0; 
    for (int i = 0; i<size; i++){
        sum += slots[chosen_slots[i]];
    }
    return sum;
    //printf("Sum of the chosen slots is %d", sum);
}

int average_chosen(int *slots, int *chosen_slots){
    int size = (sizeof(chosen_slots)/sizeof(int));
    int sum = sum_chosen(slots, chosen_slots);
    return (sum/size);
    //printf("Sum of the chosen slots is %d", (sum/size));
}

void print(int *slots, int slot){
    printf("%d\n", slots[slot]);
}