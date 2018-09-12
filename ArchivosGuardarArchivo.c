void guardarArchivos(struct persona alu[], int cant)
{
	FILE *pf;
	*pf = fopen("lista.dat", "wb"); //abro el archivo lista.dat donde voy a escribir (para guardarlo) y es binario por el .dat
	if (pf) //Si pude abrir el archivo quiere decir esto. Si pude, voy a guardar mis datos en el archivo.
	{
		fwrite(alu, sizeof(struct persona), cant, pf); //le paso: donde esta la info a guardar(le paso el vector, es decir, la dirección del vector, le paso el tamaño, para eso uso SIZEOF, le paso la cantidad de registros que los saco de CANT Y por último el archivo pf
		fclose(pf); //Cierro el archivo
	}
	else
	{
		printf("No se pudo abrir el archivo\n");
	}
}
