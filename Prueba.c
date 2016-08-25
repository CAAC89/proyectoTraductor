#include <stdio.h>
int validaCaracteresArab();		   //Todos son numeros arab
int validaCaracteresRomanos();	   //Todos los caracteres son Roman
int esNum(char c);				   //Revisa si caracter es arab
int esNumRomano(char c);		   //Revisa si caracter es romano
int valorDe(char c);			   //Da valor de Signo romano
void numeroAromano(int numero);	   //Convierte a Roman
int romanoAnumero(char numero[]);  //Convierte a arab

int main() {
//	int flag = 1;
//	while (flag) {
//		char _numero[10];
//		printf("-------------------------------\n");
//		printf("Por favor ingrese un numero: ");
//		scanf(" %s", &_numero);
//		if (validaCaracteresArab(_numero)) {
//			numeroAromano(_numero);
//		} else if (validaCaracteresRomanos(_numero)) {
//			printf("Equivale a: %d \n", romanoAnumero(_numero));
//		} else {
//			printf("Error de reconocimiento!!! \n");
//		}
//		//-------------------------------//
//		char _salir;
//		printf("Desea salir? (Y/N): ");
//		scanf(" %c", &_salir);
//		if (_salir == 'Y' || _salir == 'y') {
//			printf("Programa acabado");
//			flag = 0;
//		}
//	}


	printf("%d",revisaRomano("MDXLXVIII"));
}


int revisaRomano(char numero[]){
	int actual=0;
	int repeticiones=0;
	if(validaCaracteresRomanos(numero[])){
		while(numero[actual]!='\0'){
				if(repeticiones==4){
					return 0;
				}
				if(valorDe(numero[actual+1])<valorDe(numero[actual])){//Siguiente es menor que actual
					repeticiones=0;
					actual++;
				}else if(numero[actual+1]==numero[actual]){//Siguiente es igual al actual
					repeticiones++;
					actual++;
				}else if(valorDe(numero[actual+1])>valorDe(numero[actual])){//Siguiente es mayor que actual
					if (numero[actual]=='V'||numero[actual]=='L'||numero[actual]=='D'||repeticiones >= 1){
						return 0;
					}else{
						repeticiones=0;
						actual++;
					}
				}
			}
	}else{
		return 0;
	}
	return 1;

}


//pasar de numeros arabigos a romanos
void numeroAromano(int numero) {
	//arreglos que componen los numeros romanos en su unidad numeral
	char *millares[] = { "", "M", "MM", "MMM" };
	char *centenas[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC",
			"CM" };
	char *decenas[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX",
			"XC" };
	char *unidades[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII",
			"IX" };

	int m; //millares
	int c; //centenas
	int d; //decenas
	int u; //unidades

	int aux, aux2; //auxiliares

	m = numero / 1000;
	aux = numero % 1000;

	c = aux / 100;
	aux2 = aux % 100;

	d = aux2 / 10;

	u = aux2 % 10;

	printf("\nEl numero %d en romano es %s%s%s%s\n\n", numero, millares[m],
			centenas[c], decenas[d], unidades[u]);

}

//Retorna tamano de streing
int largo(char c[]) {
	int actual = 0;
	while (c[actual] != '\0') {
		actual++;
	}
	return actual;
}

//Se asume que entrada esta bien definida, 4000 no esta definido
//Retorna valor de numero romano
int romanoAnumero(char numero[]) {
	int actual = 0;
	int total = 0;
	while (numero[actual] != '\0') {
		if (numero[actual + 1] != '\0'
				&& (valorDe(numero[actual]) < valorDe(numero[actual + 1]))) //Hay un caracter siguiente que es mayor al actual (hay que restar)
				{
			total -= valorDe(numero[actual]);
			actual++;
		} else {
			total += valorDe(numero[actual]);
			actual++;
		}
	}
	return total;
}

//Devuelve el valor del caracter romano
int valorDe(char c) {
	if (c == 'I')
		return 1;
	if (c == 'V')
		return 5;
	if (c == 'X')
		return 10;
	if (c == 'L')
		return 50;
	if (c == 'C')
		return 100;
	if (c == 'D')
		return 500;
	if (c == 'M')
		return 1000;
	return 0;
}

//Validan que todos los caracteres del "String" sean correctos
int validaCaracteresArab(char numero[]) {
	int actual = 0;
	while (numero[actual] != '\0') {
		if (!esNum(numero[actual])) {
			return 0;
		}
		actual++;
	}
	return 1;
}
int validaCaracteresRomanos(char numero[]) {
	int actual = 0;
	while (numero[actual] != '\0') {
		if (!esNumRomano(numero[actual])) {
			return 0;
		}
		actual++;
	}
	return 1;
}

//Reciben un caracter. Devuelve 1 si es numero o 0 si no
int esNum(char c) {
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6'
			|| c == '7' || c == '8' || c == '9' || c == '0') {
		return 1;
	} else {
		return 0;
	}
}
int esNumRomano(char c) {
	if (c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D'
			|| c == 'M') {
		return 1;
	} else {
		return 0;
	}
}

//Devuelve la cantidad de numeros que tiene un numero
int cantidadNumeros(int numero) {
	int cantidad = 1;
	if (numero < 0) {
		return 0;
	}
	if (numero < 10) {
		return 1;
	}
	while ((numero / 10) >= 1) {
		cantidad++;
		numero = numero / 10;
	}
	return cantidad;
}

/*

 *    Como regla general, los símbolos se escriben y leen de izquierda a derecha, de mayor a menor valor.
 *    El valor de un número se obtiene sumando los valores de los símbolos que lo componen, salvo en la siguiente excepción.
 *    Si un símbolo está a la izquierda inmediata de otro de mayor valor, se resta al valor del segundo el valor del primero (p.e. IV=4, IX=9).
 *    Los símbolos de tipo 5 siempre suman y no pueden estar a la izquierda de uno de mayor valor.
 *    Se permiten a lo sumo tres repeticiones consecutivas del mismo símbolo de tipo 1.
 *    No se permite la repetición de una misma letra de tipo 5; su duplicado es una letra de tipo 10.
 *    Si un símbolo de tipo 1 aparece restando, sólo puede aparecer a su derecha un sólo símbolo de mayor valor.
 *    Si un símbolo de tipo 1 que aparece restando se repite, sólo se permite que su repetición esté colocada a su derecha y que no sea adyacente al símbolo que resta.
 *    Sólo se admite la resta de un símbolo de tipo 1 sobre el inmediato mayor de tipo 1 o de tipo 5. Ejemplos:
 *el símbolo I sólo puede restar a V y a X.
 *el símbolo X sólo resta a L y a C.
 *el símbolo C sólo resta a D y a M.
 *    Se permite que dos símbolos distintos aparezcan restando si no son adyacentes.

 */
