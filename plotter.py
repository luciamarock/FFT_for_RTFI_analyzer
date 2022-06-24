# -*- coding: utf-8 -*-
"""
Created on Thu Oct 25 10:07:47 2018

@author: codac_user

this script compares the python fft with mine fft C implementation

"""
import math
import numpy as np
import matplotlib.pyplot as plt
from numpy import genfromtxt
import os

print('')

os.system('./run.sh')

ascisse = genfromtxt('ascisse.txt')
#mydata=read[:,6]
ampiezza = genfromtxt('ampiezza.txt')
ampiezze = ampiezza[:512]
#time=timee[:,3]
print('')
#print('len(ascisse) = {}'.format(len(ascisse)))
plt.plot(ascisse,ampiezze)
plt.plot(ascisse,ampiezze, 's')
plt.show()

#plt.figure()
#plt.plot(ampiezza)
