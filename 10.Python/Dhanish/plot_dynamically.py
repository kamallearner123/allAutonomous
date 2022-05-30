import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation
import psutil
import collections

import sh
tail = sh.tail("-f", "data.log", _iter=True)


# function to update the data
def my_function(i):

    new_data = tail.next()
    temp,hum = list(map(int, new_data.split(",")))

    # get data
    temperatures.popleft()
    #temperatures.append(psutil.cpu_percent())
    temperatures.append(temp)
    humdity.popleft()
    #humdity.append(psutil.virtual_memory().percent)
    humdity.append(hum)

    # clear axis
    ax.cla()
    ax1.cla()
    # plot temperatures
    ax.plot(temperatures)
    ax.scatter(len(temperatures)-1, temperatures[-1])
    ax.text(len(temperatures)-1, temperatures[-1]+2, "{}%".format(temperatures[-1]))
    ax.set_ylim(0,100)
    # plot memory
    ax1.plot(humdity)
    ax1.scatter(len(humdity)-1, humdity[-1])
    ax1.text(len(humdity)-1, humdity[-1]+2, "{}%".format(humdity[-1]))
    ax1.set_ylim(0,100)



# start collections with zeros
temperatures = collections.deque(np.zeros(100))
humdity = collections.deque(np.zeros(100))
# define and adjust figure
fig = plt.figure(figsize=(12,6), facecolor='#DEDEDE')
ax = plt.subplot(121)
ax1 = plt.subplot(122)
ax.set_facecolor('#DEDEDE')
ax1.set_facecolor('#DEDEDE')
# animate
ani = FuncAnimation(fig, my_function, interval=500)
plt.show()
