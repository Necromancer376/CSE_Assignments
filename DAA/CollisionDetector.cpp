#include <iostream>
#include <vector>
#include <math.h>

#define change(x) (x == 1 ? "True" : "False")

using namespace std;


class Circle
{
public:
	int center_x, center_y;
	double length;

public:
	Circle(int x, int y, double l)
	{
		center_x = x;
		center_y = y;
		length = l;
	}

	bool isCollided(Circle obj)
	{
		double dist = sqrt(pow((this->center_x - obj.center_x), 2) + pow((this->center_y - obj.center_y), 2));

		if(dist <= length + obj.length)
			return true;

		return false;
	}
};

class Rectangle
{
public:
	int center_x, center_y;
	double length, bredth;
public:
	Rectangle(int x, int y, double l, double b)
	{
		center_x = x;
		center_y = y;
		length = l;
		bredth = b;
	}

	bool isCollided(Rectangle obj)
	{
		if(this->center_x < obj.center_x + obj.length && this->center_x + this->length > obj.center_x &&
			this->center_y < obj.center_y + obj.bredth && this->center_y + this->bredth > obj.center_y)
		{
			return true;
		}

		return false;
	}
};


class Sphere
{
public:
	int center_x, center_y, center_z;
	double length;

public:
	Sphere(int x, int y, int z, double l)
	{
		center_x = x;
		center_y = y;
		center_z = z;
		length = l;
	}

	bool isCollided(Sphere obj)
	{
		double dist = sqrt(pow((this->center_x - obj.center_x), 2) + pow((this->center_y - obj.center_y), 2) + 
			pow((this->center_z - obj.center_z), 2));

		if(dist <= length + obj.length)
			return true;

		return false;
	}
};


class Cuboid
{
public:
	int center_x, center_y, center_z;
	double length, bredth, height;
public:
	Cuboid(int x, int y, int z, double l, double b, double h)
	{
		center_x = x;
		center_y = y;
		center_z = z;
		length = l;
		bredth = b;
		height = h;
	}

	bool isCollided(Cuboid obj)
	{
		if(this->center_x < obj.center_x + obj.length && this->center_x + this->length > obj.center_x &&
			this->center_y < obj.center_y + obj.bredth && this->center_y + this->bredth > obj.center_y &&
			this->center_z < obj.center_z + obj.height && this->center_z + this->height > obj.center_z)
		{
			return true;
		}

		return false;
	}
};


bool isCollided(Rectangle rect, Circle circle)
{
	double dx = abs(circle.center_x - rect.center_x);
	double dy = abs(circle.center_y - rect.center_y);

	if(dx > rect.length/2 + circle.length)
		return false;
	if(dy > rect.bredth/2 + circle.length)
		return false;

	if(dx <= rect.length/2 + circle.length)
		return true;
	if(dy <= rect.bredth/2 + circle.length)
		return true;

	double dxy = (pow((dx - rect.length/2),2) + pow((dy - rect.bredth/2),2));

	return (dxy <= pow(circle.length, 2));
}


bool isCollided3D(Cuboid cuboid, Sphere sphere)
{
	double dx = abs(sphere.center_x - cuboid.center_x);
	double dy = abs(sphere.center_y - cuboid.center_y);
	double dz = abs(sphere.center_z - cuboid.center_z);

	if(dx > cuboid.length/2 + sphere.length)
		return false;
	if(dy > cuboid.bredth/2 + sphere.length)
		return false;
	if(dz > cuboid.height/2 + sphere.length)
		return false;

	if(dx <= cuboid.length/2 + sphere.length)
		return true;
	if(dy <= cuboid.bredth/2 + sphere.length)
		return true;
	if(dz <= cuboid.height/2 + sphere.length)
		return true;

	double dxyz = (pow((dx - cuboid.length/2),2) + pow((dy - cuboid.bredth/2),2) + pow((dy - cuboid.height/2),2));

	return (dxyz <= pow(sphere.length, 2));
}


int main()
{
	Circle circle1(0, 0, 1);
	Circle circle2(5, 5, 5);

	Rectangle rect1(5, 5, 50 , 50);
	Rectangle rect2(20, 10 , 60, 40);

	cout << "2-D" << endl;
	cout << "\tCircle-Circle: " << change(circle1.isCollided(circle2)) << endl;
	cout << "\tRectangle-Rectangle: " << change(rect1.isCollided(rect2)) << endl;
	cout << "\tCircle-Rectangle: " << change(isCollided(rect1, circle1)) << endl;

	Sphere sp1(0, 0, 0, 10);
	Sphere sp2(15, 10, 10, 50);

	Cuboid cuboid1(0, 0, 0, 10, 5, 10);
	Cuboid cuboid2(10, 20, 20, 5, 15, 10);

	cout << "3-D" << endl;
	cout << "\tSphere-Sphere: " << change(sp1.isCollided(sp2)) << endl;
	cout << "\tCuboid-Cuboid: " << change(cuboid1.isCollided(cuboid2)) << endl;
	cout << "\tCuboid-Sphere: " << change(isCollided3D(cuboid1, sp1)) << endl;

}

// 1.00000000000000000000000

