#include "Fenetre.h"
#include "boutonDemineur.h"
#include <ctime>

void Fenetre::nouvellePartie()
{
	nbMinesTrouvees = 0;
	nbTotalMines = 0;

	genererGrille();

	for (int i = 0; i < NB_CASES_HAUTEUR; i++)
	{
		for (int j = 0; j < NB_CASES_LARGEUR; j++)
		{
			boutons[i][j]->marquerDrapeau(false);
			boutons[i][j]->marquerHypothese(false);
			boutons[i][j]->setIcon(QIcon(""));
			boutons[i][j]->setText("");
			boutons[i][j]->setFlat(false);
			boutons[i][j]->setVisible(true);
		}
	}
}

void Fenetre::genererGrille()
{
	srand(time(NULL));
	int nbMinesGenerees = (NB_CASES_HAUTEUR*NB_CASES_LARGEUR)/6;
	nbDrapeauxRestants = nbMinesGenerees;
	const int MAX = 5, MIN = 1;
	int nb = 0;

	for (int i = 0; i < NB_CASES_HAUTEUR; i++)
	{
		for (int j = 0; j < NB_CASES_LARGEUR; j++)
		{
			grilleTemp[i][j] = (rand() % (MAX - MIN + 1)) + MIN;
			if (grilleTemp[i][j] >= MIN && grilleTemp[i][j] <= MAX-1)
			{
				grille[i][j] = 'c';
				boutons[i][j]->marquerMine(false);
			}
			else if (grilleTemp[i][j] == MAX)
			{
				if (nbTotalMines < nbMinesGenerees)
				{
					grille[i][j] = 'm';
					nbTotalMines++;
					boutons[i][j]->marquerMine(true);
				}
				else
				{
					grille[i][j] = 'c';
					boutons[i][j]->marquerMine(false);
				}

			}
		}
	}




	for (int i = 0; i < NB_CASES_HAUTEUR; i++)
	{
		for (int j = 0; j < NB_CASES_LARGEUR; j++)
		{
			nb = 0;

			if (grille[i][j] != 'm' && i > 0 && i < NB_CASES_HAUTEUR-1 && j > 0 && j < NB_CASES_LARGEUR-1)
			{
				if (grille[i-1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j+1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' && i == 0 && j == 0)
			{
				if (grille[i][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j+1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' &&  i == 0 && j > 0 && j < NB_CASES_LARGEUR-1)
			{

				if (grille[i][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j+1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;
			}
			else if (grille[i][j] != 'm' &&  i == 0 && j == NB_CASES_LARGEUR-1)
			{
				if (grille[i][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' &&  i > 0 && i < NB_CASES_HAUTEUR-1 && j == NB_CASES_LARGEUR-1)
			{
				if (grille[i-1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j] == 'm')
				{
					nb++;
				}

				if (grille[i][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' &&  i == NB_CASES_HAUTEUR-1 && j == NB_CASES_LARGEUR-1)
			{
				if (grille[i-1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j] == 'm')
				{
					nb++;
				}

				if (grille[i][j-1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' &&  i == NB_CASES_HAUTEUR-1 && j > 0 && j < NB_CASES_LARGEUR-1)
			{
				if (grille[i-1][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i][j-1] == 'm')
				{
					nb++;
				}

				if (grille[i][j+1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' &&  i == NB_CASES_HAUTEUR-1 && j == 0)
			{
				if (grille[i-1][j] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i][j+1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}
			else if (grille[i][j] != 'm' &&  i > 0 && i < NB_CASES_HAUTEUR-1 && j == 0)
			{
				if (grille[i-1][j] == 'm')
				{
					nb++;
				}

				if (grille[i-1][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i][j+1] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j] == 'm')
				{
					nb++;
				}

				if (grille[i+1][j+1] == 'm')
				{
					nb++;
				}

				grille[i][j] = nb+48;

			}

		}

	}




}

void Fenetre::marquerMine(int i, int j)
{
	if (boutons[i][j]->isVisible() == true) //Si le bouton n'a pas déjà été cliqué
	{
		//Si le bouton n'a pas été cliqué (ni drapeau, ni hypothèse), qu'il ne cache pas une mine et qu'il reste des drapeaux
		if (boutons[i][j]->estDrapeau() == false && boutons[i][j]->estHypothese() == false && boutons[i][j]->estMine() == false)
		{
			boutons[i][j]->setIcon(QIcon("drapeau.png"));
			boutons[i][j]->marquerDrapeau(true);
			nbDrapeauxRestants--;
		} //Sinon si le bouton n'a pas été cliqué  (ni drapeau, ni hypothèse) mais qu'il cache une mine et qu'il reste des drapeaux
		else if (boutons[i][j]->estDrapeau() == false && boutons[i][j]->estHypothese() == false && boutons[i][j]->estMine() == true )
		{
			boutons[i][j]->setIcon(QIcon("drapeau.png"));
			boutons[i][j]->marquerDrapeau(true);
			nbMinesTrouvees++;
			nbDrapeauxRestants--;
		}//Sinon si le bouton est marqué en drapeau et qu'il cache une mine
		else if (boutons[i][j]->estDrapeau() == true && boutons[i][j]->estMine() == true)
		{
			boutons[i][j]->setIcon(QIcon(""));
			boutons[i][j]->setText("?");
			nbMinesTrouvees--;
			boutons[i][j]->marquerDrapeau(false);
			boutons[i][j]->marquerHypothese(true);
			nbDrapeauxRestants++;
		}//Sinon si le bouton est marqué en drapeau et qu'il ne cache pas une mine
		else if (boutons[i][j]->estDrapeau() == true && boutons[i][j]->estMine() == false)
		{
			boutons[i][j]->setIcon(QIcon(""));
			boutons[i][j]->setText("?");
			boutons[i][j]->marquerDrapeau(false);
			boutons[i][j]->marquerHypothese(true);
			nbDrapeauxRestants++;
		}//Sinon si le bouton est marqué en hypothèse
		else if ( boutons[i][j]->estHypothese() == true)
		{
			boutons[i][j]->setIcon(QIcon(""));
			boutons[i][j]->setText("");
			boutons[i][j]->marquerDrapeau(false);
			boutons[i][j]->marquerHypothese(false);
		}

		if (nbMinesTrouvees == nbTotalMines && nbDrapeauxRestants == 0)
		{
			gagne();
		}

	}

}

void Fenetre::afficherCase(int i, int j)
{
	if (boutons[i][j]->estDrapeau() == false) //Si on ne clique pas sur un drapeau
	{
		if (grille[i][j] != 'm') //Si on est pas sur une mine, on affiche le nombre avoisinant et on enfonce le bouton
		{
			//Si la case n'est à proximité d'aucune mine
			if (grille[i][j] == '0')
			{
				effacerCase(i, j);
			}
			//Sinon elle touche une mine ou plusieurs mines
			else
			{
				boutons[i][j]->setText(QString(grille[i][j])); //On affiche le nombre de mines qu'elle touche et on enfonce le bouton
				boutons[i][j]->setFlat(true);
			}

		}
		else //Si c'est une mine, on affiche toutes les autres et on a perdu la partie
		{

			for (int k = 0; k < NB_CASES_HAUTEUR-1; k++)
			{
				for (int l = 0; l < NB_CASES_LARGEUR-1; l++)
				{
					if (grille[k][l] == 'm')
					{
						boutons[k][l]->setFlat(true);
						if (boutons[k][l]->estDrapeau() == true)
						{
							boutons[k][l]->setIcon(QIcon("mine_trouvee.png"));
						}
						else
						{
							boutons[k][l]->setIcon(QIcon("mine.png"));
						}
					}
				}

			}

			reponse = QMessageBox::question(this, "Démineur", "Vous avez perdu !<br />Démarrer une nouvelle partie ?", QMessageBox::Yes | QMessageBox::No);

			if (reponse == QMessageBox::Yes)
			{
				nouvellePartie();
			}
			else if (reponse == QMessageBox::No)
			{
				emit quitter();
			}

		}
		
		/*if (nbMinesTrouvees == nbTotalMines)
		{
			gagne();
		}*/
	}
}

void Fenetre::effacerCase(int i, int j)
{
	boutons[i][j]->setVisible(false);
	boutons[i][j]->setText("");
	//delete boutons[i][j];

	if (i > 0 && i < NB_CASES_HAUTEUR-1 && j > 0 && j < NB_CASES_LARGEUR-1)
	{
		if (grille[i-1][j-1] == '0' && boutons[i-1][j-1]->isVisible() == true && boutons[i-1][j-1]->estDrapeau() == false)
		{
			effacerCase(i-1,j-1);
		}
		else if (grille[i-1][j-1] != '0' && boutons[i-1][j-1]->estDrapeau() == false)
		{
			boutons[i-1][j-1]->setText(QString(grille[i-1][j-1]));
			boutons[i-1][j-1]->setFlat(true);
		}

		if (grille[i-1][j] == '0' && boutons[i-1][j]->isVisible() == true && boutons[i-1][j]->estDrapeau() == false)
		{
			effacerCase(i-1,j);
		}
		else if (grille[i-1][j] != '0' && boutons[i-1][j]->estDrapeau() == false)
		{
			boutons[i-1][j]->setText(QString(grille[i-1][j]));
			boutons[i-1][j]->setFlat(true);
		}

		if (grille[i-1][j+1] == '0' && boutons[i-1][j+1]->isVisible() == true && boutons[i-1][j+1]->estDrapeau() == false)
		{
			effacerCase(i-1,j+1);
		}
		else if (grille[i-1][j+1] != '0' && boutons[i-1][j+1]->estDrapeau() == false)
		{
			boutons[i-1][j+1]->setText(QString(grille[i-1][j+1]));
			boutons[i-1][j+1]->setFlat(true);
		}


		if (grille[i][j-1] == '0' && boutons[i][j-1]->isVisible() == true && boutons[i][j-1]->estDrapeau() == false)
		{
			effacerCase(i,j-1);
		}
		else if (grille[i][j-1] != '0' && boutons[i][j-1]->estDrapeau() == false)
		{
			boutons[i][j-1]->setText(QString(grille[i][j-1]));
			boutons[i][j-1]->setFlat(true);
		}

		if (grille[i][j+1] == '0' && boutons[i][j+1]->isVisible() == true && boutons[i][j+1]->estDrapeau() == false)
		{
			effacerCase(i,j+1);
		}
		else if (grille[i][j+1] != '0' && boutons[i][j+1]->estDrapeau() == false)
		{
			boutons[i][j+1]->setText(QString(grille[i][j+1]));
			boutons[i][j+1]->setFlat(true);
		}

		if (grille[i+1][j-1] == '0' && boutons[i+1][j-1]->isVisible() == true && boutons[i+1][j-1]->estDrapeau() == false)
		{
			effacerCase(i+1,j-1);
		}
		else if (grille[i+1][j-1] != '0' && boutons[i+1][j-1]->estDrapeau() == false)
		{
			boutons[i+1][j-1]->setText(QString(grille[i+1][j-1]));
			boutons[i+1][j-1]->setFlat(true);
		}

		if (grille[i+1][j] == '0' && boutons[i+1][j]->isVisible() == true && boutons[i+1][j]->estDrapeau() == false)
		{
			effacerCase(i+1,j);
		}
		else if (grille[i+1][j] != '0' && boutons[i+1][j]->estDrapeau() == false)
		{
			boutons[i+1][j]->setText(QString(grille[i+1][j]));
			boutons[i+1][j]->setFlat(true);
		}

		if (grille[i+1][j+1] == '0' && boutons[i+1][j+1]->isVisible() == true && boutons[i+1][j+1]->estDrapeau() == false)
		{
			effacerCase(i+1,j+1);
		}
		else if (grille[i+1][j+1] != '0' && boutons[i+1][j+1]->estDrapeau() == false)
		{
			boutons[i+1][j+1]->setText(QString(grille[i+1][j+1]));
			boutons[i+1][j+1]->setFlat(true);
		}

	}
	else if (i == 0 && j == 0)
	{
		if (grille[i][j+1] == '0' && boutons[i][j+1]->isVisible() == true && boutons[i][j+1]->estDrapeau() == false)
		{
			effacerCase(i,j+1);
		}
		else if (grille[i][j+1] != '0' && boutons[i][j+1]->estDrapeau() == false)
		{
			boutons[i][j+1]->setText(QString(grille[i][j+1]));
			boutons[i][j+1]->setFlat(true);
		}

		if (grille[i+1][j] == '0' && boutons[i+1][j]->isVisible() == true && boutons[i+1][j]->estDrapeau() == false)
		{
			effacerCase(i+1,j);
		}
		else if (grille[i+1][j] != '0' && boutons[i+1][j]->estDrapeau() == false)
		{
			boutons[i+1][j]->setText(QString(grille[i+1][j]));
			boutons[i+1][j]->setFlat(true);
		}

		if (grille[i+1][j+1] == '0' && boutons[i+1][j+1]->isVisible() == true && boutons[i+1][j+1]->estDrapeau() == false)
		{
			effacerCase(i+1,j+1);
		}
		else if (grille[i+1][j+1] != '0' && boutons[i+1][j+1]->estDrapeau() == false)
		{
			boutons[i+1][j+1]->setText(QString(grille[i+1][j+1]));
			boutons[i+1][j+1]->setFlat(true);
		}
	}
	else if (i == 0 && j > 0 && j < NB_CASES_LARGEUR-1)
	{

		if (grille[i][j-1] == '0' && boutons[i][j-1]->isVisible() == true && boutons[i][j-1]->estDrapeau() == false)
		{
			effacerCase(i,j-1);
		}
		else if (grille[i][j-1] != '0' && boutons[i][j-1]->estDrapeau() == false)
		{
			boutons[i][j-1]->setText(QString(grille[i][j-1]));
			boutons[i][j-1]->setFlat(true);
		}

		if (grille[i][j+1] == '0' && boutons[i][j+1]->isVisible() == true && boutons[i][j+1]->estDrapeau() == false)
		{
			effacerCase(i,j+1);
		}
		else if (grille[i][j+1] != '0' && boutons[i][j+1]->estDrapeau() == false)
		{
			boutons[i][j+1]->setText(QString(grille[i][j+1]));
			boutons[i][j+1]->setFlat(true);
		}

		if (grille[i+1][j-1] == '0' && boutons[i+1][j-1]->isVisible() == true && boutons[i+1][j-1]->estDrapeau() == false)
		{
			effacerCase(i+1,j-1);
		}
		else if (grille[i+1][j-1] != '0' && boutons[i+1][j-1]->estDrapeau() == false)
		{
			boutons[i+1][j-1]->setText(QString(grille[i+1][j-1]));
			boutons[i+1][j-1]->setFlat(true);
		}

		if (grille[i+1][j] == '0' && boutons[i+1][j]->isVisible() == true && boutons[i+1][j]->estDrapeau() == false)
		{
			effacerCase(i+1,j);
		}
		else if (grille[i+1][j] != '0' && boutons[i+1][j]->estDrapeau() == false)
		{
			boutons[i+1][j]->setText(QString(grille[i+1][j]));
			boutons[i+1][j]->setFlat(true);
		}

		if (grille[i+1][j+1] == '0' && boutons[i+1][j+1]->isVisible() == true && boutons[i+1][j+1]->estDrapeau() == false)
		{
			effacerCase(i+1,j+1);
		}
		else if (grille[i+1][j+1] != '0' && boutons[i+1][j+1]->estDrapeau() == false)
		{
			boutons[i+1][j+1]->setText(QString(grille[i+1][j+1]));
			boutons[i+1][j+1]->setFlat(true);
		}
	}
	else if (i == 0 && j == NB_CASES_LARGEUR-1)
	{
		if (grille[i][j-1] == '0' && boutons[i][j-1]->isVisible() == true && boutons[i][j-1]->estDrapeau() == false)
		{
			effacerCase(i,j-1);
		}
		else if (grille[i][j-1] != '0' && boutons[i][j-1]->estDrapeau() == false)
		{
			boutons[i][j-1]->setText(QString(grille[i][j-1]));
			boutons[i][j-1]->setFlat(true);
		}

		if (grille[i+1][j-1] == '0' && boutons[i+1][j-1]->isVisible() == true && boutons[i+1][j-1]->estDrapeau() == false)
		{
			effacerCase(i+1,j-1);
		}
		else if (grille[i+1][j-1] != '0' && boutons[i+1][j-1]->estDrapeau() == false)
		{
			boutons[i+1][j-1]->setText(QString(grille[i+1][j-1]));
			boutons[i+1][j-1]->setFlat(true);
		}

		if (grille[i+1][j] == '0' && boutons[i+1][j]->isVisible() == true && boutons[i+1][j]->estDrapeau() == false)
		{
			effacerCase(i+1,j);
		}
		else if (grille[i+1][j] != '0' && boutons[i+1][j]->estDrapeau() == false)
		{
			boutons[i+1][j]->setText(QString(grille[i+1][j]));
			boutons[i+1][j]->setFlat(true);
		}

	}
	else if (i > 0 && i < NB_CASES_HAUTEUR-1 && j == NB_CASES_LARGEUR-1)
	{
		if (grille[i-1][j-1] == '0' && boutons[i-1][j-1]->isVisible() == true && boutons[i-1][j-1]->estDrapeau() == false)
		{
			effacerCase(i-1,j-1);
		}
		else if (grille[i-1][j-1] != '0' && boutons[i-1][j-1]->estDrapeau() == false)
		{
			boutons[i-1][j-1]->setText(QString(grille[i-1][j-1]));
			boutons[i-1][j-1]->setFlat(true);
		}

		if (grille[i-1][j] == '0' && boutons[i-1][j]->isVisible() == true && boutons[i-1][j]->estDrapeau() == false)
		{
			effacerCase(i-1,j);
		}
		else if (grille[i-1][j] != '0' && boutons[i-1][j]->estDrapeau() == false)
		{
			boutons[i-1][j]->setText(QString(grille[i-1][j]));
			boutons[i-1][j]->setFlat(true);
		}

		if (grille[i][j-1] == '0' && boutons[i][j-1]->isVisible() == true && boutons[i][j-1]->estDrapeau() == false)
		{
			effacerCase(i,j-1);
		}
		else if (grille[i][j-1] != '0' && boutons[i][j-1]->estDrapeau() == false)
		{
			boutons[i][j-1]->setText(QString(grille[i][j-1]));
			boutons[i][j-1]->setFlat(true);
		}

		if (grille[i+1][j-1] == '0' && boutons[i+1][j-1]->isVisible() == true && boutons[i+1][j-1]->estDrapeau() == false)
		{
			effacerCase(i+1,j-1);
		}
		else if (grille[i+1][j-1] != '0' && boutons[i+1][j-1]->estDrapeau() == false)
		{
			boutons[i+1][j-1]->setText(QString(grille[i+1][j-1]));
			boutons[i+1][j-1]->setFlat(true);
		}

		if (grille[i+1][j] == '0' && boutons[i+1][j]->isVisible() == true && boutons[i+1][j]->estDrapeau() == false)
		{
			effacerCase(i+1,j);
		}
		else if (grille[i+1][j] != '0' && boutons[i+1][j]->estDrapeau() == false)
		{
			boutons[i+1][j]->setText(QString(grille[i+1][j]));
			boutons[i+1][j]->setFlat(true);
		}

	}
	else if (i == NB_CASES_HAUTEUR-1 && j == NB_CASES_LARGEUR-1)
	{
		if (grille[i-1][j-1] == '0' && boutons[i-1][j-1]->isVisible() == true && boutons[i-1][j-1]->estDrapeau() == false)
		{
			effacerCase(i-1,j-1);
		}
		else if (grille[i-1][j-1] != '0' && boutons[i-1][j-1]->estDrapeau() == false)
		{
			boutons[i-1][j-1]->setText(QString(grille[i-1][j-1]));
			boutons[i-1][j-1]->setFlat(true);
		}

		if (grille[i-1][j] == '0' && boutons[i-1][j]->isVisible() == true && boutons[i-1][j]->estDrapeau() == false)
		{
			effacerCase(i-1,j);
		}
		else if (grille[i-1][j] != '0' && boutons[i-1][j]->estDrapeau() == false)
		{
			boutons[i-1][j]->setText(QString(grille[i-1][j]));
			boutons[i-1][j]->setFlat(true);
		}

		if (grille[i][j-1] == '0' && boutons[i][j-1]->isVisible() == true && boutons[i][j-1]->estDrapeau() == false)
		{
			effacerCase(i,j-1);
		}
		else if (grille[i][j-1] != '0' && boutons[i][j-1]->estDrapeau() == false)
		{
			boutons[i][j-1]->setText(QString(grille[i][j-1]));
			boutons[i][j-1]->setFlat(true);
		}

	}
	else if (i == NB_CASES_HAUTEUR-1 && j > 0 && j < NB_CASES_LARGEUR-1)
	{
		if (grille[i-1][j-1] == '0' && boutons[i-1][j-1]->isVisible() == true && boutons[i-1][j-1]->estDrapeau() == false)
		{
			effacerCase(i-1,j-1);
		}
		else if (grille[i-1][j-1] != '0' && boutons[i-1][j-1]->estDrapeau() == false)
		{
			boutons[i-1][j-1]->setText(QString(grille[i-1][j-1]));
			boutons[i-1][j-1]->setFlat(true);
		}

		if (grille[i-1][j] == '0' && boutons[i-1][j]->isVisible() == true && boutons[i-1][j]->estDrapeau() == false)
		{
			effacerCase(i-1,j);
		}
		else if (grille[i-1][j] != '0' && boutons[i-1][j]->estDrapeau() == false)
		{
			boutons[i-1][j]->setText(QString(grille[i-1][j]));
			boutons[i-1][j]->setFlat(true);
		}

		if (grille[i-1][j+1] == '0' && boutons[i-1][j+1]->isVisible() == true && boutons[i-1][j+1]->estDrapeau() == false)
		{
			effacerCase(i-1,j+1);
		}
		else if (grille[i-1][j+1] != '0' && boutons[i-1][j+1]->estDrapeau() == false)
		{
			boutons[i-1][j+1]->setText(QString(grille[i-1][j+1]));
			boutons[i-1][j+1]->setFlat(true);
		}

		if (grille[i][j-1] == '0' && boutons[i][j-1]->isVisible() == true && boutons[i][j-1]->estDrapeau() == false)
		{
			effacerCase(i,j-1);
		}		
		else if (grille[i][j-1] != '0' && boutons[i][j-1]->estDrapeau() == false)
		{
			boutons[i][j-1]->setText(QString(grille[i][j-1]));
			boutons[i][j-1]->setFlat(true);
		}

		if (grille[i][j+1] == '0' && boutons[i][j+1]->isVisible() == true && boutons[i][j+1]->estDrapeau() == false)
		{
			effacerCase(i,j+1);
		}		
		else if (grille[i][j+1] != '0' && boutons[i][j+1]->estDrapeau() == false)
		{
			boutons[i][j+1]->setText(QString(grille[i][j+1]));
			boutons[i][j+1]->setFlat(true);
		}

	}
	else if (i == NB_CASES_HAUTEUR-1 && j == 0)
	{
		if (grille[i-1][j] == '0' && boutons[i-1][j]->isVisible() == true && boutons[i-1][j]->estDrapeau() == false)
		{
			effacerCase(i-1,j);
		}		
		else if (grille[i-1][j] != '0' && boutons[i-1][j]->estDrapeau() == false)
		{
			boutons[i-1][j]->setText(QString(grille[i-1][j]));
			boutons[i-1][j]->setFlat(true);
		}

		if (grille[i-1][j+1] == '0' && boutons[i-1][j+1]->isVisible() == true && boutons[i-1][j+1]->estDrapeau() == false)
		{
			effacerCase(i-1,j+1);
		}		
		else if (grille[i-1][j+1] != '0' && boutons[i-1][j+1]->estDrapeau() == false)
		{
			boutons[i-1][j+1]->setText(QString(grille[i-1][j+1]));
			boutons[i-1][j+1]->setFlat(true);
		}

		if (grille[i][j+1] == '0' && boutons[i][j+1]->isVisible() == true && boutons[i][j+1]->estDrapeau() == false)
		{
			effacerCase(i,j+1);
		}		
		else if (grille[i][j+1] != '0' && boutons[i][j+1]->estDrapeau() == false)
		{
			boutons[i][j+1]->setText(QString(grille[i][j+1]));
			boutons[i][j+1]->setFlat(true);
		}
	}
	else if (i > 0 && i < NB_CASES_HAUTEUR-1 && j == 0)
	{
		if (grille[i-1][j] == '0' && boutons[i-1][j]->isVisible() == true && boutons[i-1][j]->estDrapeau() == false)
		{
			effacerCase(i-1,j);
		}		
		else if (grille[i-1][j] != '0' && boutons[i-1][j]->estDrapeau() == false)
		{
			boutons[i-1][j]->setText(QString(grille[i-1][j]));
			boutons[i-1][j]->setFlat(true);
		}

		if (grille[i-1][j+1] == '0' && boutons[i-1][j+1]->isVisible() == true && boutons[i-1][j+1]->estDrapeau() == false)
		{
			effacerCase(i-1,j+1);
		}		
		else if (grille[i-1][j+1] != '0' && boutons[i-1][j+1]->estDrapeau() == false)
		{
			boutons[i-1][j+1]->setText(QString(grille[i-1][j+1]));
			boutons[i-1][j+1]->setFlat(true);
		}

		if (grille[i][j+1] == '0' && boutons[i][j+1]->isVisible() == true && boutons[i][j+1]->estDrapeau() == false)
		{
			effacerCase(i,j+1);
		}		
		else if (grille[i][j+1] != '0' && boutons[i][j+1]->estDrapeau() == false)
		{
			boutons[i][j+1]->setText(QString(grille[i][j+1]));
			boutons[i][j+1]->setFlat(true);
		}

		if (grille[i+1][j] == '0' && boutons[i+1][j]->isVisible() == true && boutons[i+1][j]->estDrapeau() == false)
		{
			effacerCase(i+1,j);
		}		
		else if (grille[i+1][j] != '0' && boutons[i+1][j]->estDrapeau() == false)
		{
			boutons[i+1][j]->setText(QString(grille[i+1][j]));
			boutons[i+1][j]->setFlat(true);
		}

		if (grille[i+1][j+1] == '0' && boutons[i+1][j+1]->isVisible() == true && boutons[i+1][j+1]->estDrapeau() == false)
		{
			effacerCase(i+1,j+1);
		}		
		else if (grille[i+1][j+1] != '0' && boutons[i+1][j+1]->estDrapeau() == false)
		{
			boutons[i+1][j+1]->setText(QString(grille[i+1][j+1]));
			boutons[i+1][j+1]->setFlat(true);
		}

	}

}

void Fenetre::gagne()
{
	reponse = QMessageBox::question(this, "Démineur", "Vous avez gagné !<br />Démarrer une nouvelle partie ?", QMessageBox::Yes | QMessageBox::No);

	if (reponse == QMessageBox::Yes)
	{
		nouvellePartie();
	}
	else if (reponse == QMessageBox::No)
	{
		emit quitter();
	}
}

