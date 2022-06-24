# -*- coding: utf-8 -*-
"""
Created on Thu Oct 25 10:07:47 2018

@author: codac_user

this script performs the (python) fft of the input .wav file 

"""
import os
import math
import numpy as np
import matplotlib.pyplot as plt
from numpy import genfromtxt
from scipy.io.wavfile import read
from scipy.io.wavfile import write


(Fs, x1) = read('./audiofiles/short.wav')
x = np.zeros(1024)
for i in range(len(x1)):
    x[i] = x1[i]
print('Fs = {}'.format(Fs))
print('numero campioni = {}'.format(len(x)))
time = np.arange(x.size)/float(Fs)
#plt.plot(tempo,segnale)

spettro=np.fft.fft(np.array(x))

modulo=[]

for i in range (len(spettro)):
    modulo.append(math.sqrt(pow(spettro[i].real,2)+pow(spettro[i].imag,2))/len(spettro)*2)

print('len(modulo) = {}'.format(len(modulo)))

plt.subplot(211)
plt.plot(time,x)


spaziatura=float(Fs)/len(modulo)

frequenze=[]
ampiezze=[]


for i in range (len(modulo)):
    ampiezze.append(modulo[i])
    frequenze.append(i*spaziatura)
    

plt.subplot(212)
plt.plot(frequenze,ampiezze)
plt.plot(frequenze,ampiezze,'s')
plt.show()

os.system('./clean.sh')

