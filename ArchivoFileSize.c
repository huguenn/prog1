/*
La logica de esto es enviar a fseek al final y preguntar con ftell donde está.
*/
long int filesize(FILE*pf) //recibe un puntero a FILE
{
	long int posicionactual, posicionfinal; //Long INT por que esto va a devolver eso el ftell (devuelve long int)
	posicionactual = ftell(pf); //me dice a donde esta el indicador del archivo (que posición)
	fseek(pf,0L,SEEK_END); //función que permite mover la posición dentro del archivo, le tengo que decir cuantos lugares me quiero mover y respecto de quien. Se permite mover al comienzo, posición actual o al final (byte que le sigue a lo último escrito). Se puede usar seekend, seekcur o seekset. La "L" es por ser LONG INT.
	posicionfinal = ftell(pf); //le pregunto la posición actual que es la final, ahora tnego inicio y fin.
	fseek(pf, posicionactual, SEEK_SET); //lo vuelvo a mover al inicio, lo muevo hacia el inicio desde "poisicionesactuales
	return posicionfinal;
}
