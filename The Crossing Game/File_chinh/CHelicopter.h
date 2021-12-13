
#include "CVehicle.h"

class CHELICOPTER : public CVEHICLE {
private:
public:
	CHELICOPTER();
	CHELICOPTER(short, bool);
	~CHELICOPTER();

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };

	// Minh họa
	virtual void drawBody();
	virtual void tell();
	virtual void move();
};

