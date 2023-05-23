#include "Element.h"

class Platform 
	: public Element {

private:
	bool bIsMove;
	float speed = 1;
	int direction;
	float r_border, l_border;

public:
	void Move();
	void SetBorder(float r, float l);
	void SetDirection(bool bIsMove, int direction = 1);
};
