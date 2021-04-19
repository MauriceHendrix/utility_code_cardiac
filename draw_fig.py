from sympy import *
from sys import float_info
import matplotlib.pyplot as plt
plt.rcParams['font.size'] = '20'

Vmin, Vmax = -1.3356169352750066e-6, 1.3356169352750066e-6

V = Symbol('V', real=True)
Ca_o = 1.8
FonRT = 0.0374358835078
F = 96485.0
GCab = 7.9803360000000004e-7
Ca_i = 0.000223768331231758

ICab = (-0.34100000000000003 * Ca_o + Ca_i * exp(2.0 * FonRT * V)) * F * FonRT * GCab * V / (-1.0 + exp(2.0 * FonRT * V))
fix = (-374358.83507800003 * (-1.3356169352750065e-6 + V) * (-0.0048242499999999995 * (-0.34100000000000003 * Ca_o + Ca_i * exp(9.9999999999999995e-8)) * GCab / (-1.0 + exp(9.9999999999999995e-8)) - 0.0048242499999999995 * (-0.34100000000000003 * Ca_o + Ca_i * exp(-9.9999999999999995e-8)) * GCab / (-1.0 + exp(-9.9999999999999995e-8))) + 0.0048242499999999995 * (-0.34100000000000003 * Ca_o + Ca_i * exp(9.9999999999999995e-8)) * GCab / (-1.0 + exp(9.9999999999999995e-8)))
#fix = 0.000884254431877711*V - 0.0236221547699112

fig, (ax1, ax2) = plt.subplots(1, 2)

#print(ICab.replace(V,0.0))
#assert False

x, y, x2, y2 = [], [], [], []
current = -80
while current < 80 and current < Vmin:
    x.append(current)
    y.append(ICab.replace(V, current))
    current += 1/10


current = Vmin
while current <= Vmax:
    try:
        val = ICab.replace(V, current)
        val = Float(val)
        x.append(current)
        y.append(val)
    except TypeError:
        pass
        x2.append(current)
        y2.append(fix.replace(V, current))
        x.append(current)
        x.append(current)
        y.append(limit(ICab, V, current, dir='-').replace(oo,100).replace(-oo, -100))
        y.append(limit(ICab, V, current, dir='+').replace(oo,100).replace(-oo, -100))

    x2.append(current)
    y2.append(fix.replace(V, current))
    current += (Vmax - Vmin) / 10000
    
current = Vmax
while current < 80:
    x.append(current)
    y.append(ICab.replace(V, current))
    current += 1/10


#plt.xlim(float(Vmin - (Vmax - Vmin)), float(Vmax + (Vmax - Vmin)))
ax1.plot(x,y, color="blue")
ax1.plot(x2,y2, color="red")
ax1.set_ylim(-0.15, 0.005)
ax1.set_ylabel('ICab', fontsize=25)
ax1.set_xlabel('V', fontsize=25)


ax2.plot(x,y, color="blue")
ax2.plot(x2,y2, color="red")
ax2.set_ylim(-0.023622155965, -0.023622153531)
ax2.set_xlim(-1.5*1e-6, 1.5*1e-6)
ax2.set_ylabel('ICab', fontsize=25)
ax2.set_xlabel('V', fontsize=25)


plt.show()
plt.close('all')