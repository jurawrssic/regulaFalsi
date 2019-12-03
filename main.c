#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

float f(float x);
int cr(float a, float b);

float a=-10, b=-5, criterio1=0.0005, criterio2=0, maxIt=100;
float m, x0, fx;

float f(float x){
    float y;
    return y = (float)((pow(x,2))-(9*x)+3);
}

int main()
{
    printf("\t- REGULA FALSI -\n\n");
    printf("Calculando f(a) e f(b) temos: \n\t   f(%0.0f)=%f \n\t   f(%0.0f)=%f \n", a, f(a), b, f(b));
    printf("\t   |b-a| = %f\n", fabs(b-a));
    if((f(a)*f(b)) < 0){
        printf("\nCondicao f(a)*f(b)<0 OK\n");

        for(int i=0; i<maxIt; i++){
            printf("\n\nIt: %d\n", i+1);
            printf("\n\t[a,b] = [%f, %f]", a, b);

            if(fabs(b-a) < criterio1){
                printf("\nTodo o intervalo entre %f e %f eh valido.\n", a, b);
                break;
            }

            if (cr(a,b)) break;

            m = f(a);
            x0 = ((a*f(b)) - (b*f(a)) / (f(b)-f((a))));
            fx = f(x0);

            printf("\n\tM recebe M=%0.0f\n", m);
            printf("\tO novo valor de x eh x=%f\n", x0);
            printf("\tA funcao fica f(x)=%f", fx);

            if(criterio2!=0){
                if(fx<criterio2){
                    printf("");
                    break;
                }
            }

            if((m*fx) > 0){
                printf("\n\n\tM*f(x) > 0, entao a=x \n\t\t\t  b=%f", fx);
                a = x0;
            }else{
                printf("\n\n\tM*f(x) < 0, entao b=x \n\t\t\t  b=%f", fx);
                b = x0;
            }

            if (cr(a,b)) break;

            if((fabs(b-a)) < criterio1){
                printf("\n\nTodo o intervalo entre %f e %f eh valido.", a, b);
                break;
            }
            if((i+1)==maxIt){
                printf("\n\nNumero de iteracoes excedido, execucao interrompida.");
            }
        }
    }else{
        printf("\nCondicao 'f(a)*f(b)<0' nao validada, execucao interrompida.");
        return;
    }
}

int cr(float a, float b){
    if(criterio2!=0){
        if((f(a)<criterio2) || (f(b)<criterio2)){
            printf("A ou B eh valido.");
            return 1;
        }
    }else{
        return 0;
    }
}
