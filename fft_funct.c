#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fft_funct.h" // definition of fft_funct
#define PI 3.14159265358979323
#define N 4096   // maximum number of samples

// coefficients
double Wre[N/2];
double Wim[N/2];
// CalcolaW() declaration
void CalcolaW(int n);

void fft_funct(double * buffer, int size)
{    
    int posizioni[N] = {0};
    int i,j;
    int numerobit;
    int appoggio=0;
    int NC;
    float scarto;
    // variables for calculus of steps
    int k=0;
    int v=0;
    int a,b;    
    int incremento;
    int nBlocchi,elBlocco;
    // temporary vectors for storing values between steps
    double Xreapp[N] = {0};
    double Ximapp[N] = {0};
    // sequences 
    double Xre[N] = {0};
    double Xim[N] = {0};
    
    
    scarto = log2(size)-((int)log2(size)); 
    if (scarto >= 0.5)
        NC = pow(2,(((int)log2(size))+1));
    else
        NC = pow(2,((int)log2(size)));
    
    // bit inversion
    numerobit=log2(NC);       
    for (i=0; i<NC; i++)
    {
     appoggio =i;
     posizioni[i] = (appoggio&0x0001)|(posizioni[i]);
     for (j=0; j<(numerobit-1); j++)
        { 
            appoggio = appoggio >> 1;
            posizioni[i] = ((posizioni[i])<<1);
            posizioni[i] = (appoggio&0x0001)|(posizioni[i]);
        }
    }
    
    printf("size = %d \n", size);
    printf("NC = %d \n", NC);
    
    // sequences initialization     
    i=0;
    if (size>=NC)
    {
       while(i<NC)
        {
            Xre[posizioni[i]] = buffer[i];
            i=i+1;
        }
    }
    else
    {
       while(i<size)
        {
            Xre[posizioni[i]] = buffer[i];
            i=i+1;
        }  
        while(i<NC)
        {     
            Xre[posizioni[i]] =  0.0;
            i=i+1;
        }
    }  
    
    // coefficients calculation
    CalcolaW(NC);
  
    for(i=0;i<NC;i++)
    {
        Xreapp[i] = Xre[i]; 
        //Ximapp[i] = Xim[i];         
    }
 
 for(i=0;i<numerobit;i++)
 {    
    nBlocchi = NC /pow(2,i+1);
    incremento = NC /pow(2,i+1);
    elBlocco= NC/nBlocchi;
  
      for (a=0; a<nBlocchi; a++)
      {  
          
          for(b=0; b<(elBlocco/2); b++)
          {
           Xre[k]=Xreapp[k]+ (Wre[v]*Xreapp[k+(int)(pow(2,i))] - Wim[v]*Ximapp[k+(int)(pow(2,i))]);
           Xim[k]=Ximapp[k]+ (Wim[v]*Xreapp[k+(int)(pow(2,i))] + Wre[v]*Ximapp[k+(int)(pow(2,i))]);  
           
           Xre[k+(int)(pow(2,i))]=Xreapp[k]- (Wre[v]*Xreapp[k+(int)(pow(2,i))] - Wim[v]*Ximapp[k+(int)(pow(2,i))]); 
           Xim[k+(int)(pow(2,i))]=Ximapp[k]- (Wim[v]*Xreapp[k+(int)(pow(2,i))] + Wre[v]*Ximapp[k+(int)(pow(2,i))]); 
            
           v = v + incremento;
           if (i != 0)
             k = k+1;  
          }
          k = a*(elBlocco);
          k = k + (elBlocco);
          v=0;
      }
      k=0;
      // writing of next temporary vectors 
      for(j=0;j<NC;j++)
      {
        Xreapp[j] = Xre[j]; 
        Ximapp[j] = Xim[j];         
      }  
                
 } 
    
 // amplitude calculation 
 for(i=0;i<NC/2;i++)
 {            
    buffer[i] = pow(((Xre[i]*Xre[i])+(Xim[i]*Xim[i])),0.5)/NC*2.0;
 }    
   FILE* fptxtasc;
   fptxtasc = fopen("ascisse.txt","w");
  
   float step=44100/NC;
   for(i=0; i<(NC/2); i++)
   {
    fprintf(fptxtasc,"%2.3f\n",i*step);
   } 
}


// CalcolaW() definition
void CalcolaW(int n)
{
     int i;
     for (i=0;i<(n/2);i++)
     {
         Wre[i]=cos(2*PI*i/n);
         Wim[i]=-sin(2*PI*i/n);
   
     }
     
}
