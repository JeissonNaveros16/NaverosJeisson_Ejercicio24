metropolis.png : metropolis.dat metropolis.py
    python metropolis.py

metropolis.dat : metropolis.x
    ./metropolis.x > metropolis.dat

metropolis.x : metropolis.cpp
    c++ metropolis.cpp -o metropolis.x