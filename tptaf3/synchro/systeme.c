#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <semaphore.h>
#include <math.h>
#include <errno.h>
#include <pthread.h>

int cont=1;
int sens =1;
int vitesse =1;
long origine =0 ;
double coord_x =0.0;
double coord_y =0.0;
pthread_t * simulateur;
pthread_t * th_afficheur;





void afficheur () {

  while(cont>0){

    printf("X : %f;",coord_x);
#ifdef TEMPO
    usleep(TEMPO);
#endif
    printf(" Y : %f;",coord_y);
    printf(" R : %f;\n",coord_x*coord_x+coord_y*coord_y);
    usleep(1000000);

  }
}

void simu_systeme(){
	long valeur_suivante;
	while(cont>0){
	valeur_suivante=(long)time((time_t*)NULL);
	coord_x=cos(sens*vitesse*(valeur_suivante-origine)/36.0*2*3.14);
	// temporisation pour simuler la difficulte du calcul
#ifdef TEMPO
	usleep (2*TEMPO);
#endif
	coord_y= sin(sens*vitesse*(valeur_suivante-origine)/36.0*2*3.14);
	usleep(30000);
	}
}


int main()
{

  void bye();
  void biip();
  // 2 actions sont possible : insertion d'un texte "inependant "
  signal(SIGUSR1,biip);
  siginterrupt(SIGUSR1,1);
  // Mise en place du controle de l'arret du  systeme
  signal (SIGINT,bye);

  printf("S-> Demarrage de la simulation...  \n\n");
  simulateur=(pthread_t *)malloc(sizeof(pthread_t));
  pthread_create(simulateur,NULL,(void *)simu_systeme, NULL);
  th_afficheur=(pthread_t *)malloc(sizeof(pthread_t));
  pthread_create(th_afficheur,NULL,(void *)afficheur, NULL);
  pthread_join(*simulateur,NULL);
  printf("\n***********\nDernier etat connu (X,Y):(%f,%f)\n",coord_x,coord_y);
  return 0;
}

void biip(){
  printf(".");
  fflush(stdout);
}

void bye()
{
  cont=0;
  printf("S-> Salut !\n");
  }
