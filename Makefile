all: plot.git datos_v.dat rodriguezvanessa_30.x

plot.git: datos_v.dat graficar.py
	python3 graficar.py

datos_v.dat: rodriguezvanessa_30.x
	./rodriguezvanessa_30.x

rodriguezvanessa_30.x: rodriguezvanessa_30.cpp
	g++ rodriguezvanessa_30.cpp -o rodriguezvanessa_30.x

clean:
	rm -rf *.x *.dat *.png
