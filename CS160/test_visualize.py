from wire_plotter import Wire_Plotter

def main():

    wire_len = 10.0
    wire_div = 10
    temp_left = 0
    temp_right = 100

    # setting up the plotter
    plotter = Wire_Plotter(wire_len, wire_div, temp_left, temp_right, True)

    f = open("CS160/wire_temps.csv", "r")
    lines = f.readlines()
    for line in lines:
        # reading in a line from the file and separating it on spaces
        wire_temps = line.split(",")
        # converting all elements of the list to be floats
        for i in range(len(wire_temps)):
           wire_temps[i]=float(wire_temps[i])
        print(wire_temps)
        # this is where you would pass in your array of wire temperatures
        plotter.add_interval(wire_temps)
    # call this once you have added all the lines and it will animate
    plotter.animate()


main()
