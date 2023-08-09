
#include "vector.h"

//gcc vectormain.c vector.c -o test_vector
//./test_vector 5 a 3 r 0 append 9 retrieve 1 aaaaa 8 r 0 r 2
//./test_vector 5 a 3 r 0 append 9 retrieve 1 aaaaa 8 r 0 r 2 i 0 4 r 0 r 1 r 2 r 3 e 0 r 0 r 1 r 2
int main(int argc, char* argv[])
{
    if (argc >= 2) {
        int cap, idx;
        if (sscanf(argv[1], "%d", &cap) != 1) exit(-1);
        Vector v;
        if (!initialize(&v, cap)) exit(-1);
        int i = 2;
        while (i+1 < argc) {
            switch (argv[i][0]) {
            case 'a': sscanf(argv[i+1], "%d", &cap) == 1 && append(&v, cap); break;
            case 'r': sscanf(argv[i+1], "%d", &cap) == 1 && printf("%d\n", retrieve(&v, cap)); break;
            case 'e': sscanf(argv[i+1], "%d", &cap) == 1 && erase(&v, cap); break;
            case 'i': sscanf(argv[i+1], "%d", &idx) == 1 &&
                sscanf(argv[i+2], "%d", &cap) == 1 && insert(&v, idx, cap); i++; break;
            default: exit(-1); break;
            }
            i+= 2;
        }
        dispose(&v);
    }
}