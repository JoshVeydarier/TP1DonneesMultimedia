
// test_couleur.cpp : Seuille une image en niveau de gris
#include <fstream>
#include <stdio.h>
#include "Image_ppm.h"


int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH,nW,nTaille;
  
  if (argc != 2) 
     {
       printf("Usage: ImageIn.pgm \n"); 
       exit (1) ;
     }
   
  sscanf (argv[1],"%s",cNomImgLue) ;

  int tableau[256];
  for (int i=0; i<256; i++){
    tableau[i] = 0;
  }

   OCTET *ImgIn;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
 
 for (int i=0; i < nH; i++)
   for (int j=0; j < nW; j++)
     tableau[ImgIn[i*nW+j]]++;

 std::ofstream fichier{"histo.dat"};

 for (int i=0; i<256; i++){
   fichier <<i<< "\t"<<tableau[i]<<"\n";
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
