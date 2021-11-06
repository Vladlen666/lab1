#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<locale.h>
main()      
{
  setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    long int  n = 0;
    long double min, max, sum = 0.0;
    double* mas1;
    int* mas2;
    int i , k = 0;
    printf("Введите значение min:  ");
    scanf_s("%lf", &min);
    printf("Введите значение max:  ");
    scanf_s("%lf", &max);
    printf("Введите значение n:  ");
    scanf_s("%ld", &n);
    if ((n <= 0)||(max<= min))
    {
        printf("Ошибка!!! (n <= 0)||(max<= min) ");
        return 0;
    }
    mas1 = (double*)malloc(n * sizeof(double));
    mas2 = (int*)malloc(n * sizeof(int));
    if (mas1 == 0||mas2==0)
    {
        printf("Ошибка!!! (mas1 == 0||mas2==0)");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        mas1[i] = (((double)rand() / RAND_MAX) * (max - min) + min);
        printf("%lf\n", mas1[i]);
        mas2[i] = ((mas1[i] - (int)mas1[i]) * 10000000);
        while (mas2[i] % 10 == 0)
            mas2[i] = mas2[i] / 10;
    }
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (i == mas2[k])
            {
                sum = sum - mas1[i];
            }
        }
    }
    for(i=0; i<n; i++)
    {
        sum = sum + mas1[i];
    }
    
    printf("СУММА=%lf\n", sum);
    free(mas1);
    free(mas2);
    return 0;
}