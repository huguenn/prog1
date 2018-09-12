for(f=0;f<3;f++){
  for (c=0;c<3;c++)
  {
    aux=mat[f][c];
    mat[f][c]=mat[c][f];
    mat[c][f]=aux;
  }
  c++;
}
