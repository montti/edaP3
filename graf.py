#pip install matplotlib pandas

import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("patronCrece.log")

print(data);

print(data.n)
#print(data.t_filas)

#plt.plot(data.n, data.tBusSA,"-bo", label="SA")
#plt.plot(data.n, data.tBusKMP,"-ro", label ="KMP")
#plt.plot(data.n, data.tBusFM,"-go", label ="FM Index")
#plt.title("Búsqueda")

plt.plot(data.n, data.tConsSA,"-bo", label="SA")
plt.plot(data.n, data.tConsKMP,"-ro", label ="KMP")
plt.plot(data.n, data.tConsFM,"-go", label ="FM Index")
plt.title("Construcción")

plt.xlabel("Tamaño de patrón")
#plt.xlabel("Tamaño texto [MB]")
plt.ylabel("Tiempo [ms]");

plt.legend()


#plt.savefig("grafica.svg")


plt.show()

