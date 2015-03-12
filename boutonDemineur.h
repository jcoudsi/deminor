#pragma once
#include <QtGui>

class boutonDemineur : public QPushButton
{
Q_OBJECT

public:
	boutonDemineur();
	boutonDemineur(int i, int j);
	~boutonDemineur();
	void setI(int i);
	void setJ(int j);
	void marquerDrapeau(bool booleen);
	void marquerHypothese(bool booleen);
	void marquerMine(bool booleen);

	void mousePressEvent(QMouseEvent *event);

	bool estMine();
	bool estDrapeau();
	bool estHypothese();

public slots:
	void clicRecu();

signals:
	void clic(int i, int j);
	void clicGauche(int i, int j);
	void clicDroit(int i, int j);

private:
	int posI;
	int posJ;

	bool drapeau;
	bool hypothese;
	bool mine;

};
