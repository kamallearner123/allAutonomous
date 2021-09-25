
#include <stdio.h>

/*Rule
 *
 *1) It is height balanced
 *2) Every node is R/B
 *3) Root is B
 *4) NIL should be B
 *5) No of Bs from root to leaf nodes is same
 *6) No 2 consecutive R. chlid of R should be B
 *7) New inserted node is R
 *8) Maximum height: 2logn
 */
struct rb_tree {
    bool color;
    int id;
    char *name;

    struct rb_tree *right, *left;
};


int main(int argc, char **argv)
{
    printf("Let us start RB tree\n");
}
