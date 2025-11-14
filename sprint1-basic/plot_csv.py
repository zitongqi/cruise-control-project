import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("velocity.csv", header=None)
velocity = data[0]

plt.plot(velocity)
plt.xlabel("Step")
plt.ylabel("Velocity (m/s)")
plt.title("Car Velocity Response")
plt.grid(True)

plt.savefig("velocity_plot.png")
print("Plot saved as velocity_plot.png")
