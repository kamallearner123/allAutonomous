#include <stdbool.h>
#include <stdlib.h>
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




void preorder_display(struct rb_tree *root) {

    if (root == NULL)
        return;

    preorder_display(root->left);
    printf("Addr = %p, id = %d\n", root, root->id);
    preorder_display(root->right);
    
    return;
}

void insert_node(struct rb_tree **rroot, int id) {
    struct rb_tree *root = *rroot;
    struct rb_tree *ptr = calloc(1, sizeof(struct rb_tree));
    ptr->id = id;

    if (root == NULL) {
        *rroot = ptr;
        return;
    }
        
    while(1) {
        //printf("Root->id = %d,", root->id);
        if (id > root->id) {
            if (root->right == NULL)
            {
                root->right = ptr;
                break;
            }
            root = root->right;
        }
        else {
            if (root->left == NULL) {
                root->left = ptr;
                break;
            }
            root = root->left;
        }
    }
    return;
}

void do_delete(struct rb_tree **pptr, struct rb_tree *root) {
    struct rb_tree *tmp = root;
    

    if (root->left == NULL) {
        *pptr = root->right;
        free(root);
        return;
    }

    *pptr = root->left;
    tmp = root->left;
    while(tmp->right != NULL)
        tmp = tmp->right;

    tmp->right = root->right;

    free (root);
}

int delete_node(struct rb_tree **rroot, int id) {
    struct rb_tree *root, **prev_root;
    root = *rroot;

    if (root == NULL)
        return 0;
    if (root->id == id) {
        do_delete(rroot, root);
        return 1;
    }
    
    while(root!= NULL) {
        if (id > root->id){
            prev_root = &root->right;
            root = root->right;
        }
        else if (id < root->id){
            prev_root = &root->left;
            root = root->left;
        }
    
    
        else {
            
            if ( (root->right == NULL) && (root->left == NULL)) {
                *prev_root = NULL;
                free(root);
            }
            else {
                do_delete(prev_root, root);
            }

            return 1;
        }

    }

    return 0;

}


int main(int argc, char **argv)
{
    struct rb_tree *root = NULL;
    printf("Let us start RB tree\n");

    int i,n,id;
    printf("How many elements ?:");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the number : ");
        scanf("%d", &id);
        insert_node(&root, id);
        printf("\n");
    }


    preorder_display(root);
    
    while(1) {
        printf("Enter the id:");
        scanf("%d", &id);

        if (1 == delete_node(&root, id)) {
            printf("Deleted the node\n");
            preorder_display(root);
        }
        else {
            printf("Node is not found\n");
            preorder_display(root);
            printf("Exiting....\n");
            break;
        }
    }

    preorder_display(root);
    
    return 0;
}
