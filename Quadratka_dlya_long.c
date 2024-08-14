#include <stdio.h>
#include <math.h>
#define typ long

long mpow(long, long);

int main(){
    typ a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);
    if (a==0){
        if (b==0){
            if (c==0){
                printf("Roots are all numbers\n");
                return 1;
            }else{
                printf("Roots don't exist\n");
                return 1;
            }
        }else{
            printf("There is only one root. x = %ld / %ld", -c,b);
            return 1;
        }
    }
    typ d = b * b - 4 * a * c;
    if (d<0){
        printf("There are no roots\n");
        return 1;
    }else if (d==0){
        if (b%2==0){
            printf ("Roots are similar and equal %ld \n", -b/2);
            return 1;
        }else{
            printf ("Roots are similar and equal %.1f \n", (float)(-b)/2);
            return 1;
        }
    }
    typ del[d/2+1];
    typ r = d / 2;
    for (typ i=2; i <= r; i++){
        del[i]=0;
        if (d%i==0){
            while (d%i==0){
                d/=i;
                del[i]++;
            }
        }
    }
    if (d==1){
        typ k=1;
        for (typ i=2; i <= r; i++){
            k*=mpow(i,(del[i]/2));
            d*=mpow(i,(del[i]%2));
        }
        if (d==1){
            if ((b+k)%2==0){
                printf(" x1 = %ld \n x2 = %ld \n", -(b-k)/2, -(b+k)/2);
            }else{
                printf(" x1 = %.1f \n x2 = %.1f \n", ((float)(-b+k))/2, ((float)(-b-k))/2);
            }
        }else{
        if (k>0){
            if ((b%2==0) && (k%2==0)){
                printf (" x1 = %ld + %ld * √%ld \n x2 = %ld - %ld * √%ld \n", -b/2, k/2, d, -b/2, k/2, d);
            }else{
                printf (" x1 = (%ld + %ld * √%ld) / 2 \n x2 = (%ld - %ld * √%ld) / 2 \n", -b, k, d, -b, k, d);
            }
        }else{
            if ((b%2==0) && (k%2==0)){
                printf (" x1 = %ld + %ld * √%ld \n x2 = %ld - %ld * √%ld \n", -b/2, -k/2, d, -b/2, -k/2, d);
            }else{
                printf (" x1 = (%ld + %ld * √%ld) / 2 \n x2 = (%ld - %ld * √%ld) / 2 \n", -b, -k, d, -b, -k, d);
            }
        }
        }
    }

}

long mpow (long a, long b)
{
    long k = 1;
    for (long i = 0; i<b; i++)
        k*=a;
    return k;
}
