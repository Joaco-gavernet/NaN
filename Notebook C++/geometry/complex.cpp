/*
 * Numeros complejos
 * 
 * Tener en cuentas que:
 * 
 * - No se pueden leer complejos directamente con cin >>; 
 * - Una vez definidas las macros, no podemos definir variables con el
 * 	 mismo nombre
 * 
 */

typedef complex<double> complejo;
#define x real()
#define y imag()

complejo a, b, c;
abs(a); // Devuelve sqrt(a.x^2 + a.y^2)
arg(a); // Devuelve el angulo entre ( -pi ; pi ]
conj(a); // Devuelve a.x - i*a.y
a*b; // Devuelve (a.x*b.x-a.y*b.y) + i*(a.x*b.y + a.y*b.x)
polar(1.0,pi); // Devuelve el complejo de modulo 1 y angulo pi
    (conj(a)*b).y // Producto cruz -> a.x*b.y - a.y*b.x
(conj(b-a)*(c-a)).y/abs(b-c) // Devuelve distancia punto a -> recta bc
