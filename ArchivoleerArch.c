int leerArch(struct persona alu[])
{
	FILE * pf = fopen("Lista.dat", "rb"); // inicializo y abro mi archivo
	int cant = 0; //variable para guardar la cantidad de registros.  Lo inicializa en cero, por que si no pude abrir el archivo, va a devolver cero
	if (pf) //esto pregunta SI PUDE ABRIR EL ARCHIVO
	{
		cant = filesize(pf) / sizeof(struct persona); //esto da la cantidad de registros que hay.
		fread(alu, sizeof(struct persona), cant, pf); //primer parametro la dirección deonde lo guardo (el vector), el tamaño de la estructura el segundo, la cantidad de registros y el archivo
		fclose(pf);
	}
	else
	{
		printf("No se pudo leer el archivo\n");
	}
	return cant;
}
