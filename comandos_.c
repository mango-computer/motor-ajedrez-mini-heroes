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
		printf("ata n			: Devuelve un mapa de bit de todos los atacantes en el escaque dado\n");
		printf("blanco			: Blanco mueve\n");
		printf("cc			: Jugar computadora vs computadora\n");
//		printf("configuracion		: Configura el tablero\n");
		printf("dale			: Juega la computadora\n");
		printf("d			: Mostrar Tablero\n");
		printf("eval			: Muestra evaluacion estatica de esta posición\n");
		printf("g			: Gira el tablero\n");
		printf("i			: Muestra el valor de las variables\n");
		printf("info			: Muestra el valor de las variables\n");
		printf("juego			: Muestra los movimientos del juego\n");
		printf("leerfen nombreArchivo n	: Lee el numero de lineaa de un archivo FEN\n");
		printf("librono			: Des-habilita el uso de diccionario o libro de aperturas\n");
		printf("librosi			: Habilita el uso de diccionario o libro de aperturas\n");
		printf("movimientos		: Muestra todos los movimientos legales\n");
		printf("negro			: Negro mueve\n");
		printf("nuevo			: Inicia un nuevo juego\n");
		printf("regresar		: Devuelve el ultimo movimiento\n");
		printf("r			: Gira el tablero\n");
		printf("sd n			: Establece la profundidad de busquedad en n*2\n");
		printf("t			: Mostrar Tablero\n");
		printf("u			: Devuelve el ultimo movimiento\n");
		printf("ver blancos		: Muestra el bitmap de los blancos\n");
		printf("ver destinos blancos	: Muestra el bitmap de los destinos blancos\n");
		printf("ver destinos negros	: Muestra el bitmap de los destinos negros\n");
		printf("ver			: Muestra la versión y autor del motor de ajedrez\n");
		printf("ver negros		: Muestra el bitmap de los negros\n");
		printf("ver ocupados		: Muestra el bitmap de ocupados\n");
		printf("ver peones blancos	: Muestra el bitmap de los peones blancos\n");
		printf("ver peons negros	: Muestra el bitmap de los peones negros\n");
		printf("ver todos mov		: Muestra todos los movimientos generados sin validar\n");
		printf("xboard			: Inicia el Modo Xboard\n");
		printf("XMM			: Inicia el Modo XMM\n");


		printf("\n******* Help *******\n");
		printf("ata n			: Devuelve un mapa de bit de todos los atacantes en el escaque dado\n");
		printf("black			: Negro mueve\n");
		printf("cc			: Jugar computadora vs computadora\n");
		printf("d			: Mostrar Tablero\n");
		printf("eval			: Muestra evaluacion estatica de esta posición\n");
		printf("exit			: Salir del Juego\n");
		printf("game			: Muestra los movimientos del juego\n");
		printf("g			: Gira el tablero\n");
		printf("go			: Juega la computadora\n");
		printf("i			: Muestra el valor de las variables\n");
		printf("info			: Muestra el valor de las variables\n");
		printf("move e2e4		: Introduce un movimiento (use este formato)\n");
		printf("moves			: Muestra todos los movimientos legales\n");
		printf("new			: Inicia un nuevo juego\n");
		printf("perft n			: Calcula el numero de nodos en bruto, con profundida n\n");
		printf("perft			: punto de referencia un número de funciones clave\n");
		printf("quit			: Salir del programa\n");
		printf("readfen nombreArchivo n	: Lee el numero de lineaa de un archivo FEN\n");
		printf("r			: Gira el tablero\n");
		printf("sd n			: Establece la profundidad de busquedad en n*2\n");
		printf("setup			: Configura el tablero\n");
		printf("t			: Mostrar Tablero\n");
		printf("u			: Devuelve el ultimo movimiento\n");
		printf("undo			: Devuelve el ultimo movimiento\n");
		printf("white			: Blanco mueve\n");
		printf("xboard			: Inicia el Modo Xboard\n");
		printf("XMM			: Inicia el Modo XMM\n");


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

	if ((!strcmp(buff, "eval")))
	{
		CONT_BUFF_COMANDOS = '\0';
		int resulEval = evaluacionTablero(-INFINITO,INFINITO);
		printf("Evaluación Estatica del Tablero Actual\nEval:	%d\n",resulEval);
		return VERDADERO;    
	}
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
		mostrarMensajeFinalJuego();

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

		mostrarMensajeFinalJuego();
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

				printf("result 1-0 {White mates}\n");

			} else if (statusFinJuego == STATUS_FIN_JUEGO_MATE_GANAN_N){

				printf("result 0-1 {Black mates}\n");

			} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS_REPETICION) {

				printf("result 1/2-1/2 {Draw by repetition}\n");

			} else if (statusFinJuego == STATUS_FIN_JUEGO_TABLAS_INSUFI_MATERIAL) {

				printf("result 1/2-1/2 {Draw by insufficient material}\n");
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
	int i=0;
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

void verMovimentosTodos()
{
	int i=0;

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
	int i=0;

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
	printf("Ori=%d, Des=%d, Pieza=%d, Captura=%d, Promocion=%d, cod=%d, EET=%d\n", 
		OBT_MOV_ORIGEN(mov),  OBT_MOV_DESTINO(mov),   OBT_MOV_PIEZA(mov),
		OBT_MOV_CAPTURA(mov), OBT_MOV_PROMOCION(mov), OBT_MOV_CODIGO(mov), EET(mov));
	 
}

void verMov2(MOVIMIENTO mov)
{
	printf("%d-%d\n",OBT_MOV_ORIGEN(mov),OBT_MOV_DESTINO(mov));
 
}

void nuevo_juego()
{
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
	int inc = 0;
	int mps = 0;
	BOOLEANO esPermitirPonder = FALSO;

	computadora = NEGRO;
	char linea[256], buffComandos[256];
	MOVIMIENTO m, ponder_mov=0;
	BOOLEANO esJaque;	
	esPost = VERDADERO;
	BOOLEANO esPonder=FALSO;
	printf("\n");

	nuevo_juego();
	computadora = NEGRO;

	for (;;) 
	{
		if (juego.colorTurno == computadora) {

			tipoDeBusqueda = TIPO_BUSQUEDA_NORMAL;
			m = pensarRapido();
			if (!m) continue; 
			hacerMovimiento(m);
			printf("move "); imprimirMovimiento(m);printf("\n");
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			statusFinJuego = obtEstadoJuego();
			mostrarMensajeFinalJuego();
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

		if (!fgets(linea, 256, stdin))
			return;
		if (linea[0] == '\n')
			continue;
		sscanf(linea, "%s", buffComandos);
		if (!strcmp(buffComandos, "xboard"))
		{
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
			sscanf(buffComandos, "sd %d", &juego.profundidadBusquedad);
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
		if (!strcmp(buffComandos, "go"))
		{
			computadora = juego.colorTurno;
			continue;
		}
		if (!strcmp(buffComandos, "protover"))
		{
			printf("feature setboard=0 analyze=0 ping=1 colors=0 draw=0 sigint=0 sigterm=0"
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

			sscanf(linea, "setboard %s %s %s %s %d %d",
						fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov);
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

			setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);
			continue;
		}


		if (!strcmp(buffComandos, "hint"))
		{
			m = pensarRapido();
			if (!m) continue; 
			printf("Hint: ");
			imprimirMovimiento(m);printf("\n");
			continue;
		}
		if (!strcmp(buffComandos, "undo"))
		{
			if (juego.indiceHJuego > 0)
			{
				desHacerMovimiento(juego.historicoJuego[juego.indiceHJuego-1].mov);
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
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
			int n;
			sscanf(linea, "ping %d", &n);
			printf("pong %d\n",n);
			continue;
		}

		if (!strcmp(buffComandos, "random"))
		{
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
		if (m == -1)
			printf("Illegal move: %s\n", buffComandos);
		else {
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
	int i = 0;
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

	return -1;
}

BOOLEANO esMovimentoLegal(MOVIMIENTO m)
{
	int i=0;
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

void xmm()
{
	char linea[256], buffComandos[256];
	int numMinijuegoActual = -1;
	printf("%sOK 1.0\n",NPROM);

	time_t now;
	srand((unsigned int)time(&now));

	nuevo_juego();
	computadora = NEGRO;

	for (;;) 
	{
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
				mostrarAyuda("MJN - Mini Juego Nuevo.","MJN nn",
					"Inicia el Mini Juego número (nn) con posiciones aleatorias. Los valores devueltos dependerán del Mini Juego iniciado.",
					"nn",
					"Número del Mini Juego.");
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
				mostrarAyuda("CFN - Cambiar Tablero Según Cadena Fen.","CFN cadena-fen",
					"Cambia el fen interno del motor a el fen establecido en cadena-fen sin cambiar el número del Mini Juego.",
					"cadena-fen",
					"Una cadena fen. Ej. PP4PP/2P2PP1/1P2P3/PPb5/P7/6PP/2P1r3/PPP2P1K w");
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


			if (!strcmp(comando, "EAP"))
			{
				mostrarAyuda("EAP - Escaques Amenazados por la Pieza.","EAP pos",
					"Devuelve los escaques amenazados (Movilidad) por la pieza ubicada en pos, no devuelve los escaques que sean capturas.",
					"pos",
					"pos es una posición en el tablero en el rango 0 - 63");
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

			if (!strcmp(comando, "GMR"))
			{
				mostrarAyuda("GMR - Genera Movimiento Ramdon o Aleatorio.","GMR",
					"Genera un movimiento aleatorio entre las piezas enemigas seleccionada tambien aleatoriamente.",
					"",
					"");
				continue;
			}

			if (!strcmp(comando, "GMV"))
			{
				mostrarAyuda("GMV - Genera Movimiento Ramdon o Aleatorio de una Posición.","GMR pos",
					"Genera un movimiento aleatorio de una pieza enemiga ubicada en la posición indicada en pos.",
					"pos",
					"pos es una posición en el tablero en el rango [0 - 63]");
				continue;
			}

			if (!strcmp(comando, "MJF"))
			{
				mostrarAyuda("MJF - Iniciar Mini Juego Según Cadena Fen.","MJF nn cadena-fen",
					"Inicia el Mini Juego número nn con la cadena fen.",
					"nn\tNúmero del Mini Juego.\n",
					" cadena-fen\tUna cadena fen. Ej. PP4PP/2P2PP1/1P2P3/PPb5/P7/6PP/2P1r3/PPP2P1K w");
				continue;
			}

			if (!strcmp(comando, "MJN"))
			{
				mostrarAyuda("MJN - Iniciar Mini Juego.","MJN nn",
					"Inicia el Mini Juego número nn con posiciones aleatorias generadas por el motor.",
					"nn",
					"Número del Mini Juego.");
				continue;
			}

			if (!strcmp(comando, "MOV"))
			{
				mostrarAyuda("MOV - Realiza Movimiento de Pieza.","MOV pos1 pos2",
					"Realiza el movimiento de la pieza ubicada en pos1 hasta la pos2 en caso de ser valido.",
					"pos1\tPosición Inicial en el tablero en el rango 0 - 63.\n",
					" pos2\tPosición Inicial en el tablero en el rango 0 - 63.");
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

			if (!strcmp(comando, "T"))
			{
				mostrarAyuda("T - Muestra el Tablero.","T",
					"Muestra el tablero en formato ascii.",
					"",
					"");
				continue;
			}


			if (!strcmp(comando, "NMJ"))
			{
				mostrarAyuda("NMJ - Número del Mini Juego Actual.","NMJ",
					"Devuelve el Número del Mini Juego Actual o -1 Si No Hay Mini Juego Seleccionado.",
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

			if (!strcmp(comando, "CPR"))
			{
				mostrarAyuda("CPR - Coloca una Pieza en el Tablero de Forma Aleatoria o Random.","CPR PIEZA",
					"El motor Mango Paola coloca en el tablero de forma aleatoria o random la pieza indicada en el parametro del comando\n\t validando que el tablero no quede en jaque.",
					"PIEZA",
					"[DN]Dama Negra  [TN]Torre Negra  [AN]Alfil Negro  [CN]Caballo Negro  [PN]Peon Negro\n\t\t[DB]Dama Blanca [TB]Torre Blanca [AB]Alfil Blanca [CB]Caballo Blanca [PB]Peon Blanca");
				continue;
			}

			if (!strcmp(comando, "QPR"))
			{
				mostrarAyuda("CPR - Quita una Pieza del Tablero de Forma Aleatoria o Random.","QPR COLOR",
					"El motor Mango Paola quita del tablero de forma aleatoria o random una pieza del color indicado en el parametro del comando\n\t validando que el tablero no quede en jaque.",
					"COLOR",
					"[BLANCO] [NEGRO]");
				continue;
			}
			printf("%s[%s] No se reconoce como un comando\n",NPROM,comando);
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
			int num=0;

			sscanf(linea, "MJF %d %s %s %s %s %d %d", &num,
						fen,fencolor,fenEnroque,fenPeonPaso,&fenReglaCincuentaMov,&fenTotalMov);
			
			if ((num==1) || (num==2) || (num==3) || (num==4))
			{
				setupFen(fen, fencolor, fenEnroque, fenPeonPaso, fenReglaCincuentaMov, fenTotalMov);
				numMinijuegoActual = num;
				printf("%sOK\n",NPROM);
			} else {
				printf("%sCOD901\n",NPROM);
			}
			continue;
		}

		if (!strcmp(buffComandos, "MJN"))
		{
			int num=0;
			sscanf(linea,"MJN %d", &num);
			if (num==1)
			{
				iniMiniJuego1();
				numMinijuegoActual = num;

			} else if (num==2) {
			
				iniMiniJuego2();
				numMinijuegoActual = num;

			} else if (num==3) {
			
				iniMiniJuego2();
				numMinijuegoActual = num;

			} else if (num==4) {
			
				iniMiniJuego4();
				numMinijuegoActual = num;

			} else {
				printf("%sCOD901\n",NPROM);	
			}
			continue;
		}

		if (!strcmp(buffComandos, "T"))
		{
			mostrarTablero();
			continue;
		}

		if (!strcmp(buffComandos, "NMJ"))
		{
			printf("%s%d\n",NPROM,numMinijuegoActual);
			continue;
		}

		if (!strcmp(buffComandos, "QPR"))
		{
			char ccolor[100];
			int posCol = SIN_POS_VALIDA;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("%sCOD910\n",NPROM);
				continue;
			}
			
			memset(ccolor,0,sizeof(ccolor));
			sscanf(linea, "QPR %s", ccolor);
			
			if (!strcmp(ccolor, "BLANCO"))
			{
				if (quitarPiezaPosRandom(BLANCO, &posCol))
				{
					printf("%s%d\n",NPROM, posCol);

				} else {

					printf("%sCOD912\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ccolor, "NEGRO"))
			{
				if (quitarPiezaPosRandom(NEGRO, &posCol))
				{
					printf("%d\n", posCol);

				} else {

					printf("%sCOD912\n",NPROM);
				}
				continue;
			} 

			printf("%sCOD913\n",NPROM);
			continue;
		}

		if (!strcmp(buffComandos, "CPR"))
		{
			char ppieza[100];
			int posCol = SIN_POS_VALIDA;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("%sCOD910\n",NPROM);
				continue;
			}
			
			memset(ppieza,0,sizeof(ppieza));
			sscanf(linea, "CPR %s", ppieza);
			
			if (!strcmp(ppieza, "PN"))
			{
				if (agregarPiezaPosRandom(PEON_NEGRO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ppieza, "DN"))
			{
				if (agregarPiezaPosRandom(DAMA_NEGRO, &posCol))
				{
					printf("%s%d\n",NPROM, posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}

				continue;
			} 

			if (!strcmp(ppieza, "CN"))
			{
				if (agregarPiezaPosRandom(CABALLO_NEGRO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ppieza, "AN"))
			{
				if (agregarPiezaPosRandom(ALFIL_NEGRO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ppieza, "TN")) 
			{
				if (agregarPiezaPosRandom(TORRE_NEGRO, &posCol))
				{
					printf("%s%d\n",NPROM, posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

		// PIEZAS BLANCAS CPR *************************************************
			if (!strcmp(ppieza, "PB"))
			{
				if (agregarPiezaPosRandom(PEON_BLANCO, &posCol))
				{
					printf("%s%d\n",NPROM, posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ppieza, "DB"))
			{
				if (agregarPiezaPosRandom(DAMA_BLANCO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}

				continue;
			} 

			if (!strcmp(ppieza, "CB"))
			{
				if (agregarPiezaPosRandom(CABALLO_BLANCO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ppieza, "AB"))
			{
				if (agregarPiezaPosRandom(ALFIL_BLANCO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			if (!strcmp(ppieza, "TB")) 
			{
				if (agregarPiezaPosRandom(TORRE_BLANCO, &posCol))
				{
					printf("%s%d\n", NPROM,posCol);

				} else {

					printf("%sCOD911\n",NPROM);
				}
				continue;
			} 

			printf("%sCOD911\n",NPROM);
			continue;
		}


		if (!strcmp(buffComandos, "EAP")) //Escaques Amenazados Pieza
		{
			int i=0;
			int pos=0;
			int cMov=0;
			uint64 listaMov[28];

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("%sCOD910\n",NPROM);
				continue;
			}

			sscanf(linea, "EAP %d",&pos);

			if (!ES_RANGO_POS_VALIDA(pos))
			{
				printf("%sCOD906\n",NPROM);
				continue;
			}

			if (ES_POS_VACIO(pos))
			{
				printf("%sCOD908\n",NPROM);
				continue;
			}

			if (OBT_COLOR_PIEZA(ESCAQUES[pos])==BLANCO)
			{
				printf("%sCOD907\n",NPROM);
				continue;
			}

			juego.colorTurno = NEGRO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

			if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
			{
				juego.colorTurno = BLANCO;
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				printf("%sCOD903\n",NPROM);
				continue;
			}

			memset(listaMov,0,sizeof(listaMov));
			for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
			{
				if (OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos && !ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
				{
					listaMov[cMov++] = juego.Buffer_MOV[i];
				}
			}

			if (cMov)
			{
				for (i=0;i<cMov;i++)
				{
					printf("%s%d ",NPROM,(int)OBT_MOV_DESTINO(listaMov[i]));
				}
				printf("\n");
				juego.colorTurno = BLANCO;
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				continue;
			}

			juego.colorTurno = BLANCO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			printf("%sCOD903\n", NPROM);
			continue;
		}


		if (!strcmp(buffComandos, "GMR"))
		{
			int cMov=0;
			int i=0;
			BOOLEANO esJaque = FALSO;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("%sCOD910\n",NPROM);
				continue;
			}

			uint64 listaMov[280];
			memset(listaMov,0,sizeof(listaMov));

			juego.colorTurno = NEGRO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

			if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
			{
				juego.colorTurno = BLANCO;
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				printf("%sCOD903\n",NPROM);
				continue;
			}

			for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
			{
				if (!ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
				{
					hacerMovimiento(juego.Buffer_MOV[i]);
					esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
					desHacerMovimiento(juego.Buffer_MOV[i]);

					if (!esJaque)
					{
						listaMov[cMov++] = juego.Buffer_MOV[i];
					} 
				}
			}

			if (cMov)
			{
				int index = rand()%cMov; 
				hacerMovimiento(listaMov[index]);
				juego.colorTurno = BLANCO;
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				printf("%s%d %d\n",NPROM,(int)OBT_MOV_ORIGEN(listaMov[index]),(int)OBT_MOV_DESTINO(listaMov[index]));
				continue;
			}

			juego.colorTurno = BLANCO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			printf("%sCOD900\n",NPROM);
			continue;
		}

		if (!strcmp(buffComandos, "GMV"))
		{
			int pos=0;
			int cMov=0;
			int i=0;
			BOOLEANO esJaque = FALSO;

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("%sCOD910\n",NPROM);
				continue;
			}

			uint64 listaMov[28];
			memset(listaMov,0,sizeof(listaMov));

			sscanf(linea, "GMV %d",&pos);

			if (!ES_RANGO_POS_VALIDA(pos))
			{
				printf("%sCOD906\n",NPROM);
				continue;
			}

			if (ES_POS_VACIO(pos))
			{
				printf("%sCOD908\n",NPROM);
				continue;
			}

			if (OBT_COLOR_PIEZA(ESCAQUES[pos])==BLANCO)
			{
				printf("%sCOD907\n",NPROM);
				continue;
			}

			juego.colorTurno = NEGRO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);

			if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
			{
				juego.colorTurno = BLANCO;
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				printf("%sCOD903\n",NPROM);
				continue;
			}

			for (i=juego.Buffer_MOV_INDEXCAPAS[0];i<juego.Buffer_MOV_INDEXCAPAS[1];i++)
			{
				if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos) && !ES_MOV_CAPTURA(juego.Buffer_MOV[i]))
				{
					hacerMovimiento(juego.Buffer_MOV[i]);
					esJaque = esAtacadoPor(juego.tablero[BLANCO][REY], NEGRO);
					desHacerMovimiento(juego.Buffer_MOV[i]);

					if (!esJaque)
					{
						listaMov[cMov++] = juego.Buffer_MOV[i];
					} 
				}
			}

			if (cMov)
			{
				int index = rand()%cMov; 
				hacerMovimiento(listaMov[index]);
				juego.colorTurno = BLANCO;
				juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
				printf("%s%d\n",NPROM,(int)OBT_MOV_DESTINO(listaMov[index]));
				continue;
			}

			juego.colorTurno = BLANCO;
			juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
			printf("%sCOD900\n",NPROM);
			continue;
		}

		if (!strcmp(buffComandos, "MOV"))
		{

			if (!ES_ESTA_ON_MINIJUEGO(numMinijuegoActual))
			{
				printf("%sCOD910\n",NPROM);
				continue;
			}

			if (juego.Buffer_MOV_INDEXCAPAS[0] == juego.Buffer_MOV_INDEXCAPAS[1])
			{
				printf("%sCOD903\n",NPROM);
				continue;
			}

			int pos1 = SIN_POS_VALIDA;
			int pos2 = SIN_POS_VALIDA;
			int i=0;
			BOOLEANO esExisteMov = FALSO;

			sscanf(linea, "MOV %d %d",&pos1,&pos2);

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
							if (esMovimentoLegal(juego.Buffer_MOV[i]))
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								break;
							}
						}
					}
				
				} else if (numMinijuegoActual==3) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							if (esMovimentoLegal(juego.Buffer_MOV[i]))
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								break;
							}
						}
					}

				} else if (numMinijuegoActual==4) {

					if (OBT_MOV_PIEZA(juego.Buffer_MOV[i])==REY_BLANCO)
					{
						if ((OBT_MOV_ORIGEN(juego.Buffer_MOV[i])==pos1) &&
							(OBT_MOV_DESTINO(juego.Buffer_MOV[i])==pos2))
						{
							if (esMovimentoLegal(juego.Buffer_MOV[i]))
							{
								hacerMovimiento(juego.Buffer_MOV[i]);
								juego.colorTurno = BLANCO;
								juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
								esExisteMov = VERDADERO;
								break;
							}
						}
					}
				
				} 
			}

			if (esExisteMov)
				printf("%sOK\n",NPROM);
			else
				printf("%sCOD902\n",NPROM);
			
			continue;
		}

		if (!strcmp(buffComandos, "FIN"))
		{
			printf("%sOK\n",NPROM);
			return;
		}

		if (!strcmp(buffComandos, "FEN"))
		{
			char fen[100];
			memset(fen,'\0', 100);
			converTabler2FEN(fen);
			printf("%s%s\n",NPROM,fen);
			continue;
		}

		if (!strcmp(buffComandos, "BLA"))
		{
			juego.colorTurno = BLANCO;
			computadora = NEGRO;
			printf("%sOK\n",NPROM);
			continue;
		}

		if (!strcmp(buffComandos, "TUR"))
		{
			if (juego.colorTurno)
				printf("%sNGR\n",NPROM);
			else
				printf("%sBLA\n",NPROM);
			continue;
		}

		if (!strcmp(buffComandos, "NGR"))
		{
			juego.colorTurno = NEGRO;
			computadora = BLANCO;
			printf("%sOK\n",NPROM);
			continue;
		}

		if (!strcmp(buffComandos, "CTR"))
		{
			computadora = juego.colorTurno;
			juego.colorTurno = !juego.colorTurno;
			printf("%sOK\n",NPROM);
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
			printf("%sOK\n",NPROM);
			continue;
		}

		printf("%sCOD905\n",NPROM);

	}
//*/
}



//*/
#endif



