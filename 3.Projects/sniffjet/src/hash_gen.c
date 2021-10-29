#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char ids[126];
static int sps_index,  id_ind, sp_max, max_key_len;
int *sps;

char *key =NULL;
#if 0
char* fill_other()
{
    if (max_key_len == sps_index) 
    {
        printf("Done with keys\n");
        return NULL;
    }

    if (id_ind >= sp_max)
    {
        sps_index++;
        id_ind = 0;
        fill_other();
    }

    /* Updates sps_index with id_ind */

    key[sps_index] = ids[id_ind];
    id_ind++;
    return key;
}
#endif

char *seq()
{
    
}



char *get_token(const char *comb, int key_len) 
{

    int i;
    if (comb != NULL)
    {
        for (int i =0; i<strlen(comb); i++)
        {
            ids[i] = comb[i];
        }
        ids [i] =0;

        sps_index = 0;
        sp_max = strlen(comb);
        max_key_len = key_len;
        key = calloc(1, key_len+1);

        sps = calloc(1, key_len);

        key[strlen(comb)] = 0;

        for (int i=0; i<key_len; i++)
        {
            key[i] = comb[0];
        }
        id_ind++;
        sps_index++;
//        return key;
    }

    return seq();

}

