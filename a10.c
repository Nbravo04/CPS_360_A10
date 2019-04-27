#include <stdio.h>

#define SETS 1024
#define LINES 4
struct cacheline{
    char valid; /* for valid/invalid entry */
    unsigned char age; /* for age of entry */
    int tag;
};
typedef struct cacheline cache;
cache l1[SETS * LINES];
int reference, miss; /* keep track of cache misses */

int main(void) {
    void initcache(void);

    initcache();

    return 0;
}

int checkargs(){

}

/* Design a module that prints out the correct way to use the
   program using the progname to get the name of the program
   ending the program afterwards.
   Takes progname and print out the correct usage of the program
   to stderr then exits the program with a failure.
   Called by main().
*/
void usage(char *progname)
{
    fprintf(stderr, "./%s <filepath> <start-address> <end-address>\n", progname); exit(1);
}

int isahit(unsigned ref){
    int indx = ((ref >> 6) & 0x3ff) << 2;
    int tag = (ref >> 16) & 0xffff;
    int i;

    for(i=0; i<4; i++){
        if(l1[indx+i].valid && l1[indx+i].tag == tag) break;
    }
    if(i == 4) return 0;
    return 1;
}

void initcache(void){
    int i, j, setindx;

    for(i=0; i<4; i++){
        setindx = i%4;
        if(i == 1) setindx <<2;
        if(i == 2) setindx <<4;
        if(i == 3) setindx <<6;
        for(j=0; j<3; j++){
            struct cacheline cl;
            cl.age = 0;
            cl.tag = 0;
            cl.valid = 0;
            l1[setindx+j] = cl;
        }
    }
}

void printrslts(unsigned ref){

}

void processref(){

}

void getnextref(){

}

void randomalgo(struct cacheline line){

}

void fifoalgo(struct cacheline line){

}
