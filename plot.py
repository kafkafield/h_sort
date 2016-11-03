import matplotlib as mpl
mpl.use('Agg') 
import matplotlib.pyplot as plt
import numpy as np

order = np.loadtxt('order.log')
random = np.loadtxt('random.log')
order = np.transpose(order)
random = np.transpose(random)

plt.figure()
p1 = plt.subplot(211)
p2 = plt.subplot(212)

p1.plot(order[0], order[1], '-', label="quick sort")
p1.plot(order[0], order[2], '--', label="hybrid sort")
p2.plot(random[0], random[1], label="quick sort")
p2.plot(random[0], random[2], label="hybrid sort")
p1.grid(True)
p2.grid(True)
p1.legend()
p2.legend()
p1.set_ylabel("time(s)")
p2.set_ylabel("time(s)")
p2.set_xlabel("k value")

p1.set_title("Random 1000000 numbers")
p1.set_title("Almost in order 1000000 numbers")

plt.savefig("h.png")
