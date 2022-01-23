Ya se ha creado el archivo ejecutable, unicamente
ejecute ./encripta para que se generen los resultados, también se puede ejecutar el makefile

Los resultados se encuentran en la carpeta "resultados/"

Existen dos versiones de la encriptacion, uno es haciendo split a los bytes de el mapeo, de aquí
Observe que si obtenemos solo los bits de cada byte y los hacemos xor la encriptacion, no funciona
Por ejemplo si tenemos el numero 000000000000000011111111111111111 un numero entero de 4 bytes, si le hago split de tal manera que se separa en 4 nuevos enteros 11111111, 11111111, 00000000, 00000000, (y demás ceros llenando sus bytes), la encriptacion deja mucho que desear.

Si hago un split tal que 11111111, 1111111100000000, 0000000000000000, ...., para el numero 000000000000000011111111111111111 la encriptación da un mejor resultado pero aun no es la mejor, de cualquier manera esta opción para encriptar se muestra en el programa, ya que es parte de la tarea.

 La mejor encriptacion es cuando se aplica directamente a cada byte el xor con el mapeo, es decir el numero 000000000000000011111111111111111, sin hacer ningún split. 
En la carpeta resultados/directo, se encuentran los resultados de encriptar y desencriptar usando el método de mateo directo. En la carpeta resultados/split se encuentra el método de split.