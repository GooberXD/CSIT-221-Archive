struct Point{
	int x, y;
	
	Point midpoint(Point* other){
		Point mid;
		
		mid.x = (other->x + x) / 2;
		mid.y = (other->y + y) / 2;
		return mid;
	}
	
	
	
};

typedef Point point;
