#include <math.h>
#include "nr.h"
#include "gaussj.c"
#include "nrutil.c"
#include "nrutil.h"

int main(){

  //k/m=1
  //w=sqrt(k/m) => w=1
  int w=1;
  float v=0;
  float A=1;
  float h=0.1;
  int n=300;
  float y=((w*w)*(h*h))-2;

  float **a, **b;
  int i=0;
  int j=0;

  a=matrix(1,n,1,n);
  b=matrix(1,n,1,1);

  // macierz z wynikiem i jej wypisanie
  b[1][1]=A;
  b[1][2]=v*h;
  //printf("%f \n%f \n", b[1][1], b[1][2]);
  for(i=3;i<n;i++){
    b[1][i]=0;
    //printf("%f \n",b[1][i]);
  }

  for(i=1; i<n+1; i++){
    a[i][i]=1;
    //printf("\n");
    if(i-1>0){
      a[i][i-1]=y;
    }
    if(i-2>0){
      a[i][i-2]=1;
    }
  }
  a[2][1]=-1;
  gaussj(a,n,b,1);

  FILE *fp=fopen("dane.dat","w");
  for(i=1; i<n; i++){
    // fprintf(fp," 0 0 ");
    fprintf(fp," %f %f \n",h*i, b[i][1]);
  }
  fclose(fp);
  return 0;
}
