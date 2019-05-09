import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

datos=np.loadtxt("data_v.dat")
n=datos.shape[0]
m=datos.shape[1]
x, y = np.linspace(0,1,m), []
g_1, lim = plt.subplots()

plot ,  = plt.plot(x, datos[0])

def init(): 
    lim.set_xlim(0, 1)
    lim.set_ylim(-0.05, 0.05)
    lim.set_xlabel("Posición[m]")
    lim.set_ylabel("U[]") 

    return plot ,  



def animate(i):
    plot.set_ydata(datos[i])
    lim.set_title(str(2*i/n))
    return plot , 


plot_1= animation.FuncAnimation(
    g_1, animate, init_func=init, interval=100,frames=range(n), blit=True, save_count=50)


plot_1.save("plot.gif")


