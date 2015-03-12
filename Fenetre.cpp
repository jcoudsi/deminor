#include "Options.h"
#include "Fenetre.h"
#include "boutonDemineur.h"
#include <ctime>
#include <QtGui>

Fenetre::Fenetre() : QMainWindow()
{
	nbCasesHauteur = 16;
	nbCasesLargeur = 16;
	
	zoneCentrale = new QWidget;
	setCentralWidget(zoneCentrale);

	menuFichier = menuBar()->addMenu("&Partie");

	actionNouvellePartie = new QAction("&Nouvelle partie", this);
	//actionOptions = new QAction("&Options", this);
	actionQuitter = new QAction("&Quitter", this);

	menuFichier->addAction(actionNouvellePartie);
	//menuFichier->addAction(actionOptions);
	menuFichier->addAction(actionQuitter);


	QObject::connect(actionNouvellePartie, SIGNAL(triggered()), this, SLOT(nouvellePartie()));
	//QObject::connect(actionOptions, SIGNAL(triggered()), this, SLOT(ouvrirOptions()));
	QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
	QObject::connect(this, SIGNAL(quitter()), qApp, SLOT(quit()));

	layout_v = new QVBoxLayout;
	layout_h = new QHBoxLayout;
	layout_grille = new QGridLayout;

	for (int i = 0; i < NB_CASES_HAUTEUR; i++)
	{
		for (int j = 0; j < NB_CASES_LARGEUR; j++)
		{
			boutons[i][j] = new boutonDemineur(i,j);
			boutons[i][j]->setFixedSize(20, 20);
			layout_grille->addWidget(boutons[i][j], i,j);
		}
	}

	layout_grille->setHorizontalSpacing(0);
	layout_grille->setVerticalSpacing(0);

	layout_v->addLayout(layout_grille);
	layout_h->addLayout(layout_v);
	zoneCentrale->setLayout(layout_h);

	for (int i = 0; i < NB_CASES_HAUTEUR; i++)
	{
		for (int j = 0; j < NB_CASES_LARGEUR; j++)
		{
			QObject::connect(boutons[i][j], SIGNAL(clicGauche(int, int)), this, SLOT(afficherCase(int, int)));
			QObject::connect(boutons[i][j], SIGNAL(clicDroit(int, int)), this, SLOT(marquerMine(int, int)));
		}
	}

	//QObject::connect(this, SIGNAL(miseAJourGrille()), this, SLOT(nouvellePartie()));

	nouvellePartie();
}

void Fenetre::ouvrirOptions()
{
	Options option(this, nbCasesHauteur, nbCasesLargeur);
	option.exec();
}

int Fenetre::getNbCasesHauteur()
{
	return nbCasesHauteur;
}

int Fenetre::getNbCasesLargeur()
{
	return nbCasesLargeur;
}

//void Fenetre::optionsValidees()
//{
//	emit miseAJourGrille();
//}

Fenetre::~Fenetre()
{
}



