#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int width;
    int height;
}Rectangle;
Rectangle* create(int width, int height);
void rescale(Rectangle* r, int factor);
void printRec(Rectangle* r);
int main() {
    Rectangle* r1 = create(3,3);
    printRec(r1);
    rescale(r1, 6);
    printRec(r1);
    return 0;
}
Rectangle* create(int width, int height)
{
    Rectangle* r = (Rectangle*)malloc(sizeof(Rectangle));
    if (r==NULL) return NULL;
    r->width = width>0? width: 1;
    r->height = height>0? height: 1;
    return r;
}
void rescale(Rectangle* r, int factor)
{
    if(factor<=0) return;
    r->width*=factor;
    r->height*=factor;
}
void printRec(Rectangle* r)
{
    printf("Width: %d\nHeight: %d\n", r->width, r->height);
}