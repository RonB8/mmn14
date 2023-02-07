//התכנית שלהלן מקבלת טקסט של קובץ כתוביות ומשנה את זמני הכתוביות באלפית שניה לפי ערך הnumToShift
//HEY
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
void readLine(FILE*);
int timeLine();
int isDigit(char ch);
int isCharOfTimeLine(char);
void resetFlags();
void shift();
int stringToNum(char* s);
void numToString(int n, char*);
void getParameters();
char curLine[30];
char from[13], until[13];
char fromNew[13], untilNew[13];
int hyphenFlag=0, colonFlag=0, greaterThenFlag=0, digitFlag=0, commaFlag=0;
int isEOF=0;
int signOfShift; //Its value will be 1 for acceleration, and minus 1 for delay
int MSToShift; //Millisecond to shift

int main() {
    int isTimeLine; //will function as a boolean variable
    FILE* file1 = fopen("C:\\Users\\user\\OneDrive - Open University of Israel\\programing\\c projects\\File for subtitle\\Loudermilk.S01E04.web-eSc.English-WWW.MY-SUBS.CO.srt", "r");
    FILE* file2 = fopen("C:\\Users\\user\\OneDrive - Open University of Israel\\programing\\c projects\\File for subtitle\\After shift\\Loudermilk.S01E04.web-eSc.English-WWW.MY-SUBS.CO.srt", "w");
    getParameters(); //The desired action and the desired change time
    while(!isEOF) {
        readLine(file1);
        isTimeLine = timeLine();
        if (isTimeLine) {
            strncpy(from, curLine, 13);
            strcpy(until, curLine + 17);
            shift();
            fprintf(file2,"%s --> %s\n", fromNew, untilNew);
        } else
            fprintf(file2, "%s\n", curLine);
    }
    puts("The change has been made");
    return 0;
}
//Receives the desired change time, and the desired action - acceleration or delay
void getParameters(){
    int ch;
    char operation[12];
    puts("Hello, the program below accelerates/delays subtitle display time.");
    puts("What action do you want to take?");
    puts("To accelerate press - 1 \\n To delay press - 2 \\n When finished press enter");
    while(ch!=1 && ch!=2){
        scanf("%i", &ch);
        if(ch==1) {
            signOfShift = 1;
            strcpy(operation, "acceleration");
            break;
        }
        else if(ch==2) {
            signOfShift = -1;
            strcpy(operation, "delay");
            break;
        }
        else
            puts("Error! Only 1 or 2 should be entered");
    }
    printf("Enter the desired %s time in milliseconds\n", operation);
    scanf("%d", &MSToShift);
}
void shift(){
    int n1, n2;
    n1= stringToNum(from);
    n2= stringToNum(until);
    n1+= MSToShift;
    n2+= MSToShift;
    numToString(n1, fromNew);
    numToString(n2, untilNew);
}
int stringToNum(char* s){
    int i=0;
    int result=0;
    while(i<13){
        if(s[i]<='9' && s[i]>='0'){
            result *= 10;
            result += s[i]-48;
        }
        i++;
    }
    return result;
}
void numToString(int n, char* s){
    int num=n;
    int i=11;
    char result[13] = {0};
    result[12]='\0';
    while(i>=0){
        if(i==8)
            result[i] = ',';
        else if(i==5 || i==2)
            result[i] = ':';
        else {
            result[i] = (num % 10)+48;
            num = num/10;
        }
        i--;
    }
    strcpy(s, result);
}
void readLine(FILE* file){
    char ch;
    int i=0;
    char s[70]={0};
    strcpy(curLine, s);
    while(ch != '\n'){
//        ch = getchar();
        ch = fgetc(file);
        if(ch == '\n')
            break;
        if(ch == -1){
            isEOF=1;
            break;
        }
        curLine[i++] = ch;
    }
    curLine[i]='\0';
}
int timeLine(){
    int result=1;
    char ch;
    int i=0;
    while(i < strlen(curLine)){
        ch = curLine[i++];
        if(!isCharOfTimeLine(ch)) {
            result = 0;
//            printf("The miss: %d\n", ch);
            break;
        }
    }
    result = result && digitFlag && greaterThenFlag && colonFlag && commaFlag && hyphenFlag;
    resetFlags();
    return result;
}
int isCharOfTimeLine(char ch){
    int result = 1;
    if(isDigit(ch)) digitFlag = 1;
    else if(ch == '-') hyphenFlag = 1;
    else if(ch == ',') commaFlag = 1;
    else if(ch == ':') colonFlag = 1;
    else if(ch == '>') greaterThenFlag = 1;
    else if(ch != ' ') result = 0;
    return result;
}
int isDigit(char ch){
    return ('0'<=ch && ch<='9');
}
void resetFlags(){
    hyphenFlag = colonFlag = greaterThenFlag = digitFlag = commaFlag = 0;
}
