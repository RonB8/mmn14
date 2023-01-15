/*

 * */
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#ifndef MMN14_DATA_H
#define MMN14_DATA_H

#endif //MMN14_DATA_H
//מבנה שמכיל את כל הפרמטרים הנדרשים לפונקציות, מוגדר כמבנה כדי שיהיה אפשר להעביר את כל המשתנים בין הפונקציות ע"י כתובת אחת - של Vars
typedef struct {
    char firstWord[14];
    char addWord1[14]; //first additional word
    char addWord2[14]; //second additional word
    char currentWord[14]; //לתוכה תיכנס המילה שניקראה, יתבצע העיבוד, ואז המילה תועתק למילה הרלוונטית (מתוך ה3 למעלה)
    //      -flags-
    //דלוק = 1, כבוי = 0
    int mcrFlag; //נדלק אם זוהתה פקודת מאקרו("mcr"), נכבה אם זוהתה סוף פקודת מאקרו ("endmcr")
}Vars; //variables (אם יש לך שם יותר טוב מוזמן להציע)

//      -Functions-
//קורא את הword (שזה כל השורה) הבאה ושומר אותה ב-currentWord, נעצר בתו '\n' או בEOF
void readWord(Vars*);
//קבוצה 1 - {mov, cmp, add, sub, lea} מקבלות 2 אופרנדים
//קבוצה 2 - {not, clr, inc, dec, jmp, bne, red, prn, jsr} מקבלות אופרנד אחד, סיביות 4-5 חסרות משמעות
//קבוצה 3 - {rts, stop} אין אופרנדים, הקידוד מורכב ממילה אחת, סיביות 2-5 אינם בשימוש
int typeIncSet(Vars*); //מחזיר מספר מ1-3 שמייצג לאיזו קבוצת הוראות שייכת ההוראה הנוכחית
