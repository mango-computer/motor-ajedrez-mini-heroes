/* 1359
	Mango Paola Ajedrez 1.0
	Licencia: GPLv3   
    	Copyright (c) 2012-2013 - Mango Computer c.a 

    	El Programa Mango Paola Ajedrez ésta basado en la investigación de Jose Andres Morales Linares.

	Nadie debería estar restringido por el software que utilizan. Hay cuatro libertades que cada usuario debe tener:
	* La libertad de usar el programa para cualquier propósito,
	* La libertad de cambiar el software para satisfacer sus necesidades,
	* La libertad de compartir el software con sus amigos y vecinos.
	* La libertad de compartir los cambios que realice.

	Cuando un programa se ofrece a los usuarios todas estas libertades, lo llamamos software libre.

	Winglet es un bitboard de código abierto motor de ajedrez. El programa es software libre. Usted puede redistribuirlo y/o 		modificarlo bajo los términos de la Licencia Pública General de GNU según es publicada por la Free Software Foundation, 	bien de 	la versión 3 de la Licencia, o (a su elección) cualquier versión posterior. El programa se distribuye 		con la esperanza de que 		sea útil, pero SIN NINGUNA GARANTÍA, incluso sin la garantía implícita de 		COMERCIALIZACIÓN o IDONEIDAD PARA UN PROPÓSITO 		PARTICULAR. Vea la Licencia Pública General de GNU para más 		detalles: http://www.gnu.org/licenses/

	Existen muchos avances en la forma de escribir motores de ajedrez, estos dos sitios web 
	fuerón de mucha ayuda durante el proceso de investigacion y desarrollo. 
	* http://chessprogramming.wikispaces.com
    	* http://www.sluijten.com/winglet/

    	Información de contacto:
	comprasmangocomputer@gmail.com

*/


#ifndef XMM_C
#define XMM_C

void mostrarTablaCodigos()
{
	printf("\nTABLA DE CÓDIGOS\n\n");
	printf("\t%s\t%s\n","OK",     ": El Comando se ha Ejecutado Satisfactoriamente.");
	printf("\t%s\t%s\n","COD900", ": Error Desconocido.");
	printf("\t%s\t%s\n","COD901", ": Mini Juego no Soportado.");
	printf("\t%s\t%s\n","COD902", ": Movimiento no se Encuentra entre las Posibles Respuestas.");
	printf("\t%s\t%s\n","COD903", ": No Hay Movimientos Posibles.");
	printf("\t%s\t%s\n","COD904", ": Comando no Soportado.");
	printf("\t%s\t%s\n","COD905", ": Comando Desconocido.");
	printf("\t%s\t%s\n","COD906", ": Posición Inválida (Fuera del Rango de [0-63]).");
	printf("\t%s\t%s\n","COD907", ": Color de Pieza Seleccionada Incorrecto.");
	printf("\t%s\t%s\n","COD908", ": Escaque Vacío.");
	printf("\t%s\t%s\n","COD909", ": Movimiento Crea Jaque.");
	printf("\t%s\t%s\n","COD910", ": Comando Necesita un Mini Juego Iniciado.");
	printf("\t%s\t%s\n","COD911", ": No se Puede Agregar la Pieza.");
	printf("\t%s\t%s\n","COD912", ": No se Puede Quitar una Pieza.");
	printf("\t%s\t%s\n","COD913", ": Color del Comando QPR no Reconocido, se Esperaba [BLANCO] [NEGRO].");
	printf("\t%s\t%s\n","COD914", ": Cantidad de Tesoros Fuera del Rango, se Esperaba entre [0-63].");
	printf("\t%s\t%s\n","COD915", ": No Hay Tesoros.");
	printf("\t%s\t%s\n","COD916", ": Mini Juego 19 no se ha Iniciado.");
	printf("\t%s\t%s\n","COD917", ": No Hay Mas de 2 Piezas Atacadas.");
	printf("\t%s\t%s\n","COD918", ": No Hay Peones Enemigos.");
	printf("\t%s\t%s\n","COD919", ": Escaque es una puerta de salida.");
	printf("\t%s\t%s\n","COD920", ": Escaque no esta vacio.");
	printf("\t%s\t%s\n","COD921", ": Creacion de Pieza Crea Jaque.");
	printf("\t%s\t%s\n","COD922", ": El minijuego no tiene un laberinto.");
	printf("\t%s\t%s\n","COD923", ": No hay rey blanco en el tablero.");
	printf("\t%s\t%s\n","COD924", ": Mini Juego 1 no se ha Iniciado.");
	printf("\t%s\t%s\n","COD925", ": No existe un escaque de salida o no existe un laberinto en el MiniJuego actual.");
	printf("\t%s\t%s\n","COD926", ": No existe muros para mover.");
	printf("\t%s\t%s\n","COD927", ": Mini Juego 23 no se ha Iniciado.");
	printf("\t%s\t%s\n","COD928", ": GMO no ha encontrado movimientos posibles que cumplan las reglas que se han especificado.");
	printf("\t%s\t%s\n","COD929", ": Mini Juego no tiene puerta de salida.");
	printf("\t%s\t%s\n","COD930", ": CUP no ha encontrado movimientos posibles.");
	printf("\t%s\t%s\n","COD931", ": GON no ha encontrado movimientos posibles.");
	printf("\t%s\t%s\n","COD932", ": Mini Juego 21 no se ha Iniciado.");
	printf("\t%s\t%s\n","COD933", ": M21 no ha encontrado movimientos posibles.");

}

void mostrarListaAyudaGeneral()
{
printf("\nLISTA DE COMANDOS DEL PROTOCOLO XMM. Tecleé MAN y el nombre un comando para ampliar la ayuda (Ej. MAN MJN)\n\n");
printf("\t%s\t%s\n","AGM [pos][COLOR]          ", ": Agrega un muro en pos enemigo/amigo según el parámetro color.");
printf("\t%s\t%s\n","APR [PIEZA]               ", ": Agrega la pieza en el tablero de forma aleatoria.");
printf("\t%s\t%s\n","ATE [cantidad]            ", ": Agrega tesoros al tablero según el parámetro cantidad.");
printf("\t%s\t%s\n","AUC [nn]                  ", ": Activa/Desactiva la opción de informar la ultima captura.");
printf("\t%s\t%s\n","AYUDA                     ", ": Muestra la presente ayuda.");
printf("\t%s\t%s\n","BLA                       ", ": Cambia el turno a blancas.");
printf("\t%s\t%s\n","C2M [n]                   ", ": Configura el GMO para permitir promoción.");
printf("\t%s\t%s\n","CFN [cadena-fen]          ", ": Cambia el tablero según la cadena fen.");
printf("\t%s\t%s\n","CM1                       ", ": Cambiar mapa del laberinto del MiniJuego #1.");
printf("\t%s\t%s\n","CM10                      ", ": Cambiar mapa del laberinto del MiniJuego #10.");
printf("\t%s\t%s\n","CM23                      ", ": Cambiar mapa del laberinto del MiniJuego #23.");
printf("\t%s\t%s\n","CMA [n]                   ", ": Configura el GMO para establecer prioridad en el movimiento a escaques no amenazados.");
printf("\t%s\t%s\n","CMC [n]                   ", ": Configura el GMO para establecer prioridad en las capturas.");
printf("\t%s\t%s\n","CMF [n]                   ", ": Configura el GMO para permitir solamente movimientos en la misma fila.");
printf("\t%s\t%s\n","CML [n]                   ", ": Configura el GMO para permitir solamente movimientos en la misma columna.");
printf("\t%s\t%s\n","CMM [n]                   ", ": Configura el GMO para permitir el movimiento de muro o peón.");
printf("\t%s\t%s\n","CMP [n]                   ", ": Configura el GMO puede capturar.");
printf("\t%s\t%s\n","CMS [n]                   ", ": Configura el GMO mueva solo un paso en cada movimiento (modo sigiloso).");
printf("\t%s\t%s\n","CMT [n]                   ", ": Configura el GMO solamente movimientos capturas, excluyendo todos los demás.");
printf("\t%s\t%s\n","CMW [n]                   ", ": Configura el GMO para permitir la captura de muros o peones.");

printf("\t%s\t%s\n","COD                       ", ": Muestra la tabla de códigos.");
printf("\t%s\t%s\n","CTR                       ", ": Cambia el color del turno actual.");
printf("\t%s\t%s\n","CUP [n]                   ", ": Genera un movimiento a las negras para bloquear la salida del laberinto.");
printf("\t%s\t%s\n","DTE                       ", ": Devuelve las pos de los tesoros.");
printf("\t%s\t%s\n","IGJ                       ", ": Activa/Desactiva la opción de ignorar jaque cuando el rey mueve.");
printf("\t%s\t%s\n","M21                       ", ": Genera un movimiento aleatorio de una pieza negra en el minijuego21.");
printf("\t%s\t%s\n","MCP                       ", ": Devuelve todos los escaques de captura de todos los peones negros.");
printf("\t%s\t%s\n","MMR [COLOR]               ", ": Mueve un muro enemigo/amigo según el parámetro color.");
printf("\t%s\t%s\n","MUR [COLOR][n][nnn]       ", ": Agrega muros aleatoriamente del color especificado, bloqueantes o no, con la densidad.");
printf("\t%s\t%s\n","MVI [pos][opcion]         ", ": Devuelve los escaques donde puede moverse la pieza ubicada en pos.");
printf("\t%s\t%s\n","MVL                       ", ": Devuelve todos los escaques donde puede moverse todas las piezas.");
printf("\t%s\t%s\n","FIN                       ", ": Cierra el protocolo XMM.");
printf("\t%s\t%s\n","FEN                       ", ": Devuelve la cadena fen actual del tablero.");
printf("\t%s\t%s\n","GMO [COLOR][RAND|POS][nn] ", ": Genera un movimiento aleatorio de una pieza.");
printf("\t%s\t%s\n","GON                       ", ": Genera un movimiento de las piezas negras pensado por el motor.");
printf("\t%s\t%s\n","MAN [COMANDO]             ", ": Amplía la ayuda del comando. Ej. MAN MJN");
printf("\t%s\t%s\n","MJF [nn][cadena-fen]      ", ": Inicia el Mini Juego # nn con las posiciones indicadas en la cadena fen.");
printf("\t%s\t%s\n","MJN [nn][nn]              ", ": Inicia el Mini Juego # nn generado aleatoriamente.\n\t\t                          opcionalmente se puede proporcionar en el segundo parámetro la densidad de muros.");
printf("\t%s\t%s\n","MOV [pos1][pos2]          ", ": Realiza el movimiento de la pieza desde pos1 hasta pos2.");
printf("\t%s\t%s\n","NBP                       ", ": Devuelve el total de piezas blancas incluyendo los peones pero sin contar el rey.");
printf("\t%s\t%s\n","NBS                       ", ": Devuelve el total de piezas blancas sin contar los peones y sin contar el rey).");
printf("\t%s\t%s\n","NDF [nn]                  ", ": Establece el nivel de dificultad o el nivel de capas de búsqueda según el parámetro nn.");
printf("\t%s\t%s\n","NGR                       ", ": Cambia el turno a negras.");
printf("\t%s\t%s\n","NMJ                       ", ": Muestra el número del mini juego actual.");
printf("\t%s\t%s\n","NNP                       ", ": Devuelve el total de piezas negras incluyendo los peones pero sin contar el rey.");
printf("\t%s\t%s\n","NNS                       ", ": Devuelve el total de piezas negras sin contar los peones y sin contar el rey.");
printf("\t%s\t%s\n","PIN [n]                   ", ": Devuelve un PON con el número enviado.");
printf("\t%s\t%s\n","POW                       ", ": Devuelve todos los escaques donde se encuentran los muros blancos.");
printf("\t%s\t%s\n","QAC [pos]                 ", ": Quita las piezas atacadas doblemente por el caballo (Sólo para el mini juego 19)");
printf("\t%s\t%s\n","QPP [pos]                 ", ": Quita la pieza ubicada en pos del tablero.");
printf("\t%s\t%s\n","QPR [PIEZA][COLOR]        ", ": Quita del tablero una pieza de forma random.");
printf("\t%s\t%s\n","QTE                       ", ": Quitar tesoro del tablero de forma random.");
printf("\t%s\t%s\n","T                         ", ": Muestra el tablero en formato ascii.");
printf("\t%s\t%s\n","TUR                       ", ": Devuelve el color del turno actual.");
printf("\t%s\t%s\n","VCL                       ", ": Devuelve los escaques donde puede mover el rey para resolver el laberinto.");
printf("\t%s\t%s\n","VER                       ", ": Muestra información sobre el protocolo.");
printf("\t%s\t%s\n","VPR                       ", ": Devuelve el número del escaque donde se encuentra el rey blanco.");
printf("\t%s\t%s\n","VPS                       ", ": Devuelve el número del escaque de salida del laberinto.");

}

void mostrarAyuda(char *nombre, char *sinopsis, char *descripcion, char *param, char *des_param)
{
	printf("\nNOMBRE\n");
	printf("\t %s\n",nombre);

	printf("\nSINOPSIS\n");
	printf("\t %s\n",sinopsis);

	printf("\nDESCRIPCION\n");
	printf("\t %s\n",descripcion);

	printf("\nPARAMETROS\n");
	printf("\t %s\t%s\n",param,des_param);
}

void conver2FEN(TABLERO t, char *string)
{
	int x, y, l=0, i=0, sq;
	char row[8];

	strcpy(string,"");

	for (y=0;y<8;y++) {
		i=l=0;
		strcpy(row,"");
		for (x=0;x<8;x++) {
			sq = (y*8)+x;
			if (t[ESPEJO[sq]] == VACIO) l++;
			else {
				if (l>0) 
				{
					row[i] = (char) (l+48);
					i++;
				}
				l=0;
				switch (t[ESPEJO[sq]]) 
				{
					case PEON_BLANCO 	: row[i]='P';break;
					case CABALLO_BLANCO 	: row[i]='N';break;
					case ALFIL_BLANCO	: row[i]='B';break;
					case TORRE_BLANCO	: row[i]='R';break;
					case DAMA_BLANCO	: row[i]='Q';break;
					case REY_BLANCO	 	: row[i]='K';break;

					case PEON_NEGRO	 	: row[i]='p';break;
					case CABALLO_NEGRO 	: row[i]='n';break;
					case ALFIL_NEGRO	: row[i]='b';break;
					case TORRE_NEGRO	: row[i]='r';break;
					case DAMA_NEGRO	 	: row[i]='q';break;
					case REY_NEGRO	 	: row[i]='k';break;
				}
				i++;
			}
		}
		if (l>0) {
			row[i] = (char) (l+48);
			i++;
		}
		strncat(string,row,i);
		if (y<7) strcat(string,"/");
	}

	if (juego.colorTurno) strcat(string," b ");
	else strcat(string," w ");
}

void setFENXMM(TABLERO t, int pos2, BOOLEANO esMostrar)
{
	char fenn[100];
	memset(fenn,VACIO,sizeof(fenn));
	conver2FEN(t,fenn);
	if (esMostrar)
	{
		char fennW[100];
		strncpy(fennW,fenn,sizeof(fenn));
		parseFEN2FENW(fennW);

		if (pos2 > -1)
		{
			parseFENW2FENWS(pos2,fennW);
			printf("%s\n",fennW);

		} else {

			printf("%s\n",fennW);
		}
	}

	char fen[100];
	char fencolor[2];     
	char fenEnroque[5];
	char fenPeonPaso[3];
	int fenReglaCincuentaMov=0;
	int fenTotalMov=0;

	sscanf(fenn, "%s %s %s %s %d %d",
				fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov);
	setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);
}

void parseFENW2FENWS(int posS, char *fen)
{
	int i, file, rank, contador;
	int x, y, l=0, sq;
	char row[8];

	TABLERO ESCAQUES_TMP; 

	for (i = 0; i < 64; i++)
	{
	      ESCAQUES_TMP[i] = VACIO;
	}
 
       file = 1;
       rank = 8;
       i = 0;
       contador = 0;
       while ((contador < 64) && (fen[i] != '\0'))
       {
              if (((int) fen[i] > 48) && ((int) fen[i] < 57))
              {
                     file+= (int) fen[i] - 48;
                     contador+= (int) fen[i] - 48;
              } else {
                     switch (fen[i])
                     {
                           case '/':
                                  rank--;
                                  file = 1;
                                  break;
 
                           case 'P':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = PEON_BLANCO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'N':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = CABALLO_BLANCO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'B':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = ALFIL_BLANCO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'R':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = TORRE_BLANCO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'Q':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = DAMA_BLANCO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'K':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = REY_BLANCO;
                                  file += 1;
                                  contador += 1;
                                  break;

                           case 'W':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = W_MURO;
                                  file += 1;
                                  contador += 1;
                                  break;

 
                           case 'p':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = PEON_NEGRO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'n':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = CABALLO_NEGRO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'b':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = ALFIL_NEGRO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'r':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = TORRE_NEGRO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'q':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = DAMA_NEGRO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'k':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = REY_NEGRO;
                                  file += 1;
                                  contador += 1;
                                  break;
 
                           case 'w':
                                  ESCAQUES_TMP[FILERANK2POS[file][rank]] = w_MURO;
                                  file += 1;
                                  contador += 1;
                                  break;

                           default:
                                  break;
                     }
              }
              i++;
       }

	if (ES_RANGO_POS_VALIDA(posS))
		ESCAQUES_TMP[posS] = SALIDA_LABERINTO; 

	x=0;
	y=0;
	l=0;
	i=0; 
	sq=0;

	char fen_tmp[100];
	memset(fen_tmp,'\0',100);

	for (y=0;y<8;y++) {
		i=l=0;
		strcpy(row,"");
		for (x=0;x<8;x++) {
			sq = (y*8)+x;
			if (ESCAQUES_TMP[ESPEJO[sq]] == VACIO) l++;
			else {
				if (l>0) 
				{
					row[i] = (char) (l+48);
					i++;
				}
				l=0;
				switch (ESCAQUES_TMP[ESPEJO[sq]]) 
				{
					case PEON_BLANCO 	: row[i]='P';break;
					case CABALLO_BLANCO 	: row[i]='N';break;
					case ALFIL_BLANCO	: row[i]='B';break;
					case TORRE_BLANCO	: row[i]='R';break;
					case DAMA_BLANCO	: row[i]='Q';break;
					case REY_BLANCO	 	: row[i]='K';break;
					case W_MURO	 	: row[i]='W';break;

					case PEON_NEGRO	 	: row[i]='p';break;
					case CABALLO_NEGRO 	: row[i]='n';break;
					case ALFIL_NEGRO	: row[i]='b';break;
					case TORRE_NEGRO	: row[i]='r';break;
					case DAMA_NEGRO	 	: row[i]='q';break;
					case REY_NEGRO	 	: row[i]='k';break;
					case w_MURO	 	: row[i]='w';break;

					case SALIDA_LABERINTO 	: row[i]='E';break;
				}
				i++;
			}
		}
		if (l>0) {
			row[i] = (char) (l+48);
			i++;
		}
		strncat(fen_tmp,row,i);
		if (y<7) strcat(fen_tmp,"/");
	}

	char fen1[100];
	char fencolor[2];     

	sscanf(fen, "%s %s", fen1,fencolor);
	memset(fen,'\0',100);
	sprintf(fen,"%s %s",fen_tmp,fencolor);
}

void parseFEN2FENW(char *fen)
{
	int i=0;
	for (i=0;i<100;i++)
	{
		if (fen[i]=='P') fen[i]='W';
		if (fen[i]=='p') fen[i]='w';
	}
}

void parseFEN2FENW_SIN_w(char *fen)
{
	int i=0;
	for (i=0;i<100;i++)
	{
		if (fen[i]=='P') fen[i]='W';
	}
}

void parseFENW2FEN(char *fen)
{
	int i=0;
	for (i=0;i<100;i++)
	{
		if (fen[i]=='W') fen[i]='P';
		if (fen[i]=='w') fen[i]='p';
	}
}

void limpiarTableroMiniJuegos()
{
	TABLERO t;
	memset(t, VACIO, sizeof(t));
	setFENXMM(t, -1, FALSO);
}

void cambiarMapaMiniJuego1()
{
	uint64 tempDestinos = getMapaMuros(caminoLaberintoMapa | juego.tablero[BLANCO][REY]);
	int escaqueDestino=SIN_POS_VALIDA;
	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	

	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_BLANCO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	t[bitScanForwardBruijn(juego.tablero[BLANCO][REY])] = REY_BLANCO;
	setFENXMM(t, posSalida, VERDADERO);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void cambiarMapaMiniJuego10()
{
	uint64 tempDestinos = getMapaMuros(caminoLaberintoMapa | juego.tablero[BLANCO][ALFIL]);
	int escaqueDestino=SIN_POS_VALIDA;
	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	

	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_NEGRO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	tempDestinos = getMapaCrearMuros(VERDADERO);
	tempDestinos |= BITSET[posSalida];
	tempDestinos ^= BITSET[posSalida];
	int cmb=0, maxPeones = (cuentaBit(tempDestinos)-1);
	while (cmb < maxPeones)
	{
		escaqueDestino = rand()%64;
		if (BITSET[escaqueDestino] & tempDestinos)
		{
			t[escaqueDestino] = PEON_NEGRO;
			tempDestinos ^= BITSET[escaqueDestino];
			cmb++;
		}
	}

	t[bitScanForwardBruijn(juego.tablero[BLANCO][ALFIL])] = ALFIL_BLANCO;
	setFENXMM(t, posSalida, VERDADERO);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

uint64 getMapaCrearMuros(BOOLEANO esBloqueante)
{
	uint64 mapaDestinos;

	if (caminoLaberintoMapa)
	{
		if (esBloqueante)
		{
			mapaDestinos = (~juego.ocupados & caminoLaberintoMapa); 
	
		} else {

			mapaDestinos = (~juego.ocupados & ~caminoLaberintoMapa);
		}

	} else {
		
		mapaDestinos = ~juego.ocupados;
	}

	return mapaDestinos;
}

void crearMuros(COLOR colorMuros, BOOLEANO esBloqueante)
{
	int vuelta = 0;
	int pos = 0;
	uint64 mapaDestinos;
	
	if (!llenado_laberinto) return;

	mapaDestinos = getMapaCrearMuros(esBloqueante);

	TABLERO t;
	memcpy(t, ESCAQUES, sizeof(t));	
	PIEZA peonMuro = (colorMuros ? PEON_NEGRO:PEON_BLANCO);

	for (vuelta=0;vuelta<llenado_laberinto;vuelta++)
	{
		pos = rand()%64;
		if (mapaDestinos & BITSET[pos])
		{
			t[pos] = peonMuro;
			mapaDestinos ^= BITSET[pos];
		}
	}

	setFENXMM(t, posSalida, FALSO);
	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);
}

void llenadoPeonMuro(PIEZA pp)
{
	int posCol, densidad, i;

	if (llenado_laberinto>0 && llenado_laberinto<121)
		densidad = llenado_laberinto/4;
	else
		return;

	for (i=0;i< densidad;i++)
	{
		agregarPiezaPosRandom(pp, &posCol, FALSO);
	}

}

int iniMiniJuego1(BOOLEANO esVerFen)
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int pos1=SIN_POS_VALIDA,pos2=SIN_POS_VALIDA;
	uint64 mapaParedes = getMapaMuros(getBitMapCaminoMapa(&pos1,&pos2));
	posSalida = pos2;
	uint64 tempDestinos = mapaParedes;
	int escaqueDestino=SIN_POS_VALIDA;
	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	

	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_BLANCO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	t[pos1] = REY_BLANCO;
	setFENXMM(t, pos2, esVerFen);

	memset(monedasTablero,0, sizeof(uint8) * 64);

	return pos2;
}

void iniMiniJuego2()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = iniMiniJuego1(FALSO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol,FALSO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol,FALSO);	

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);
}

void iniMiniJuego3()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = SIN_POS_VALIDA;
	TABLERO t;
	memset(t, VACIO, sizeof(t));
	t[rand()%64] = REY_BLANCO;
	setFENXMM(t, -1, FALSO);

	llenadoPeonMuro(PEON_BLANCO);

//	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
//	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
//*
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);
//*/

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW_SIN_w(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego4()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = iniMiniJuego1(FALSO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);	

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);

//	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego5()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = SIN_POS_VALIDA;

	limpiarTableroMiniJuegos();
	llenadoPeonMuro(PEON_NEGRO);
/*
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);
*/
	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);

	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego6()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = SIN_POS_VALIDA;

	limpiarTableroMiniJuegos();
	
	llenadoPeonMuro(PEON_BLANCO);
/*
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
*/	
	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);

	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego7()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = SIN_POS_VALIDA;

	limpiarTableroMiniJuegos();

	llenadoPeonMuro(PEON_NEGRO);

	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);	
	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);

	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);	

/*
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
*/

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego8()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int pos1=SIN_POS_VALIDA, pos2=SIN_POS_VALIDA, contPiezas=0,maxPeones=0, escaquePos=SIN_POS_VALIDA, posCol=SIN_POS_VALIDA;
//	uint64 mapaParedes = getBitMapCaminoMapaAlfil(&pos1,&pos2);
	uint64 ppiezas = getBitMapCaminoMapaAlfil(&pos1,&pos2);;
	ppiezas ^= ppiezas;
	posSalida = pos2;

	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 

	t[pos1] = REY_BLANCO;
	ppiezas = (BITSET[pos1] | BITSET[pos2]);

	setFENXMM(t, pos2, FALSO);

	uint64 mapaDestinoTorre = mascaraRey[pos1];
	int posTorre=SIN_POS_VALIDA;

	while(VERDADERO)
	{
		posTorre = rand()%64;
		if (BITSET[posTorre] & mapaDestinoTorre)
		{
			ppiezas |= BITSET[posTorre];
			t[posTorre] = TORRE_BLANCO;
			break;	
		}		
	}

	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);	
	ppiezas |= BITSET[posCol];
	t[posCol] = ALFIL_NEGRO;	
	
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	ppiezas |= BITSET[posCol];	
	t[posCol] = ALFIL_NEGRO;


	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);	
	ppiezas |= BITSET[posCol];
	t[posCol] = TORRE_NEGRO;	
	
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);
	ppiezas |= BITSET[posCol];	
	t[posCol] = TORRE_NEGRO;


	if (llenado_laberinto>0 && llenado_laberinto<120)
		maxPeones = llenado_laberinto/3;
	else
		maxPeones = 0;
	

	while (contPiezas<maxPeones)
	{
		escaquePos = rand()%64;
		if (BITSET[escaquePos] & ppiezas) continue;
		t[escaquePos] = PEON_NEGRO;
		ppiezas |= BITSET[escaquePos];
		contPiezas++;
	}

	setFENXMM(t, pos2, FALSO);
	
	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego9()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = iniMiniJuego1(FALSO);

	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	

	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);	
	agregarPiezaPosRandom(TORRE_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, FALSO);
	

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);

//	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego10()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int pos1=SIN_POS_VALIDA,pos2=SIN_POS_VALIDA;
	uint64 mapaParedes = getMapaMuros(getBitMapCaminoMapaAlfil(&pos1,&pos2));
	posSalida = pos2;
	uint64 tempDestinos = mapaParedes;
	int escaqueDestino=SIN_POS_VALIDA;
	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	
	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_NEGRO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	tempDestinos = getMapaCrearMuros(VERDADERO);
	tempDestinos |= BITSET[pos2];
	tempDestinos ^= BITSET[pos2];
	int cmb=0, maxPeones = (cuentaBit(tempDestinos)-1);
	while (cmb < maxPeones)
	{
		escaqueDestino = rand()%64;
		if (BITSET[escaqueDestino] & tempDestinos)
		{
			t[escaqueDestino] = PEON_NEGRO;
			tempDestinos ^= BITSET[escaqueDestino];
			cmb++;
		}
	}

	t[pos1] = ALFIL_BLANCO;
	setFENXMM(t, pos2, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego11()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = SIN_POS_VALIDA;

	limpiarTableroMiniJuegos();

	llenadoPeonMuro(PEON_NEGRO);

	agregarPiezaPosRandom(ALFIL_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(ALFIL_BLANCO, &posCol, FALSO);

	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego12()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	t[2]  = ALFIL_BLANCO;
	t[5]  = ALFIL_BLANCO;

	t[49] = PEON_NEGRO;
	t[50] = PEON_NEGRO;
	t[53] = PEON_NEGRO;
	t[54] = PEON_NEGRO;
	t[58] = TORRE_NEGRO;
	t[61] = TORRE_NEGRO;

	t[24] = PEON_NEGRO;
	t[25] = PEON_NEGRO;
	t[31] = PEON_NEGRO;
	t[30] = PEON_NEGRO;
	t[32] = TORRE_NEGRO;
	t[39] = TORRE_NEGRO;

	setFENXMM(t, -1, VERDADERO);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego13()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int pos1=SIN_POS_VALIDA,pos2=SIN_POS_VALIDA;
	uint64 mapaParedes = getMapaMuros(getBitMapCaminoMapaAlfil(&pos1,&pos2));
	posSalida = pos2;
	uint64 tempDestinos = mapaParedes;
	int escaqueDestino=SIN_POS_VALIDA;
	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	
	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_NEGRO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	t[pos1] = ALFIL_BLANCO;

	setFENXMM(t, pos2, FALSO);

	if (BITSET[pos1] & ESCAQUES_BLANCOS)
	{
		tempDestinos = (~juego.ocupados & ESCAQUES_BLANCOS);	
	
	} else {

		tempDestinos = (~juego.ocupados & ESCAQUES_NEGROS);
	}

	tempDestinos |= mascaraRey[pos2];
	tempDestinos ^= mascaraRey[pos2];

	while(tempDestinos)
	{
		escaqueDestino = rand()%64;
		if (BITSET[escaqueDestino] & tempDestinos)
		{
			t[escaqueDestino] = ALFIL_BLANCO;
			setFENXMM(t, pos2, FALSO);
			break;
		}
	}

	tempDestinos = getMapaCrearMuros(VERDADERO);

	tempDestinos |= BITSET[pos2];
	tempDestinos ^= BITSET[pos2];

	int cmb=0, maxPeones = (cuentaBit(tempDestinos)-1);
	while (cmb < maxPeones)
	{
		escaqueDestino = rand()%64;
		if (BITSET[escaqueDestino] & tempDestinos)
		{
			t[escaqueDestino] = PEON_NEGRO;
			tempDestinos ^= BITSET[escaqueDestino];
			cmb++;
		}
	}

	setFENXMM(t, pos2, FALSO);
	
//	agregarPiezaPosRandom(ALFIL_BLANCO, &posCol, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego14()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	t[0]  = TORRE_BLANCO;
	t[2]  = ALFIL_BLANCO;
	t[4]  = REY_BLANCO;
	t[7]  = TORRE_BLANCO;
	t[5]  = ALFIL_BLANCO;

	t[57]  = TORRE_NEGRO;
	t[58]  = ALFIL_NEGRO;
	t[60]  = REY_NEGRO;
	t[62]  = TORRE_NEGRO;
	t[61]  = ALFIL_NEGRO;

	setFENXMM(t, -1, VERDADERO);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego15()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int pos1=SIN_POS_VALIDA,pos2=SIN_POS_VALIDA, posCol=SIN_POS_VALIDA;
	posSalida = SIN_POS_VALIDA;

	uint64 mapaParedes = getMapaMuros(getBitMapCaminoMapa(&pos1,&pos2));
	posSalida = pos2;

	uint64 tempDestinos = mapaParedes;
	int escaqueDestino=SIN_POS_VALIDA;
	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	

	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_BLANCO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	t[pos1] = DAMA_BLANCO;
	setFENXMM(t, pos2, FALSO);

	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
//	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego16()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int pos1=SIN_POS_VALIDA,pos2=SIN_POS_VALIDA;
	posSalida = SIN_POS_VALIDA;

	uint64 mapaParedes = getMapaMuros(getBitMapCaminoMapa(&pos1,&pos2));
	posSalida = pos2;

	uint64 tempDestinos = mapaParedes;
	int escaqueDestino=SIN_POS_VALIDA;
	int posCol;

	TABLERO t = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0}; 
	

	while (tempDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(tempDestinos);
		t[escaqueDestino] = PEON_BLANCO;
		tempDestinos ^= BITSET[escaqueDestino];
	}

	t[pos1] = DAMA_BLANCO;
	setFENXMM(t, pos2, FALSO);

	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);	
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);	
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);	
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);	

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego17()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = iniMiniJuego1(FALSO);

	agregarPiezaPosRandom(DAMA_BLANCO, &posCol, FALSO);	
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, FALSO);	
	agregarPiezaPosRandom(ALFIL_NEGRO, &posCol, VERDADERO);
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);	
	agregarPiezaPosRandom(TORRE_NEGRO, &posCol, VERDADERO);	

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	parseFENW2FENWS(posSalida,fen);
	printf("%s\n",fen);
//	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego18()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int posCol=0;
	posSalida = SIN_POS_VALIDA;

	limpiarTableroMiniJuegos();

	llenadoPeonMuro(PEON_BLANCO);
/*	
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
	agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);
*/
	agregarPiezaPosRandom(CABALLO_BLANCO, &posCol, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	parseFEN2FENW(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego19()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	int i=0, densidad=0;
	int escaqueDestino=0;
	uint64 mapaDestinos, mapaDestinosCaballo;
	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);
	mapaDestinos ^= mapaDestinos;

	if (llenado_laberinto>0 && llenado_laberinto<121)
		densidad = llenado_laberinto/10;

	for (i=0;i<densidad;i++)
	{
		mapaDestinos |= mascaraCaballo[rand()%64];
	}

	mapaDestinosCaballo = ~mapaDestinos;

	while (mapaDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(mapaDestinos);
		t[escaqueDestino] = PEON_NEGRO; 
		mapaDestinos ^= BITSET[escaqueDestino];
	}	
	
	i=0;
	while (mapaDestinosCaballo && i<2)
	{
		escaqueDestino = rand()%64;
		if (mapaDestinosCaballo & BITSET[escaqueDestino])
		{
			i++;
			t[escaqueDestino] = CABALLO_BLANCO;	
			mapaDestinosCaballo ^= BITSET[escaqueDestino];
		}
	}	

	setFENXMM(t, -1, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego20()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	t[8]  = PEON_BLANCO;
	t[9]  = PEON_BLANCO;
	t[10] = PEON_BLANCO;
	t[11] = PEON_BLANCO;
	t[12] = PEON_BLANCO;
	t[13] = PEON_BLANCO;
	t[14] = PEON_BLANCO;
	t[15] = PEON_BLANCO;

	setFENXMM(t, -1, FALSO);

	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	printf("%s\n",fen);

	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego21()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	t[24] = PEON_BLANCO;
	t[25] = PEON_BLANCO;
	t[26] = PEON_BLANCO;
	t[27] = PEON_BLANCO;
	t[28] = PEON_BLANCO;
	t[29] = PEON_BLANCO;
	t[30] = PEON_BLANCO;
	t[31] = PEON_BLANCO;

	t[48] = PEON_NEGRO;
	t[49] = PEON_NEGRO;
	t[50] = PEON_NEGRO;
	t[51] = PEON_NEGRO;
	t[52] = PEON_NEGRO;
	t[53] = PEON_NEGRO;
	t[54] = PEON_NEGRO;
	t[55] = PEON_NEGRO;

	setFENXMM(t, -1, FALSO);
	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	printf("%s\n",fen);
	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego22()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;	

	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	t[1]  = CABALLO_BLANCO;
	t[6]  = CABALLO_BLANCO;
	t[9] = PEON_BLANCO;
	t[10] = PEON_BLANCO;
	t[11] = PEON_BLANCO;
	t[12] = PEON_BLANCO;
	t[13] = PEON_BLANCO;
	t[14] = PEON_BLANCO;

	t[48] = PEON_NEGRO;
	t[49] = PEON_NEGRO;
	t[50] = PEON_NEGRO;
	t[51] = PEON_NEGRO;
	t[52] = PEON_NEGRO;
	t[53] = PEON_NEGRO;
	t[54] = PEON_NEGRO;
	t[55] = PEON_NEGRO;

	setFENXMM(t, -1, FALSO);
	char fen[100];
	memset(fen,'\0', 100);
	converTabler2FEN(fen);
	printf("%s\n",fen);
	memset(monedasTablero,0, sizeof(uint8) * 64);
}

void iniMiniJuego23()
{
	caminoLaberintoMapa ^= caminoLaberintoMapa;
	mapaMinijuego23	^= mapaMinijuego23;	

	TABLERO t;
	posSalida = SIN_POS_VALIDA;
	
	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	printf("%s\n", MAPAS_FEN[cambiarMapaMiniJuego23()]);
}

int cambiarMapaMiniJuego23()
{
	TABLERO t;
	int mapaEnrroqueId;

	limpiarTableroMiniJuegos();
	memset(t,VACIO, sizeof(uint8)*64);

	int cantidadContada = cuentaBit(mapaMinijuego23);
 
	if (cantidadContada==MAX_MAPAS_MINIJUEGO23)
	{
		mapaMinijuego23 ^= mapaMinijuego23;
	}

	while (VERDADERO)
	{
		mapaEnrroqueId = rand()%MAX_MAPAS_MINIJUEGO23;
		if (BITSET[mapaEnrroqueId] & mapaMinijuego23)
		{
			continue;

		} else {
			
			mapaMinijuego23 |= BITSET[mapaEnrroqueId];
			break;
		}
	}

	char fen[100];
	char fencolor[2];     
	char fenEnroque[5];
	char fenPeonPaso[3];
	int fenReglaCincuentaMov=0;
	int fenTotalMov=0;
	statusFinJuego = STATUS_FIN_JUEGO_SIN_ESTATUS;

	sscanf(MAPAS_FEN[mapaEnrroqueId], "%s %s %s %s %d %d",
		   fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov);

	setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);

	return mapaEnrroqueId;
}

int quitarPiezasAtacadasPorCaballo(int pos)
{
	uint64 mapaPiezas;
	int escaqueDestino=0;
	int c=0;
	TABLERO t;
	
	if (!(juego.tablero[BLANCO][CABALLO] & BITSET[pos])) return 0;

	mapaPiezas = juego.negros ^ juego.tablero[NEGRO][REY];
	mapaPiezas &= mascaraCaballo[pos];


	if (cuentaBit(mapaPiezas) < 2) return c;

	memcpy(t, ESCAQUES, sizeof(ESCAQUES));

	while (mapaPiezas)
	{
		escaqueDestino = bitScanForwardBruijn(mapaPiezas);
		printf("%d ",escaqueDestino);
		mapaPiezas ^= BITSET[escaqueDestino];
		t[escaqueDestino] = VACIO;
		c++;
	}

	if (c)
	{
		printf("\n");
		setFENXMM(t, -1, FALSO);
	}

	return c;
}

BOOLEANO quitarPiezaPos(int pos)
{
	BOOLEANO retorno = VERDADERO;
	TABLERO t;
	PIEZA pieza = ESCAQUES[pos]; 

	memcpy(t, ESCAQUES, sizeof(ESCAQUES));

	t[pos] = VACIO;
	setFENXMM(t, -1, FALSO);

	if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO) || esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO))
	{
		t[pos] = pieza;
		setFENXMM(t, -1, FALSO);
		retorno = FALSO;
	}
	
	return retorno;	
}


BOOLEANO quitarPiezaPosRandom(COLOR color, PIEZA pieza, int *posCol)
{
	uint64 mapDestinos;
	int escaqueDestino = 0;	
	int c = 0;
	int cc=0;
	int i=0;
	int index=0;
	int vDestinos[64];
	int vDestinos_t[64];
	BOOLEANO retorno = FALSO;
	TABLERO t, t2;

	switch(pieza)
	{
		case PEON_BLANCO:
			mapDestinos = juego.tablero[BLANCO][PEON];
			break;

		case TORRE_BLANCO:
			mapDestinos = juego.tablero[BLANCO][TORRE];
			break;

		case CABALLO_BLANCO:
			mapDestinos = juego.tablero[BLANCO][CABALLO];
			break;

		case ALFIL_BLANCO:
			mapDestinos = juego.tablero[BLANCO][ALFIL];
			break;

		case DAMA_BLANCO:
			mapDestinos = juego.tablero[BLANCO][DAMA];
			break;


		case PEON_NEGRO:
			mapDestinos = juego.tablero[NEGRO][PEON];
			break;

		case TORRE_NEGRO:
			mapDestinos = juego.tablero[NEGRO][TORRE];
			break;

		case CABALLO_NEGRO:
			mapDestinos = juego.tablero[NEGRO][CABALLO];
			break;

		case ALFIL_NEGRO:
			mapDestinos = juego.tablero[NEGRO][ALFIL];
			break;

		case DAMA_NEGRO:
			mapDestinos = juego.tablero[NEGRO][DAMA];
			break;


		default:
			mapDestinos = (color ? 
				(juego.negros ^ juego.tablero[NEGRO][REY]) : (juego.blancos ^ juego.tablero[BLANCO][REY]));
	}

	if (!mapDestinos) return FALSO;

	memcpy(t, ESCAQUES, sizeof(t));
	memcpy(t2, ESCAQUES, sizeof(t2));
	memset(vDestinos,SIN_POS_VALIDA,sizeof(vDestinos));

	while (mapDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(mapDestinos);
		vDestinos[c++] = escaqueDestino; 
		mapDestinos ^= BITSET[escaqueDestino];
	}

	while (c)
	{
		index = rand()%c;
		escaqueDestino = vDestinos[index];
		*posCol = escaqueDestino;
		t[escaqueDestino] = VACIO;
		setFENXMM(t, -1, FALSO);

		if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO) || esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO))
		{
			memset(vDestinos_t,SIN_POS_VALIDA,sizeof(vDestinos_t));
			setFENXMM(t2, -1, FALSO);
			t[escaqueDestino] = VACIO;
			cc=0;
			for (i=0;i<index;i++)
			{
				vDestinos_t[cc++] = vDestinos[i]; 		
			}

			for (i=index+1;i<c;i++)
			{
				vDestinos_t[cc++] = vDestinos[i]; 		
			}

			memset(vDestinos,SIN_POS_VALIDA,sizeof(vDestinos));
			for (i=0;i<cc;i++)
			{
				vDestinos[i] = vDestinos_t[i]; 	
			}
			c--;
			continue;
		}
		retorno = VERDADERO;
		break;
	}

	if (!retorno) setFENXMM(t2, -1, FALSO);
	
	return retorno;	
}

BOOLEANO agregarPiezaPosRandom(PIEZA p, int *posCol, __attribute__ ((unused)) BOOLEANO esValidarNoDefendidaPieza)
{

	BOOLEANO esValidarJaque = (juego.tablero[NEGRO][REY] || juego.tablero[BLANCO][REY]);
	uint64 mapDestinos;

	if ((p==ALFIL_BLANCO) && (cuentaBit(juego.tablero[BLANCO][ALFIL])==1))
	{
		if (juego.tablero[BLANCO][ALFIL] & ESCAQUES_BLANCOS)
		{
			mapDestinos = (~juego.ocupados & ESCAQUES_NEGROS);			

		} else {
			mapDestinos = (~juego.ocupados & ESCAQUES_BLANCOS);
		}

	} else if ((p==ALFIL_NEGRO) && (cuentaBit(juego.tablero[NEGRO][ALFIL])==1)) {

		if (juego.tablero[NEGRO][ALFIL] & ESCAQUES_BLANCOS)
		{
			mapDestinos = (~juego.ocupados & ESCAQUES_NEGROS);			

		} else {
			mapDestinos = (~juego.ocupados & ESCAQUES_BLANCOS);
		}

	} else {
		
		mapDestinos = ~juego.ocupados;
	}


	if ((posSalida != SIN_POS_VALIDA) && (mapDestinos & BITSET[posSalida]))
	{
		mapDestinos ^= BITSET[posSalida];
	}

	if (caminoLaberintoMapa && (OBT_COLOR_PIEZA(p)==NEGRO))
	{
		uint64 tmp_camino = caminoLaberintoMapa;
		int escaqueCamino;
		while (tmp_camino)
		{
			escaqueCamino = bitScanForwardBruijn(tmp_camino);
			tmp_camino ^= BITSET[escaqueCamino];

			if (mapDestinos & BITSET[escaqueCamino]) mapDestinos ^= BITSET[escaqueCamino];
		}
	}

	uint32 escaqueDestino = 0;	
	int c = 0;
	int cc=0;
	int i=0;
	uint32 ii=0;
	int index=0;
	int vDestinos[64];
	int vDestinos_t[64];
	COLOR colorActual = juego.colorTurno;
	BOOLEANO esJaque;
	BOOLEANO retorno = FALSO;
//	BOOLEANO esPiezaAtacadas = FALSO;
	int numMovValidos=99;
	int numMovRey1, numMovRey2;
	TABLERO t, t2;
	memcpy(t, ESCAQUES, sizeof(t));
	memcpy(t2, ESCAQUES, sizeof(t2));
	memset(vDestinos,SIN_POS_VALIDA,sizeof(vDestinos));

	if (!mapDestinos) return FALSO;

	numMovRey2 = numMovRey1 = contarMovLegalesPieza(REY_BLANCO);	
/*
	juego.colorTurno = OBT_COLOR_PIEZA(p);

	if (juego.colorTurno != colorActual)
	{
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	}

	if (esValidarNoDefendidaPieza && juego.Buffer_MOV_INDEXCAPAS[0] != juego.Buffer_MOV_INDEXCAPAS[1])
	{
		for (ii=juego.Buffer_MOV_INDEXCAPAS[0];ii<juego.Buffer_MOV_INDEXCAPAS[1];ii++)
		{
			if (ES_MOV_PEON(juego.Buffer_MOV[ii])) continue;
			if (mapDestinos & BITSET[OBT_MOV_DESTINO(juego.Buffer_MOV[ii])])
				mapDestinos ^= BITSET[OBT_MOV_DESTINO(juego.Buffer_MOV[ii])];
		}
	}
*/

	uint64 mapaTemporal=mapDestinos;



//*
//	printf("Antes\n");
//	imprimirBitTablero(mapDestinos);
	
	juego.colorTurno = OBT_COLOR_PIEZA(p) ? BLANCO : NEGRO;	
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	
	//Eliminar escaques amenazados por las blancas cuando se coloca una pieza negra
	for (ii=juego.Buffer_MOV_INDEXCAPAS[0];ii<juego.Buffer_MOV_INDEXCAPAS[1];ii++)
	{
		if (ES_MOV_PEON(juego.Buffer_MOV[ii])) continue;
		mapaTemporal |= BITSET[OBT_MOV_DESTINO(juego.Buffer_MOV[ii])];
		mapaTemporal ^= BITSET[OBT_MOV_DESTINO(juego.Buffer_MOV[ii])];
	}
	
	if (mapaTemporal) mapDestinos = mapaTemporal;
	
//	printf("Despues\n");
//	imprimirBitTablero(mapDestinos);
//*/
	juego.colorTurno = OBT_COLOR_PIEZA(p);
	if (juego.colorTurno != colorActual)
	{
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	}

	while (mapDestinos)
	{
		escaqueDestino = bitScanForwardBruijn(mapDestinos);
		vDestinos[c++] = escaqueDestino; 
		mapDestinos ^= BITSET[escaqueDestino];
	}

	while (c)
	{
		index = rand()%c;
		escaqueDestino = vDestinos[index];
		*posCol = escaqueDestino;
		t[escaqueDestino] = p;
		setFENXMM(t, -1, FALSO);
		
//BLOQUE PARA VALIDAR QUE LA PIEZA A INTRODUCIR TENGA MOVILIDAD
//***********************************************************	
//*		
		if ((p!=PEON_BLANCO) && (p!=PEON_NEGRO))
		{
//			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			numMovValidos = 0;

			if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
			{
			
			} else {

				for (ii=juego.Buffer_MOV_INDEXCAPAS[0];ii<juego.Buffer_MOV_INDEXCAPAS[1];ii++)
				{
					if (OBT_MOV_ORIGEN(juego.Buffer_MOV[ii]) == escaqueDestino && !ES_MOV_CAPTURA(juego.Buffer_MOV[ii]))
					{
						hacerMovimiento(juego.Buffer_MOV[ii]);

						esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO) ||
							  esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);

						desHacerMovimiento(juego.Buffer_MOV[ii]);
		
						if (!esJaque)
						{
							numMovValidos++;
						}
					}
				}
			}	
		} 
//*/
//***********************************************************		
/*
		if (esValidarNoDefendidaPieza)
		{
			esPiezaAtacadas = (obtMapaAtacadasPorPieza_Color(escaqueDestino, OBT_COLOR_PIEZA(p))) ?
							VERDADERO:FALSO; 
		}	
*/
		if ((p!=PEON_BLANCO) && (p!=PEON_NEGRO))
		{
			numMovRey2 = contarMovLegalesPieza(REY_BLANCO);	
		}
/*
		if ((p!=PEON_BLANCO) && (p!=PEON_NEGRO))
		{
			printf("numMovRey1=%d numMovRey2=%d\n",numMovRey1,numMovRey2);
			mostrarTablero();
			if (((numMovRey1<4) && (numMovRey1>numMovRey2)))
			{
				printf("entro\n");			
			}
		}
//*/
/*
		if (((numMovRey1<4) && (numMovRey1>numMovRey2))		||
		    (numMovValidos < 4) 				|| 
		    (esValidarNoDefendidaPieza && esPiezaAtacadas) 	||
		    (esValidarJaque && 
		       (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO)||esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO))))
*/

		if (((numMovRey1 < 5) && (numMovRey1>numMovRey2))	||
		    (numMovValidos < 5) 				|| 
		    (esValidarJaque && 
		       (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO)||esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO))))
		{
			memset(vDestinos_t,SIN_POS_VALIDA,sizeof(vDestinos_t));
			setFENXMM(t2, -1, FALSO);
			t[escaqueDestino] = VACIO;
			cc=0;
			for (i=0;i<index;i++)
			{
				vDestinos_t[cc++] = vDestinos[i]; 		
			}

			for (i=index+1;i<c;i++)
			{
				vDestinos_t[cc++] = vDestinos[i]; 		
			}

			memset(vDestinos,SIN_POS_VALIDA,sizeof(vDestinos));
			for (i=0;i<cc;i++)
			{
				vDestinos[i] = vDestinos_t[i]; 	
			}
			c--;
			continue;
		}
 
		retorno = VERDADERO;
		break;
	}

	juego.colorTurno = colorActual;

	if (retorno) 
		setFENXMM(t, -1, FALSO);
	else
		setFENXMM(t2, -1, FALSO);

	return retorno;
}

//*
uint64 getMapaMuros(uint64 mapaCamino)
{
	int vuelta = 0;
	int pos = 0;
	uint64 mapaBitMuros;
	uint64 mapaDestinos = ~mapaCamino;

	mapaBitMuros ^= mapaBitMuros;

	for (vuelta=0;vuelta<llenado_laberinto;vuelta++)
	{
		pos = rand()%64;
		if (mapaDestinos & BITSET[pos])
		{
			mapaBitMuros |= BITSET[pos];
			mapaDestinos ^= BITSET[pos];
		}
	}

	return mapaBitMuros;
}
//*/

uint64 getBitMapCaminoMapa(int *p1, int *p2)
{
	int n;
	int pos1;
	int pos2;
	int pos_candidata;
	int escaqueDestino;
	int lista_escaques_destino[8];
	int cc;
	uint64 tempDestinos;
	uint64 bitmap_camino_en_laberinto;
	BOOLEANO camino_en_laberinto[64];
	BOOLEANO buscarCamino;
	
	memset(camino_en_laberinto,FALSO,sizeof(camino_en_laberinto));

	n=rand()%4;
	pos1 = get_pos_lado[n][rand()%8];
	pos2 = get_pos_lado[get_lado_opuesto[n]][rand()%8];
	*p1 = pos1;
	*p2 = pos2;
	camino_en_laberinto[pos1] = VERDADERO;
	camino_en_laberinto[pos2] = VERDADERO;

	bitmap_camino_en_laberinto ^= bitmap_camino_en_laberinto;
	bitmap_camino_en_laberinto |= BITSET[pos1];
	bitmap_camino_en_laberinto |= BITSET[pos2];

	buscarCamino = VERDADERO;
	pos_candidata = SIN_POS_VALIDA;
	escaqueDestino = SIN_POS_VALIDA;

	while(buscarCamino)
	{
		tempDestinos = mascaraRey[pos1];
		memset(lista_escaques_destino,SIN_POS_VALIDA,sizeof(lista_escaques_destino));
		cc = 0;

		while (tempDestinos)
		{
			escaqueDestino = bitScanForwardBruijn(tempDestinos);
			if (escaqueDestino == pos2)
			{
				buscarCamino = FALSO; 
				break;
			}
				
			lista_escaques_destino[cc++]=escaqueDestino;
			tempDestinos ^= BITSET[escaqueDestino];
		}
		
		if (!buscarCamino) break;

		do {
			pos_candidata = lista_escaques_destino[rand()%cc];

		} while (camino_en_laberinto[pos_candidata] || 
			(DISTANCIA[pos1][pos2] < DISTANCIA[pos_candidata][pos2]));

		camino_en_laberinto[pos_candidata] = VERDADERO;
		bitmap_camino_en_laberinto |= BITSET[pos_candidata];
		pos1 = pos_candidata;
	}
	
	caminoLaberintoMapa = bitmap_camino_en_laberinto; 
	return bitmap_camino_en_laberinto;
}

void crearHacerMovPos(uint32 pos, int tipo)
{
	int cMov=0, cMovSinFiltro=0, index;
	uint32 i=0, pos1,pos2;
	BOOLEANO esJaque = FALSO;
	COLOR colorPieza; 
	PIEZA ppieza;

	MOVIMIENTO listaMov[256],listaMovSinFiltro[256];
	memset(listaMov,0,sizeof(listaMov));
	memset(listaMovSinFiltro,0,sizeof(listaMovSinFiltro));

	if (pos != SIN_POS_VALIDA)
	{
		if (!ES_RANGO_POS_VALIDA(pos))
		{
			printf("COD906\n");
			return;
		}

		if (ES_POS_VACIO(pos))
		{
			printf("COD908\n");
			return;
		}

		colorPieza = OBT_COLOR_PIEZA(ESCAQUES[pos]);

	} else {
		//Ver con cual color trabajar
		if (tipo==1)//Generar movimiento blanco
		{
			colorPieza = BLANCO;

		} else if (tipo==2) { //Negro

			colorPieza = NEGRO;

		} else { // Cualquiera de los dos

			colorPieza = (rand()%2) ? BLANCO : NEGRO;
		}
	}

	if (colorPieza)
	{
		juego.colorTurno = NEGRO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

	} else {

		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	}

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		printf("COD903\n");
		return;
	}

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{
		pos1   = OBT_MOV_ORIGEN(juego.Buffer_MOV[i]);
		pos2   = OBT_MOV_DESTINO(juego.Buffer_MOV[i]);
		ppieza = OBT_MOV_PIEZA(juego.Buffer_MOV[i]);

		if (ES_MOV_CAPTURA_REY(juego.Buffer_MOV[i])) continue;

		if (colorPieza)
		{
			if (juego.tablero[NEGRO][REY])
			{
				hacerMovimiento(juego.Buffer_MOV[i]);
				esJaque = esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);
				desHacerMovimiento(juego.Buffer_MOV[i]);
				if (esJaque) continue;
			}

		} else {

			if (juego.tablero[BLANCO][REY])
			{
				hacerMovimiento(juego.Buffer_MOV[i]);
				esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);
				desHacerMovimiento(juego.Buffer_MOV[i]);
				if (esJaque) continue;
			} 
		}

		if ((pos!=SIN_POS_VALIDA) && (pos1!=pos)) continue;

		if (!GMO_permitir_mov_peon && ((OBT_MOV_PIEZA(juego.Buffer_MOV[i])==PEON_BLANCO) || 
					       (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==PEON_NEGRO))) continue;

		if ((posSalida != SIN_POS_VALIDA) && (pos2==posSalida)) continue;

		if (GMO_prioridad_no_amenazados && (esAtacadoPorSRSP(BITSET[pos2], !colorPieza))) continue;

		if (GMO_solamenteMovCapturas && !ES_MOV_CAPTURA(juego.Buffer_MOV[i])) continue; 

		//Validacion solo para el minijuego 11
		if ((numMinijuegoActual==11) && mapaTableroMonedas && !(mapaTableroMonedas & BITSET[pos2])) continue; 

		if (GMO_prioridad_captura && ES_MOV_CAPTURA(juego.Buffer_MOV[i])) 
		{
			listaMov[cMov++] = juego.Buffer_MOV[i];
			continue;

		} else if (!GMO_prioridad_captura){

			if (!GMO_puede_capturar && ES_MOV_CAPTURA(juego.Buffer_MOV[i])) continue;

			if (GMO_modoPatrullaje && !(ppieza==CABALLO_BLANCO || ppieza==CABALLO_NEGRO) &&
				 !(mascaraRey[pos1] & BITSET[pos2])) continue;

			if (!GMO_puede_capturar_peon && ES_MOV_CAPTURA(juego.Buffer_MOV[i]) && 
					(ESCAQUES[pos2]==PEON_BLANCO || ESCAQUES[pos2]==PEON_NEGRO)) continue;		
		
			if (!GMO_permitir_mov_peon_y_promocion && ES_MOV_PROMOCION(juego.Buffer_MOV[i])) continue;

			if (GMO_soloMismaFILE && (ppieza==TORRE_BLANCO || ppieza==TORRE_NEGRO) && 
					!(FILEBIT[FILES[pos1]] & BITSET[pos2])) continue;

			if (GMO_soloMismaRANK && (ppieza==TORRE_BLANCO || ppieza==TORRE_NEGRO) && 
				!(RANKBIT[RANKS[pos1]] & BITSET[pos2])) continue;

			listaMov[cMov++] = juego.Buffer_MOV[i];
			continue;
		}
	}

	if (!cMov)
	{

		for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
		{
			pos1   = OBT_MOV_ORIGEN(juego.Buffer_MOV[i]);
			pos2   = OBT_MOV_DESTINO(juego.Buffer_MOV[i]);
			ppieza = OBT_MOV_PIEZA(juego.Buffer_MOV[i]);

			if (ES_MOV_CAPTURA_REY(juego.Buffer_MOV[i])) continue;

			if (colorPieza)
			{
				if (juego.tablero[NEGRO][REY])
				{
					hacerMovimiento(juego.Buffer_MOV[i]);
					esJaque = esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);
					desHacerMovimiento(juego.Buffer_MOV[i]);
					if (esJaque) continue;
				}

			} else {

				if (juego.tablero[BLANCO][REY])
				{
					hacerMovimiento(juego.Buffer_MOV[i]);
					esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);
					desHacerMovimiento(juego.Buffer_MOV[i]);
					if (esJaque) continue;
				} 
			}

			if ((pos!=SIN_POS_VALIDA) && (pos1!=pos)) continue;

			if ((posSalida != SIN_POS_VALIDA) && (pos2==posSalida)) continue;

			if (GMO_solamenteMovCapturas && !ES_MOV_CAPTURA(juego.Buffer_MOV[i])) continue; 

			if (!GMO_permitir_mov_peon && ((OBT_MOV_PIEZA(juego.Buffer_MOV[i])==PEON_BLANCO) || 
						       (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==PEON_NEGRO))) continue;

			if (!GMO_permitir_mov_peon_y_promocion && ES_MOV_PROMOCION(juego.Buffer_MOV[i])) continue;

			if (!GMO_puede_capturar && ES_MOV_CAPTURA(juego.Buffer_MOV[i])) continue;

			if (!GMO_puede_capturar_peon && ES_MOV_CAPTURA(juego.Buffer_MOV[i]) && 
					(ESCAQUES[pos2]==PEON_BLANCO || ESCAQUES[pos2]==PEON_NEGRO)) continue;	


			//Con Pocos Filtros			
			listaMovSinFiltro[cMovSinFiltro++] = juego.Buffer_MOV[i];

			if ((numMinijuegoActual==11) && mapaTableroMonedas && !(mapaTableroMonedas & BITSET[pos2])) continue; 

			if (GMO_modoPatrullaje && !(ppieza==CABALLO_BLANCO || ppieza==CABALLO_NEGRO) &&
				 !(mascaraRey[pos1] & BITSET[pos2])) continue;

			if (GMO_soloMismaFILE && (ppieza==TORRE_BLANCO || ppieza==TORRE_NEGRO) && 
					!(FILEBIT[FILES[pos1]] & BITSET[pos2])) continue;

			if (GMO_soloMismaRANK && (ppieza==TORRE_BLANCO || ppieza==TORRE_NEGRO) && 
				!(RANKBIT[RANKS[pos1]] & BITSET[pos2])) continue;

			if (GMO_prioridad_no_amenazados && (esAtacadoPorSRSP(BITSET[pos2], !colorPieza))) continue;

			listaMov[cMov++] = juego.Buffer_MOV[i];
			continue;
		}
	}

	if (cMov)
	{
		index = rand()%cMov; 
		hacerMovimiento(listaMov[index]);
		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		printf("%d %d",(int)OBT_MOV_ORIGEN(listaMov[index]),(int)OBT_MOV_DESTINO(listaMov[index]));
		if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
		{
			printf("+");
		}
		printf("\n");
		return;

	} else if (cMovSinFiltro) {

		index = rand()%cMovSinFiltro; 
		hacerMovimiento(listaMovSinFiltro[index]);
		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		printf("%d %d",(int)OBT_MOV_ORIGEN(listaMovSinFiltro[index]),(int)OBT_MOV_DESTINO(listaMovSinFiltro[index]));
		if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
		{
			printf("+");
		}
		printf("\n");
		return;

	}

	juego.colorTurno = BLANCO;
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	printf("COD928\n");
}

int llenarPosMovilidad(int movv[], uint32 pos, int tipoMovimiento)
{
	uint32 i=0;
	uint32 cMov=0;
	MOVIMIENTO listaMov[28];
	COLOR cp; 
	BOOLEANO esJaque;


	memset(movv,SIN_POS_VALIDA, sizeof(int)*28);

	cp = OBT_COLOR_PIEZA(ESCAQUES[pos]);

	if (!ES_RANGO_POS_VALIDA(pos))
	{
		return 0;
	}

	if (ES_POS_VACIO(pos))
	{
		return 0;
	}

	if (cp) // NEGRO
	{
		juego.colorTurno = NEGRO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	}

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		if (cp)
		{
			juego.colorTurno = BLANCO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		}
		return 0;
	}

	memset(listaMov,0,sizeof(listaMov));
	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{

		if (tipoMovimiento==1) //Movilidad
		{
			if (OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos && !ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
			{
				hacerMovimiento(juego.Buffer_MOV[i]);
				if (cp)
					esJaque = esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);
				else
					esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);

				desHacerMovimiento(juego.Buffer_MOV[i]);
				if (!esJaque) listaMov[cMov++] = juego.Buffer_MOV[i];
			}

		} else if (tipoMovimiento==2) { // Capturas

			if (OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos && ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
			{
				hacerMovimiento(juego.Buffer_MOV[i]);
				if (cp)
					esJaque = esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);
				else
					esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);

				desHacerMovimiento(juego.Buffer_MOV[i]);
				if (!esJaque) listaMov[cMov++] = juego.Buffer_MOV[i];
			}

		} else { //Todos

			if (OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos)
			{
				hacerMovimiento(juego.Buffer_MOV[i]);
				if (cp)
					esJaque = esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);
				else
					esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);

				desHacerMovimiento(juego.Buffer_MOV[i]);
				if (!esJaque) listaMov[cMov++] = juego.Buffer_MOV[i];
			}
		}
	}

	if (cMov)
	{
		for (i=0;i<cMov;i++)
		{
			movv[i] = (int)OBT_MOV_DESTINO(listaMov[i]);
		}

		if (cp)
		{
			juego.colorTurno = BLANCO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		}
		return cMov;
	}

	if (cp)
	{
		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	}
	return 0;
}


void agregarMuros(int posw, PIEZA p)
{
	BOOLEANO todo_ok = VERDADERO;
	TABLERO t;
	memcpy(t, ESCAQUES, sizeof(ESCAQUES));
	t[posw] = p;
	setFENXMM(t, -1, FALSO);

	if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO) || 
		esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO))
	{
		t[posw] = VACIO;
		setFENXMM(t, -1, FALSO);
		todo_ok = FALSO;
	}

	if (todo_ok)
		printf("OK\n");
	else
		printf("COD921\n");
}

uint64 getBitMapCaminoMapaAlfil(int *p1, int *p2)
{

	COLOR colorEscaqueAlfil; 

	int n;
	int pos1;
	int pos2;
	int pos_candidata;
	int escaqueDestino;
	int lista_escaques_destino[8];
	int cc;
	uint64 tempDestinos;
	uint64 bitmap_camino_en_laberinto;
	BOOLEANO camino_en_laberinto[64];
	BOOLEANO buscarCamino;
	
	memset(camino_en_laberinto,FALSO,sizeof(camino_en_laberinto));

	n=rand()%4;
	pos1 = get_pos_lado[n][rand()%8];

	colorEscaqueAlfil = ((BITSET[pos1] & ESCAQUES_BLANCOS) ? BLANCO : NEGRO);

	do {
		pos2 = get_pos_lado[get_lado_opuesto[n]][rand()%8];

	} while ( ((BITSET[pos2] & ESCAQUES_BLANCOS) ? BLANCO : NEGRO) != colorEscaqueAlfil);

	*p1 = pos1;
	*p2 = pos2;
	camino_en_laberinto[pos1] = VERDADERO;
	camino_en_laberinto[pos2] = VERDADERO;

	bitmap_camino_en_laberinto ^= bitmap_camino_en_laberinto;
	bitmap_camino_en_laberinto |= BITSET[pos1];
	bitmap_camino_en_laberinto |= BITSET[pos2];

	buscarCamino = VERDADERO;
	pos_candidata = SIN_POS_VALIDA;
	escaqueDestino = SIN_POS_VALIDA;

	while(buscarCamino)
	{
		tempDestinos = mascaraRey[pos1];
	
		if (colorEscaqueAlfil) //Alfil camina por Negro, se elimina escaques blancos
		{
			tempDestinos |= ESCAQUES_BLANCOS;
			tempDestinos ^= ESCAQUES_BLANCOS;
		
		} else {//Blanco

			tempDestinos |= ESCAQUES_NEGROS;
			tempDestinos ^= ESCAQUES_NEGROS;

		}

		memset(lista_escaques_destino,SIN_POS_VALIDA,sizeof(lista_escaques_destino));
		cc = 0;

		while (tempDestinos)
		{
			escaqueDestino = bitScanForwardBruijn(tempDestinos);
			if (escaqueDestino == pos2)
			{
				buscarCamino = FALSO; 
				break;
			}
				
			lista_escaques_destino[cc++]=escaqueDestino;
			tempDestinos ^= BITSET[escaqueDestino];
		}
		
		if (!buscarCamino) break;

		do {
			pos_candidata = lista_escaques_destino[rand()%cc];

		} while (camino_en_laberinto[pos_candidata] || 
			(DISTANCIA[pos1][pos2] < DISTANCIA[pos_candidata][pos2]));

		camino_en_laberinto[pos_candidata] = VERDADERO;
		bitmap_camino_en_laberinto |= BITSET[pos_candidata];
		pos1 = pos_candidata;
	}
	
	caminoLaberintoMapa = bitmap_camino_en_laberinto; 
	return bitmap_camino_en_laberinto;
}

void crearHacerMovCuidarSalida(BOOLEANO esPuedeCapturar)
{
	uint32 cMov=0, cMovSinFiltro=0;
	uint32 i=0, pos2;
	BOOLEANO esJaque = FALSO;

	MOVIMIENTO listaMov[256],listaMovSinFiltro[256];
	memset(listaMov,0,sizeof(listaMov));
	memset(listaMovSinFiltro,0,sizeof(listaMovSinFiltro));

	if (posSalida == SIN_POS_VALIDA) return;

	juego.colorTurno = NEGRO;
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{
//		pos1   = OBT_MOV_ORIGEN(juego.Buffer_MOV[i]);
		pos2   = OBT_MOV_DESTINO(juego.Buffer_MOV[i]);
//		ppieza = OBT_MOV_PIEZA(juego.Buffer_MOV[i]);

		if (ES_MOV_CAPTURA_REY(juego.Buffer_MOV[i])) continue;
		if (ES_MOV_PEON(juego.Buffer_MOV[i])) continue;
		if (pos2==posSalida) continue;
		if (!esPuedeCapturar && ES_MOV_CAPTURA(juego.Buffer_MOV[i])) continue;

		if (juego.tablero[BLANCO][REY])
		{
			hacerMovimiento(juego.Buffer_MOV[i]);
			esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);
			desHacerMovimiento(juego.Buffer_MOV[i]);
			if (esJaque) continue;
		} 

		listaMovSinFiltro[cMovSinFiltro++] = juego.Buffer_MOV[i];

		if (GMO_prioridad_no_amenazados && (esAtacadoPorSRSP(BITSET[pos2], BLANCO))) continue;

		listaMov[cMov++] = juego.Buffer_MOV[i];
	}

	uint32 distancia2puerta=99; 
	MOVIMIENTO movMasCerca=0;
	if (cMov)
	{
		for (i=0;i<cMov;i++)
		{
			pos2 = OBT_MOV_DESTINO(listaMov[i]);
			if (distancia2puerta > DISTANCIA[pos2][posSalida])
			{
				distancia2puerta = DISTANCIA[pos2][posSalida];
				movMasCerca = listaMov[i];
			}
		}

		if (movMasCerca)
			hacerMovimiento(movMasCerca);

		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		printf("%d %d",(int)OBT_MOV_ORIGEN(movMasCerca),(int)OBT_MOV_DESTINO(movMasCerca));
		if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
		{
			printf("+");
		}
		printf("\n");
		return;

	} else if (cMovSinFiltro) {

		for (i=0;i<cMovSinFiltro;i++)
		{
			pos2 = OBT_MOV_DESTINO(listaMovSinFiltro[i]);
			if (distancia2puerta > DISTANCIA[pos2][posSalida])
			{
				distancia2puerta = DISTANCIA[pos2][posSalida];
				movMasCerca = listaMovSinFiltro[i];
			}
		}
		if (movMasCerca)
			hacerMovimiento(movMasCerca);

		juego.colorTurno = BLANCO;
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		printf("%d %d",(int)OBT_MOV_ORIGEN(movMasCerca),(int)OBT_MOV_DESTINO(movMasCerca));
		if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
		{
			printf("+");
		}
		printf("\n");
		return;

	}

	juego.colorTurno = BLANCO;
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	printf("COD930\n");
}

void crearHacerMovMinijuego21()
{
	uint32 cMov=0, cMov2=0, i=0;
	MOVIMIENTO listaMov[256],listaMov2[256];
	MOVIMIENTO m=0;

	memset(listaMov,0,sizeof(listaMov));
	memset(listaMov2,0,sizeof(listaMov2));

	juego.colorTurno = NEGRO;
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{
		if (ES_MOV_PROMOCION(juego.Buffer_MOV[i])) continue;

		if (ES_MOV_PEON_DOBLE(juego.Buffer_MOV[i]))
		{
			listaMov[cMov++] = juego.Buffer_MOV[i];
		}

		listaMov2[cMov2++] = juego.Buffer_MOV[i];
	}

	if (cMov)
	{
		m = listaMov[rand()%cMov];

	} else if (cMov2) {

		m = listaMov2[rand()%cMov2];
	} 


	if (m)
	{
		hacerMovimiento(m);
		printf("%d %d\n",(int)OBT_MOV_ORIGEN(m),(int)OBT_MOV_DESTINO(m));

	} else {

		printf("COD930\n");
	}

	juego.colorTurno = BLANCO;
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
}


#endif
