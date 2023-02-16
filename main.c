#include "hash.h"

int main (int argc, char** argv) {
    char *seed = (char *) malloc(DIGEST_SIZE*sizeof(char));
    char input[100] = {0};
    seed[0] = 11;
    seed[1] = 22;
    seed[2] = 33;
    seed[3] = 44;
    seed[4] = 55;

    printf("Enter a input: ");
    scanf("%s", input);
    
    for(int i = 0; i < strlen(input); i++){
        if(input[i] != '\0'){
            for(int j = 0; j < 12; j++){
                SHA_40(input[i], strlen(input));
            }
        }
    }

    /*
    printf("Input: %s\n", input);
    for(int i =0; i < 5; i++){
        printf("Seed[%d]: %d\n", i, seed[i]);
    }
    */
    return 0;
}

unsigned char* SHA_40(const unsigned char* data, size_t size) {

    return 0;
} // SHA_40 hash function 


int digest_equal(struct Digest *digest1, struct Digest *digest2) { //return 1 (true) or 0 (false)
    int result;

    if(digest1->hash0 == digest2->hash0 && digest1->hash1 == digest2->hash1 &&
     digest1->hash2 == digest2->hash2 && digest1->hash3 == digest2->hash3 && 
     digest1->hash4 == digest2->hash4)
        result = 1;
    else
        result = 0;

    return result;
}