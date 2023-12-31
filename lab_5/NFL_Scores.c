/*
 * NFL Score
 * EECS 348
 * Author: Humzeh Al-Tamari
 * created: 10/15/2023
 * this program takes in a NFL score and returns all posible ways to get that score
 */

#include <stdio.h>
#include <stdlib.h>

void football()
{
    int safety = 2, touchconversion = 8, touchpat = 7, touchdown = 6, fieldGoal = 3;
    int score = 0;

    printf("Enter 0 or 1 to STOP \nEnter the NFL score: ");
    scanf("%d", &score);

    while (score > 1)
    {

        for (int i = 0; i <= score / 8; i++)
        {
            touchconversion++;
            for (int j = 0; j <= score / 7; j++)
            {
                touchpat++;
                for (int k = 0; k <= score / 6; k++)
                {
                    touchdown = k;
                    for (int l = 0; l <= score / 3; l++)
                    {
                        fieldGoal = l;
                        for (int m = 0; m <= score / 2; m++)
                        {
                            safety = m;
                            int n = (i * 8) + (j * 7) + (k * 6) + (l * 3) + (m * 2);
                            if (n == score)
                            {
                                touchconversion = i;
                                touchpat = j;
                                touchdown = k;
                                fieldGoal = l;
                                safety = m;
                                printf("%d TD + 2pt, %d TD + PAT, %d TD, %d FG, %d Safety\n", touchconversion, touchpat, touchdown, fieldGoal, safety);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    football(); 
    return 0;
}