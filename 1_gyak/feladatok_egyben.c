#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

void Szovegkitoltes();//2. feladat
void sleepTeszt();//3. feladat
int Random_Egesz(int min, int max, bool disp); //4. és 5. feladat
double Random_Lebegopontos(double min, double max); //4. és 5. feladat
void OsszeadasJatek();//6. feladat

int main() {
    Szovegkitoltes();
    sleepTeszt();
    Random_Egesz(700,1900,true);
    Random_Lebegopontos(700,1900);
    OsszeadasJatek();
    return 0;
}
//2. feladat
void Szovegkitoltes(){
    printf("%*s\n", 8, "A");
    printf("%*s\n", 8, "szoveg");
    printf("%*s\n", 8, "jobbra");
    printf("%*s\n", 8, "van");
    printf("%*s\n", 8, "igazitva.");
}
//3. feladat
void sleepTeszt(){
    printf("Hola\n");
    Sleep(4);
    printf("Adio's\n");

}
//4. és 5. feladat
int Random_Egesz(int min, int max, bool disp){
    if (min >= max)
    {
        printf("Nem jol adtunk intervallumot.(min >= max)!\n");
        return -1;
    }
    else
    {
        int num = (rand() % (max - min + 1)) + min;
        if (disp == true)
        {
            printf("A random egesz szam %d es %d kozott:\n", min, max);
            printf("%d\n", num);
        }
        return num;
    }
}
//4. és 5. feladat
double Random_Lebegopontos(double min, double max){
    if (min >= max)
    {
        printf("Nem jol adtunk intervallumot (min >= max)!\n");
        return -1;
    }
    else
    {
        printf("A random lebegopontos szam %f es %f kozott:\n", min, max);
        double part = ((double)rand()) / ((double)RAND_MAX);
        double num = part * (max - min) + min;
        printf("%f\n", num);
        return num;
    }
}
//6. feladat
void OsszeadasJatek(){
    int x = Random_Egesz(0,10, false);
    int y = Random_Egesz(0,10, false);
    int guess = -1;
    printf("Mennyi %d + %d?\n", x, y);
    clock_t time = clock();
    do
    {
        scanf("%d", &guess);
        if (guess != x+y)
            printf("Helytelen, probalja ujra!\n");
    }while(guess != x+y);
    time = clock()-time;
    double time_taken = ((double)time)/CLOCKS_PER_SEC;
    printf("Helyes valasz!\n");
    printf(" %f mp alatt valaszolta meg a kerdest.\n", time_taken);
}
