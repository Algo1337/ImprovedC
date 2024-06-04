/* 
*           [ICS]: ImprovedC Struct
*
*   - All Structs In ICS are to be typedef structs in C
* 
*   [ ICS Example ]
*   
*   
*   struct Person {
*       string name;
*       integer age;
*   }
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"

ICS *new_struct(char *struct_block) {
    ICS *ics = (ICS *)malloc(sizeof(ICS *));
    String *block_data = string(struct_block);

    long line_c = (long)block_data->Utils(block_data, _COUNTCH, '\n');
    if(line_c == 0) {
        long argc = (long)block_data->Utils(block_data, _COUNTCH, ' ');

        if(argc == 0)
            return ics;
            
        char **args = (char **)block_data->Utils(block_data, _SPLIT, ' ');
    }

    return ics;
}