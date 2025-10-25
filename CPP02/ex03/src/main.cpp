#include <iostream>
#include "fixed.hpp"
#include "Point.hpp"

int	main(void) {
	// Définir un triangle
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	// Point à l'intérieur
	Point inside(5.0f, 5.0f);
	std::cout << "Point (5, 5) inside triangle: " 
			  << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;

	// Point à l'extérieur
	Point outside(15.0f, 5.0f);
	std::cout << "Point (15, 5) inside triangle: " 
			  << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;

	// Point sur un bord (doit retourner false)
	Point onEdge(5.0f, 0.0f);
	std::cout << "Point (5, 0) on edge: " 
			  << (bsp(a, b, c, onEdge) ? "YES" : "NO") << std::endl;

	// Point sur un sommet (doit retourner false)
	Point vertex(0.0f, 0.0f);
	std::cout << "Point (0, 0) on vertex: " 
			  << (bsp(a, b, c, vertex) ? "YES" : "NO") << std::endl;

	return 0;
}