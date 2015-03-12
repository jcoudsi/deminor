#pragma once
#include <QtGui>

class Fenetre;

class Options : public QDialog
{
	Q_OBJECT

public:
	Options(Fenetre *fenetre, int nombreCasesHauteur, int nombreCasesLargeur);
	~Options();

public slots:
	void miseAJourNbCasesHauteur(int nbCases);
	void miseAJourNbCasesLargeur(int nbCases);
	void sauvegarderValeursNbCases(Fenetre *fenetre);
	void envoyerValeursNbCases();

signals:
	void emitValeursNbCases(Fenetre *fenetre);

private:
	QSpinBox *champNbCasesHauteur;
	QSpinBox *champNbCasesLargeur;

	QPushButton *boutonOK;
	QPushButton *boutonAnnuler;

	QFormLayout *layout_form;
	QHBoxLayout *layout_h;
	QVBoxLayout *layout_v;

	Fenetre *pointeurSurFenetre;

	int nbCasesHauteur;
	int nbCasesLargeur;
};
