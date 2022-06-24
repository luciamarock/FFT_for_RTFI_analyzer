#!/bin/bash

rm -f fft_ita ascisse.txt ampiezza.txt 
gcc -o fft_ita fft.c fft_funct.c -lm
./fft_ita 

