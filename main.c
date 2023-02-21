#include "hash.h"

int main (int argc, char** argv) {
    char input[100] = {0};
    struct Digest* digest;

    //geting input
    printf("Enter a input: ");
    scanf("%s", input);

    //testing hashing
    /*
    digest = SHA_40((const unsigned char*)input, strlen(input));
    for(int i = 0; i < DIGEST_SIZE; i++){
        //prints this out as decimal numbers but can be anyhting
        printf("%x ", digest->hash0);
        printf("%x ", digest->hash1);
        printf("%x ", digest->hash2);
        printf("%x ", digest->hash3);
        printf("%x ", digest->hash4);
    }
    */
    

   //testing digest_equal
   /*
    digest = SHA_40((const unsigned char*)input, strlen(input));
    char input2[100] = {0};
    printf("Enter a secondary input: ");
    scanf("%s", input2);
    struct Digest* digest2;
    digest2 = SHA_40((const unsigned char*)input2, strlen(input2));
    if(digest_equal(digest, digest2) == 1)
        printf("The digests are equal");
    else
        printf("The digests are not equal");

    return 0;
    */
    free(digest);
}

/*
modified to return a struct that represents a digest.
The method takes the entire string then for each letter it will do the hashing function
*/
struct Digest* SHA_40(const unsigned char* data, size_t size) {
    struct Digest* digest = (struct Digest*) malloc(DIGEST_SIZE);
    for(int i = 0; i < size; i++){
        if(data[i] != '\0'){
            for(int j = 0; j < 12; j++){
            if(j == 0){
                digest->hash0 = 11;
                digest->hash1 = 22;
                digest->hash2 = 33;
                digest->hash3 = 44;
                digest->hash4 = 55;
            }

            unsigned char F = ((digest->hash1 & digest->hash2) ^ digest->hash3);
            unsigned char E = F + (digest->hash0 >> 5) + data[i] + j;
            digest->hash0 = E;
            digest->hash1 = digest->hash0;
            digest->hash2 = digest->hash1 << 2; 
            digest->hash3 = digest->hash2;
            digest->hash4 = digest->hash3;

            }
        }else{
            break;
        }
    }

    return digest;
} // SHA_40 hash function 


/*
takes two digests and compares them to see if they are equal
dies this by comparing each byte in hte hash
*/
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