#include "hash.h"

int main (int argc, char** argv) {
    char input[100] = {0};


    printf("Enter a input: ");
    scanf("%s", input);
    
    for(int i = 0; i < strlen(input); i++){
        if(input[i] != '\0'){
                SHA_40((const unsigned char *) &input[i], strlen(input));
        }else{
            break;
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
    unsigned char* digest = (unsigned char*) malloc(DIGEST_SIZE*sizeof(unsigned char));
    if(digest[0] == '\0'){
        digest[0] = 11;
        digest[1] = 22;
        digest[2] = 33;
        digest[3] = 44;
        digest[4] = 55;
    }

    for(int j = 0; j < 12; j++){

        unsigned char F = ((digest[1] & digest[2]) ^ digest[3]);

        unsigned char E = F + (digest[0] >> 5) + *data + j;

        digest[0] = E;
        digest[1] = digest[0];
        digest[2] = digest[1] << 2; 
        digest[3] = digest[2];
        digest[4] = digest[3];
    }
    
    printf("Hash: %s\n", digest);
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