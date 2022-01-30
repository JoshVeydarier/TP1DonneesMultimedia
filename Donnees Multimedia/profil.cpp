#include <stdio.h>

#include <fstream>

#include "Image_ppm.h"

 

int main(int argc, char*argv[])

{

  char cNomImgLue[250], info;

  int nH, nW, nTaille, indice;

 

   if (argc!=4)

    {

      printf("Usage : ImageIn.pgm info indice \n");

      exit(1) ;

    }

  sscanf(argv[1],"%s",cNomImgLue) ;

  sscanf(argv[2],"%s",&info) ;

  sscanf(argv[3],"%i",&indice) ;

 

  OCTET *ImgIn;

 

  lire_nb_lignes_colonnes_image_pgm(cNomImgLue,&nH,&nW);

  nTaille = nH*nW ;

 

  allocation_tableau(ImgIn, OCTET, nTaille);

  lire_image_pgm(cNomImgLue, ImgIn, nH*nW);

 

  if (info=='c')

    {

      int tableau[nW];

 

      for (int j=0; j<nW ; j++)

    {

      tableau[j] = ImgIn[indice*nW+j];

      printf("%i %i", j, tableau[j]);

    }

       std::ofstream fichier ("profil.dat");

 

      for (int i=0; i<nW; i++){

    fichier <<i<<"\t"<<tableau[i]<<"\n";

      }

      fichier.close();

    }

 

  else

    {

      int tab[nH];

 

      for (int i=0; i<nH ; i++)

    {

      tab[i] = ImgIn[i*nW+indice];

      printf("%i %i", i, tab[i]);

    }

      std::ofstream fichier ("profil.dat");

      for (int i=0; i<nH; i++){

    fichier <<i<<"\t"<<tab[i]<<"\n";

      }

      fichier.close();

    }

 


	
   //   for (int i=0; i < nTaille; i++)
   // {
   //  if ( ImgIn[i] < S) ImgOut[i]=0; else ImgOut[i]=255;
   //  }

 /*
 for (int i=0; i < nH; i++)
   for (int j=0; j < nW; j++)
     {
       if ( ImgIn[i*nW+j] < S1)
	 ImgOut[i*nW+j]=0;
       else if (ImgIn[i*nW+j] < S2)
   ImgOut[i*nW+j] = 128;
   else ImgOut[i*nW+j] = 255;
     }
 
   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
 */
}
