import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


"""
Wrapper class to simplify using the plotting functions
"""
class Wire_Plotter:   
    def __init__(self, length, divisions, temp_min = 0, temp_max = 100, verbose = False):
        self.length         = length
        self.divisions      = divisions
        self.temp_min       = temp_min
        self.temp_max       = temp_max
        self.wire           = []
        self.verbose        = verbose

    def add_interval(self, wire):
        self.wire.append(list.copy(wire))
        self.out("INFO", "Added wire of length %d to plotter." % len(wire))

    def animate(self):
        if self.validate():
            self.out("INFO", "Starting diffusion animation.")
            animate1D(self.wire, self.length, self.divisions, self.temp_min, self.temp_max, smooth=True)
        else:
            self.out("ERROR", "Cannot animate, wire is not valid")

    def draw_interval(self, interval):
        self.validate()
        self.out("INFO", "Drawing wire at time interval %d" % interval)
        draw1D(self.wire[interval], self.length, self.divisions, self.temp_min, self.temp_max, smooth=True)
    
    def draw_last(self):
        self.validate() # Dont need to stop, but should show error
        self.draw_interval(-1)
    
    def validate(self):
        if len(self.wire) < 1:
            self.out("WARN","No intervals to show")
            return False

        size = len(self.wire[0])
        if not all(len(arr) == size for arr in self.wire):
            self.out("WARN","Not all intervals are the same size")
            return False
        return True

    def out(self, state, msg):
        if self.verbose:
            print("PLT-LIB::%-5s|| %s" % (state, msg))
"""
draw 1D

Purpose: Draws heat transfer over wire (1D Array)
Parameters:
    values: 1D array of temperature values
    wire_length: The length of the wire
    wire_divisions: How many segments exist in the wire
    temp_min: minimum temperature of wire. 0 Default
    temp_max: maximum temperature of the wire. 100 Default

    Kwargs: Smooth -> Boolean. True for smooth, otherwise blocky display
"""
def draw1D(values, wire_length, wire_divisions, temp_min = 0, temp_max = 100, **kwargs):

    smooth = 'none'
    if "smooth" in kwargs and kwargs['smooth'] == True:
            smooth = 'bilinear'

    plt.rcParams["figure.figsize"]  = 10, 4
    x = np.linspace(0,wire_length, wire_divisions)
    y = np.asarray(values)

    fig, (ax,ax2) = plt.subplots(nrows=2, sharex=True)

    imgCoords = [
        x[0]-(x[1]-x[0])/2.,    # Left
        x[-1]+(x[1]-x[0])/2.,   # Right
        0,                      # Bottom
        1]                      # Top
    
    ax.imshow(y[np.newaxis,:], cmap="plasma", aspect="auto", extent =imgCoords, interpolation = smooth, vmin = temp_min, vmax = temp_max)
    ax.set_yticks([])
    ax.set_xlim(imgCoords[0], imgCoords[1])
    

    ax2.plot(x,y)
    plt.tight_layout()
    plt.show()



"""
Animate 1D

Purpose: Animates heat transfer over wire (1D Array)
Parameters:
    allValues: 2D array of temperature values, where second dimension is time
    wire_length: The length of the wire
    wire_divisions: How many segments exist in the wire
    temp_min: minimum temperature of wire. 0 Default
    temp_max: maximum temperature of the wire. 100 Default

    Kwargs: Smooth -> Boolean. True for smooth, otherwise blocky display
"""
def animate1D(all_values, wire_length, wire_divisions, temp_min = 0, temp_max = 100, timeModifier = 5, **kwargs):
    smooth = 'none'
    if "smooth" in kwargs and kwargs['smooth']:
            smooth = 'bilinear'

    plt.rcParams["figure.figsize"] = 10, 4
    x = np.linspace(0, wire_length, wire_divisions)
    y = np.asarray(all_values[0])

    fig, (ax,ax2) = plt.subplots(nrows=2, sharex=True)

    imgCoords = [
        x[0]-(x[1]-x[0])/2.,    # Left
        x[-1]+(x[1]-x[0])/2.,   # Right
        0,                      # Bottom
        1]                      # Top
    
    image = ax.imshow(y[np.newaxis,:], cmap="plasma", aspect="auto", extent = imgCoords, interpolation = smooth, vmin = temp_min, vmax = temp_max)
    ax.set_yticks([])
    ax.set_xlim(imgCoords[0], imgCoords[1])
    
    linePlot, = ax2.plot(x,y)
    
    def animate(i):
        y = np.asarray(all_values[i])
        
        image.set_array(y[np.newaxis,:])
        linePlot.set_ydata(y)
        return [image]
    
    ani = FuncAnimation(fig, animate, np.arange(0, len(all_values)), interval = 100, blit = False, repeat=False)

    plt.tight_layout()
    plt.show()
    del ani
    plt.close()

