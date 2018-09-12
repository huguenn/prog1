void ordenarMatriz(int matriz[FIL][COL]){
  int f=0,c,i,aux;
  for(i=0;i<3;i++) //WTF Porque 3????? - Mas alla de eso esto 
  {
    for(c=0;c<3;c++)
    {
      if(matriz[F][C]>matriz[F][C+1])
      {
        for(f=0;f<3;f++)
        {
          aux=matriz[F][C];
          matriz[F][C]=matriz[F][C+1];
          matriz[F][C]=aux;
        }
        F=0; //No entiendo porque esta esto. Posiblemente este muy quemado
      }
    }
  }
}
