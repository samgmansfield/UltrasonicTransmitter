from __future__ import division

'''
Created on Nov 22, 2013

@author: matt.weber
'''
'''
Created on Nov 20, 2013

@author: matt.weber
'''

import scipy.io.wavfile

from scipy import fft, arange, io

from numpy import sin, linspace, pi, log10
from pylab import plot, show, title, xlabel, ylabel, subplot

#numpy.set_printoptions(threshold=numpy.nan)

import wave
import sqlite3

dbpath = '/Users/matt.weber/Documents/EE249/BearLoc/bearloc/server/bearloc.db'
wavfpath = 'audio.wav'

conn = sqlite3.connect(database = dbpath)
cur = conn.cursor()

conn.text_factory = str

# extract attributes and store in db
operation = "SELECT channel, sampwidth, framerate, nframes, raw FROM audio;"
cur.execute(operation)
audio = cur.fetchall()
(channel, sampwidth, framerate, nframes, raw) = audio[-1]

wavf = wave.open(wavfpath, 'wb')
wavf.setnchannels(channel)
wavf.setsampwidth(sampwidth)
wavf.setframerate(framerate)
wavf.setnframes(nframes)
wavf.writeframesraw(raw)
wavf.close()


""" section break """

filename="audio.wav"

rate, data = scipy.io.wavfile.read(filename, mmap=False)
print rate
print len(data)
n = len(data)  # length of the signal

k = arange(n)
T = n/rate

print T
frq = k/T # two sides frequency range

print frq

frq = frq[range(n//2)] # one side frequency range



Y = fft(data)/n # fft computing and normalization
Y = Y[range(n//2)]

prePlotY = abs(Y)
dbY = log10(prePlotY / 10000 )*20


#plot(frq,dbY,'r') # plotting the spectrum
plot(frq,prePlotY,'r') # plotting the spectrum
xlabel('Freq (Hz)')
ylabel('|Y(freq)|')
print prePlotY
show()
