#include <vector>
#include "Point.h"

class Object{

	const enum Color{
		RED,
		BLUE,
		GREEN,
		BLACK
	};

public:
	virtual float Right();
	virtual float Left();
	virtual float Top();
	virtual float Bottom();

	virtual float getSize();
	virtual float getWidth();
	virtual float getHeight();

	virtual void setLocation(Point*);

	virtual std::vector<Object*> getParts();
	virtual void addPart(Object*);

	Object();
private:
	Point* location;
	float width, height;
	Color color; // Will replace with texture
	std::vector<Object*> parts; // parts is empty if this is the base object
};

