/* 
	Mango Paola Ajedrez 5.0
	Licencia: GPLv3   
    	Copyright (c) 2012-2016 - Mango Computer c.a 

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

#ifndef COMANDOS_C
#define COMANDOS_C

void leerComandos()
{
	int c=0;
	setbuf(stdout, NULL);

	printf("Blancas> ");

	while ( (c=getc(stdin)) != EOF  )
	{
		if (c=='\n')
		{
			BUFF_COMANDOS[CONT_BUFF_COMANDOS] = '\0';

			while (CONT_BUFF_COMANDOS)
			{
				if (!ejecutarComando(BUFF_COMANDOS)) return;
			}

			if (juego.colorTurno)
			{		
				printf("Negras> ");
			} else {
				printf("Blancas> ");
			}
			fflush(stdout);

		} else {
			if (CONT_BUFF_COMANDOS>=LARGO_BUFER_COMANDOS)
			{
				printf("Comando muy largo\n");
				CONT_BUFF_COMANDOS = 0;
			}
			
			BUFF_COMANDOS[CONT_BUFF_COMANDOS++] = c;
		}

	}

}

BOOLEANO ejecutarComando(const char *buff)
{
	BOOLEANO esJaque;
	uint64 tiempo_ms  = 0;  
	MOVIMIENTO m;
	int profundidadSugerida;

	if (!strcmp(buff, ""))
	{
		CONT_BUFF_COMANDOS = '\0';
		return VERDADERO;    
	}

	if ((!strcmp(buff, "help")) || (!strcmp(buff, "h")) || (!strcmp(buff, "?")) || (!strcmp(buff, "ayuda")))
	{

		printf("\n******* Ayuda *******\n");
		printf("ata n				: Devuelve un mapa de bit de todos los atacantes en el escaque dado\n");
		printf("blanco				: Blanco mueve\n");
		printf("cc					: Jugar computadora vs computadora\n");
//		printf("configuracion		: Configura el tablero\n");
		printf("dale				: Juega la computadora\n");
		printf("d					: Mostrar Tablero\n");
		printf("eval				: Muestra evaluacion estatica de esta posición\n");
		printf("g					: Gira el tablero\n");
		printf("i					: Muestra el valor de las variables\n");
		printf("info				: Muestra el valor de las variables\n");
		printf("juego				: Muestra los movimientos del juego\n");
		printf("leerfen nombreArchivo n	: Lee el numero de lineaa de un archivo FEN\n");
		printf("librono				: Des-habilita el uso de diccionario o libro de aperturas\n");
		printf("librosi				: Habilita el uso de diccionario o libro de aperturas\n");
		printf("movimientos			: Muestra todos los movimientos legales\n");
		printf("negro				: Negro mueve\n");
		printf("nuevo				: Inicia un nuevo juego\n");
		printf("regresar			: Devuelve el ultimo movimiento\n");
		printf("r					: Gira el tablero\n");
		printf("sd n				: Establece la profundidad de busquedad en n*2\n");
		printf("t					: Mostrar Tablero\n");
		printf("u					: Devuelve el ultimo movimiento\n");
		printf("ver blancos			: Muestra el bitmap de los blancos\n");
		printf("ver destinos blancos	: Muestra el bitmap de los destinos blancos\n");
		printf("ver destinos negros		: Muestra el bitmap de los destinos negros\n");
		printf("ver					: Muestra la versión y autor del motor de ajedrez\n");
		printf("ver negros			: Muestra el bitmap de los negros\n");
		printf("ver ocupados		: Muestra el bitmap de ocupados\n");
		printf("ver peones blancos	: Muestra el bitmap de los peones blancos\n");
		printf("ver peons negros	: Muestra el bitmap de los peones negros\n");
		printf("ver todos mov		: Muestra todos los movimientos generados sin validar\n");
		printf("xboard				: Inicia el Modo Xboard\n");
		printf("XMM					: Inicia el Modo XMM\n");


		printf("\n******* Help *******\n");
		printf("ata n			: Devuelve un mapa de bit de todos los atacantes en el escaque dado\n");
		printf("black			: Negro mueve\n");
		printf("cc				: Jugar computadora vs computadora\n");
		printf("d				: Mostrar Tablero\n");
		printf("eval			: Muestra evaluacion estatica de esta posición\n");
		printf("exit			: Salir del Juego\n");
		printf("game			: Muestra los movimientos del juego\n");
		printf("g				: Gira el tablero\n");
		printf("go				: Juega la computadora\n");
		printf("i				: Muestra el valor de las variables\n");
		printf("info			: Muestra el valor de las variables\n");
		printf("move e2e4		: Introduce un movimiento (use este formato)\n");
		printf("moves			: Muestra todos los movimientos legales\n");
		printf("new				: Inicia un nuevo juego\n");
		printf("perft n			: Calcula el numero de nodos en bruto, con profundida n\n");
		printf("perft			: punto de referencia un número de funciones clave\n");
		printf("quit			: Salir del programa\n");
		printf("readfen nombreArchivo n	: Lee el numero de lineaa de un archivo FEN\n");
		printf("r				: Gira el tablero\n");
		printf("sd n			: Establece la profundidad de busquedad en n*2\n");
		printf("setup			: Configura el tablero\n");
		printf("t				: Mostrar Tablero\n");
		printf("u				: Devuelve el ultimo movimiento\n");
		printf("undo			: Devuelve el ultimo movimiento\n");
		printf("white			: Blanco mueve\n");
		printf("xboard			: Inicia el Modo Xboard\n");
		printf("XMM				: Inicia el Modo XMM\n");


		CONT_BUFF_COMANDOS = '\0';
		return VERDADERO;    
       }

	if (buff[0] == 'p' && buff[1] == 'e' && buff[2] == 'r' && buff[3] == 'f' && buff[4] == 't' && isdigit(buff[6]))  
	{
		uint64 resulPerft = 0;
		tiempo_ms  = 0;  
		uint8  profundidad = buff[6] - 48;
		printf("Inciado la prueba a una profundidad de %d\n", profundidad);
		printf("...\n");

		DataPerft.InvCaptura		= 0;
		DataPerft.InvPeonPaso		= 0;
		DataPerft.InvPromocion		= 0;	
		DataPerft.InvEnroqueOO		= 0;
		DataPerft.InvEnroqueOOO		= 0;
		DataPerft.InvJaqueContrario	= 0;

		prepararTiempo();
		iniciarTiempo();
		resulPerft = perft(0,profundidad);
		detenerTiempo();
		tiempo_ms  = obt_msTiempo();
		printf("Nodos %lld, en %lld ms\n",resulPerft,tiempo_ms);

		printf("\n");
		printf("Capturas	: %u\n",DataPerft.InvCaptura);
		printf("Peon al Paso	: %u\n",DataPerft.InvPeonPaso);
		printf("Promocion	: %u\n",DataPerft.InvPromocion);
		printf("OO		: %u\n",DataPerft.InvEnroqueOO);
		printf("OOO		: %u\n",DataPerft.InvEnroqueOOO);
		printf("Total Enroque	: %u\n",(DataPerft.InvEnroqueOOO+DataPerft.InvEnroqueOO));
		printf("Jaque enemigo	: %u\n",DataPerft.InvJaqueContrario);
		printf("\n");

		if (tiempo_ms > 0)
		{
			printf("Relacion: %lld knods/s \n", resulPerft/tiempo_ms);
		}
		CONT_BUFF_COMANDOS = '\0';
		return VERDADERO;    
	}




	if (buff[0] == 'm' && buff[1] == 'o' && buff[2] == 'v' && buff[3] == 'e' && buff[4] == ' ')  
	{
		CONT_BUFF_COMANDOS = '\0';
		MOVIMIENTO mov;
		mov ^= mov;
		if (esValidoMovUsuario(buff, &mov))
		{
			hacerMovimiento(mov);

			if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
			{
				esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
			} else {
				esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
			}
			
			if (!esJaque)
			{
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				mostrarTablero();
			} else {
				printf("Movimiento Ilegal: !!! Rey queda en jaque !!!\n");
				desHacerMovimiento(mov);
			}
		} else {
			printf("Movimiento Ilegal: Escaque origen/destino invalido\n");
		}

		return VERDADERO;    
	}

	if ((!strncmp(buff, "sd", 2)))
	{
		CONT_BUFF_COMANDOS = '\0';
		sscanf(buff,"sd %d", &profundidadSugerida);
		if (profundidadSugerida < 2) profundidadSugerida = 2;
		juego.profundidadBusquedad = profundidadSugerida;
		nivelPC = PC_NIVEL_PERSONALIZADO;
		return VERDADERO;    
	}

	if (buff[0] == 'l' && buff[1] == 'e' && buff[2] == 'e' && buff[3] == 'r' && buff[4] == 'f' && buff[5] == 'e' && buff[6] == 'n')
	{
		CONT_BUFF_COMANDOS = '\0';
		char nombreArchivo[80];
		int numero=0;
		sscanf(buff,"leerfen %s %d", nombreArchivo, &numero);
		readFen(nombreArchivo, numero);
		mostrarTablero();
		return VERDADERO;    
	}


	if (buff[0] == 'r' && buff[1] == 'e' && buff[2] == 'a' && buff[3] == 'd' && buff[4] == 'f' && buff[5] == 'e' && buff[6] == 'n')
	{
		CONT_BUFF_COMANDOS = '\0';
		char nombreArchivo[80];
		int numero=0;
		sscanf(buff,"readfen %s %d", nombreArchivo, &numero);
		readFen(nombreArchivo, numero);
		mostrarTablero();
		return VERDADERO;    
	}

	if ((!strcmp(buff, "undo")) || (!strcmp(buff, "regresar")) || (!strcmp(buff, "u")))
	{
		CONT_BUFF_COMANDOS = '\0';
		if (juego.indiceHJuego > 0)
		{
			desHacerMovimiento(juego.historicoJuego[juego.indiceHJuego-1].mov);
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			mostrarTablero();
		}
		return VERDADERO;    
	}
//*
	if ((!strcmp(buff, "eval")))
	{
		CONT_BUFF_COMANDOS = '\0';
		int resulEval =  evaluacionTablero(-INFINITO,INFINITO);
//		resulEval =+ ((rand()%(VALOR_DAMA*3)) * ((rand()%2)?-1:1));
		printf("Evaluación Estatica del Tablero Actual\nEval:	%d\n",resulEval);
		return VERDADERO;    
	}
//*/
#ifdef COMPILAR_CON_EGBB
	if ((!strcmp(buff, "nalimov")))
	{
		CONT_BUFF_COMANDOS = '\0';
		if (usar_egbb && egbb_is_loaded)
		{
			int totalPiezas = 
			cuentaBit(juego.tablero[BLANCO][PEON]) + cuentaBit(juego.tablero[NEGRO][PEON]) +
			cuentaBit(juego.tablero[BLANCO][DAMA]) + cuentaBit(juego.tablero[NEGRO][DAMA]) + 
			cuentaBit(juego.tablero[BLANCO][CABALLO]) + cuentaBit(juego.tablero[NEGRO][CABALLO]) + 
			cuentaBit(juego.tablero[BLANCO][TORRE]) + cuentaBit(juego.tablero[NEGRO][TORRE])   + 
			cuentaBit(juego.tablero[BLANCO][ALFIL])   + cuentaBit(juego.tablero[NEGRO][ALFIL]) + 2;

			if (totalPiezas <= nLimitePiezasBitBases)
			{
				int V_egbb=0;
				if (probe_bitbases(&V_egbb)) 
				{
					printf("V_egbb: %d\n",V_egbb);
				}
			}
		}

		return VERDADERO;    
	}
#endif
	if ((!strcmp(buff, "facil")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.maxTiempo 		= 3000;
		juego.profundidadBusquedad	= 98;
		nivelPC = PC_NIVEL_FACIL;
		return VERDADERO;    
	}

	if ((!strcmp(buff, "medio")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.maxTiempo 		= 7000;
		juego.profundidadBusquedad	= 98;
		nivelPC = PC_NIVEL_MEDIO;
		return VERDADERO;    
	}

	if ((!strcmp(buff, "fuerte")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.maxTiempo 		= 12000;
		juego.profundidadBusquedad	= 98;
		nivelPC = PC_NIVEL_FUERTE;
		return VERDADERO;    
	}

	if ((!strcmp(buff, "fen")))
	{
		CONT_BUFF_COMANDOS = '\0';
		char fen[100];
		memset(fen,'\0', 100);
		converTabler2FEN(fen);
		printf("FEN: %s\n",fen);
		return VERDADERO;    
	}


	if ((!strncmp(buff, "time", 4)))
	{
		CONT_BUFF_COMANDOS = '\0';
		int tiempoUser = juego.maxTiempo/1000;
		sscanf(buff,"time %d", &tiempoUser);
		if (tiempoUser < 1) tiempoUser = 1;
		juego.maxTiempo = tiempoUser * 1000;
		printf("juego.maxTiempo = %d\n",juego.maxTiempo);
		nivelPC = PC_NIVEL_PERSONALIZADO;
		return VERDADERO;    
	}

	if ((!strcmp(buff, "new")) || (!strcmp(buff, "nuevo")))
	{
		CONT_BUFF_COMANDOS = '\0';
		nuevo_juego();
		printf("Motor Re-Inicializado\n");
		return VERDADERO;    
	}

	if ((!strcmp(buff, "white")) || (!strcmp(buff, "blanco")))
	{
		CONT_BUFF_COMANDOS = '\0';
		if (juego.colorTurno)
		{
			juego.colorTurno   = BLANCO;
			juego.llaveHash   ^= arrayHash.lado;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		}
		return VERDADERO;    
	}

	if ((!strcmp(buff, "black")) || (!strcmp(buff, "negro")))
	{
		CONT_BUFF_COMANDOS = '\0';
		if (!juego.colorTurno)
		{
			juego.colorTurno   = NEGRO;
			juego.llaveHash   ^= arrayHash.lado;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		}
		return VERDADERO;    
	}


	if ((!strcmp(buff, "info")) || (!strcmp(buff, "i")))
	{
		CONT_BUFF_COMANDOS = '\0';
		informacionVariables();
		return VERDADERO;    
	}

	if ((!strcmp(buff, "r")) || (!strcmp(buff, "g")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.vista = !juego.vista;
		mostrarTablero();
		return VERDADERO;    
	}



	if ((!strcmp(buff, "d")) || (!strcmp(buff, "t")))
	{
		CONT_BUFF_COMANDOS = '\0';
		mostrarTablero();
		return VERDADERO;    
	}

	if ((!strcmp(buff, "game")) || (!strcmp(buff, "juego")))
	{
		CONT_BUFF_COMANDOS = '\0';
		verMovimentosJuego();
		return VERDADERO;    
	}


	if ((!strcmp(buff, "moves")) || (!strcmp(buff, "movimientos")))
	{
		CONT_BUFF_COMANDOS = '\0';
		verMovimentosLegales();
		return VERDADERO;    
	}

	if ((!strcmp(buff, "genmov")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		verMovimentosLegales();
		return VERDADERO;    
	}

	if ((!strcmp(buff, "genmovcap")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.Buffer_MOV_INDEXCAPAS[1] = generarMovCapPro(0);
		verMovimentosLegales();
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "eetpos")))
	{
		CONT_BUFF_COMANDOS = '\0';
		int ponderacion=0,i=0;
		for(i=0;i<64;i++)
		{
			
			printf("eetpos pos=%d valor=%d\n",i, EETPOS(i, juego.colorTurno));
			ponderacion += EETPOS(i,  juego.colorTurno);
		}
		printf("ponderacion=%d\n",ponderacion);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "genmovcapt")))
	{
		CONT_BUFF_COMANDOS = '\0';
		juego.Buffer_MOV_INDEXCAPAS[1] = generarMovCapPro(0);
		verMovimentosLegales();
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		return VERDADERO;    
	}

//*
	if ((!strncmp(buff, "test",4)))
	{
		CONT_BUFF_COMANDOS = '\0';
		char nombreArchivo[100];
		printf("Por favor espere mientras el test se realiza...\n");
		FILE *fp = freopen("test.txt", "w",stdout);
		sscanf(buff,"test %s", nombreArchivo);

		printf("MODO TEST en %s\n",nombreArchivo);

		int i=1;
		while(readFen(nombreArchivo, i))
		{
			printf("Iteracion # %d\n",i);
			pensarRapido();
			i++;
		}	

		fclose(fp);
//		stdout = fdopen(2, "w");
		return VERDADERO;    
	}
//*/
	if (buff[0] == 'e' && buff[1] == 'e' && buff[2] == 't')  
	{
		CONT_BUFF_COMANDOS = '\0';
		int escaque=0;
		int ccolor=0;
		sscanf(buff,"eet %d %d", &escaque, &ccolor);
		if (escaque >= 0 && escaque < 64 )
		{
			printf("Escaque=%d EET=%d\n",escaque, EETPOS(escaque, ccolor));
		} else {
			printf("Escaque=%d fuera de rango (0-63) \n",escaque);
		}
		return VERDADERO;    
	}


	if (((!strcmp(buff, "go")) || (!strcmp(buff, "dale"))) && STATUS_FIN_JUEGO_NO_TERMINADO)
	{

		CONT_BUFF_COMANDOS = '\0';
		printf("Pensando... profundidad: %d\n", juego.profundidadBusquedad);
		esConsola = VERDADERO;
		m = pensarRapido();
		esConsola = FALSO;
		if (!m)
		{
			printf("\nNo se encontró ningun movimiento valido\n");
			return VERDADERO;    
		} 

		hacerMovimiento(m);
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		imprimirMovimiento(m);	
		mostrarTablero();
		statusFinJuego = obtEstadoJuego();
		mostrarMensajeFinalJuego();printf("\n");

		return VERDADERO;    
	}

	if (!strcmp(buff, "."))
	{

		CONT_BUFF_COMANDOS = '\0';
		printf("Pensando sin qbusquedad... profundidad: %d\n", juego.profundidadBusquedad);
		esVariable = VERDADERO;	
		m = pensarRapido();
		esVariable = FALSO;	

		if (!m)
		{
			printf("\nNo se encontró ningun movimiento valido\n");
			return VERDADERO;    
		} 

		hacerMovimiento(m);
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
		imprimirMovimiento(m);	
		mostrarTablero();

		return VERDADERO;    
	}

	if ((!strcmp(buff, "xboard")))
	{
		CONT_BUFF_COMANDOS = '\0';
		xboard();
		return VERDADERO;    
	}

	if ((!strcmp(buff, "XMM")))
	{
		CONT_BUFF_COMANDOS = '\0';
		xmm();
		return VERDADERO;    
	}


	if ((!strcmp(buff, "exit")) || (!strcmp(buff, "quit")) || (!strcmp(buff, "salir")))
	{
		CONT_BUFF_COMANDOS = '\0';
		CLOSE_BOOK();
#ifdef COMPILAR_CON_EGBB
		cerrarBitbases();
#endif
		return FALSO;    
	}

	if ((!strcmp(buff, "librosi")))
	{
		CONT_BUFF_COMANDOS = '\0';
		usarLibroAperturas = VERDADERO;
		return VERDADERO;    
	}

	if ((!strcmp(buff, "librono")))
	{
		CONT_BUFF_COMANDOS = '\0';
		usarLibroAperturas = FALSO;
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver")))
	{
		CONT_BUFF_COMANDOS = '\0';
		printf("%s\n",VERSION_MANGO_AJEDREZ);
		return VERDADERO;    
	}
	

	if ((!strcmp(buff, "cc")) && STATUS_FIN_JUEGO_NO_TERMINADO)
	{
		CONT_BUFF_COMANDOS = '\0';
		statusFinJuego = obtEstadoJuego();

		while (STATUS_FIN_JUEGO_NO_TERMINADO && (juego.indiceHJuego < MAX_BUFF_MOV))
		{
			tiempo_ms  = 0;  
			prepararTiempo();
			iniciarTiempo();
			m = pensarRapido();
			detenerTiempo();
			tiempo_ms  = obt_msTiempo();
			printf("Tiempo de Proceso: %lld ms ",tiempo_ms);
			if (!m)
			{
				printf("\nNo se encontró ningun movimiento valido\n");
				break;
			} 
			hacerMovimiento(m);
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			imprimirMovimiento(m);	
			mostrarTablero();
			statusFinJuego = obtEstadoJuego();
		}

		mostrarMensajeFinalJuego();printf("\n");
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver ocupados")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero(juego.ocupados);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver blancos")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero(juego.blancos);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver negros")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero(juego.negros);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver peones blancos")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero(juego.tablero[BLANCO][PEON]);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver peones negros")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero(juego.tablero[NEGRO][PEON]);
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver destinos blancos")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero((~juego.ocupados | juego.negros));
		return VERDADERO;    
	}

	if ((!strcmp(buff, "ver destinos negros")))
	{
		CONT_BUFF_COMANDOS = '\0';
		imprimirBitTablero((~juego.ocupados | juego.blancos));
		return VERDADERO;    
	}


	printf("Comando desconocido, Escriba \'ayuda\' para mayor información\n");
	CONT_BUFF_COMANDOS = '\0';
	return VERDADERO;    
}

void mostrarMensajeFinalJuego()
{
	if (statusFinJuego == STATUS_FIN_JUEGO_MATE_GANAN_B){

		printf(" [result 1-0 {White mates}]");

	} else if (statusFinJuego == STATUS_FIN_JUEGO_MATE_GANAN_N){

		printf(" [result 0-1 {Black mates}]");

	} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS_REPETICION) {

		printf(" [result 1/2-1/2 {Draw by threefold repetition}]");

	} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS_INSUFI_MATERIAL) {

		printf(" [result 1/2-1/2 {Draw by insufficient material}]");

	} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS) {

		printf(" [result 1/2-1/2 {Draw by Stalemate}]");

	} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS_REGLA_50MOV) {

		printf(" [result 1/2-1/2 {Draw by fifty-move rule}]");

	} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS_ACORDADAS) {

		printf(" [result 1/2-1/2 {Draw by agreed}]");
	}

}


void mostrarTablero()
{
	int rank, file;
	printf("\n");

	if (!juego.vista)
        {
		for (rank = 8; rank >= 1; rank--)
                {
			printf("    +---+---+---+---+---+---+---+---+\n");
			printf("  %d |",rank);
                        for (file = 1; file <= 8; file++)
                        {
				printf(" %s|",NOMBREPIEZA[ESCAQUES[FILERANK2POS[file][rank]]]);
                        }
			printf("\n"); 	  
		}
		printf("    +---+---+---+---+---+---+---+---+\n");
		printf("      a   b   c   d   e   f   g   h\n");
	} else {
		printf("      h   g   f   e   d   c   b   a\n");
		for (rank = 1; rank <= 8; rank++)
		{
			printf("    +---+---+---+---+---+---+---+---+\n");
			printf("    |");
                        for (file = 8; file >= 1; file--)
                        {
				printf(" %s|",NOMBREPIEZA[ESCAQUES[FILERANK2POS[file][rank]]]);
                        }
			printf(" %d \n",rank);
                 }
		printf("    +---+---+---+---+---+---+---+---+\n");
	}

	return;

}

void verMovimentosLegales()
{
	uint32 i=0;
	BOOLEANO esJaque;	

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		printf("No hay movimientos validos\n");
		return;
	}

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{

		hacerMovimiento(juego.Buffer_MOV[i]);

		if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
		{
			esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
		} else {
			esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
		}

		desHacerMovimiento(juego.Buffer_MOV[i]);
		
		if (!esJaque)
		{
			verMov(juego.Buffer_MOV[i]);
		}
	}
}

MOVIMIENTO getMovimentoRandom()
{
	uint32 i=0;
	BOOLEANO esJaque;
	int c=0, cc=0;	
	MOVIMIENTO *arrayMov;

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		return 0;
	}

	//Contar el numero de movimientos
	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{

		hacerMovimiento(juego.Buffer_MOV[i]);

		if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
		{
			esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
		} else {
			esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
		}

		desHacerMovimiento(juego.Buffer_MOV[i]);
		
		if (!esJaque)
		{
			c++; //verMov(juego.Buffer_MOV[i]);
		}
	}

	arrayMov = malloc(sizeof(MOVIMIENTO)*(c+1));

	//crear vector de movimientos
	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{

		hacerMovimiento(juego.Buffer_MOV[i]);

		if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
		{
			esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
		} else {
			esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
		}

		desHacerMovimiento(juego.Buffer_MOV[i]);
		
		if (!esJaque)
		{
			arrayMov[cc++] = juego.Buffer_MOV[i];
		}
	}

	MOVIMIENTO mAleatorio = arrayMov[rand()%c];
	free(arrayMov);

	return mAleatorio;
}


void verMovimentosTodos()
{
	uint32 i=0;

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		printf("No hay movimientos validos\n");
		return;
	}

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{
		verMov(juego.Buffer_MOV[i]);
	}
}


void verMovimentosJuego()
{
	uint32 i=0;

	for (;i< juego.indiceHJuego;i++)
	{
		printf("%c ", ((i % 2) ? 'N':'B'));
		printf("%s ", juego.historicoJuego[i].movAlg);
		printf("ori=%d des=%d pieza=%d cap=%d\n",OBT_MOV_ORIGEN(juego.historicoJuego[i].mov),
							OBT_MOV_DESTINO(juego.historicoJuego[i].mov),
							OBT_MOV_PIEZA(juego.historicoJuego[i].mov),
							OBT_MOV_CAPTURA(juego.historicoJuego[i].mov));
	}
}

void informacionVariables()
{
	printf("*** Información Variables del Juego ***\n\n");
	printf("Profundidad de Busquedad	(profundidadBusquedad)	: %d\n", juego.profundidadBusquedad);
	printf("Tiempo x Movimiento		(juego.maxTiempo)	: %d ms\n", juego.maxTiempo);
	printf("Libro de Aperturas (SI/NO)	(usarLibroAperturas)	: %s\n", usarLibroAperturas?"Si":"No");
	printf("Nivel PC			(nivelPC)		: %s\n", NOMBRENIVELPC[nivelPC]);
	printf("Balance material		(material_total)	: %d\n", juego.material_total);
	printf("Material blanco			(material_lado_blanco)	: %d\n", juego.material_lado_blanco);
	printf("Material peones blanco		(material_peon_blanco)	: %d\n", juego.material_peon_blanco);
	printf("Material negro			(material_lado_negro)	: %d\n", juego.material_lado_negro);
	printf("Material peones negro		(material_peon_negro)	: %d\n", juego.material_peon_negro);
	printf("Color bando jugar 		(colorTurno)		: %s\n",(juego.colorTurno?"Negro":"Blanco"));
	printf("# Movimientos \"Regla 50 mov\"	(reglaCincuentaMov)	: %d\n",juego.reglaCincuentaMov);
	printf("# Total Movimientos 		(totalMov)		: %d\n",juego.totalMov);
	printf("Es posible OO  blanco		(OOB)			: %s\n",(juego.OOB?"Si":"No"));
	printf("Es posible OOO blanco		(OOOB)			: %s\n",(juego.OOOB?"Si":"No"));
	printf("Es posible OO  negro		(OON)			: %s\n",(juego.OON?"Si":"No"));
	printf("Es posible OOO negro		(OOON)			: %s\n",(juego.OOON?"Si":"No"));
	printf("Hubo Enroque blanco		(ENROQUEB)		: %s\n",(juego.ENROQUEB?"Si":"No"));
	printf("Hubo Enroque negro		(ENROQUEN)		: %s\n",(juego.ENROQUEN?"Si":"No"));
	printf("Indice del Juego		(juego.indiceHJuego)	: %d\n",juego.indiceHJuego);
	if (juego.posPeonPaso==SIN_POS_VALIDA)
	{
		printf("Escaque \"Peon al Paso\"		(posPeonPaso)		: Sin una posición valida\n");
	} else {
		printf("Escaque \"Peon al Paso\"		(posPeonPaso)		: %d\n",juego.posPeonPaso);
	}
	printf("Utiliti 			(numEstatico)		: %d\n",numEstatico);
	printf("maxHistorial Blanco		(maxHistorial[BLANCO])	: %d\n",maxHistorial[BLANCO]);
	printf("maxHistorial Negro		(maxHistorial[NEGRO])	: %d\n",maxHistorial[NEGRO]);

}


void verMov(MOVIMIENTO mov)
{
	printf("origen=%d\t destino=%d\t  pieza=%d\t  captura=%d\t  promocion=%d\n", 
		OBT_MOV_ORIGEN(mov),  OBT_MOV_DESTINO(mov),   OBT_MOV_PIEZA(mov),
		OBT_MOV_CAPTURA(mov), OBT_MOV_PROMOCION(mov));
}

void verMov2(MOVIMIENTO mov)
{
	printf("%d-%d\n",OBT_MOV_ORIGEN(mov),OBT_MOV_DESTINO(mov));
 
}

void nuevo_juego()
{
		jugadaRandom = 0;
		inicializarTablero();
		inicializarVar();
		iniTablerosUtil();
		actualizarTablerosUtil(BLANCO);
		iniHashTablero();
		juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
}
//*

void xboard()
{
//	int quedan=0;
	int entrada = 0;                                
	char minutos[4];	                        
	int incremento;	                                
	__attribute__ ((unused)) int inc = 0;
	__attribute__ ((unused)) int mps = 0;
	BOOLEANO esPermitirPonder = FALSO;
//	int estado_seetree=1;
//	int seeprompt = 0;
	int setTipoTorneo = 1;
	
	computadora = NEGRO;
	char linea[256], buffComandos[256];
	MOVIMIENTO m;
	__attribute__ ((unused)) MOVIMIENTO ponder_mov=0;
	BOOLEANO esJaque;	
	esPost = VERDADERO;
	BOOLEANO esPonder=FALSO;
	char cadenaMov[20];
	BOOLEANO esJaquePrint;
	printf("\n");

	nuevo_juego();
	computadora = NEGRO;

	for (;;) 
	{
//printf("DEBUG: juego.colorTurno=%d computadora=%d statusFinJuego=%d\n",juego.colorTurno,  computadora,statusFinJuego);
		if (juego.colorTurno == computadora) 
		{
			tipoDeBusqueda = TIPO_BUSQUEDA_NORMAL;

			if (jugadaRandom)
			{
				if ((rand()%9) <= jugadaRandom) 
					m = getMovimentoRandom(jugadaRandom);
				else
					m = pensarRapido();

			} else {

				m = pensarRapido();
			}

			if (!m)
			{
				computadora = SIN_COLOR;
				continue;
			} 
			if (esMostrarAlgMov) mov2alg(m,cadenaMov);
			hacerMovimiento(m);
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

			statusFinJuego = obtEstadoJuego();

			printf("move "); imprimirMovimiento(m);
			esJaquePrint = xboardVerJaque && ES_ESTADO_JUEGO_JAQUE; 
			if (esJaquePrint) printf("+");
			mostrarMensajeFinalJuego();

			if (esMostrarAlgMov)
			{
				if (esJaquePrint && STATUS_FIN_JUEGO_TERMINADO)	
					printf(" [%s++] ",cadenaMov);
				else if (esJaquePrint && STATUS_FIN_JUEGO_NO_TERMINADO)
					printf(" [%s+] ",cadenaMov);
				else
					printf(" [%s] ",cadenaMov);
			} 

//			if (STATUS_FIN_JUEGO_NO_TERMINADO) printf("\n");
			printf("\n");
			esPermitirPonder = VERDADERO;
			continue;

		} else if (computadora != SIN_COLOR) {

			if (esPonder && esPermitirPonder)
			{
				if (esMovimentoLegal(juego.triangularArray[0][1]))
				{
					tipoDeBusqueda = TIPO_BUSQUEDA_PONDER;
					mponder = juego.triangularArray[0][1];
					hacerMovimiento(mponder);
					ponder_mov = pensarRapido();
					desHacerMovimiento(mponder);
					juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				}

				esPermitirPonder = FALSO;
				continue;
			}
		}

		if (xboardVerPrompt)
			printf("xboard> ");

		if (!fgets(linea, 256, stdin))
			return;
		if (linea[0] == '\n')
			continue;

		sscanf(linea, "%s", buffComandos);

		if (!strcmp(buffComandos, "help"))
		{
printf("\t%s\t%s\n","moves [nn]                ", ": Devuelve los movimientos legales y validos en la pos (no es parte del xboard).");
printf("\t%s\t%s\n","book          [0|1]       ", ": Activa/Desactiva libro de aperturas    [1=on][0=off] (no es parte del xboard).");
printf("\t%s\t%s\n","seeAlgMov     [0|1]       ", ": Muestra o no en formato algebraico     [1=on][0=off] (no es parte del xboard).");
printf("\t%s\t%s\n","seetree       [0|1]       ", ": Muestra o no el árbol de pensamiento   [1=on][0=off] (no es parte del xboard).");
printf("\t%s\t%s\n","seecheck      [0|1]       ", ": Muestra o no un + sí el mov es jaque   [1=on][0=off] (no es parte del xboard).");
printf("\t%s\t%s\n","seeprompt     [0|1]       ", ": Muestra o no un prompt                 [1=on][0=off] (no es parte del xboard).");
printf("\t%s\t%s\n","setTipoTorneo [0|1]          ", ": Activa/Desactiva Comportamiento Torneo [1=on][0=off] (no es parte del xboard).");
printf("\t%s\t%s\n\n","help                     ", ": Muestra la presente ayuda                            (no es parte del xboard).");

printf("\t%s\n","Los movimientos realizados por el usuario se introducen en el formato origen-destino o origen-destino-piezaPromover.\n\tNota: Las piezas a promover deberán ser la inicial en ingles (q,r,b,n).");
printf("\t%s\n\n","Ejemplos: [d2d4] o [a7a8q].");

printf("\t%s\t%s\n","black                    ", ": Pasa el turno a las negras.");
printf("\t%s\t%s\n","easy                     ", ": El motor no puede pensar en el tiempo del rival.");
printf("\t%s\t%s\n","force                    ", ": La computadora deja de crear jugadas (usuario vs usuario).");
printf("\t%s\t%s\n","go                       ", ": La computadora genera un movimiento y lo ejecuta para el turno actual.");
printf("\t%s\t%s\n","hard                     ", ": El motor puede pensar en el tiempo del rival.");
printf("\t%s\t%s\n","hint                     ", ": Sugiere un movimiento para el color actual [6 segundos para pensarlo].");
printf("\t%s\t%s\n","?                        ", ": La computadora deja de crear jugadas (usuario vs usuario).");
printf("\t%s\t%s\n","new                      ", ": Reinicia el motor.");
printf("\t%s\t%s\n","nopost                   ", ": El motor no puede pensar en el tiempo del rival.");
printf("\t%s\t%s\n","ping [número]            ", ": Envía un número al motor y se espera que el devuelva un pong con el mismo número.");
printf("\t%s\t%s\n","post                     ", ": El motor puede pensar en el tiempo del rival.");
printf("\t%s\t%s\n","protover                 ", ": Muestra los comandos básicos implementados.");
printf("\t%s\t%s\n","quit                     ", ": Cerrar el protocolo xboard.");
printf("\t%s\t%s\n","random [1-9]             ", ": Genera un posible movimiento tonto, según la probabilidad en numero 1=10% hasta 9=90%, en el caso de no caer la probabilidad se genera un movimiento según la fuerza actual.");
printf("\t%s\t%s\n","remove                   ", ": Deshace los dos últimos movimiento realizados.");
printf("\t%s\t%s\n","result                   ", ": La computadora deja de crear jugadas (usuario vs usuario).");
printf("\t%s\t%s\n","sd [profundidad-búsqueda]", ": Específica número de capas en el árbol a pensar por Mango Paola en cada movimiento, valores entre [1-99].");
printf("\t%s\t%s\n","setboard [cadena-fen]    ", ": Configura el tablero según la cadena fen.");
printf("\t%s\t%s\n","st [segundos]            ", ": Específica número de segundos a pensar por Mango Paola en cada movimiento.");
printf("\t%s\t%s\n","time                     ", ": Tiempo en segundos que le quedan a Mango Paola (juegos por tiempo).");
printf("\t%s\t%s\n","undo                     ", ": Deshace el último movimiento realizado.");
printf("\t%s\t%s\n","white                    ", ": Pasa el turno a las blancas.");

			continue;
		}

		if ((!strcmp(buffComandos, "fen")))
		{
			char fen[100];
			memset(fen,'\0', 100);
			converTabler2FEN(fen);
			printf("%s\n",fen);
			continue;
		}


		if (!strcmp(buffComandos, "xboard"))
		{
			continue;
		}

		if (!strcmp(buffComandos, "moves"))
		{
			uint32 posMoves = 0;
			int numMoves = 0;
			sscanf(linea, "moves %d", &posMoves);
			if (ES_RANGO_POS_VALIDA(posMoves) && !ES_POS_VACIO(posMoves) && 
				(OBT_COLOR_PIEZA(ESCAQUES[posMoves])==juego.colorTurno))
			{
				uint32 i=0;
				BOOLEANO esJaque;	

				if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
				{
					printf("No Moves\n");
					continue;
				}

				for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
				{
					if (OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==posMoves)
					{
						hacerMovimiento(juego.Buffer_MOV[i]);
						if (juego.colorTurno) 
						{
							esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);

						} else {

							esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
						}

						desHacerMovimiento(juego.Buffer_MOV[i]);
		
						if (!esJaque)
						{
							numMoves++;
							imprimirMovimiento(juego.Buffer_MOV[i]);
							printf(" Destino=%d, Captura=%d, Promocion=%d\n", 
							OBT_MOV_DESTINO(juego.Buffer_MOV[i]), 
							OBT_MOV_CAPTURA(juego.Buffer_MOV[i]), 
							OBT_MOV_PROMOCION(juego.Buffer_MOV[i]));
						}
					}
				}
			}
			
			if (!numMoves)
			{
				printf("No Moves\n");
			}

			continue;
		}

		if (!strcmp(buffComandos, "book"))
		{
			int usarBook=0;
			sscanf(linea, "book %d", &usarBook);
			usarLibroAperturas = (usarBook>0);
			printf("book=[%s]\n",usarLibroAperturas?"on":"off");
			continue;
		}

		if (!strcmp(buffComandos, "seeAlgMov"))
		{
			int ver;
			sscanf(linea, "seeAlgMov %d", &ver);
			esMostrarAlgMov = (ver>0)?VERDADERO:FALSO;
			printf("seeAlgMov=[%s]\n",esMostrarAlgMov?"on":"off");
			continue;
		}

		if (!strcmp(buffComandos, "seecheck"))
		{
			int verJaque = 0;
			sscanf(linea, "seecheck %d", &verJaque);
			xboardVerJaque = (verJaque>0)?VERDADERO:FALSO;
			printf("seecheck=[%s]\n",xboardVerJaque?"on":"off");
			continue;
		}

		if (!strcmp(buffComandos, "eval"))
		{
			int resultEval = evaluacionTablero(-INFINITO,INFINITO);

			printf("%d\n",resultEval);
			continue;
		}

		if (!strcmp(buffComandos, "analizar"))
		{

			if (juego.colorTurno==BLANCO)
			{
				int resul=FALSO;
				ES_INSUFICIENTE_MATERIAL_LADO_NEGRO(resul);
				if (resul)
				{
					printf("analizar: %d\n",VALOR_JAQUE_MATE);
					continue;
				}				

			} else if (juego.colorTurno==NEGRO) {

				int resul=FALSO;
				ES_INSUFICIENTE_MATERIAL_LADO_BLANCO(resul);
				if (resul)
				{
					printf("analizar: %d\n",VALOR_JAQUE_MATE);
					continue;
				}
			}				

			//La compu tiene material suficiente para dar mate, explorar como vamos
			m = pensarRapido();
			if (m)
			{
				printf("analizar: %d\n", valoracion_export);
	
			} else {

				printf("analizar: 0\n");
			}			

			continue;
		}


		if (!strcmp(buffComandos, "t"))
		{
			mostrarTablero();
			continue;
		}


		if (!strcmp(buffComandos, "seetree"))
		{
			int ver;
			sscanf(linea, "seetree %d", &ver);
			xboardVerDetalles = (ver>0)?VERDADERO:FALSO;
			printf("seetree=[%s]\n",xboardVerDetalles?"on":"off");
			continue;
		}

		if (!strcmp(buffComandos, "seeprompt"))
		{
			int ver;
			sscanf(linea, "seeprompt %d", &ver);
			xboardVerPrompt = (ver>0)?VERDADERO:FALSO;
			continue;
		}

		if (!strcmp(buffComandos, "setTipoTorneo"))
		{
			sscanf(linea, "setTipoTorneo %d", &setTipoTorneo);
			esTorneoMensajesFinal = (setTipoTorneo>0)?VERDADERO:FALSO;
			printf("setTipoTorneo=[%s]\n",esTorneoMensajesFinal?"on":"off");
			continue;
		}

		if (!strcmp(buffComandos, "new"))
		{
			nuevo_juego();
			computadora = NEGRO;
			continue;
		}
		if (!strcmp(buffComandos, "quit"))
		{
			return;
		}
		if (!strcmp(buffComandos, "white"))
		{
			juego.colorTurno = BLANCO;
			computadora = NEGRO;
			continue;
		}
		if (!strcmp(buffComandos, "black"))
		{
			juego.colorTurno = NEGRO;
			computadora = BLANCO;
			continue;
		}
		if (!strcmp(buffComandos, "st"))
		{
			sscanf(linea, "st %d", &juego.maxTiempo);
			juego.maxTiempo *= 1000;
			juego.profundidadBusquedad = MAX_CAPAS;
			continue;
		}
		if (!strcmp(buffComandos, "sd"))
		{
			int profun=0;
			sscanf(linea, "sd %d", &profun);

			if (profun < 1)
			{
				juego.profundidadBusquedad = 1;

			} else if (profun > MAX_CAPAS) {

				juego.profundidadBusquedad = MAX_CAPAS;

			} else {

				juego.profundidadBusquedad = profun;
			}
			juego.maxTiempo = 1 << 25;
			continue;
		}

		if (!strcmp(buffComandos, "level"))
		{
			sscanf(linea, "level %d %s %d", &entrada, minutos, &incremento);
			mps = entrada;	    
			inc = incremento * 1000;
			continue;
		}

		if (!strcmp(buffComandos, "time"))
		{
			sscanf(linea, "time %d", &juego.maxTiempo);

			juego.maxTiempo *= 10;
			juego.maxTiempo /= 25;
			juego.maxTiempo -= 110;
/*
			if (mps == 0 && inc > 0)
			{
				if (juego.maxTiempo < 3 * inc)
				{
					juego.maxTiempo = 75*inc/100;

				} else {
					juego.maxTiempo = (juego.maxTiempo/30 + inc)*4;
				}
				continue;
			}

			if (computadora == BLANCO)
				quedan = (mps-juego.totalMov/2)-1;
			else
				quedan = (mps-juego.totalMov/2);
			if (mps == 0) {
				quedan = 30;
			}
			else {
				while (quedan <= 0)
					quedan += mps;
			}
			juego.maxTiempo = (juego.maxTiempo/quedan)*(5/4);
//*/
			continue;
		}

		if (!strcmp(buffComandos, "otim"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "go") || !strcmp(buffComandos, "j"))
		{
			computadora = juego.colorTurno;
			continue;
		}
		if (!strcmp(buffComandos, "protover"))
		{
			printf("feature setboard=1 analyze=0 ping=1 colors=0 draw=0 sigint=0 sigterm=0"
				   " variants=\"normal\" myname=\"%s\"\n",NOMBRE_MANGO_PAOLA);
			printf("feature done=1\n");
			continue;
		}

		if (!strcmp(buffComandos, "accepted"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "rejected"))
		{
			printf("feature rejected\n");
			continue;
		}
		if (!strcmp(buffComandos, "setboard"))
		{

			char fen[100];
			char fencolor[2];     
			char fenEnroque[5];
			char fenPeonPaso[3];
			int fenReglaCincuentaMov=0;
			int fenTotalMov=0;
			int verDetalles=0;
			computadora = SIN_COLOR;
			statusFinJuego = STATUS_FIN_JUEGO_SIN_ESTATUS;

			sscanf(linea, "setboard %s %s %s %s %d %d %d",
				   fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov, &verDetalles);
//*
			if (verDetalles)
			{
				if (fencolor[0] == 'w')
				{
					printf("# blanco es siguiente movimiento\n");
				} else {
					printf("# negro es siguiente movimiento\n");
				}

				printf("# Enroque: %s\n", fenEnroque);
				printf("# Peon al Paso Escaque: %s\n", fenPeonPaso);
				printf("# Regla 50 mov: %d\n", fenReglaCincuentaMov);
				printf("# Total mov: %d\n", fenTotalMov);
			}
//*/
			setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);
			continue;
		}


		if (!strcmp(buffComandos, "hint"))
		{
//			int pro_b = 0;
//			uint32 max_t = 0;
//			max_t = juego.maxTiempo;
//			pro_b = juego.profundidadBusquedad;		

//			juego.maxTiempo = 6000;
//			juego.profundidadBusquedad = MAX_CAPAS;;		

			m = pensarRapido();

//			juego.maxTiempo 	   = max_t;
//			juego.profundidadBusquedad = pro_b;		

			if (!m) continue; 
			printf("Hint: ");

			if (esMostrarAlgMov) mov2alg(m,cadenaMov);
			imprimirMovimiento(m);
			esJaquePrint = xboardVerJaque && ES_ESTADO_JUEGO_JAQUE; 
			if (esJaquePrint) printf("+");
			if (esMostrarAlgMov)
			{
				if (esJaquePrint)	
					printf(" [%s+]",cadenaMov);
				else
					printf(" [%s]",cadenaMov);
			} 
			printf("\n");
			continue;
		}
		if (!strcmp(buffComandos, "undo"))
		{
			if (juego.indiceHJuego > 0)
			{
				desHacerMovimiento(juego.historicoJuego[juego.indiceHJuego-1].mov);
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				computadora = !juego.colorTurno;
				statusFinJuego = STATUS_FIN_JUEGO_SIN_ESTATUS;
			}
			continue;
		}
		if (!strcmp(buffComandos, "remove"))
		{
			if (juego.indiceHJuego > 1)
			{
				desHacerMovimiento(juego.historicoJuego[juego.indiceHJuego-1].mov);
				desHacerMovimiento(juego.historicoJuego[juego.indiceHJuego-1].mov);
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				computadora = !juego.colorTurno;
				statusFinJuego = STATUS_FIN_JUEGO_SIN_ESTATUS;
			}
			continue;
		}
		if (!strcmp(buffComandos, "force"))
		{
			computadora = SIN_COLOR;
			continue;
		}
		if (!strcmp(buffComandos, "result"))
		{
			computadora = SIN_COLOR;
			continue;
		}
		if (!strcmp(buffComandos, "?"))
		{
			computadora = SIN_COLOR;
			continue;
		}
		if (!strcmp(buffComandos, "post"))
		{
			esPost = VERDADERO;
			continue;
		}
		if (!strcmp(buffComandos, "nopost"))
		{
			esPost = FALSO;
			continue;
		}

		if (!strcmp(buffComandos, "ping"))
		{
			int n=0;
			sscanf(linea, "ping %d", &n);
			printf("pong %d\n",n);
			continue;
		}

		if (!strcmp(buffComandos, "random"))
		{
			int n=0;
			sscanf(linea, "random %d", &n);
			if (n<0) n=0;
			if (n>9) n=9;
			jugadaRandom = n;
			printf("random %d\n",jugadaRandom);
			continue;

		}
		if (!strcmp(buffComandos, "computer"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "easy")) 
		{
			esPonder=FALSO;
			continue;
		}
		if (!strcmp(buffComandos, "hard"))
		{
			esPonder=VERDADERO;
			continue;
		}
		if (!strcmp(buffComandos, "name"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "bk"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "edit"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "rating"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "ics"))
		{
			continue;
		}
		if (!strcmp(buffComandos, "."))
		{
			continue;
		}

		if (!esUnMovimiento(buffComandos))
		{
			printf("Error (unknown command): %s\n", buffComandos);
			continue;
		}

		m = parse_mov(linea);
		if (!m)
			printf("Illegal move: %s\n", buffComandos);
		else {

			if (esMostrarAlgMov) mov2alg(m,cadenaMov);

			hacerMovimiento(m);

			if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
			{
				esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
			} else {
				esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
			}
			
			if (!esJaque)
			{
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				statusFinJuego = obtEstadoJuego();
				mostrarMensajeFinalJuego();

				if (esMostrarAlgMov)
				{
					esJaquePrint = xboardVerJaque && ES_ESTADO_JUEGO_JAQUE;

					if (esJaquePrint && STATUS_FIN_JUEGO_TERMINADO)	
						printf("[%s++] ",cadenaMov);
					else if (esJaquePrint && STATUS_FIN_JUEGO_NO_TERMINADO)
						printf("[%s+] ",cadenaMov);
					else
						printf("[%s] ",cadenaMov);
				} 

			} else {
				printf("Illegal move (in check): %s\n", buffComandos);
				desHacerMovimiento(m);
			}
		}
	}
//*/
}


BOOLEANO esUnMovimiento(const char *l)
{
	if (l[0] > 96 && l[0] < 105)
	{
		if (l[1] > 48 && l[1] < 57)
		{
			if (l[2] > 96 && l[2] < 105)
			{
				if (l[3] > 48 && l[3] < 57)
				{
					return VERDADERO;
				}			
			}
		}	
	}

	return FALSO;
}

MOVIMIENTO parse_mov(char *s)
{
	uint8 origen, destino;
	uint32 i = 0;
	PIEZA pCoronada = VACIO;

	origen  = s[0]   - 97;
	origen += ((s[1] - 49) * 8);

	destino  = s[2]   - 97;
	destino += ((s[3] - 49) * 8);

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{
		if ( ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])) == origen) &&  ((OBT_MOV_DESTINO(juego.Buffer_MOV[i]))==destino))
		{
			if (ES_MOV_PROMOCION(juego.Buffer_MOV[i]))
			{
				switch (s[4]) 
				{
					case 'n':
					case 'N':
						pCoronada = OBT_MOV_PROMOCION(juego.Buffer_MOV[i]);
						if (pCoronada == CABALLO_BLANCO || pCoronada == CABALLO_NEGRO)
							return juego.Buffer_MOV[i];
						break;
					case 'b':
					case 'B':
						pCoronada = OBT_MOV_PROMOCION(juego.Buffer_MOV[i]);
						if (pCoronada == ALFIL_BLANCO || pCoronada == ALFIL_NEGRO)
							return juego.Buffer_MOV[i];
						break;
					case 'r':
					case 'R':
						pCoronada = OBT_MOV_PROMOCION(juego.Buffer_MOV[i]);
						if (pCoronada == TORRE_BLANCO || pCoronada == TORRE_NEGRO)
							return juego.Buffer_MOV[i];
						break;
					default:  
						return juego.Buffer_MOV[i];
				}

			} else {

				return juego.Buffer_MOV[i];
			}
		}
	}

	return 0; //-1;
}

BOOLEANO esMovimentoLegal(MOVIMIENTO m)
{
	uint32 i=0;
	BOOLEANO esJaque;	

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		return FALSO;
	}

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{

		if (juego.Buffer_MOV[i]== m)
		{
			hacerMovimiento(juego.Buffer_MOV[i]);

			if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
			{
				esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
			} else {
				esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
			}

			desHacerMovimiento(juego.Buffer_MOV[i]);
		
			if (!esJaque)
			{
				return VERDADERO;
			}
		}
	}

	return FALSO;
}

BOOLEANO esMovimentoLegalXMM(MOVIMIENTO m)
{
	uint32 i=0;
	BOOLEANO esJaque;	

	if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
	{
		return FALSO;
	}

	for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
	{

		if (juego.Buffer_MOV[i]== m)
		{
			hacerMovimiento(juego.Buffer_MOV[i]);

			if (juego.colorTurno) // Le toca al negro, se chequea que el rey blanco no haya quedado en jaque
			{
				esJaque = esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO);
			} else {
				esJaque = esAtacadoPorSRSP(juego.tablero[NEGRO][REY], BLANCO);
			}

			desHacerMovimiento(juego.Buffer_MOV[i]);
		
			if (!esJaque)
			{
				return VERDADERO;
			}
		}
	}

	return FALSO;
}

void xmm()
{
	char linea[256], buffComandos[256];
	numMinijuegoActual = -1;
	caminoLaberintoMapa ^= caminoLaberintoMapa;	
	printf("%sOK 1.0\n",NPROM);

	time_t now;
	srand((unsigned int)time(&now));

	nuevo_juego();
	computadora = NEGRO;

	for (;;) 
	{
		printf("%s",NPROM);

		if (!fgets(linea, 256, stdin))
			return;
		if (linea[0] == '\n')
			continue;

		sscanf(linea, "%s", buffComandos);

		if (!strcmp(buffComandos, "AYUDA") || !strcmp(buffComandos, "ayuda") || !strcmp(buffComandos, "?") || 
			!strcmp(buffComandos, "HELP") || !strcmp(buffComandos, "help"))
		{

			mostrarListaAyudaGeneral();
			continue;
		}

		if (!strcmp(buffComandos, "COD"))
		{
			mostrarTablaCodigos();
			continue;
		}

		if (!strcmp(buffComandos, "MAN"))
		{
			char comando[256];
			memset(comando,'\n',sizeof(comando));

			sscanf(linea, "MAN %s", comando);

			if (!strcmp(comando, "MJN"))
			{
				mostrarAyuda("MJN - mini juego Nuevo.","MJN [nn][nn]",
					"Inicia el mini juego número (nn) con posiciones aleatorias. Los valores devueltos dependerán del mini juego iniciado.",
					"[nn] [nn]",
					"\n\t\t nn Número del mini juego.\n\t\t nn Opcionalmente se puede proporcionar la densidad de muros, rango esperado [1-120], valor por defecto 32.");
				continue;
			}

			if (!strcmp(comando, "CUP"))
			{
				mostrarAyuda("CUP - Custodiar Puerta de Salida.","CUP [n]",
					"Genera un movimiento a las negras para bloquear la salida del laberinto, pudiendo ser captura o no.",
					"[n]",
					"\n\t n puede ser los valores 1=ON ó 0=OFF\n\t [ON] puede capturar, [OFF] no puede capturar.");
				continue;
			}

			if (!strcmp(comando, "BLA"))
			{
				mostrarAyuda("BLA - Cambia a Blanco el Turno.","BLA",
					"Cambia el color del turno actual a color Blanco.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "COD"))
			{
				mostrarAyuda("COD - Tabla de Códigos.","COD",
					"Muestra la tabla de todos los códigos del protocolo XMM.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "CFN"))
			{
				mostrarAyuda("CFN - Cambiar Tablero Según Cadena Fen.","CFN [cadena-fen]",
					"Cambia el fen interno del motor a el fen establecido en cadena-fen sin cambiar el número del mini juego.",
					"[cadena-fen]",
					"cadena-fen. Ej. PP4PP/2P2PP1/1P2P3/PPb5/P7/6PP/2P1r3/PPP2P1K w");
				continue;
			}

			if (!strcmp(comando, "ATE"))
			{
				mostrarAyuda("ATE - Agrega Tesoros al Tablero.","ATE [cantidad]",
					"Agrega tesoros al tablero según el parámetro cantidad, los tesoros no se muestran con el comando T, véase el comando DTE.",
					"[cantidad]",
					"rango esperado [1-64].");
				continue;
			}


			if (!strcmp(comando, "QTE"))
			{
				mostrarAyuda("QTE - Quitar un Tesoro del Tablero de Forma Random.","QTE",
					"Quitar un tesoro del tablero de una pos random de ser posible.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "DTE"))
			{
				mostrarAyuda("DTE - Devuelve las Pos de los Tesoros.","DTE",
					"Devuelve las pos o números de escaques donde se encuentran los tesoros.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "M21"))
			{
				mostrarAyuda("M21 - Genera Movimiento Minijuego21.","M21",
					"Genera un movimiento aleatorio de una pieza negra en el minijuego21.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "VER"))
			{
				mostrarAyuda("VER - Muestra Información Sobre el Protocolo.","VER",
					"Muestra información sobre el protocolo y su versión.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "VCL"))
			{
				mostrarAyuda("VCL - Ver Camino Laberinto.","VCL",
					"Devuelve los escaques donde puede mover el rey para resolver el laberinto.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "VPR")) 
			{
				mostrarAyuda("VPR - Ver Posición del Rey Blanco.","VPR",
					"Devuelve el número del escaque donde se encuentra el rey blanco.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "CTR"))
			{
				mostrarAyuda("CTR - Cambiar Color de Turno Actual.","COD",
					"Cambia el color del turno actual a jugar, si es blanco pasaŕa a negro y viceversa.",
					"",
					"");
				continue;
			}

//Quita del Tablero Piezas Atacadas por el Caballo (Sólo para el mini juego 20)

			if (!strcmp(comando, "QAC"))
			{
				mostrarAyuda("QAC - Quita las Piezas Atacadas Doblemente por el Caballo (Sólo para el mini juego 19).","QAC [pos]",
					"Quita del tablero las piezas atacadas doblemente por el caballo ubicado en pos, sólo si existen más de 2 piezas atacadas por el mismo caballo.",
					"[pos]",
					"pos es una posición en el tablero en el rango [0-63]");
				continue;
			}

			if (!strcmp(comando, "MVI"))
			{
				mostrarAyuda("MVI - Escaques Movilidad Pieza.","MVI [pos] [opcion]",
					"Devuelve los escaques de movilidad por la pieza ubicada en pos\n\t Según el parámetro puede devolver los movimientos sin las capturas\n\t sólo las capturas o todos los movimientos.",
					"[pos] [opcion]",
					"pos es una posición en el tablero en el rango [0-63]\n\t opcion [1-2-3] donde 1 movimientos sin las capturas, 2 sólo capturas y 3 Todos los movimientos.");
				continue;
			}

			if (!strcmp(comando, "MVL"))
			{
				mostrarAyuda("MVL - Escaques Movilidad.","MVL",
					"Devuelve todos escaques de movilidad por cada pieza en el tablero\n\t según el color de turno actual, incluye los movimientos de capturas, promociones\n\t y movimientos tranquilos.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "FIN"))
			{
				mostrarAyuda("FIN - Finaliza el Modo Protocolo XMM.","FIN",
					"Cierra el modo protocolo XMM en el motor Mango Paola",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "FEN"))
			{
				mostrarAyuda("FEN - Cadena Fen.","FEN",
					"Devuelve la cadena fen del tablero actual.",
					"",
					"");
				continue;
			}
// GMO [BLANCO | NEGRO | TODOS] [SI_CAPTURA | NO_CAPTURA] [PATRULLAJE | NO] [RANDOM | POS] [nn]
			if ((!strcmp(comando, "GMO")) || (!strcmp(comando, "C2M")) || (!strcmp(comando, "CMA"))
				|| (!strcmp(comando, "CMC")) || (!strcmp(comando, "CMM")) || (!strcmp(comando, "CMP"))
				|| (!strcmp(comando, "CMS")) || (!strcmp(comando, "CMW")))
			{
				mostrarAyuda("GMO - Genera un Movimiento Random Válido.","GMO [COLOR][RANDOM|POS][nn]",
					"Genera un movimiento de las piezas blancas, negras o cualquier.\n\t tambien se puede filtrar las capturas o no.\n\t de igual forma sí Mango Paola escoge la pieza de forma random o directamente en una pos.\n\t NOTA: Existen una lista de comandos externos que modifican el comportamiento del GMO.",
					"GMO [COLOR][RANDOM|POS][nn] ",
					"\n\n\t COLOR puede ser [BLANCO | NEGRO | TODOS], BLANCO sólo blancas, NEGRO sólo negras o TODOS blancas o negras\n\t [RANDOM|POS], random deja que Mango Paola escoja la pieza que deseé entre las opciones de color seleccionado antes\n\t POS permite al usuario introducir la pos en el parámetro nn donde está la pieza a generar el movimiento random\n\t nn puede ser una pos entre [0-63].\n\n\t NOTA: sino se especifica parámetros por defecto se toma COLOR:TODOS y RANDOM.\n\n\t NOTA: Véase También los comandos abajo listados, donde n es [1=ON, 0=OFF] OFF por defecto a todos.\n\n\t\t C2M [n] configura el GMO para permitir promoción.\n\n\t\t CMA [n] configura el GMO para establecer prioridad en el movimiento a escaques no amenazados.\n\n\t\t CMC [n] configura el GMO para establecer prioridad en las capturas.\n\n\t\t CMM [n] configura el GMO para permitir el movimiento de muro o peon.\n\n\t\t CMP [n] configura el GMO puede capturar.\n\n\t\t CMS [n] configura el GMO mueva solo un paso en cada movimiento (modo sigiloso).\n\n\t\t CMW [n] configura el GMO para permitir la captura de muros o peones.\n\n\t\t CMF [n] configura el GMO para permitir solamente movimientos en la misma fila.\n\n\t\t CML [n] configura el GMO para permitir solamente movimientos en la misma columna.\n\n\t\t CMT [n] configura el GMO solamente movimientos capturas, excluyendo todos los demás.");
				continue;
			}

			if (!strcmp(comando, "NDF"))
			{
				mostrarAyuda("NDF - Nivel de Dificultad.","NDF [nn]",
					"Establece el nivel de dificultad o el nivel de capas de búsqueda según el parámetro nn.",
					"nn",
					"Número de capas en el arbol de búsqueda, valores esperados [2-98]");
				continue;
			}


			if (!strcmp(comando, "AGM"))
			{
				mostrarAyuda("AGM - Agrega un Muro en pos Enemigo/Amigo Según el Parametro Color.","AGM [nn][COLOR]",
					"Agrega un muro en el escaque definido en pos, si esta se encuentra libre y no genera jaque.",
					"[nn][COLOR]",
					"\n\n\t nn permite al usuario introducir el número del escaque donde se quiere colocar la pieza (Debe estar vacio)\n\t nn puede ser una pos entre [0-63].\n\t COLOR puede ser [BLANCO | NEGRO].");
				continue;
			}

			if (!strcmp(comando, "MMR"))
			{
				mostrarAyuda("MMR - Mover un Muro en pos Random Enemigo/Amigo Según el Parametro Color.","MMR [COLOR]",
					"Mueve un muro en un escaque random, si esta se encuentra libre y no genera jaque.",
					"[COLOR]",
					"\n\n\t COLOR puede ser [BLANCO | NEGRO | TODOS].");
				continue;
			}

			if (!strcmp(comando, "AUC"))
			{
				mostrarAyuda("AUC - Activa/Desactiva la opción de informar la última captura.","AUC [n]",
					"Activa/Desactiva la opción de informar la última captura.\n\t El motor informa por medio de los caracteres ##, el primero las piezas negras sin contar los peones, el segundos piezas negras contando los peones\n\t para ambos casos no se cuenta el rey negro.\n\t Ejemplo:\n\t OK #  (Significa solo hay peones negros con o sin el rey negro)\n\t OK ## (Significa no hay piezas negras, pudiendo estar el rey negro o no)",
					"[n]",
					" n puede ser 1=ON o 0=OFF.");
				continue;
			}

			if (!strcmp(comando, "MJF"))
			{
				mostrarAyuda("MJF - Iniciar mini juego Según Cadena Fen.","MJF [nn] [cadena-fen]",
					"Inicia el mini juego número nn con la cadena fen.",
					"[nn]\tNúmero del mini juego.\n",
					" [cadena-fen]\tUna cadena fen. Ej. PP4PP/2P2PP1/1P2P3/PPb5/P7/6PP/2P1r3/PPP2P1K w");
				continue;
			}

			if (!strcmp(comando, "PIN"))
			{
				mostrarAyuda("PIN - Envia un Número al Motor.","PIN [nn]",
					"Envia un Número al Motor y Devuelve un PON con el Mismo Número.",
					"[nn]",
					"Número que se espera que devuelva. Ej. XMM>PIN 10 devuelve PON 10");
				continue;
			}

			if (!strcmp(comando, "MOV"))
			{
				mostrarAyuda("MOV - Realiza Movimiento de Pieza.","MOV [pos1][pos2]",
					"Realiza el movimiento de la pieza ubicada en pos1 hasta la pos2 en caso de ser válido.",
					"[pos1]\tPosición o escaque inicial en el tablero, se espera un valor entre [0-63].\n",
					" [pos2]\tPosición o escaque final en el tablero, se espera un valor entre [0-63].");
				continue;
			}

			if (!strcmp(comando, "NGR"))
			{
				mostrarAyuda("NGR - Cambia a Negro el Turno.","NGR",
					"Cambia el color del turno actual a color Negro.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "CM1"))
			{
				mostrarAyuda("CM1 - Cambia el Mapa del MiniJuego1.","CM1",
					"Cambia el mapa del laberinto del MiniJuego1 manteniendo el rey y la puerta de salida en el mismo lugar.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "CM10"))
			{
				mostrarAyuda("CM1 - Cambia el Mapa del MiniJuego10.","CM10",
					"Cambia el mapa del laberinto del MiniJuego10 manteniendo el alfil y la puerta de salida en el mismo lugar.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "NBP"))
			{
				mostrarAyuda("NBP - Número de piezas blancas incluyendo los peones blancos.","NBP",
					"Devuelve el total de piezas blancas incluyendo los peones pero sin contar el rey.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "GON"))
			{
				mostrarAyuda("GON - Go para la Piezas Negras.","GON",
					"Genera un movimiento de las piezas negras pensado por el motor..",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "NBS"))
			{
				mostrarAyuda("NBS - Número de piezas blancas \"sin\" incluir los peones blancos.","NBS",
					"Devuelve el total de piezas blancas sin contar los peones y sin contar el rey.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "NNP"))
			{
				mostrarAyuda("NNP - Número de piezas negras incluyendo los peones negros.","NNP",
					"Devuelve el total de piezas negras incluyendo los peones pero sin contar el rey.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "NNS"))
			{
				mostrarAyuda("NNS - Número de piezas negras \"sin\" incluir los peones negros.","NNS",
					"Devuelve el total de piezas negras sin contar los peones y sin contar el rey.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "VPS"))
			{
				mostrarAyuda("VPS - Ver Pos de Salida del Laberinto .","VPS",
					"Devuelve el número del escaque de salida del laberinto para el minijuego actual, de ser posible.",
					"",
					"");
				continue;
			}


			if (!strcmp(comando, "MUR"))
			{
				mostrarAyuda("MUR - Agrega Muros Aleatoriamente.","MUR [COLOR][BLOQUEANTE][DENSIDAD]",
					"Agrega muros del color especificado, bloqueantes o no, con la densidad.",
					"[COLOR][BLOQUEANTE][DENSIDAD]",
					"\n\n\t COLOR puede ser BLANCO | NEGRO | TODOS del muro, en caso de ser TODOS mango randomiza el color.\n\t BLOQUEANTE puede ser 1=ON o 0=OFF, bloqueante se colocaran los muros en el camino del laberinto si es posible.\n\t DENSIDAD puede ser un valor entre 0 y 120.\n\n\t NOTA: Véase el comando AGM");
				continue;
			}

			if (!strcmp(comando, "T"))
			{
				mostrarAyuda("T - Muestra el Tablero.","T",
					"Muestra el tablero en formato ascii.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "IGJ"))
			{
				mostrarAyuda("IGJ - Ignorar Jaque","IGJ [n]",
					"Enciende o apaga la opción de ignorar el jaque cuando el mismo se coloca en jaque.",
					"[n]",
					"Valor 0 apagado, valor 1 lo enciende.");
				continue;
			}

			if (!strcmp(comando, "NMJ"))
			{
				mostrarAyuda("NMJ - Número del mini juego Actual.","NMJ",
					"Devuelve el número del mini juego actual o código 910 sí no hay mini juego seleccionado.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "MCP"))
			{
				mostrarAyuda("MCP - Movimientos de captura de todos los peones negros.","MCP",
					"Devuelve una lista con todos los escaques de captura de todos los peones negros.",
					"",
					"");
				continue;
			}


			if (!strcmp(comando, "TUR"))
			{
				mostrarAyuda("TUR - Devuelve el Color del Turno Actual.","TUR",
					"Devuelve el color del turno actual.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "APR"))
			{
				mostrarAyuda("APR - Agrega una Pieza en el Tablero de Forma Aleatoria o Random.","APR [PIEZA]",
					"El motor Mango Paola coloca en el tablero de forma aleatoria o random la pieza indicada en el parámetro del comando\n\t validando que el tablero no quede en jaque.",
					"[PIEZA]",
					"[DN]Dama Negra  [TN]Torre Negra  [AN]Alfil Negro  [CN]Caballo Negro  [PN]Peon Negro\n\t\t[DB]Dama Blanca [TB]Torre Blanca [AB]Alfil Blanco [CB]Caballo Blanco [PB]Peon Blanco");
				continue;
			}

			if (!strcmp(comando, "QPR"))
			{
				mostrarAyuda("QPR - Quita una Pieza del Tablero.","QPR [PIEZA][COLOR]",
					"Se quita del tablero una pieza específica o una pieza random\n\t Se valída que el tablero no quede en jaque.",
					"[PIEZA][COLOR]",
					"\n\t Pieza puede ser [T] cualquier pieza (random) del color que se establezca en el parámetro [COLOR]\n\t También puede ser [DN]Dama Negra  [TN]Torre Negra  [AN]Alfil Negro  [CN]Caballo Negro  [PN]Peon Negro\n\t [DB]Dama Blanca [TB]Torre Blanca [AB]Alfil Blanco [CB]Caballo Blanco [PB]Peon Blanco\n\t COLOR puede ser [BLANCO] [NEGRO]\n\t NOTA: Cuando se establece una pieza ya no es necesario el parámetro [COLOR]");
				continue;
			}

			if (!strcmp(comando, "QPP"))
			{
				mostrarAyuda("QPP - Quita la Pieza Ubicada en pos del Tablero.","QPP [pos]",
					"Quita la pieza ubicada en posición [pos] del Tablero\n\t Se valída que el tablero no quede en jaque, ni para el blanco ni el negro.",
					"[pos]",
					"Posición en el tablero donde se ubica la pieza, se espera un rango entre [0-63]");
				continue;
			}

			if (!strcmp(comando, "POW"))
			{
				mostrarAyuda("POW - Devuelve todos los escaques donde se encuentran los muros blancos.","POW",
					"",
					"",
					"");
				continue;
			}

			printf("No existe la ayuda para [%s] o no se reconoce como un comando\n",comando);
			continue;
		}

		if (!strcmp(buffComandos, "MJF"))
		{
			char fen[100];
			char fencolor[2];     
			char fenEnroque[5];
			char fenPeonPaso[3];
			int fenReglaCincuentaMov=0;
			int fenTotalMov=0;
			int num=99;

			sscanf(linea, "MJF %d %s %s %s %s %d %d", &num,
						fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov);
			
			if (ES_ESTA_ON_MINIJUEGO(num))
			{
//				parseFENW2FEN(fen);
				setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);
				numMinijuegoActual = num;
				printf("OK\n");
			} else {
				printf("COD901\n");
			}
			continue;
		}

		if (!strcmp(buffComandos, "MJN"))
		{
			int num=0;
			int llenado=0;
			sscanf(linea,"MJN %d %d", &num, &llenado);

			llenado_laberinto = ((llenado>0 && llenado<121)?llenado:0);

			if (num==1)
			{
				__attribute__ ((unused)) int posSalida = iniMiniJuego1(VERDADERO);
				numMinijuegoActual = num;

			} else if (num==2) {

				iniMiniJuego2();
				numMinijuegoActual = num;

			} else if (num==3) {
			
				iniMiniJuego3();
				numMinijuegoActual = num;

			} else if (num==4) {
			
				iniMiniJuego4();
				numMinijuegoActual = num;

			} else if (num==5) {
			
				iniMiniJuego5();
				numMinijuegoActual = num;

			} else if (num==6) {
			
				iniMiniJuego6();
				numMinijuegoActual = num;

			} else if (num==7) {
			
				iniMiniJuego7();
				numMinijuegoActual = num;

			} else if (num==8) {
			
				iniMiniJuego8();
				numMinijuegoActual = num;

			} else if (num==9) {
			
				llenado_laberinto /=3;			
				iniMiniJuego9();
				numMinijuegoActual = num;

			} else if (num==10) {
			
				iniMiniJuego10();
				numMinijuegoActual = num;

			} else if (num==11) {
			
				iniMiniJuego11();
				numMinijuegoActual = num;

			} else if (num==12) {
			
				iniMiniJuego12();
				numMinijuegoActual = num;

			} else if (num==13) {
			
				iniMiniJuego13();
				numMinijuegoActual = num;

			} else if (num==14) {
			
				iniMiniJuego14();
				numMinijuegoActual = num;

			} else if (num==15) {
			
				uint32 i;
				BOOLEANO esRepetir = FALSO;

				do 
				{
					iniMiniJuego15();
					esRepetir = FALSO;

					for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
					{
						if (ES_MOV_PEON(juego.Buffer_MOV[i])) continue;

						if (OBT_MOV_DESTINO(juego.Buffer_MOV[i])==posSalida)
						{
							esRepetir=VERDADERO;
							i = juego.Buffer_MOV_INDEXCAPAS[1];
						}
					}
	
		
				} while (esRepetir);

				char fen[100];
				memset(fen,'\0', 100);
				converTabler2FEN(fen);
				parseFEN2FENW(fen);
				parseFENW2FENWS(posSalida,fen);
				printf("%s\n",fen);										
				numMinijuegoActual = num;

			} else if (num==16) {
			
				iniMiniJuego16();
				numMinijuegoActual = num;

			} else if (num==17) {
			
				iniMiniJuego17();
				numMinijuegoActual = num;

			} else if (num==18) {
			
				iniMiniJuego18();
				numMinijuegoActual = num;

			} else if (num==19) {
			
				iniMiniJuego19();
				numMinijuegoActual = num;

			} else if (num==20) {
			
				iniMiniJuego20();
				numMinijuegoActual = num;

			} else if (num==21) {
			
				iniMiniJuego21();
				numMinijuegoActual = num;

			} else if (num==22) {
			
				iniMiniJuego22();
				numMinijuegoActual = num;

			} else if (num==23) {
			
				iniMiniJuego23();
				numMinijuegoActual = num;

			} else {

				printf("COD901\n");	
			}
			continue;
		}

		if (!strcmp(buffComandos, "T"))
		{
			mostrarTablero();
			continue;
		}

		if (!strcmp(buffComandos, "MVL"))
		{
			verMovimentosLegales();
				printf("\n B PEON=1 REY=2  CABALLO=3  ALFIL=5  TORRE=6  DAMA=7\n N PEON=9 REY=10 CABALLO=11 ALFIL=13 TORRE=14 DAMA=15\n");

			continue;    
		}

		if (!strcmp(buffComandos, "QAC")) //Doble Ataque Caballo Mini 20 [DAC pos]
		{
			int pos = SIN_POS_VALIDA;

			if (numMinijuegoActual != 19)
			{
				printf("COD916\n");
				continue;
			}

			sscanf(linea, "QAC %d",&pos);

			if (ES_POS_VACIO(pos))
			{
				printf("COD908\n");
				continue;
			}

			if (!ES_RANGO_POS_VALIDA(pos))
			{
				printf("COD906\n");
				continue;
			}

			if (quitarPiezasAtacadasPorCaballo(pos)) continue;

/*
			int posEliminadas = quitarPiezasAtacadasPorCaballo(pos);

			if (posEliminadas)
			{
				char fen[100];
				memset(fen,'\0', 100);
				converTabler2FEN(fen);
				printf("%d %s\n",posEliminadas,fen);
				continue;
			}
*/
			
			printf("COD917\n");
			continue;
		}

		if (!strcmp(buffComandos, "NMJ"))
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			printf("%d\n",numMinijuegoActual);
			continue;
		}

		if (!strcmp(buffComandos, "NNP"))
		{
			printf("%d\n",NTOTAL_PIEZAS_NEGRAS_SR);
			continue;
		}

		if (!strcmp(buffComandos, "POW"))
		{
			uint64 tempOrigenes = juego.tablero[BLANCO][PEON];
			uint32 escaqueOrigen;

			while (tempOrigenes)
			{
				escaqueOrigen = bitScanForwardBruijn(tempOrigenes);
				tempOrigenes ^= BITSET[escaqueOrigen];
				printf("%d ",escaqueOrigen);
			}
			
			printf("\n");
			continue;
		}

		if (!strcmp(buffComandos, "NBP"))
		{
			printf("%d\n",NTOTAL_PIEZAS_BLANCAS_SR);
			continue;
		}

		if (!strcmp(buffComandos, "NNS"))
		{
			printf("%d\n",NTOTAL_PIEZAS_NEGRAS_SR_SP);
			continue;
		}

		if (!strcmp(buffComandos, "NBS"))
		{
			printf("%d\n",NTOTAL_PIEZAS_BLANCAS_SR_SP);
			continue;
		}

		if (!strcmp(buffComandos, "NDF"))
		{
			int nivel_sd=6;
			sscanf(linea, "NDF %d",&nivel_sd);
			
			if ((nivel_sd > 0) && (nivel_sd < 99)) 
			{
				juego.profundidadBusquedad = nivel_sd;
			} else {
				juego.profundidadBusquedad = 6;
			}
			nivelPC = PC_NIVEL_PERSONALIZADO;
			printf("sd %d OK\n",juego.profundidadBusquedad);
			continue;
		}

		if (!strcmp(buffComandos, "AGM")) //Agregar Muro 
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			int posw=SIN_POS_VALIDA;
			char cc[128];
			sscanf(linea, "AGM %d %s",&posw, cc);

			if (!ES_POS_VACIO(posw))
			{
				printf("COD920\n");
				continue;
			}

			if (!ES_RANGO_POS_VALIDA(posw))
			{
				printf("COD906\n");
				continue;
			}

			if (!strcmp(cc, "BLANCO"))
				agregarMuros(posw, PEON_BLANCO);
			else	
				agregarMuros(posw, PEON_NEGRO);

			continue;
		}



		if (!strcmp(buffComandos, "QPP"))
		{
			int pos=SIN_POS_VALIDA;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			sscanf(linea, "QPP %d",&pos);

			if (ES_POS_VACIO(pos))
			{
				printf("COD908\n");
				continue;
			}

			if (!ES_RANGO_POS_VALIDA(pos))
			{
				printf("COD906\n");
				continue;
			}

			if (quitarPiezaPos(pos))
			{
				printf("OK\n");
				continue;
			} 

			printf("COD912\n");
			continue;
		}

		if (!strcmp(buffComandos, "QPR"))
		{
			char ccolor[100];
			int posCol = SIN_POS_VALIDA;
			char ppieza[100];
			PIEZA pieza = VACIO;
			COLOR color = BLANCO;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}
			
			memset(ccolor,0,sizeof(ccolor));
			memset(ppieza,0,sizeof(ppieza));
			sscanf(linea, "QPR %s %s",ppieza, ccolor);
			
			if (!strcmp(ppieza, "PN"))
			{
				pieza = PEON_NEGRO;
				color = NEGRO;

			} else 	if (!strcmp(ppieza, "DN")) {

				pieza = DAMA_NEGRO;
				color = NEGRO;

			} else if (!strcmp(ppieza, "CN")) {

				pieza = CABALLO_NEGRO;
				color = NEGRO;

			} else if (!strcmp(ppieza, "AN")) {

				pieza = ALFIL_NEGRO;
				color = NEGRO;

			} else if (!strcmp(ppieza, "TN")) {

				pieza = TORRE_NEGRO;
				color = NEGRO;

			} else if (!strcmp(ppieza, "PB")) {

				pieza = PEON_BLANCO;
				color = BLANCO;

			} else if (!strcmp(ppieza, "DB")) {

				pieza = DAMA_BLANCO;
				color = BLANCO;

			} else if (!strcmp(ppieza, "CB")) {

				pieza = CABALLO_BLANCO;
				color = BLANCO;

			} else if (!strcmp(ppieza, "AB")) {

				pieza = ALFIL_BLANCO;
				color = BLANCO;

			} else if (!strcmp(ppieza, "TB")) {

				pieza = TORRE_BLANCO;
				color = BLANCO;
			} 

			if (!strcmp(ccolor, "BLANCO"))
			{
				color = BLANCO;

			} else if (!strcmp(ccolor, "NEGRO")) {

				color = NEGRO;
			} 

			if (quitarPiezaPosRandom(color, pieza, &posCol))
			{
				printf("%d\n", posCol);

			} else {

				printf("COD912\n");
			}

			continue;
		}

		if (!strcmp(buffComandos, "VPS")) //Ver Pos Salida del Laberinto
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			if (posSalida != SIN_POS_VALIDA)
			{
				printf("%d\n",posSalida);
			} else {

				printf("COD925\n");
			}
			continue;
		}

		if (!strcmp(buffComandos, "CM1")) //Cambiar Mapa del Minijuego 1
		{
			if (numMinijuegoActual==1 && caminoLaberintoMapa)
			{
				cambiarMapaMiniJuego1();
	
			} else {

				printf("COD924\n");
			}
			continue;
		}

		if (!strcmp(buffComandos, "CM10")) //Cambiar Mapa del Minijuego 10
		{
			if (numMinijuegoActual==10 && caminoLaberintoMapa)
			{
				cambiarMapaMiniJuego10();
	
			} else {

				printf("COD924\n");
			}
			continue;
		}

		if (!strcmp(buffComandos, "VPR")) //Ver Pos Rey Blanco
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			if (juego.tablero[BLANCO][REY])
			{
				printf("%d\n",bitScanForwardBruijn(juego.tablero[BLANCO][REY]));

			} else {

				printf("COD923\n");
			}
			continue;
		}


		if (!strcmp(buffComandos, "VCL")) //Ver Camino Laberinto
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			if (caminoLaberintoMapa)
			{
				uint64 tempOrigenes = caminoLaberintoMapa;
 				int escaquePos;
				while (tempOrigenes)
				{
					escaquePos = bitScanForwardBruijn(tempOrigenes);
					tempOrigenes ^= BITSET[escaquePos];
					printf("%d ", escaquePos);
				}	
				printf("\n");
				
			} else {

				printf("COD922\n");
			}
			continue;
		}	

		if (!strcmp(buffComandos, "APR"))
		{
			char ppieza[100];
			int posCol = SIN_POS_VALIDA;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}
			
			memset(ppieza,0,sizeof(ppieza));
			sscanf(linea, "APR %s", ppieza);
			
			if (!strcmp(ppieza, "PN"))
			{
				if (agregarPiezaPosRandom(PEON_NEGRO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			if (!strcmp(ppieza, "DN"))
			{
				if (agregarPiezaPosRandom(DAMA_NEGRO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}

				continue;
			} 

			if (!strcmp(ppieza, "CN"))
			{
				if (agregarPiezaPosRandom(CABALLO_NEGRO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			if (!strcmp(ppieza, "AN"))
			{
				if (agregarPiezaPosRandom(ALFIL_NEGRO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			if (!strcmp(ppieza, "TN")) 
			{
				if (agregarPiezaPosRandom(TORRE_NEGRO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

		// PIEZAS BLANCAS CPR *************************************************
			if (!strcmp(ppieza, "PB"))
			{
				if (agregarPiezaPosRandom(PEON_BLANCO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			if (!strcmp(ppieza, "DB"))
			{
				if (agregarPiezaPosRandom(DAMA_BLANCO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}

				continue;
			} 

			if (!strcmp(ppieza, "CB"))
			{
				if (agregarPiezaPosRandom(CABALLO_BLANCO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			if (!strcmp(ppieza, "AB"))
			{
				if (agregarPiezaPosRandom(ALFIL_BLANCO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			if (!strcmp(ppieza, "TB")) 
			{
				if (agregarPiezaPosRandom(TORRE_BLANCO, &posCol,FALSO))
				{
					printf("%d\n", posCol);

				} else {

					printf("COD911\n");
				}
				continue;
			} 

			printf("COD911\n");
			continue;
		}

		if (!strcmp(buffComandos, "MCP")) 
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			if (juego.tablero[NEGRO][PEON])
			{
				int escaqueOrigen = 0, escaqueDestino = 0;
				uint64 tempOrigenes = juego.tablero[NEGRO][PEON];
				uint64 mapaDestinosCaptura;

				while (tempOrigenes)
				{
					escaqueOrigen = bitScanForwardBruijn(tempOrigenes);
					mapaDestinosCaptura = mascaraCapturarPeon[escaqueOrigen][NEGRO];

 					while (mapaDestinosCaptura)
					{
						escaqueDestino = bitScanForwardBruijn(mapaDestinosCaptura);
						printf("%d ",escaqueDestino);
						mapaDestinosCaptura ^= BITSET[escaqueDestino]; 
					}

					printf("\n");
					tempOrigenes ^= BITSET[escaqueOrigen];
					
				}

			} else {

				printf("COD918\n");
			}

			continue;
		}

		if (!strcmp(buffComandos, "MVI")) //MVI pos tipo
		{
			int pos=0;
			int tipoMovimiento=3;
			int movv[28];

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			sscanf(linea, "MVI %d %d",&pos, &tipoMovimiento);

			if (tipoMovimiento < 1 || tipoMovimiento > 4) 
				tipoMovimiento = 3;			

			if (!ES_RANGO_POS_VALIDA(pos))
			{
				printf("COD906\n");
				continue;
			}

			if (ES_POS_VACIO(pos))
			{
				printf("COD908\n");
				continue;
			}

			int cPos = llenarPosMovilidad(movv,pos, tipoMovimiento);
			int i =0;

			if (cPos)
			{
				for (i=0;i<cPos;i++)
				{
					printf("%d ",movv[i]);
				}
				printf("\n");
				continue;
			}

			printf("COD903\n");
			continue;
		}

		if (!strcmp(buffComandos, "MMR"))
		{
			// MMR [BLANCO | NEGRO | TODOS]  

			char cc[128];
			int posEscaque=0;
			uint64 mapaMuros;
			mapaMuros ^= mapaMuros;
			BOOLEANO exito=FALSO;
			COLOR color_pieza_quitada;
			int posCol=SIN_POS_VALIDA;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			sscanf(linea, "MMR %s",cc);
			
			if (!strcmp(cc, "BLANCO"))
			{
				mapaMuros = juego.tablero[BLANCO][PEON];

			} else if (!strcmp(cc, "NEGRO")) {

				mapaMuros = juego.tablero[NEGRO][PEON];

			} else {

				mapaMuros = (juego.tablero[BLANCO][PEON] | juego.tablero[NEGRO][PEON]);
			}

			if (mapaMuros)
			{
				while (mapaMuros)
				{
					posEscaque = rand()%64;
					if (BITSET[posEscaque] & mapaMuros)
					{
						mapaMuros ^= BITSET[posEscaque];
						color_pieza_quitada = OBT_COLOR_PIEZA(ESCAQUES[posEscaque]);
						if (quitarPiezaPos(posEscaque))
						{
							exito = VERDADERO;
							mapaMuros ^= mapaMuros;
							printf("%d ",posEscaque);
						}
					}
				}

				if (exito)
				{
					if (color_pieza_quitada)
						agregarPiezaPosRandom(PEON_NEGRO, &posCol, FALSO);	
					else 
						agregarPiezaPosRandom(PEON_BLANCO, &posCol, FALSO);

					printf("%d\n",posCol);
				}

			} else {

				printf("COD926\n");
			}

			continue;
		}

		if (!strcmp(buffComandos, "MUR")) //Crea muros bloqueantes o perifericos COLOR BLOQUEANTE DENSIDAD
		{
			int bloqueante=0;
			int densidadW=0;
			char cc[128];
			COLOR colorW = BLANCO;

			sscanf(linea, "MUR %s %d %d", cc ,&bloqueante, &densidadW);

			if (!strcmp(cc, "BLANCO"))
			{
				colorW = BLANCO;

			} else if (!strcmp(cc, "NEGRO")) {

				colorW = NEGRO;
			}

			llenado_laberinto = ((densidadW>0 && densidadW<121)?densidadW:32);

			crearMuros(colorW, (bloqueante>0?VERDADERO:FALSO));
			continue;
		}


		if (!strcmp(buffComandos, "CMP")) //Configura el GMO puede capturar
		{
			int banderaActivo=0;
			sscanf(linea, "CMP %d",&banderaActivo);
			GMO_puede_capturar = banderaActivo ? VERDADERO : FALSO;

			if (GMO_puede_capturar)
				printf("CMP=[on]\n");
			else 
				printf("CMP=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMS")) //Configura el GMO mueva solo un paso, modo sigiloso
		{
			int banderaActivo=0;
			sscanf(linea, "CMS %d",&banderaActivo);
			GMO_modoPatrullaje = banderaActivo ? VERDADERO : FALSO;

			if (GMO_modoPatrullaje)
				printf("CMS=[on]\n");
			else
				printf("CMS=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMM")) //Configura el GMO permite movimiento muro o peon 
		{
			int banderaActivo=0;
			sscanf(linea, "CMM %d",&banderaActivo);
			GMO_permitir_mov_peon = banderaActivo ? VERDADERO : FALSO;

			if (GMO_permitir_mov_peon)
				printf("CMM=[on]\n");
			else
				printf("CMM=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMF")) //Configura el GMO solo movimientos en fila 
		{
			int banderaActivo=0;
			sscanf(linea, "CMF %d",&banderaActivo);
			GMO_soloMismaRANK = banderaActivo ? VERDADERO : FALSO;

			if (GMO_soloMismaRANK)
			{
				printf("CMF=[on] CML=[OFF]\n");
				GMO_soloMismaFILE = FALSO;
			} else
				printf("CMF=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMT")) //Configura el GMO solamente movimientos capturas
		{
			int banderaActivo=0;
			sscanf(linea, "CMT %d",&banderaActivo);
			GMO_solamenteMovCapturas = banderaActivo ? VERDADERO : FALSO;

			if (GMO_solamenteMovCapturas)
			{
				printf("CMT=[on] CMP=[on]\n");
				GMO_puede_capturar = VERDADERO;
			} else
				printf("CMT=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CML")) //Configura el GMO solo movimientos en columna 
		{
			int banderaActivo=0;
			sscanf(linea, "CML %d",&banderaActivo);
			GMO_soloMismaFILE = banderaActivo ? VERDADERO : FALSO;

			if (GMO_soloMismaFILE)
			{
				printf("CML=[on] CMF=[OFF]\n");
				GMO_soloMismaRANK = FALSO;
			} else
				printf("CML=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "C2M")) //Configura el GMO a permitir promocion
		{
			int banderaActivo=0;
			sscanf(linea, "C2M %d",&banderaActivo);
			GMO_permitir_mov_peon_y_promocion = banderaActivo ? VERDADERO : FALSO;

			if (GMO_permitir_mov_peon_y_promocion)
			{
				GMO_permitir_mov_peon = VERDADERO;
			}

			if (GMO_permitir_mov_peon_y_promocion)
				printf("C2M=[on] CMM=[on]\n");
			else
				printf("C2M=[off] CMM=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMC")) //Configura el GMO a prioridad capturas
		{
			int banderaActivo=0;
			sscanf(linea, "CMC %d",&banderaActivo);
			GMO_prioridad_captura = banderaActivo ? VERDADERO : FALSO;

			if (GMO_prioridad_captura)
			{
				GMO_puede_capturar = VERDADERO;
			}

			if (GMO_prioridad_captura)
				printf("CMC=[on] CMP=[on]\n");
			else
				printf("CMC=[off] CMP=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMW")) //Configura el GMO a permite captura de peones 
		{
			int banderaActivo=0;
			sscanf(linea, "CMW %d",&banderaActivo);
			GMO_puede_capturar_peon = banderaActivo ? VERDADERO : FALSO;

			if (GMO_puede_capturar_peon)
			{
				GMO_puede_capturar = VERDADERO;
			}

			if (GMO_puede_capturar_peon)
				printf("CMW=[on] CMP=[on]\n");
			else
				printf("CMW=[off] CMP=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CMA")) //Configura el GMO a prioridad escaque no amenazados
		{
			int banderaActivo=0;
			sscanf(linea, "CMA %d",&banderaActivo);
			GMO_prioridad_no_amenazados = banderaActivo ? VERDADERO : FALSO;

			if (GMO_prioridad_no_amenazados)
				printf("CMA=[on]\n");
			else
				printf("CMA=[off]\n");

			continue;
		}

		if (!strcmp(buffComandos, "CUP"))
		{
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			if (posSalida == SIN_POS_VALIDA) 
			{
				printf("COD929\n");
				continue;
			}

			int banderaActivo=0;
			sscanf(linea, "CUP %d",&banderaActivo);

			crearHacerMovCuidarSalida(banderaActivo>0?VERDADERO:FALSO);
			continue;
		}

		if (!strcmp(buffComandos, "GMO"))
		{
			// GMO [BLANCO | NEGRO | TODOS] | [RANDOM | POS] [nn]  

			char cc[128];
			char pp[128];
			int tipo=3; //Deafult TODOS
			int pos=SIN_POS_VALIDA;
	
			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			sscanf(linea, "GMO %s %s %d",cc,pp,&pos);
			
			if (!strcmp(cc, "BLANCO"))
			{
				tipo = 1;

			} else if (!strcmp(cc, "NEGRO")) {

				tipo = 2;
			}

			//Default Random 

			if (!strcmp(pp, "POS"))
			{
				crearHacerMovPos(pos, tipo);
			
			} else {

				crearHacerMovPos(SIN_POS_VALIDA, tipo);
			}
			continue;
		}

		if (!strcmp(buffComandos, "ATE"))
		{
			int num = 0;
			int escaqueDestino;
			TABLERO posDisponibles;
			int cPos=0;
			int i=0;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			sscanf(linea, "ATE %d",&num);

			if (num < 1 || num > 64)
			{
				printf("COD914\n");
				continue;
			}

			memset(posDisponibles, 0, sizeof(uint8) * 64);

			uint64 destinos = ~juego.ocupados;
			if (posSalida != SIN_POS_VALIDA)
			{
				destinos |= BITSET[posSalida];
				destinos ^= BITSET[posSalida];
			}

			if (numMinijuegoActual==10)
			{
				if (juego.tablero[BLANCO][ALFIL] & ESCAQUES_BLANCOS)
				{
					destinos |= ESCAQUES_NEGROS;
					destinos ^= ESCAQUES_NEGROS;

				} else if (juego.tablero[BLANCO][ALFIL] & ESCAQUES_NEGROS) {

					destinos |= ESCAQUES_BLANCOS;
					destinos ^= ESCAQUES_BLANCOS;

				}
			}

			int cEspaciosLibres = cuentaBit(destinos);
			if (cEspaciosLibres < num) num = cEspaciosLibres;

			while (destinos)
			{
				escaqueDestino = bitScanForwardBruijn(destinos);
				posDisponibles[cPos++] = escaqueDestino;
				destinos ^= BITSET[escaqueDestino];
			}

			if (cPos)
			{
				mapaTableroMonedas ^= mapaTableroMonedas; 
				i = 0;
				while (i<num)
				{
					escaqueDestino = posDisponibles[rand()%cPos];
					if (mapaTableroMonedas & BITSET[escaqueDestino]) continue; 
					monedasTablero[escaqueDestino] = 1;
					mapaTableroMonedas |= BITSET[escaqueDestino];
					printf("%d ", escaqueDestino);
					i++;
				}
				printf("\n");
				continue;

			} else {

				printf("COD914\n");
				continue;
			}
		}


		if (!strcmp(buffComandos, "QTE"))
		{

			int num = 0;
			TABLERO posDisponibles;
			int cPos=0;
			int i=0;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			memset(posDisponibles, 0, sizeof(uint8) * 64);

			for (i=0;i<64;i++)
			{
				if (monedasTablero[i])
				posDisponibles[num++] = i;
			}

			if (num)
			{
				cPos = posDisponibles[rand()%num]; 
				monedasTablero[cPos] = 0;
				printf("%d \n", cPos);
				continue;
			} 

			printf("COD915\n");
			continue;
	
		}


		if (!strcmp(buffComandos, "DTE"))
		{
			int i=0;
			BOOLEANO bandera = FALSO;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			for (i=0;i<64;i++)
			{
				if (monedasTablero[i])
				{
					printf("%d ", i);
					bandera = VERDADERO;
				}
			}

			if (bandera)
				printf("\n");
			else
				printf("COD915\n");

			continue;
		}

		if (!strcmp(buffComandos, "IGJ")) //Ignorar Jaque
		{
			int estadoIGJ=0;
			sscanf(linea, "IGJ %d", &estadoIGJ);
			esIgnorarVal = (estadoIGJ>0)?VERDADERO:FALSO;
			printf("IGJ=[%s]\n",esIgnorarVal?"on":"off");		
			continue;
		}

		if (!strcmp(buffComandos, "CM23")) //Cambia el mapa del minijuego 23
		{
			if (numMinijuegoActual==23)
			{
				printf("%s\n", MAPAS_FEN[cambiarMapaMiniJuego23()]);
	
			} else {

				printf("COD927\n");
			}
			continue;
		}

		if (!strcmp(buffComandos, "M21")) //Genera movimiento del peon negro minijuego 21
		{
			if (numMinijuegoActual==21)
			{
				crearHacerMovMinijuego21();
	
			} else {

				printf("COD932\n");
			}
			continue;
		}


		if (!strcmp(buffComandos, "MOV"))
		{

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("COD910\n");
				continue;
			}

			if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
			{
				printf("COD903\n");
				continue;
			}

			uint32 pos1 = SIN_POS_VALIDA;
			uint32 pos2 = SIN_POS_VALIDA;
			char promocionPieza;
			uint32 i=0;
			BOOLEANO esExisteMov = FALSO;
			PIEZA promoPieza = VACIO;
			MOVIMIENTO movHecho = 0;

			sscanf(linea, "MOV %d %d %c",&pos1,&pos2,&promocionPieza);

			switch(promocionPieza)
			{
				case 'D':
					promoPieza = DAMA_BLANCO;
					break;

				case 'A':
					promoPieza = ALFIL_BLANCO;
					break;

				case 'T':
					promoPieza = TORRE_BLANCO;
					break;

				case 'C':
					promoPieza = CABALLO_BLANCO;
					break;
			}

			for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
			{

				if (numMinijuegoActual==1)
				{
					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2) && 
							!ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}
				
				} else if (numMinijuegoActual==2) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2) && 
							!ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
						{
							if (esMovimentoLegalXMM(juego.Buffer_MOV[i]) || esIgnorarVal)
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
								{
									printf("+");
								}
								break;
							}
						}
					}
				
				} else if ((numMinijuegoActual==3) || (numMinijuegoActual==4)) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							if (esMovimentoLegalXMM(juego.Buffer_MOV[i]) || esIgnorarVal)
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
								{
									printf("+");
								}
								if (!NTOTAL_PIEZAS_NEGRAS_SR)
								{
									printf("FIN ");
								}
								break;
							}
						}
					}

				} else if (numMinijuegoActual==5) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==TORRE_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}
				
				} else if ((numMinijuegoActual==6) || (numMinijuegoActual==7) || (numMinijuegoActual==8)
						|| (numMinijuegoActual==9)) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO ||
						OBT_MOV_PIEZA(juego.Buffer_MOV[i])==TORRE_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							if (esMovimentoLegalXMM(juego.Buffer_MOV[i]) || esIgnorarVal)
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
								{
									printf("+");
								}
								break;
							}
						}
					}

				} else if ((numMinijuegoActual==10) || (numMinijuegoActual==13)) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==ALFIL_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if (numMinijuegoActual==12) {

					if ((OBT_MOV_PIEZA(juego.Buffer_MOV[i])==ALFIL_BLANCO))
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2)/* && 
								!ES_MOV_CAPTURA(juego.Buffer_MOV[i])*/)
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if (numMinijuegoActual==11) {

					if ((OBT_MOV_PIEZA(juego.Buffer_MOV[i])==ALFIL_BLANCO))
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2) && 
								!ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if ((numMinijuegoActual==14)) {

					BOOLEANO esJaque;

					if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
					{

						hacerMovimiento(juego.Buffer_MOV[i]);

						if (juego.colorTurno)
						{
							esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
						} else {
							esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
						}

						if (esJaque)
						{
							desHacerMovimiento(juego.Buffer_MOV[i]);

						} else {

							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							statusFinJuego = obtEstadoJuego();
							mostrarMensajeFinalJuego();
							if (STATUS_FIN_JUEGO_NO_TERMINADO)
							{	
								if (statusFinJuego==STATUS_FIN_JUEGO_JAQUE)
									printf("OK+ ");
								else
									printf("OK ");
							}

							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}
				

				} else if ((numMinijuegoActual==15) || (numMinijuegoActual==16)) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==DAMA_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if (numMinijuegoActual==17) {

					if ((OBT_MOV_PIEZA(juego.Buffer_MOV[i])==DAMA_BLANCO) || 
						(OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO))
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							if (esMovimentoLegalXMM(juego.Buffer_MOV[i]) || esIgnorarVal)
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								if (esAtacadoPorSRSP(juego.tablero[BLANCO][REY], NEGRO))
								{
									printf("+");
								}
								break;
							}
						}
					}

				} else if (numMinijuegoActual==18) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==CABALLO_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if (numMinijuegoActual==19) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==CABALLO_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2)/* &&
							 (!ES_MOV_CAPTURA(juego.Buffer_MOV[i]))*/)
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if (numMinijuegoActual==20) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==PEON_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							hacerMovimiento(juego.Buffer_MOV[i]);
							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}

				} else if (numMinijuegoActual==21) {

					if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2) &&
							!ES_MOV_PROMOCION(juego.Buffer_MOV[i]))
					{
						hacerMovimiento(juego.Buffer_MOV[i]);
						juego.colorTurno = BLANCO;
						juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
						esExisteMov = VERDADERO;
						break;
					}

				} else if (numMinijuegoActual==22) {

					if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
					{

						if (ES_MOV_PROMOCION(juego.Buffer_MOV[i]))
						{
							if (promoPieza==VACIO) promoPieza = DAMA_BLANCO;

							if (OBT_MOV_PROMOCION(juego.Buffer_MOV[i]) != promoPieza ) continue;
						}

						hacerMovimiento(juego.Buffer_MOV[i]);
						juego.colorTurno = BLANCO;
						juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
						esExisteMov = VERDADERO;
						break;
					}

				} else if (numMinijuegoActual==23) {

					BOOLEANO esJaque;

					if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
					{

						hacerMovimiento(juego.Buffer_MOV[i]);

						if (juego.colorTurno)
						{
							esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
						} else {
							esJaque = esAtacadoPor(juego.tablero[NEGRO][REY], BLANCO);
						}

						if (esJaque)
						{
							desHacerMovimiento(juego.Buffer_MOV[i]);

						} else {

							juego.colorTurno = BLANCO;
							juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
							esExisteMov = VERDADERO;
							break;
						}
					}
				}
			}

			if (esExisteMov)
			{
				if ((numMinijuegoActual!=14) /*&& (numMinijuegoActual!=21) && 
					(numMinijuegoActual!=22) && (numMinijuegoActual!=23)*/)
					printf("OK ");
	
				if (numMinijuegoActual==23)
				{
					if (ES_MOV_ENROQUE(movHecho))
					{
						if (ES_MOV_OO(movHecho))
						{
							printf("O-O");

						} else {

							printf("O-O-O");
						}
					} 
				}
		
				if (avisarUltimaCaptura)
				{
					if (!NTOTAL_PIEZAS_NEGRAS_SR_SP)
					{
						printf("# ");
					}
					if (!NTOTAL_PIEZAS_NEGRAS_SR)
					{
						printf("# ");
					}
				}
				printf("\n");
				monedasTablero[pos2] = 0;
			 } else
				printf("COD902\n");
			
			continue;
		}

		if (!strcmp(buffComandos, "GON"))
		{
			juego.colorTurno = NEGRO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			tipoDeBusqueda = TIPO_BUSQUEDA_NORMAL;
			MOVIMIENTO m = pensarRapido();
			if (m)
			{
				hacerMovimiento(m);
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				printf("move "); imprimirMovimiento(m);
				statusFinJuego = obtEstadoJuego();
				mostrarMensajeFinalJuego();
				if (STATUS_FIN_JUEGO_NO_TERMINADO && (statusFinJuego==STATUS_FIN_JUEGO_JAQUE))
					printf("+");

				printf("\n");

			} else {
				printf("COD931\n");
			}
			
			continue;
		}

		if (!strcmp(buffComandos, "FIN"))
		{
			printf("OK\n");
			return;
		}

		if (!strcmp(buffComandos, "AUC"))
		{
			int n=0;
			sscanf(linea, "AUC %d", &n);
			avisarUltimaCaptura = (n>0?VERDADERO:FALSO);
			printf("AUC=[%s]\n",(avisarUltimaCaptura?"ON":"OFF"));
			continue;
		}

		if (!strcmp(buffComandos, "VER"))
		{
			printf("Protocolo XMM Versión 1.0 con Poderes de Super Vaca [:-)>\n");
			continue;
		}

		if (!strcmp(buffComandos, "FEN"))
		{
			char fen[100];
			memset(fen,'\0', 100);
			converTabler2FEN(fen);
			parseFEN2FENW(fen);
			parseFENW2FENWS(posSalida,fen);
			printf("%s\n",fen);
			continue;
		}

		if (!strcmp(buffComandos, "BLA"))
		{
			juego.colorTurno = BLANCO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			printf("OK\n");
			continue;
		}

		if (!strcmp(buffComandos, "TUR"))
		{
			if (juego.colorTurno)
				printf("NGR\n");
			else
				printf("BLA\n");
			continue;
		}

		if (!strcmp(buffComandos, "NGR"))
		{
			juego.colorTurno = NEGRO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			printf("OK\n");
			continue;
		}

		if (!strcmp(buffComandos, "CTR"))
		{
			juego.colorTurno = (juego.colorTurno?BLANCO:NEGRO);
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

			printf("OK\n");
			continue;
		}

		if (!strcmp(buffComandos, "PIN"))
		{
			int n=0;
			sscanf(linea, "PIN %d", &n);
			printf("PON %d\n",n);
			continue;
		}


		if (!strcmp(buffComandos, "CFN"))
		{
			char fen[100];
			char fencolor[2];     
			char fenEnroque[5];
			char fenPeonPaso[3];
			int fenReglaCincuentaMov=0;
			int fenTotalMov=0;

			sscanf(linea, "CFN %s %s %s %s %d %d",
						fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov);

			setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);
			printf("OK\n");
			continue;
		}

		printf("COD905\n\tComando desconocido, Escriba \'AYUDA\' para mayor información\n");
	}
//*/
}



//*/
#endif



