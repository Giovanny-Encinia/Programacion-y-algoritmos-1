Sobre la compilacion, ejecucion y eliminacion del programa:

El programa se puede compilar simplemente haciendo
    make
Para correr el programa se necesita hacer
    make run
Para eliminar el ejecutable se debe de usar:
    make clean

Si el make no llega a funcionar, utilice
gcc -o tarea8 main.c arboles_binarios/arboles_binarios.c arboles_binarios/funciones.c

-------------------------------------------------------------------

Sobre el programa:

Cuando se ejecuta el programa se llenara la tabla con 50 datos
de manera aleatoria para que se pueda visualizar mejor, de ahi
se desplegara un menu que le pedira all usuario elegir entre las 
5 opciones disponibles.

Cuando un arbol esta vacio y se imprime la tabla, se mostrara como
vacio, de lo contrario, se muestran los elementos del arbol ordenados.

En la carpeta /arboles_binarios, se encuentran funciones y definiciones
de la estructura arbol, analogamente sucede lo mismo con la /carpeta hash


