#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

void usage(void){
    printf("syntax : add-nbo <file1> <file2\n");
    printf("syntax : add-nbo a.bin c.bin\n");
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        usage();
        return -1;
    }

    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "r");

    if(fp1 == NULL || fp2 == NULL) return -1;

    uint32_t a1, a2;
    if(fread(&a1, 1, 4, fp1) != 4) return -1;
    if(fread(&a2, 1, 4, fp2) != 4) return -1;
    a1 = ntohl(a1);
    a2 = ntohl(a2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a1, a1, a2, a2, a1+a2, a1+a2);
}
