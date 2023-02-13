#include "data.h"
//כיוון שהקבצים לקריאה ולכתיבה נמצאים על המחשב ולא בגיטהאב, אצל כל אחד כתובת הנתיב של הקובץ היא שונה, לכן הגדרתי header -paths שלא נמצא בגיטהאב, והוא מכיל את הקבועים שמייצגים את הכתובות של הקבצים לפי המחשב שלי, תיצור גם header כזה
#include "paths.h"
#include "globals.h"
#include <stdio.h>

static boolean make_process(char argv[]);

int main(int argc, char** argv) {
    int i;
    argv[0] = "C:\\filesForC\\originalCode"; //רק בשביל הרצה
    for (i = 0; i < 1; i++)
    {
        make_process(argv[i]);
    }

}


static boolean make_process(char* argv)
{
    FILE *file1, *file2;
    file1 = fopen(argv, "r");
    if(file1!=NULL)
        file2 = mcrLabelsSpread(file1);
    /*חלק של קדם אסמבלר*/




    /*חלק של מעבר ראשון*/
    int ic = IC_ADDRESS;   /**/
    int dc = 0;
    int l = 0;
    int line_counter = 0;
//    booleen error = FALSE;
    char temp_line[MAX_LINE_LEN];



}

