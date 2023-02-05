#include "globals.h"

#include <stdio.h>

static boolean make_process(char* argv[i]);

int main(int argc, char* argv[]) {
    int i;

    for (i = 0; i < argc; i++)
    {
        make_process(argv[i]);
    }

}


static boolean make_process(char* argv[i])
{
    FILE* file;
    /*חלק של קדם אסמבלר*/




     /*חלק של מעבר ראשון*/
     int ic = IC_ADDRESS;   /**/
     int dc = 0;
     int l = 0;
     int line_counter = 0;
     booleen error = FALSE;
     char temp_line[MAX_LINE_LEN];
     

     
}

