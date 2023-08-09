#ifndef FUNCTIONS_DEFINED
#define FUNCTIONS_DEFINED


void read(int *slots, int val, int slot);
void add(int *slots, int slot1, int slot2, int slot_result);
void sub(int *slots, int slot1, int slot2, int slot_result);
void mul(int *slots, int slot1, int slot2, int slot_result);
int divide(int *slots, int slot1, int slot2, int slot_result);
int sum_chosen(int *slots, int *chosen_slots);
int average_chosen(int *slots, int *chosen_slots);
void print(int *slots, int slot);

#endif