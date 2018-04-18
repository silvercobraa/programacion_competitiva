#include <stdio.h>

// las configuraciones normales de cada dígito
char g[10][8] = {
"YYYYYYN",//0
"NYYNNNN",//1
"YYNYYNY",//2
"YYYYNNY",//3
"NYYNNYY",//4
"YNYYNYY",//5
"YNYYYYY",//6
"YYYNNNN",//7
"YYYYYYY",//8
"YYYYNYY",//9
};

int main() {
    int n, i, j, k;
    char a[20][8];
	// se lee n hasta que n sea igual a cero
    while(scanf("%d", &n) == 1 && n) {
		// se lee la secuencia de leds iluminados en cada instante
        for(i = 0; i < n; i++)
            scanf("%s", &a[i]);
        int flag = 0;
		// se prueban cada uno de los dígitos posibles iniciales. 
		// No se prueba hasta cero porque si no el display tendria que tener numeros negativos 
        for(i = 9; i >= n-1; i--) {
            int bad[10] = {};
			// por cada uno de los instantes
            for(j = 0; j < n; j++) {
				// por cada uno de los LED en un instante dado
                for(k = 0; k < 7; k++) {
					// si el LED actual está marcado malo pero está iluminado, no es una configuración válida. podamos
                    if(bad[k] && a[j][k] == 'Y')
                        break;
					// si el LED actual debe estar iluminado ado el digito que corresponde, pero no lo está, entonces se marcadicho LED como malo para los LED siguientes
                    if(a[j][k] == 'N' && g[i-j][k] == 'Y')
                        bad[k] = 1;
					// si ocurre al revés, es una configuración inválida. Se sale antes del for 
                    else if(a[j][k] == 'Y' && g[i-j][k] == 'N')
                        break;
                }
				// salimos antes del for, no se consiguió el match. Se prueba con el siguiente dígito inicial
                if(k != 7)  break;
            }
			// si se llegó al último instante, es un match. Se marca un flag para indicarlo al loop de afuera
            if(j == n) {
                flag = 1;
                break;
            }
        }
		// si no se hizo match, se imprime el prefijo "MIS"
        if(!flag)
            printf("MIS");
		// luego se imprime "MATCH" incondicionalmente, pues en ambos casos estará presente
        puts("MATCH");
    }
    return 0;
}
