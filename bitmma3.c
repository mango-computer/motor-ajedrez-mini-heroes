/*
http://chessprogramming.wikispaces.com
http://chessprogramming.wikispaces.com/General+Setwise+Operations#TheLeastSignificantOneBitLS1B
http://chessprogramming.wikispaces.com/Classical+Approach
http://chessprogramming.wikispaces.com/Efficient+Generation+of+Sliding+Piece+Attacks


gcc -lm -o mangoPaola5 bitmma3.c -O0 -Wall -Wextra
i586-mingw32msvc-gcc -lm -o mangoPaola5.exe bitmma3.c -O0 -Wall -Wextra
*/

/*
	flag del movimiento (orden de los bits y significado) basado en los estandares de juegos de ajedrez

	6: Escaque origen del movimiento
	6: Escaque destino del movimiento
	4: Pieza origen
	4: Pieza capturada
	4: Pieza Coronada
	4: codigo movimiento

	Total Bytes 28 de (uint32)

	Tabla de codigo movimientos

	cod	promocion	captura		especial 1	especial 0		tipo mov
	0	0		0		0		0			Movimiento Tranquilo
	1	0		0		0		1			Salida Doble Peon
	2	0		0		1		0			Enroque Corto oo
	3	0		0		1		1			Enroque Largo ooo
	4	0		1		0		0			Captura		
	5	0		1		0		1			Captura Peon al Paso
	8	1		0		0		0			Promocion Caballo
	9	1		0		0		1			Promocion Alfil
	10	1		0		1		0 			Promocion Torre
	11	1		0		1		1			Promocion Dama
	12	1		1		0		0			Promocion/Captura Caballo
	13	1		1		0		1			Promocion/Captura Alfil
	14	1		1		1		0			Promocion/Captura Torre
	15	1		1		1		1			Promocion/Captura Dama

	Movimientos Tranquilos:
	Son todos los movimientos que no alteren material, por lo que no capta ni promociones.
	También se puede excluir a los movimientos que presentan amenazas inminentes, tales como comprobar.


	Notas:

	printf("%#llxull\n",b);

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <ctype.h>
//#include <termios.h> 
#include <unistd.h>
#include <time.h>

#if defined (_WIN32) || defined(_WIN64)
    #ifndef WINDOWS
        #define WINDOWS
    #endif
    #include <windows.h>	//bioskey()
#endif


#include "macros.h"
#include "tipoDatos.h"
#include "data.h"
#include "prototipos.h"
#include "variables.h"
#include "operacionesBit.c"
#include "busquedad.c"
#include "busquedadTranquilidad.c"
#include "debug.c"
#include "fen.c"
#include "ataque.c"
#include "ajedrez.c"
#include "ini.c"
#include "xmm.c"
#include "comandos.c"
#include "tiempo.c"
#include "perft.c"
#include "fevaluacion.c"
#include "ordenar.c"
#include "util.c"
#include "hash.c"
#include "eet.c"
#include "libro2.c"

#ifdef COMPILAR_CON_EGBB
	#include "egbb.c"
#endif

int main(__attribute__ ((unused)) int np, __attribute__ ((unused)) char* param[])
{
/*
	int resComp  = 1;
	BOOLEANO resComp2 = FALSO;
	int enigma = 1;
	BOOLEANO esValido = FALSO;
//*/	
/*
struct tm
{
        int     tm_sec;          Seconds: 0-59 (K&R says 0-61?) 
        int     tm_min;          Minutes: 0-59 
        int     tm_hour;         Hours since midnight: 0-23 
        int     tm_mday;         Day of the month: 1-31 
        int     tm_mon;          Months *since* january: 0-11 
        int     tm_year;         Years since 1900 
        int     tm_wday;         Days since Sunday (0-6) 
        int     tm_yday;         Days since Jan. 1: 0-365 
        int     tm_isdst;        +1 Daylight Savings Time, 0 No DST,
                                 -1 don't know 
};
//*/

/*
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
//	printf("%d %d %d\n",tlocal->tm_year,tlocal->tm_mon,tlocal->tm_mday);

	if (tlocal->tm_year==116 && ((tlocal->tm_mon < 10) || (tlocal->tm_mon == 10 && tlocal->tm_mday < 5)))
	{
		esValido = VERDADERO;
	} else {

		if (np==3)
		{
			resComp = strncmp(param[1],movilidadDDama,72);
			enigma = 
			(tlocal->tm_year * 1098) + ((tlocal->tm_mon+1) * 765) + (tlocal->tm_mday*432) + (tlocal->tm_hour*1010);
			resComp2 = (atoi(param[2]) == enigma);

		}

		esValido= ((np==3) && !resComp && resComp2);
	} 
	
	if (!esValido)
	{
		printf("\nEste programa ha sido Hackeado, para poder continuar usandolo pongase en contacto con el Hacker...\n");
		printf("This program has been hacked, to continue using it please contact the Hacker...\n");
		printf("Dieses Programm wurde gehackt, um weiterhin die Hacker verwenden sie bitte an...\n");
		printf("Ce programme a été piraté, continuer à l'utiliser s'il vous plaît contacter le Hacker...\n");
		printf("Eta programma byla vzlomana, chtoby prodolzhat' ispol'zovat' yego, pozhaluysta, svyazhites' s Hacker...\n");
		printf("Zhè yī fāng'àn yǐjīng bèi hēikè rùqīn, jìxù shǐyòng tā, qǐng liánxì hēikè...\n");
		printf("Constans est caedere, ut in usus commodo Piratica...\n");
		printf("\nmangocomputer@gmail.com\n\n");

		exit(0);
	}
//*/
//************************************************************************************************************
	printf("#\n");
	printf("#	**************************************************\n");
	printf("#	*						 *\n");
	printf("#	*               MANGO PAOLA AJEDREZ      	 *\n");
	printf("#	*						 *\n");
	printf("#	* Programado por: José Andrés Morales Linares    *\n");
	printf("#	* Versión:        5.0                            *\n");
	printf("#	* Año:            2016                           *\n");
	printf("#	* Licencia:       GPLv3                          *\n");
	printf("#	* Contácto:       comprasmangocomputer@gmail.com *\n");
	printf("#	* Protocolos:     xboard, XMM                    *\n");
	printf("#	*						 *\n");
	printf("#	**************************************************\n#\n");



	LARGO_TABLA_HASH 	= LARGO_TABLA_HASH_LLAVE_22BIT;
	esUsoTablaHash		= VERDADERO;
	usarLibroAperturas 	= VERDADERO;


	FILE *mangopaolaINI = fopen("mangopaola.ini", "r");

	if (mangopaolaINI)
	{
		//Leer variables de mangopaola.ini
		char lineaINI[512];

		fseek(mangopaolaINI, 0, SEEK_SET);
		while (fgets(lineaINI, 512, mangopaolaINI)) 
		{
			if (lineaINI[0] != '#' && lineaINI[0] != ' ' && lineaINI[0] != 13 && lineaINI[0] != 10)
			{	

				if (!strncmp(lineaINI, "UsarTablaHash",13))
				{
					int u=0;
					sscanf(lineaINI, "UsarTablaHash %d", &u);
					esUsoTablaHash = ((u)?VERDADERO:FALSO);
					printf("#UsarTablaHash %d\n",esUsoTablaHash);

				} else if (!strncmp(lineaINI, "TamanioTablaHash",16)) {
					int t=0;
					sscanf(lineaINI, "TamanioTablaHash %d", &t);
		
					switch(t)
					{
						case 1: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_18BIT;break;
						case 2: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_19BIT;break;
						case 3: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_20BIT;break;
						case 4: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_21BIT;break;
						case 5: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_22BIT;break;
						case 6: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_23BIT;break;
						case 7: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_24BIT;break;
						case 8: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_25BIT;break;
						case 9: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_26BIT;break;
						default: LARGO_TABLA_HASH = LARGO_TABLA_HASH_LLAVE_22BIT;break;
					};

				} else if (!strncmp(lineaINI, "UsarLibroAperturas",18)) {
					int u=0;
					sscanf(lineaINI, "UsarLibroAperturas %d", &u);
					usarLibroAperturas = ((u) ? VERDADERO:FALSO);
					printf("#UsarLibroAperturas %d\n",usarLibroAperturas);

				} else if (!strncmp(lineaINI, "RutaRandom1",11)) {
					memset(rutaRandom1,'\0',512);
					sscanf(lineaINI, "RutaRandom1 %s", rutaRandom1);

				} else if (!strncmp(lineaINI, "RutaRandom2",11)) {
					memset(rutaRandom2,'\0',512);
					sscanf(lineaINI, "RutaRandom2 %s", rutaRandom2);

				} else if (!strncmp(lineaINI, "RutaMainBook",12)) {
					memset(rutaMainBook,'\0',512);
					sscanf(lineaINI, "RutaMainBook %s", rutaMainBook);

				} else if (!strncmp(lineaINI, "RutaTourBook",12)) {
					memset(rutaTourBook,'\0',512);
					sscanf(lineaINI, "RutaTourBook %s", rutaTourBook);
#ifdef COMPILAR_CON_EGBB
				} else if (!strncmp(lineaINI, "UsarTablaFinalesNalimov",23)) {
					int u=0;
					sscanf(lineaINI, "UsarTablaFinalesNalimov %d", &u);
					usar_egbb = ((u)?VERDADERO:FALSO);
					printf("#UsarTablaFinalesNalimov %d\n",usar_egbb);

				} else if (!strncmp(lineaINI, "RutaEGBB",8)) {
					memset(rutaEGBB,'\0',512);
					sscanf(lineaINI, "RutaEGBB %s", rutaEGBB);

				} else if (!strncmp(lineaINI, "CacheEGBB",9)) {
					egbb_cache_size = 64;
					sscanf(lineaINI, "CacheEGBB %d", &egbb_cache_size);
					if (egbb_cache_size < 1 || egbb_cache_size > 512) egbb_cache_size = 64;
#endif
 				}
			}
		}

		fclose(mangopaolaINI);
	}

	iniMatrizMov();
	iniMatrizSeguridadRey();
	iniCarreraPeonesMask();
	iniPeonEscondido();
	iniPeonCC();
	ini_is_outside();
	inicializarTablero();
	inicializarVar();
	iniTablerosUtil();
	actualizarTablerosUtil(BLANCO);
	iniciarHash();
	iniHashTablero();
	juego.Buffer_MOV_INDEXCAPAS[1] = generarTodosMov(0);
	if (usarLibroAperturas)
		abrirLibro2();
#ifdef COMPILAR_CON_EGBB
	if (usar_egbb)
		cargaBitbases();
#endif
	printf("# Escriba \"ayuda\" y presione la tecla <Enter>\n");
	leerComandos();

	exit(0);
}

