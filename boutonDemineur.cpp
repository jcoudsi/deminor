#include "boutonDemineur.h"

boutonDemineur::boutonDemineur() : QPushButton()
{
}

boutonDemineur::boutonDemineur(int i, int j) : QPushButton()
{
	posI = i;
	posJ = j;
}

void boutonDemineur::setI(int i)
{
	posI = i;
}

void boutonDemineur::setJ(int j)
{
	posJ = j;
}


void boutonDemineur::clicRecu()
{
	emit clic(posI,posJ);
}

void boutonDemineur::marquerDrapeau(bool booleen)
{
	drapeau = booleen;
}

void boutonDemineur::marquerMine(bool booleen)
{
	mine = booleen;
}

void boutonDemineur::marquerHypothese(bool booleen)
{
	hypothese = booleen;
}

bool boutonDemineur::estDrapeau()
{
	return drapeau;
}

bool boutonDemineur::estMine()
{
	return mine;
}

bool boutonDemineur::estHypothese()
{
	return hypothese;
}

void boutonDemineur::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit clicGauche(posI, posJ);
	}
	else if (event->button() == Qt::RightButton)
	{
		emit clicDroit(posI, posJ);
	}
}

boutonDemineur::~boutonDemineur()
{
}
