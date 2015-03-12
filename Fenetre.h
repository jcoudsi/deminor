#pragma once
#include <QtGui>
#include "boutonDemineur.h"
#include "Options.h"

#define NB_CASES_HAUTEUR 16
#define NB_CASES_LARGEUR 16

class Fenetre : public QMainWindow
{
Q_OBJECT

public:
	Fenetre();
	~Fenetre();
	void effacerCase(int i, int j);
	void gagne();

	int getNbCasesHauteur();
	int getNbCasesLargeur();

	friend void Options::sauvegarderValeursNbCases(Fenetre *fenetre);

	void optionsValidees();

public slots:
	//void creerCases(); 
	void nouvellePartie();
	void afficherCase(int i, int j);
	void marquerMine(int i, int j);
	void genererGrille();
	void ouvrirOptions();

signals:
	void quitter();
	//void miseAJourGrille();

private:
	QWidget *zoneCentrale;
	QMenu *menuFichier;
	QAction *actionNouvellePartie;
	QAction *actionQuitter;
	QAction *actionOptions;
	boutonDemineur *boutons[NB_CASES_HAUTEUR][NB_CASES_LARGEUR];
	QGridLayout *layout_grille;
	QVBoxLayout *layout_v;
	QHBoxLayout *layout_h;
	
	char grille[NB_CASES_HAUTEUR][NB_CASES_LARGEUR];
	int grilleTemp[NB_CASES_HAUTEUR][NB_CASES_LARGEUR];
	int nbMinesTrouvees;
	int nbTotalMines;

	int reponse;
	int nbDrapeauxRestants;

	int nbCasesHauteur;
	int nbCasesLargeur;
};
