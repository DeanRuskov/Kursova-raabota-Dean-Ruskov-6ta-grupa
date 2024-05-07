#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include "Kursova raabota Dean Ruskov 6ta grupa.h"
struct disklist {
    int x;
    disklist* next = NULL;
};
void add(int x, disklist** h)
{
    disklist* temp = (disklist*)malloc(sizeof(disklist));
    temp->x = x;
    temp->next = *h;
    *h = temp;
}
int pop(disklist** h)
{
    if (*h == NULL)return 0;
    else
    {
        disklist* temp;
        temp = (*h)->next;
        int x = (*h)->x;
        free(*h);
        *h = temp;
        return x;
    }
    disklist* temp;
    temp = (*h)->next;
    int x = (*h)->x;
    free(*h);
    *h = temp;
    return x;
}
int count(disklist* h)
{
    int a = 0;
    while (h != NULL)
    {
        if ((h)->x != 0)a++;
        h = h->next;
    }
    return a;
}
void color(int disk)
{
    if (disk % 3 == 1)printf("\033[0;37m");
    else if (disk % 3 == 2)printf("\033[0;31m");
    else printf("\033[0;32m");
}
void colorreset()
{
    printf("\033[0m");
}
void risuvai(int brdisk, disklist* ot, disklist* chrez, disklist* kum)
{
    int printdiskot, printdiskkum, printdiskchrez, razlikaOt, razlikaChrez, razlikaKum;
    razlikaOt = brdisk - count(ot);
    razlikaChrez = brdisk - count(chrez);
    razlikaKum = brdisk - count(kum);
    int shirina = (brdisk * 2) - 1;
    int n = 300;
    printf("\033[%d;%dH", (3), (0));
    for (int i = 0; i < brdisk; i++)
    {
        if (razlikaOt > 0)
        {
            for (int i = 0; i < shirina / 2; i++)
            {
                printf(" ");
            }
            printf("|");
            for (int i = 0; i < shirina / 2; i++)
            {
                printf(" ");
            }
            razlikaOt--;
        }
        else
        {
            printdiskot = (ot->x * 2) - 1;
            for (int i = 0; i < ((shirina - printdiskot) / 2); i++)
            {
                printf(" ");
            }
            for (int i = 0; i < printdiskot; i++)
            {
                color(printdiskot);
                printf("X");
                colorreset();
            }
            for (int i = 0; i < ((shirina - printdiskot) / 2); i++)
            {
                printf(" ");
            }
            ot = ot->next;
        }
        if (razlikaChrez > 0)
        {
            for (int i = 0; i < shirina / 2; i++)
            {
                printf(" ");
            }
            printf("|");
            for (int i = 0; i < shirina / 2; i++)
            {
                printf(" ");
            }
            razlikaChrez--;
        }
        else
        {
            printdiskchrez = (chrez->x * 2) - 1;
            for (int i = 0; i < ((shirina - printdiskchrez) / 2); i++)
            {
                printf(" ");
            }
            for (int i = 0; i < printdiskchrez; i++)
            {
                color(printdiskchrez);
                printf("X");
                colorreset();
            }
            for (int i = 0; i < ((shirina - printdiskchrez) / 2); i++)
            {
                printf(" ");
            }
            chrez = chrez->next;
        }
        if (razlikaKum > 0)
        {
            for (int i = 0; i < shirina / 2; i++)
            {
                printf(" ");
            }
            printf("|");
            for (int i = 0; i < shirina / 2; i++)
            {
                printf(" ");
            }
            razlikaKum--;
        }
        else
        {
            printdiskkum = (kum->x * 2) - 1;
            for (int i = 0; i < ((shirina - printdiskkum) / 2); i++)
            {
                printf(" ");
            }
            for (int i = 0; i < printdiskkum; i++)
            {
                color(printdiskkum);
                printf("X");
                colorreset();
            }
            kum = kum->next;
        }
        printf("\n");
    }
    Sleep(n);
}
void thanoi(disklist* ot, disklist* chrez, disklist* kum, int brdisk)
{
    int brdvij = pow(2, brdisk) - 1;
    int topdisk1, topdisk2, disk;
    for (int i = brdisk; i >= 1; i--)
    {
        add(i, &ot);
    }
    if (brdisk % 2 == 0)
    {
        disklist* temp = kum;
        kum = chrez;
        chrez = temp;
    }
    if (brdisk % 2 == 0) risuvai(brdisk, ot, kum, chrez);
    else risuvai(brdisk, ot, chrez, kum);
    for (int i = 1; i <= brdvij; i++)
    {
        if (i % 3 == 1)
        {
            int topdisk1 = pop(&ot);
            int topdisk2 = pop(&kum);
            disk = 0;
            if (topdisk1 == 0)
            {

                add(topdisk2, &ot);
                disk = topdisk2;
            }
            else if (topdisk2 == 0)
            {

                add(topdisk1, &kum);
                disk = topdisk1;
            }
            else if (topdisk1 > topdisk2)
            {

                add(topdisk1, &ot);
                add(topdisk2, &ot);
                disk = topdisk2;
            }
            else
            {

                add(topdisk2, &kum);
                add(topdisk1, &kum);
                disk = topdisk1;
            }
            if (brdisk % 2 == 0) risuvai(brdisk, ot, kum, chrez);
            else risuvai(brdisk, ot, chrez, kum);
        }
        else if (i % 3 == 2)
        {
            int topdisk1 = pop(&ot);
            int topdisk2 = pop(&chrez);
            if (topdisk1 == 0)
            {

                add(topdisk2, &ot);
                disk = topdisk2;
            }
            else if (topdisk2 == 0)
            {

                add(topdisk1, &chrez);
                disk = topdisk1;
            }
            else if (topdisk1 > topdisk2)
            {
                add(topdisk1, &ot);

                add(topdisk2, &ot);
                disk = topdisk2;
            }
            else
            {
                add(topdisk2, &chrez);

                add(topdisk1, &chrez);
                disk = topdisk1;
            }
            if (brdisk % 2 == 0) risuvai(brdisk, ot, kum, chrez);
            else risuvai(brdisk, ot, chrez, kum);
        }
        else if (i % 3 == 0)
        {
            int topdisk1 = pop(&chrez);
            int topdisk2 = pop(&kum);
            if (topdisk1 == 0)
            {

                add(topdisk2, &chrez);
                disk = topdisk2;
            }
            else if (topdisk2 == 0)
            {

                add(topdisk1, &kum);
                disk = topdisk1;
            }
            else if (topdisk1 > topdisk2)
            {
                add(topdisk1, &chrez);

                add(topdisk2, &chrez);
                disk = topdisk2;
            }
            else
            {
                add(topdisk2, &kum);

                add(topdisk1, &kum);
                disk = topdisk1;
            }

            if (brdisk % 2 == 0) risuvai(brdisk, ot, kum, chrez);
            else risuvai(brdisk, ot, chrez, kum);
        }

    }
    printf("gotov si shefski :)");
}
int main()
{
    printf("s kolko diska shte vurtim?\n");
    int n;
    scanf("%d", &n);
    //system("cls");
    disklist* a = new disklist();
    disklist* b = new disklist();
    disklist* c = new disklist();
    thanoi(a, b, c, n);
}