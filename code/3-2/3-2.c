#include <stdio.h>

void swap_endian(int *x) {
    unsigned char* addr = (unsigned char*)x;
    unsigned char temp;
    int n = sizeof(int) / sizeof(addr[0]);
    for(int i = 0; i < n/2; i++) {
        temp = addr[i];
        addr[i] = addr[n-i-1];
        addr[n-i-1] = temp;
    }
}

int main() {
    int x = 0x12345678;

    printf("%x\n", x);
    swap_endian(&x);
    printf("%x\n", x);

    return 0;
}
