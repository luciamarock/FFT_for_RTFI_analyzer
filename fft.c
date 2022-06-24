#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fft_funct.h" // definition of fft_funct
#define PI 3.14159265358979323
#define N 4096   // maximum number of samples



int main(int argc, char *argv[])
{  
  int i;  
  int inizioDati = 0;  
  FILE* pf;  
  int size;
  short int valore;
  double buffer[N] = {0};
  
  pf=fopen("./audiofiles/short.wav","rb"); 
  if(pf == NULL)
  {
     printf("failed to open file\n");
  }
  else
  {         
  // read file 
    while(inizioDati<40)
     {
        fread(&valore,2,1,pf);        
        inizioDati = inizioDati + 2;
     }
    
    fread(&size,4,1,pf);
    size = size/2;  
    	
    if (size>N)
    printf("file too long");
    else
    {  
 
       for(i=0; i<size; i++)
       {
           fread(&valore,2,1,pf);  
           buffer[i] = (double)valore;
       }
    
    fft_funct(buffer, size);
    
    // txt files for printing the output       
    FILE* fptxt;
    fptxt = fopen("ampiezza.txt","w");
  
        for(i=0; i<N; i++)
        {    
            fprintf(fptxt,"%lf \n",buffer[i]);
        }  
    }
  }
  return 0;
}
