
#include<stdio.h> //printf etc
#include<stdlib.h> //malloc, free, rand
#include<string.h>
//using namespace std;

// TODO char* is bullshit maybe
class DavidHash {
    private:
        int size;
        int elems;
        char** head;
        int hash(char* k, int k_size) {
            int ssf = 0; // sum so far
            for (int i = 0; i < k_size; i++) {
                ssf +=  (int)k[i];
                ssf %= size;
                printf("%d\n", ssf);
            }
            return ssf;
        }
    public:
        DavidHash(int s) {
            printf("hey im here\n");
            head = (char**) malloc(sizeof(int*) * s);
            memset(head, 0, sizeof(int*) * s);
            size = s;
            elems = 0;
        }
        void set(char* k, int k_size, char* v, bool debug=false) {
            int index = hash(k, k_size);
            if(debug) {
                printf("Setting key %s, indexed to %d, to store value %s", k, index, v);
            }
            head[index] = v;
        }
        char* get(char* k, int k_size, bool debug=false) {
            int index = hash(k, k_size);
            if(debug) {
                printf("Getting key %s as indexed to %d", k, index);
            }
            return head[index];
        }
};

void unitTest(int size) {
    DavidHash hash_table = DavidHash(size);

    int key_len = 4;
    char* key = (char*) malloc(key_len);
    memset(key, 0, key_len);
    sprintf(key, "hey");

    int value_len = 13;
    char* value = (char*) malloc(value_len);
    memset(value, 0, value_len);
    sprintf(value, "what's good?");
 
    hash_table.set(key, key_len-1, value, true);
    printf("%s\n", hash_table.get(key, key_len-1, true));
}

int main() {
    unitTest(10);
    unitTest(100);
    unitTest(1000);
    return 0;
}
