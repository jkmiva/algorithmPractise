/**
 * Huang Jiaming
 * UofS, saskatoon, Canada
 * 18.07.2016
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class AlignedMalloc{
public:
    void *aligned_malloc(size_t required, size_t alignment){
        void *p1;               // initial block
        void *p2;               // aligned block
        int offset = alignment - 1 + sizeof(void *); // allocate memory to store address of p1, for free ues
        if((p1 = (void *)malloc(required + offset)) == NULL){
            return NULL;
        }
        p2 = (void *)(((size_t)p1 + offset) & ~(alignment - 1));
        // cout << p2 << endl << p1 << endl; // for test
        ((void **)p2)[-1] = p1; // treat p2 as an array of void*, store and retrieve p1 at the index -1.
        // ((void **)p2)[0] = p2; // for test
        // cout << ((void **)p2)[0] << endl; // for test
        return p2;
    }
    void aligned_free(void *p2){
        void *p1 = ((void **)p2)[-1];
        free(p1);
    }
};

// int main(){
//     AlignedMalloc a;
//     a.aligned_malloc(12, 8);
//     return 0;
// }
