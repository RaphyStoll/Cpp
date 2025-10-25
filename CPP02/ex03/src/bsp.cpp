#include "Point.hpp"
#include "fixed.hpp"

/*
** Fonction helper : Calcule l'aire d'un triangle avec la formule :
** Aire = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
**
** On utilise la valeur absolue pour éviter les aires négatives
*/
static Fixed calculateArea(Point const p1, Point const p2, Point const p3)
{
	Fixed area = (
		(p1.getX() * (p2.getY() - p3.getY())) +
		(p2.getX() * (p3.getY() - p1.getY())) +
		(p3.getX() * (p1.getY() - p2.getY()))
	) / Fixed(2);
	
	// Retourner la valeur absolue
	if (area < Fixed(0))
		return area * Fixed(-1);
	return area;
}

/*
** BSP (Binary Space Partitioning)
** 
** Principe : Un point P est à l'intérieur d'un triangle ABC si :
** Aire(ABC) = Aire(PAB) + Aire(PBC) + Aire(PCA)
**
** Si le point est sur un bord ou un sommet, on retourne false
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculer l'aire du triangle principal ABC
	Fixed areaABC = calculateArea(a, b, c);
	
	// Calculer les aires des sous-triangles
	Fixed areaPAB = calculateArea(point, a, b);
	Fixed areaPBC = calculateArea(point, b, c);
	Fixed areaPCA = calculateArea(point, c, a);
	
	// Si une des aires est 0, le point est sur un bord
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
		return false;
	
	// Le point est à l'intérieur si la somme des aires est égale à l'aire totale
	Fixed sumAreas = areaPAB + areaPBC + areaPCA;
	
	return (areaABC == sumAreas);
}
