#include "Options.h"
#include "Fenetre.h"

class Fenetre;

Options::Options(Fenetre *fenetre, int nombreCasesHauteur, int nombreCasesLargeur) : QDialog()
{
	nbCasesHauteur = nombreCasesHauteur;
	nbCasesLargeur = nombreCasesLargeur;
	
	layout_form = new QFormLayout;

	champNbCasesHauteur = new QSpinBox;
	champNbCasesHauteur->setValue(fenetre->getNbCasesHauteur());
	champNbCasesLargeur = new QSpinBox;
	champNbCasesLargeur->setValue(fenetre->getNbCasesLargeur());

	layout_form->addRow("Nombre de cases en hauteur", champNbCasesHauteur);
	layout_form->addRow("Nombre de cases en largeur", champNbCasesLargeur);
	
	boutonOK = new QPushButton;
	boutonOK->setText("OK");

	boutonAnnuler = new QPushButton;
	boutonAnnuler->setText("Annuler");

	layout_h = new QHBoxLayout;
	layout_v = new QVBoxLayout;

	layout_h->addWidget(boutonOK);
	layout_h->addWidget(boutonAnnuler);

	layout_v->addLayout(layout_form);
	layout_v->addLayout(layout_h);

	setLayout(layout_v);

	pointeurSurFenetre = fenetre;

	QObject::connect(champNbCasesHauteur, SIGNAL(valueChanged(int)), this, SLOT(miseAJourNbCasesHauteur(int)));
	QObject::connect(champNbCasesLargeur, SIGNAL(valueChanged(int)), this, SLOT(miseAJourNbCasesLargeur(int)));
	QObject::connect(boutonOK, SIGNAL(clicked()), this, SLOT(envoyerValeursNbCases()));
	QObject::connect(this, SIGNAL(emitValeursNbCases(Fenetre*)), this, SLOT(sauvegarderValeursNbCases(Fenetre*)));
	QObject::connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(close()));
}

void Options::miseAJourNbCasesHauteur(int nbCases)
{
	nbCasesHauteur = nbCases;
}

void Options::miseAJourNbCasesLargeur(int nbCases)
{
	nbCasesLargeur = nbCases;
}

void Options::envoyerValeursNbCases()
{
	emit emitValeursNbCases(pointeurSurFenetre);
}

void Options::sauvegarderValeursNbCases(Fenetre *fenetre)
{
	fenetre->nbCasesHauteur = nbCasesHauteur;
	fenetre->nbCasesLargeur = nbCasesLargeur;
	//fenetre->optionsValidees();
	close();
}

Options::~Options()
{
}
