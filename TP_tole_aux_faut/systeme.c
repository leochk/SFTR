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
int charge_affichage, charge_calculs ,periode_affichage, periode_calculs;




void afficheur (void *s) {
  sem_t * sem = (sem_t *) s;

  while(cont>0){
    if (sem_wait(sem) != 0) continue;

    printf("X : %f;",coord_x);
	// next line is intended to allow simulating a non trivial almost zero execution time
    usleep(charge_affichage*1000);
    printf(" Y : %f;",coord_y);
    printf(" R : %f;\n",coord_x*coord_x+coord_y*coord_y);

    sem_post(sem);
    usleep(periode_affichage*1000);

  }
}

void simu_systeme(void *s){
    sem_t * sem = (sem_t *) s;

	long valeur_suivante;
	while(cont>0){
	valeur_suivante=(long)time((time_t*)NULL);
    if (sem_wait(sem) != 0) continue;
	coord_x=cos(sens*vitesse*(valeur_suivante-origine)/36.0*2*3.14);
	// temporisation pour simuler la difficulté du calcul
	usleep (charge_calculs*1000);
	coord_y= sin(sens*vitesse*(valeur_suivante-origine)/36.0*2*3.14);
    sem_post(sem);
	usleep(periode_calculs*1000);
	}
}


int main(int argc, char * argv[])
{

  void bye();
  void biip();
  // 2 actions sont possibles : insertion d'un texte "inependant "
  signal(SIGUSR1,biip);
  siginterrupt(SIGUSR1,1);
  // Mise en place du controle de l'arret du  systeme
  signal (SIGINT,bye);
  //Conversion des paramètres d'entrée
	if (argc!=5) {perror("Vous n'avez pas précisé le bon nombre de paramètres\n");
				 return -1;
				}
	else {
		periode_affichage=atoi(argv[1]);
		charge_affichage=atoi(argv[2]);
		periode_calculs=atoi(argv[3]);
		charge_calculs=atoi(argv[4]);

    }
  sem_t semaphore;
  sem_init(&semaphore, 0, 1);

  printf("S-> Demarrage de la simulation...  \n\n");
  simulateur=(pthread_t *)malloc(sizeof(pthread_t));
  pthread_create(simulateur,NULL,(void *)simu_systeme, (void *)&semaphore);
  th_afficheur=(pthread_t *)malloc(sizeof(pthread_t));
  pthread_create(th_afficheur,NULL,(void *)afficheur, (void *)&semaphore);
  pthread_join(*simulateur,NULL);
  printf("\n***********\nDernier etat connu (X,Y):(%f,%f)\n",coord_x,coord_y);
  return 0;
}

void biip(){
  printf("\nSIGUSR1 SENT \n");
  fflush(stdout);
}

void bye()
{
  cont=0;
  printf("S-> Fini \n  Salut !\n");
  }
